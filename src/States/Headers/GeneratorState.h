#pragma once
#include "State.h"

class GeneratorState : public State {
    private:;
        ItemContainer toolContainer; // Container that holds the tool to be used
        ItemContainer resultContainer; // Container that hold the resulting item
        ItemHandler* instantiator; // Creates items
        vector<vector<int>> lootTables;
    public:
        /**
         *  Constructs a GeneratorState object with a player and an a ItemHandler pointer.
         *  @param player Player pointer.
         *  @param instantiator ItemHandler pointer.
         */
        GeneratorState(Player* player, ItemHandler* instantiatr);
        void generateItem(); // Generates an item based on the tool inside the toolContainer
        void createLootTables(); // Creates loot tables for all tools that fit into toolContainer
        void update(){}; // Mandatory implementation
        void draw();
        void mouseMoved(int x, int y);
        void mousePressed(int x, int y, int button);
        void keyPressed(int key) { if (key == 'g') generateItem(); }; 
};