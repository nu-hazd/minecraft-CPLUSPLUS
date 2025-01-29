#pragma once
#include "State.h"

class CraftingState : public State {
    private:
        vector<ItemContainer> craftingGrid;
        ItemContainer resultContainer;
        ItemHandler* instantiator;
    public:
        CraftingState(Player* player, ItemHandler* instantiator);

        void craft();
        pair<Item,int> getItemFromRecipie(vector<int> grid);
        void gridStandarizer(vector<int>& grid);
        void update();
        void draw();
        void mouseMoved(int x, int y);
        void mousePressed(int x, int y, int button);
        void keyPressed(int key);
};