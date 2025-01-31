#pragma once
#include "State.h"

class FurnaceState : public State {
    private:
        int fuel;
        ItemContainer fuelContainer; // Container that holds the fuel
        ItemContainer burningContainer; // Container that holds the smeltable item
        ItemContainer resultContainer; // Container that hold the resulting item
        ItemHandler* instantiator; // Creates items
        vector<int> smeltableItems; // Holds the numbers of all smeltable items
    public:
        /**
         *  Constructs a FurnaceState object with a player and an a ItemHandler pointer.
         *  @param player Player pointer.
         *  @param instantiator ItemHandler pointer.
         */
        FurnaceState(Player* player, ItemHandler* instantiator);
        // Checks if an item is smeltable by iterating through smeltableItems
        bool isItemSmeltable(Item itm) {
            for (int itemNum : this->smeltableItems) { if (itm.getItemNumber() == itemNum) return true; }
            return false;
        }
        // Checks if conditions are met for smelting
        bool canSmelt();
        // Returns the resulting item number of the passed in smeltable item
        int getResultantItemNumber(Item itm);
        
    
        void smelt(); // Smelts
        void addSmeltableItems(); // Adds all of the smeltable items numbers to the smeltableItems vector
        void update();
        void draw();
        void mouseMoved(int x, int y);
        void mousePressed(int x, int y, int button);
        void keyPressed(int key) {}; // Mandatory implementation
};