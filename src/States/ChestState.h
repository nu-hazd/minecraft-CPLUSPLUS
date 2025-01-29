#pragma once
#include "State.h"

class ChestState : public State {
    private:
        vector<ItemContainer> chestInventory;
    public:
        ChestState(Player* player);
        void addItem(Item itm, int count);
        void addItem(Item itm, int count, int slot);

        void update();
        void draw();
        void mouseMoved(int x, int y);
        void mousePressed(int x, int y, int button);
        //void keyPressed(int key);
};