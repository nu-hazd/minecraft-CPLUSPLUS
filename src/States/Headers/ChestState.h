#pragma once
#include "State.h"

class ChestState : public State {
    private:
        vector<ItemContainer> chestInventory;   // An array of 27 ItemContainers
    public:
        /** 
         *  @brief Constructs a ChestState object with a player pointer.
         *  @param player Player pointer.
        */
        ChestState(Player* player);
        // Adds items to the first available space
        void addItem(Item itm, int count); 
        // Adds items to the specified slot
        void addItem(Item itm, int count, int slot);

        void update(){}; // Mandatory implementation
        void draw(); 
        void keyPressed(int key);
        void mouseMoved(int x, int y);
        void mousePressed(int x, int y, int button);
};