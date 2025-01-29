#pragma once
#include "ofMain.h"
#include "ItemHandler.h"
#include "ItemContainer.h"
#include "Player.h"

class State {
    private:
        Player* player;
    public:
        // State background sprites should be 704x668 pixels
        ofImage background;
        State(Player* plyr){
            this->player = plyr;
        };

        Player* getPlayer() { return this->player; }

        virtual void update() = 0;
        virtual void draw() = 0;
        virtual void mouseMoved(int x, int y) = 0;
        virtual void mousePressed(int x, int y, int button) = 0;
        virtual void keyPressed(int ket) = 0;

};