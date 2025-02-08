#pragma once
#include "Item.h"

/**
 * @class ItemContainer
 * @brief Represents a container that holds an item and its count.
 */
class ItemContainer {
    private:
        int currentItemCount; ///< Current count of the item in the container.
        Item currentItem; ///< The item held in the container.

        bool mouseHovering; ///< Indicates if the mouse is hovering over the container.
        ofImage hoverHighlighter; ///< Image used to highlight the container when hovered.
        ofRectangle collider; ///< Rectangle used for mouse collision detection.
    public:
        // Constructors
        /**
         * @brief Default constructor.
         */
        ItemContainer(){};

        /**
         * @brief Constructs an ItemContainer at a specific position.
         * @param pX Horizontal coordinate.
         * @param pY Vertical coordinate.
         */
        ItemContainer(int pX, int pY);

        // Getters
         /**
         * @brief Gets the current item count.
         * @return Current item count.
         */
        int getItemCount() { return this->currentItemCount; }

        /**
         * @brief Checks if the mouse is hovering over the container.
         * @return True if the mouse is hovering, false otherwise.
         */
        bool isMouseHovering() { return this->mouseHovering; }

        /**
         * @brief Checks if the container is empty.
         * @return True if the container is empty, false otherwise.
         */
        bool isEmpty() { return this->currentItem.getItemNumber() == 0;}

        /**
         * @brief Checks if the container is at max capacity.
         * @return True if the container is maxed, false otherwise.
         */
        bool isMaxed() { return this->getItemCount() == this->getCurrentItem().getMaxStack(); }

        /**
         * @brief Checks if adding a certain amount would exceed max capacity.
         * @param amount Amount to add.
         * @return True if the container would be maxed, false otherwise.
         */
        bool isMaxedAfter(int amount) { return this->getItemCount() + amount > this->getCurrentItem().getMaxStack(); }

        /**
         * @brief Checks if the current item is a tool.
         * @return True if the item is a tool, false otherwise.
         */
        bool isTool() { return this->currentItem.getMaxStack() == 1; }

        /**
         * @brief Gets the current item.
         * @return The current item.
         */
        Item getCurrentItem() { return this->currentItem; }

        // Setters and useful methods
        /**
         * @brief Sets the item count.
         * @param newCount New item count.
         */
        void setItemCount(int newCount) { this->currentItemCount = newCount; }

        /**
         * @brief Sets the current item.
         * @param newItem New item.
         */
        void setCurrentItem(Item newItem) { this->currentItem = newItem; }

        /**
         * @brief Sets the position of the container.
         * @param x Horizontal coordinate.
         * @param y Vertical coordinate.
         */
        void setPos(int x, int y) { this->collider.setPosition(x,y); }

        /**
         * @brief Increments the item count by one.
         */
        void addOne() { this->currentItemCount++;}

        /**
         * @brief Decrements the item count by one.
         */
        void deductOne() { this->currentItemCount--; if (currentItemCount <= 0) empty(); }

        /**
         * @brief Empties the container.
         */
        void empty() { this->currentItem.setToAir(); this->currentItemCount = 0; }

        // Swapping logic methods
        /**
         * @brief Checks if the mouse has entered the container.
         * @param x Horizontal coordinate of the mouse.
         * @param y Vertical coordinate of the mouse.
         */
        void mouseEntered(int x, int y) { this->collider.inside(x,y) ? this->mouseHovering = true : this->mouseHovering = false; }

        /**
         * @brief Handles left mouse click for swapping items.
         * @param x Horizontal coordinate of the mouse.
         * @param y Vertical coordinate of the mouse.
         * @param playerContainer The player's item container.
         */
        void leftMouseClicked(int x, int y, ItemContainer& playerContainer) { if (isMouseHovering()) leftSwapWith(playerContainer); }

        /**
         * @brief Handles right mouse click for swapping items.
         * @param x Horizontal coordinate of the mouse.
         * @param y Vertical coordinate of the mouse.
         * @param playerContainer The player's item container.
         */
        void rightMouseClicked(int x, int y, ItemContainer& playerContainer) { if (isMouseHovering()) rightSwapWith(playerContainer); }

        /**
         * @brief Swaps items with another container using left click logic.
         * @param playerContainer The player's item container.
         */
        void leftSwapWith(ItemContainer& playerContainer);

        /**
         * @brief Swaps items with another container using right click logic.
         * @param playerContainer The player's item container.
         */
        void rightSwapWith(ItemContainer& playerContainer);

        /**
         * @brief Draws the item container.
         */
        void draw();
};