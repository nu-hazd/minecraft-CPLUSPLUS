#pragma once
#include "ofMain.h"
#include "Item.h"       
#include "ItemHandler.h" 
#include "ItemContainer.h"
#include "Player.h"
#include "State.h"
#include "ChestState.h"
#include "CraftingState.h"
#include "FurnaceState.h"
using namespace std;

class ofApp : public ofBaseApp {
    public:

        Player* player;
        ItemHandler* instantiator;
        State* currentState;
        ChestState* chestState;
        CraftingState* craftingState;
        FurnaceState* furnaceState;


        void setup();
        void update();
        void draw();
        void mouseMoved(int x, int y);
        void mousePressed(int x, int y, int button);
        void giveItems();

        //--UNUSED--//
        void keyPressed(int key);
        void keyReleased(int key);
        void mouseDragged(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);




};
