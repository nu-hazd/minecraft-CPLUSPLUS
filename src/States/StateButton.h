#pragma once
#include "ofMain.h"

class StateButton {
    private:
        ofRectangle collider;
        ofImage buttonSprite;
        string targetState;
        const int WIDTH = 80;
        const int HEIGHT = 71;
        ofSoundPlayer soundEffect;
    public:
        StateButton(string dS, int pX, int pY) {
            this-> targetState = dS;
            this->buttonSprite.load("images/states/" + targetState + "StateButton.png");
            this->collider.setPosition(pX,pY);
            this->collider.setWidth(WIDTH);
            this->collider.setHeight(HEIGHT);
            this->soundEffect.load("audio/buttonClick.mp3");
        }
        string getTargetState() { return this->targetState; }
        bool onPress(int x, int y) { return collider.inside(x,y);}
        void playSoundEffect() { this->soundEffect.play(); }
        void draw() { this->buttonSprite.draw(collider.getPosition());}
};