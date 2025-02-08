#pragma once
#include "ofMain.h"
#include "ItemHandler.h"
#include "ItemContainer.h"
#include "Player.h"

/**
 * @class State
 * @brief Abstract base class representing a game state.
 */
class State {
    private:
        Player* player; ///< Pointer to the player object.
    public:
        ofImage background; ///< Background image for the state.

        /**
         * @brief Constructs a State object.
         * @param plyr Pointer to the player object.
         */
        State(Player* plyr) { this->player = plyr; }

        /**
         * @brief Gets the player object.
         * @return Pointer to the player object.
         */
        Player* getPlayer() { return this->player; }

        /**
         * @brief Updates the state. Pure virtual function to be implemented by derived classes.
         */
        virtual void update() = 0;

        /**
         * @brief Draws the state. Pure virtual function to be implemented by derived classes.
         */
        virtual void draw() = 0;

        /**
         * @brief Handles key press events. Pure virtual function to be implemented by derived classes.
         * @param key Key pressed.
         */
        virtual void keyPressed(int key) = 0;

        /**
         * @brief Handles mouse movement events.
         * @param x Horizontal coordinate of the mouse.
         * @param y Vertical coordinate of the mouse.
         */
        virtual void mouseMoved(int x, int y) {
            for (auto& slot : this->getPlayer()->getInventory()) { slot.mouseEntered(x, y); }
            player->getCursorContainer().setPos(x - 32, y - 32);
        }

        /**
         * @brief Handles mouse press events.
         * @param x Horizontal coordinate of the mouse.
         * @param y Vertical coordinate of the mouse.
         * @param button Mouse button pressed.
         */
        virtual void mousePressed(int x, int y, int button) {
            if (button == 0) for (auto& slot : player->getInventory()) { slot.leftMouseClicked(x, y, player->getCursorContainer()); }
            if (button == 2) for (auto& slot : player->getInventory()) { slot.rightMouseClicked(x, y, player->getCursorContainer()); }
        }
};