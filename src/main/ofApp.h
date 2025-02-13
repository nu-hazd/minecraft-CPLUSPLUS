#pragma once
#include "ofMain.h"
#include "Player.h"
#include "State.h"
#include "ChestState.h"
#include "CraftingState.h"
#include "FurnaceState.h"
#include "GeneratorState.h"
using namespace std;

/**
 * @class ofApp
 * @brief Main application class for the game.
 */
class ofApp : public ofBaseApp {
    public:
        Player* player; ///< Pointer to the player object.
        ItemHandler* instantiator; ///< Pointer to the item handler.
        State* currentState; ///< Pointer to the current state of the game.
        ChestState* chestState; ///< Pointer to the chest state.
        CraftingState* craftingState; ///< Pointer to the crafting state.
        FurnaceState* furnaceState; ///< Pointer to the furnace state.
        GeneratorState* generatorState; ///< Pointer to the generator state.

        ofSoundPlayer relaxingMusic; ///< Sound player for background music.
        /**
         * @brief Sets up the application.
         */
        void setup();

        /**
         * @brief Updates the application state.
         */
        void update();

        /**
         * @brief Draws the application.
         */
        void draw();

        /**
         * @brief Handles mouse movement events.
         * @param x Horizontal coordinate of the mouse.
         * @param y Vertical coordinate of the mouse.
         */
        void mouseMoved(int x, int y);

        /**
         * @brief Handles mouse press events.
         * @param x Horizontal coordinate of the mouse.
         * @param y Vertical coordinate of the mouse.
         * @param button Mouse button pressed.
         */
        void mousePressed(int x, int y, int button);

        /**
         * @brief Handles key press events.
         * @param key Key pressed.
         */
        void keyPressed(int key);

        /**
         * @brief Gives items to the player.
         */
        void giveItems();

        //--UNUSED--//
        void keyReleased(int key);
        void mouseDragged(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
};
