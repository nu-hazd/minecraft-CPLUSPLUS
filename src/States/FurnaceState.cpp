#include "FurnaceState.h"

FurnaceState::FurnaceState(Player* player, ItemHandler* instantce) : State(player) {
    this->fuel = 0;
    this->instantiator = instantce;
    this->background.load("images/states/furnace.png");
    this->fuelContainer = ItemContainer(224, 212); // These coordinate values were obtained via PaintMS. Piskel also works.
    this->burningContainer = ItemContainer(224, 68);
    this->resultContainer = ItemContainer(464, 139);
    addSmeltableItems();
};

void FurnaceState::smelt() {
    if (fuel == 0) { 
        fuel = fuelContainer.getCurrentItem().getFuelLevel(); 
        fuelContainer.setItemCount(fuelContainer.getItemCount()-1);
        if (fuelContainer.getItemCount()==0) {fuelContainer.empty();}
    }
    if (resultContainer.isEmpty()) { 
        Item newItem = instantiator->getItemFromNumber(getResultantItemNumber(burningContainer.getCurrentItem()));
        resultContainer.setCurrentItem(newItem);
        resultContainer.setItemCount(1);
    }else {
        resultContainer.setItemCount(resultContainer.getItemCount()+1);
    }

    burningContainer.setItemCount(burningContainer.getItemCount()-1);
    if (burningContainer.getItemCount()==0) { 
        burningContainer.empty(); 
        fuel = 0;
    }else {
        fuel--;
    }
}

bool FurnaceState::canSmelt() {
    if (burningContainer.isEmpty()) { return false; }
    if (resultContainer.getItemCount()+1 > resultContainer.getCurrentItem().getMaxStack()) { return false; }
    if (fuel == 0 && fuelContainer.isEmpty()) { return false; }
    if (!resultContainer.isEmpty() && (resultContainer.getCurrentItem().getItemNumber() != getResultantItemNumber(burningContainer.getCurrentItem()))) {return false;}
    return true;
}

void FurnaceState::update() {
    if (canSmelt()) {
        smelt();
    } 
};
void FurnaceState::draw() {
    background.draw(0,0);
    this->fuelContainer.draw();
    this->burningContainer.draw();
    this->resultContainer.draw();
    this->getPlayer()->draw();
}
void FurnaceState::mouseMoved(int x, int y) {
    for (auto& slot : this->getPlayer()->getInventory()) {
        slot.mouseEntered(x,y);
    }
    this->fuelContainer.mouseEntered(x,y);
    this->burningContainer.mouseEntered(x,y);
    this->resultContainer.mouseEntered(x,y);
    getPlayer()->getCursorContainer().setPos(x-32,y-32);
};
void FurnaceState::mousePressed(int x, int y, int button) {
    if (button == 0) {
        for (auto& slot : this->getPlayer()->getInventory()) {
            slot.leftMousePressed(x,y,getPlayer()->getCursorContainer());
        }

        if (this->getPlayer()->getCursorContainer().isEmpty()) {
            this->resultContainer.leftMousePressed(x,y,this->getPlayer()->getCursorContainer());
        }
        if (this->getPlayer()->getCursorContainer().isEmpty() || this->getPlayer()->getCursorContainer().getCurrentItem().getFuelLevel() > 0) {
            this->fuelContainer.leftMousePressed(x,y,this->getPlayer()->getCursorContainer());
        }
        if (this->getPlayer()->getCursorContainer().isEmpty() || isItemSmeltable(this->getPlayer()->getCursorContainer().getCurrentItem())) {
            this->burningContainer.leftMousePressed(x,y,this->getPlayer()->getCursorContainer());
        }



    }
    if (button == 2) {
         for (auto& slot : this->getPlayer()->getInventory()) {
            slot.rightMousePressed(x,y,getPlayer()->getCursorContainer());
        }
        if (this->getPlayer()->getCursorContainer().isEmpty() || this->getPlayer()->getCursorContainer().getCurrentItem().getFuelLevel() > 0) {
            this->fuelContainer.rightMousePressed(x,y,this->getPlayer()->getCursorContainer());
        }
        if (this->getPlayer()->getCursorContainer().isEmpty() || isItemSmeltable(this->getPlayer()->getCursorContainer().getCurrentItem())) {
            this->burningContainer.rightMousePressed(x,y,this->getPlayer()->getCursorContainer());
        }
        if (this->getPlayer()->getCursorContainer().isEmpty()) {
            this->resultContainer.rightMousePressed(x,y,this->getPlayer()->getCursorContainer());
        }
    }
};
void FurnaceState::keyPressed(int key) {}

void FurnaceState::addSmeltableItems() {
    this->smeltableItems.push_back(1);
    this->smeltableItems.push_back(4);
    this->smeltableItems.push_back(17);
}

int FurnaceState::getResultantItemNumber(Item itm) {
    int itemNumber = itm.getItemNumber();
    switch (itemNumber) {
        case 1:
            return 16;
        case 4:
            return 18;
        case 17:
            return 13;
        default:
            return 0;
    }
}