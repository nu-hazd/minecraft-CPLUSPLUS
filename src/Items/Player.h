#pragma once
#include "ofMain.h"
#include "ItemContainer.h"
#include "ItemHandler.h"
#include "StateButton.h"

class Player {
    private:
        ItemContainer cursorContainer; // Container that follows the mouse
        vector<ItemContainer> inventory; // An array of 27 ItemContainers
        vector<StateButton> buttons;
    public:
        Player() {
            this->cursorContainer = ItemContainer(0, 0);
            /*
                An inventory is an array of lenght 9 of ItemContainers. 
                There are 27 slots (9x3) within the players inventory.
                The offset between each slot is 12 pixels.
                We start at the top left coordinate of the inventory and create each
                container, adding them to the vector with their respective coordinates.
                The starting coordinates are: (32, 340)

            */
            const int VERT_OFFSET = 340;
            const int HORIZ_OFFSET = 32;
            const int DISTANCE_BETWEEN_CONTAINERS = 72; // 64 + 12
            const int ROWS = 3;
            const int COLS = 9;
            for (int y = VERT_OFFSET; y < VERT_OFFSET + (DISTANCE_BETWEEN_CONTAINERS*ROWS); y = y + DISTANCE_BETWEEN_CONTAINERS) {
                for (int x = HORIZ_OFFSET; x < HORIZ_OFFSET + (DISTANCE_BETWEEN_CONTAINERS*COLS); x = x + DISTANCE_BETWEEN_CONTAINERS) {
                    this->inventory.push_back(ItemContainer(x,y));
                }
            }
            // Create the StateButtons.
            const int VERT_ALIGN = 572; 
            const int HORZ_ALIGN = 32;
            const int DISTANCE_BETWEEN_BUTTONS = 6;
            const int SIZE_X = 80;
            StateButton chestStateButton{"chest", HORZ_ALIGN + (0*DISTANCE_BETWEEN_BUTTONS) + (0 * SIZE_X),VERT_ALIGN};
            StateButton craftingStateButton{"crafting", HORZ_ALIGN + (1*DISTANCE_BETWEEN_BUTTONS) + (1 * SIZE_X),VERT_ALIGN};
            StateButton furnaceStateButton{"furnace", HORZ_ALIGN + (2*DISTANCE_BETWEEN_BUTTONS) + (2 * SIZE_X),VERT_ALIGN};

            this->buttons.push_back(chestStateButton);
            this->buttons.push_back(craftingStateButton);
            this->buttons.push_back(furnaceStateButton);
    
        }


        ItemContainer& getCursorContainer() { return this->cursorContainer; }
        vector<ItemContainer>& getInventory() { return this->inventory; }
        vector<StateButton>& getStateButtons() { return this->buttons; }

        void draw() {
            for (auto button : buttons) { button.draw();}
            for (auto slot : inventory) {slot.draw();}
            this->cursorContainer.draw();
        }
        void addItem(Item itm, int count) {
            int i = 0;
            while (!this->inventory[i].isEmpty()) {i++;}
            this->inventory[i].setCurrentItem(itm);
            this->inventory[i].setItemCount(count);
        }
        void addItem(Item itm, int count, int slot){
            // Out of range checker
            if (slot < 0 || slot > 26) { slot = 0; }
            this->inventory[slot].setCurrentItem(itm);
            this->inventory[slot].setItemCount(count);
     };
};