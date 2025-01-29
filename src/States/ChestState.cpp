#include "ChestState.h"

ChestState::ChestState(Player* player) : State(player) {
    this->background.load("C:/Users/Public/of_v20240930_msys2_mingw64_release/apps/myApps/minecraft/bin/data/images/states/chest.png");
    const int VERTICAL_OFFSET = 72;
    const int HORIZONTAL_OFFSET = 32;
    const int DISTANCE_BETWEEN_CONTAINERS = 72;
    const int ROWS = 3;
    const int COLS = 9;
    for (int y = VERTICAL_OFFSET; y < VERTICAL_OFFSET + (DISTANCE_BETWEEN_CONTAINERS*ROWS); y = y + DISTANCE_BETWEEN_CONTAINERS) {
        for (int x = HORIZONTAL_OFFSET; x < HORIZONTAL_OFFSET + (DISTANCE_BETWEEN_CONTAINERS*COLS); x = x + DISTANCE_BETWEEN_CONTAINERS) {
            this->chestInventory.push_back(ItemContainer(x,y));
        }
    }
}



void ChestState::addItem(Item itm, int count) {
    int i = 0;
    while (!this->chestInventory[i].isEmpty()) {i++;}
    this->chestInventory[i].setCurrentItem(itm);
    this->chestInventory[i].setItemCount(count);
}
void ChestState::addItem(Item itm, int count, int slot){
    // Out of range checker
    if (slot < 0 || slot > 26) { slot = 0; }
    this->chestInventory[slot].setCurrentItem(itm);
    this->chestInventory[slot].setItemCount(count);
};

void ChestState::update(){
    // Chest state doesn't need an update function, but we define it so that C++ doesn't blow up
};
void ChestState::draw(){
    background.draw(0,0);
    for (auto slot : this->chestInventory) {
        slot.draw();
    }
    this->getPlayer()->draw();
};
void ChestState::mouseMoved(int x, int y){
    for (auto& slot : this->getPlayer()->getInventory()) {
        slot.mouseEntered(x,y);
    }
    for (auto& slot : this->chestInventory) {
        slot.mouseEntered(x,y);
    }
    getPlayer()->getCursorContainer().setPos(x-32,y-32);
};
void ChestState::mousePressed(int x, int y, int button){
    if (button == 0) {
        for (auto& slot : this->chestInventory) {
            slot.leftMousePressed(x,y,getPlayer()->getCursorContainer());
        }
        for (auto& slot : this->getPlayer()->getInventory()) {
            slot.leftMousePressed(x,y,getPlayer()->getCursorContainer());
        }
    }
    if (button == 2) {
        for (auto& slot : this->chestInventory) {
            slot.rightMousePressed(x,y,getPlayer()->getCursorContainer());
        }
         for (auto& slot : this->getPlayer()->getInventory()) {
            slot.rightMousePressed(x,y,getPlayer()->getCursorContainer());
        }
    }
};
void ChestState::keyPressed(int key) {}