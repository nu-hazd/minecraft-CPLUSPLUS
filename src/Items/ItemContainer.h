#pragma once
#include "Item.h"

class ItemContainer {
    private:
        // Container data variables
        int currentItemCount;
        Item currentItem;

        // Mouse detection variables
        bool mouseHovering;
        ofImage hoverHighlighter;
        ofRectangle collider;
    public:
        // Constructors
        /* Default constructor */
        ItemContainer(){};
        /**
         * Returns a simple container that holds an item and its count.
         * @param pX Horizontal coordinate
         * @param pY Vertical coordinate
         */
        ItemContainer(int pX, int pY);
        // Getters
        int getItemCount() { return this->currentItemCount; }
        bool isMouseHovering() { return this->mouseHovering; } 
        bool isEmpty() { return this->currentItem.getItemNumber() == 0;}
        bool isMaxed() { return this->getItemCount() == this->getCurrentItem().getMaxStack(); }
        bool isMaxedAfter(int amount) { return this->getItemCount() + amount > this->getCurrentItem().getMaxStack(); }
        bool isTool() { return this->currentItem.getMaxStack() == 1; } // Simplistic checker. Disables the ability to add items that have a max stack of 1 that aren't tools. 
        Item getCurrentItem() { return this->currentItem; }
        
        // Setters and useful methods
        void setItemCount(int newCount) { this->currentItemCount = newCount; }
        void setCurrentItem(Item newItem) { this->currentItem = newItem; }
        void setPos(int x, int y) { this->collider.setPosition(x,y); }
        void addOne() { this->currentItemCount++;}
        void deductOne() { this->currentItemCount--; if (currentItemCount <= 0) empty(); }
        void empty() { this->currentItem.setToAir(); this->currentItemCount = 0; }

        // Swaping logic methods
        void mouseEntered(int x, int y) { this->collider.inside(x,y) ? this->mouseHovering = true : this->mouseHovering = false; }
        void leftMouseClicked(int x, int y, ItemContainer& playerContainer) { if (isMouseHovering()) leftSwapWith(playerContainer); }
        void rightMouseClicked(int x, int y, ItemContainer& playerContainer) { if (isMouseHovering()) rightSwapWith(playerContainer); }
        void leftSwapWith(ItemContainer& playerContainer);
        void rightSwapWith(ItemContainer& playerContainer);
        void draw(); 

};