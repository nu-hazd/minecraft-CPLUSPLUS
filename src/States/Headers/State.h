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
        // Save the player pointer. It will be used within each State's logic
        State(Player* plyr){ this->player = plyr;};
        // Since player is private, we need a getter to access the attribute
        Player* getPlayer() { return this->player; }

        // Update, draw and keyPressed functions will be exclusively defined within each state 
        virtual void update() = 0;
        virtual void draw() = 0;
        virtual void keyPressed(int ket) = 0;
        // Each time the mouse is moved, this function is called. x and y are the mouse coordinates
        virtual void mouseMoved(int x, int y) { 
            for (auto& slot : this->getPlayer()->getInventory()) { slot.mouseEntered(x,y); }
            player->getCursorContainer().setPos(x-32,y-32);
        };
        // button = 0 when left mouse is clicked, button = 2 when right mouse is clicked. x and y are the mouse coordinates
        virtual void mousePressed(int x, int y, int button) {
            if (button == 0) for (auto& slot : player->getInventory()) { slot.leftMouseClicked(x,y,player->getCursorContainer()); }
            if (button == 2) for (auto& slot : player->getInventory()) {slot.rightMouseClicked(x,y,player->getCursorContainer()); }
        }
       

};