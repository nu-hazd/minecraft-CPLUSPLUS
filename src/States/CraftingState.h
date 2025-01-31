#pragma once
#include "State.h"

class CraftingState : public State {
    private:
        vector<ItemContainer> craftingGrid;
        ItemContainer resultContainer;
        ItemHandler* instantiator;
    public:
        CraftingState(Player* player, ItemHandler* instantiator);
        // Handles crafting logic
        void craft();
        // Holds all of the recipies
        pair<Item,int> getItemFromRecipie(vector<int> grid);
        // Helper function that snaps the ingredients to the upper left corner of the grid
        void standarizeGrid(vector<int>& grid);
        
        void update(){}; // Mandatory definition
        void draw(); 
        void keyPressed(int key) { if (key == 'C' || key == 'c') craft(); }
        void mouseMoved(int x, int y);
        void mousePressed(int x, int y, int button);
};