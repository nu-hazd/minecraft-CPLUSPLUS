#pragma once
#include "ofMain.h"

class StateButton {
    private:
        ofRectangle collider; // Handles collision with the mouse cursor
        ofImage buttonSprite; // Texture of the button
        string targetState; // What state the button takes you to
        const int WIDTH = 80; 
        const int HEIGHT = 71;
        ofSoundPlayer soundEffect; // *CLICK*
    public:
        /**
         * @brief Constructs a new StateButton object.
         * 
         * This constructor initializes a StateButton with a target state, position, and default dimensions.
         * It loads the button sprite and sound effect, and sets up the collider for mouse interaction.
         * 
         * @param dS The target state that the button will navigate to.
         * @param pX The x-coordinate of the button's position.
         * @param pY The y-coordinate of the button's position.
         */
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