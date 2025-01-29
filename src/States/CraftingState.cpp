#include "CraftingState.h"

CraftingState::CraftingState(Player* player, ItemHandler* instantce) : State(player) {
    this->instantiator = instantce;
    this->background.load("images/states/crafting.png");
    this->resultContainer = ItemContainer(496,139);
    const int VERTICAL_OFFSET = 68;
    const int HORIZONTAL_OFFSET = 120;
    const int DISTANCE_BETWEEN_CONTAINERS = 72;
    const int ROWS = 3;
    const int COLS = 3;
    for (int y = VERTICAL_OFFSET; y < VERTICAL_OFFSET + (DISTANCE_BETWEEN_CONTAINERS*ROWS); y = y + DISTANCE_BETWEEN_CONTAINERS) {
        for (int x = HORIZONTAL_OFFSET; x < HORIZONTAL_OFFSET + (DISTANCE_BETWEEN_CONTAINERS*COLS); x = x + DISTANCE_BETWEEN_CONTAINERS) {
            this->craftingGrid.push_back(ItemContainer(x,y));
        }
    }

};

void CraftingState::craft() {
    vector<int> translatedGrid;
    for (ItemContainer container : craftingGrid) {
        translatedGrid.push_back(container.getCurrentItem().getItemNumber());
    }
    gridStandarizer(translatedGrid);
    pair<Item, int> result = getItemFromRecipie(translatedGrid);
    if (resultContainer.isEmpty())
        {
            resultContainer.setCurrentItem(result.first);
            resultContainer.setItemCount(result.second);
        }
    else if (resultContainer.getCurrentItem() == result.first && resultContainer.getItemCount() + result.second < result.first.getMaxStack()) 
        {
            resultContainer.setCurrentItem(result.first);
            resultContainer.setItemCount(resultContainer.getItemCount()+result.second);
        }
    else { return; } 
    for (ItemContainer& ingredient : craftingGrid) {
        ingredient.setItemCount(ingredient.getItemCount()-1);
        if (ingredient.getItemCount()==0) { ingredient.empty();}
    }
}

void CraftingState::update() {};

void CraftingState::draw() {
    background.draw(0,0);
    for (auto slot : this->craftingGrid) {
        slot.draw();
    }
    this->resultContainer.draw();
    this->getPlayer()->draw();
};
void CraftingState::mouseMoved(int x, int y) {
    for (auto& slot : this->getPlayer()->getInventory()) {
        slot.mouseEntered(x,y);
    }
    for (auto& slot : this->craftingGrid) {
        slot.mouseEntered(x,y);
    }
    this->resultContainer.mouseEntered(x,y);
    getPlayer()->getCursorContainer().setPos(x-32,y-32);
};
void CraftingState::mousePressed(int x, int y, int button) {
    if (button == 0) {
        for (auto& slot : this->craftingGrid) {
            slot.leftMousePressed(x,y,getPlayer()->getCursorContainer());
        }
        for (auto& slot : this->getPlayer()->getInventory()) {
            slot.leftMousePressed(x,y,getPlayer()->getCursorContainer());
        }
        if (this->getPlayer()->getCursorContainer().isEmpty()) {
            this->resultContainer.leftMousePressed(x,y,this->getPlayer()->getCursorContainer());
        }
    }
    if (button == 2) {
        for (auto& slot : this->craftingGrid) {
            slot.rightMousePressed(x,y,getPlayer()->getCursorContainer());
        }
        for (auto& slot : this->getPlayer()->getInventory()) {
            slot.rightMousePressed(x,y,getPlayer()->getCursorContainer());
        }
        }
        if (this->getPlayer()->getCursorContainer().isEmpty()) {
            this->resultContainer.rightMousePressed(x,y,this->getPlayer()->getCursorContainer());
    }
};
void CraftingState::keyPressed(int key) {
    if (key == 'C' || key == 'c') {
        craft();
    }
}

void CraftingState::gridStandarizer(vector<int>& grid) {
    /*
        Helper function that snaps the grid to the upper-leftt corner.
    // */
    for (int i = 0; i < 2; i++) {
        // Vertical line checker
        // If theres is a line, move columns left. Do this a maximum of two times.
        if (grid[0] == 0 && grid[3] == 0 && grid[6] == 0) {
            grid[0] = grid[1];
            grid[1] = grid[2];
            grid[2] = 0;
            grid[3] = grid[4];
            grid[4] = grid[5];
            grid[5] = 0;
            grid[6] = grid[7];
            grid[7] = grid[8];
            grid[8] = 0;
        } 
    }
     for (int i = 0; i < 2; i++) {
        // Horizontal line checker
        // If theres is a line, move rows up. Do this a maximum of two times.
        if (grid[0] == 0 && grid[1] == 0 && grid[2] == 0) {
                grid[0] = grid[3];
                grid[1] = grid[4];
                grid[2] = grid[5];
                grid[3] = grid[6];
                grid[4] = grid[7];
                grid[5] = grid[8];
                grid[6] = 0;
                grid[7] = 0;
                grid[8] = 0;
        } 
    }


}



pair<Item, int> CraftingState::getItemFromRecipie(vector<int> grid) {
    // A pair holds two
    pair<Item, int> result;
    // Initialize the recipie to Item() and 0, indicating that no recipie has yet been found.
    result.first = Item();
    result.second = 0;

    /* We could, and should, have used a map. But lets keep it simple. The syntax is as follows:
        if (grid == vector<int>
                {#, #, #,
                 #, #, #,
                 #, #, #}
        ) { 
            result.first = instantiator->getItemFromNumber(itemNumber);
            result.second = itemAmount;
        }
       Make sure to align the recipie to the upper left corner of the array.
    */
        if (grid == vector<int>
                {2, 0, 0,
                 2, 0, 0,
                 0, 0, 0}
            ) {
            result.first = instantiator->getItemFromNumber(6);
            result.second = 4;
        }
        if (grid == vector<int>
                {2, 2, 2,
                 0, 6, 0,
                 0, 6, 0}
            ) {
            result.first = instantiator->getItemFromNumber(7);
            result.second = 1;
        }
        if (grid == vector<int>
                {2, 0, 0,
                 6, 0, 0,
                 6, 0, 0}
            ) {
            result.first = instantiator->getItemFromNumber(10);
            result.second = 1;
        }
         if (grid == vector<int>
                {1, 0, 0,
                 0, 0, 0,
                 0, 0, 0}
            ) {
            result.first = instantiator->getItemFromNumber(2);
            result.second = 4;
        }















        return result;       
}


