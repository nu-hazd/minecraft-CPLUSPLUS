#pragma once
#include "ofMain.h"
#include "Item.h"

class ItemContainer {
    private:
        int currentItemCount;
        Item currentItem;
        bool extractOnly;
        bool fuelOnly;

        bool mouseHovering;
        ofImage hoverHighlighter;
        ofRectangle collider;
    public:
        // Constructors
        ItemContainer(){};
        ItemContainer(int pX, int pY);
        ItemContainer(Item item, int pX, int pY, bool eO, bool fO);
        // Getters
        int getItemCount() { return this->currentItemCount; }
        bool isMouseHovering() { return this->mouseHovering; } 
        bool isExtractOnly() { return this->extractOnly; }
        bool isFuelOnly() { return this->fuelOnly; }
        bool isEmpty() { return this->currentItem.getItemNumber() == 0;}
        Item getCurrentItem() { return this->currentItem; }
        // Setters
        void setItemCount(int newCount) { this->currentItemCount = newCount; }
        void setCurrentItem(Item newItem) { this->currentItem = newItem; }
        void setPos(int x, int y){ this->collider.setPosition(x,y); }
        // Methods
        void mouseEntered(int x, int y);
        void leftMousePressed(int x, int y, ItemContainer& playerCursor);
        void rightMousePressed(int x, int y, ItemContainer& playerCursor);
        void leftWasPressed(ItemContainer& playerCursor);
        void rightWasPressed(ItemContainer& playerCursor);
        void empty();
        void draw(); 

};