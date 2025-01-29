#pragma once
#include "State.h"

class FurnaceState : public State {
    private:
        int fuel;
        ItemContainer fuelContainer;
        ItemContainer burningContainer;
        ItemContainer resultContainer;
        ItemHandler* instantiator;
        vector<int> smeltableItems;
    public:
        FurnaceState(Player* player, ItemHandler* instantiator);

        bool isItemSmeltable(Item itm) {
            for (int itemNum : this->smeltableItems) { if (itm.getItemNumber() == itemNum) return true; }
            return false;
        }
        bool canSmelt();
        int getResultantItemNumber(Item itm);
        

        void smelt();
        void addSmeltableItems();
        void update();
        void draw();
        void mouseMoved(int x, int y);
        void mousePressed(int x, int y, int button);
        void keyPressed(int key);
};