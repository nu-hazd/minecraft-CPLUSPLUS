#pragma once
#include "ofMain.h" 


class Item {
    private:
        int itemNumber;
        int maxStack;
        int fuelLevel;
        ofImage sprite;
        string name;
    public:
        /**
        * Constructs an Item object. All items must have a unique item number.
        * @param iN Unique item identifier. Conventionally itemNumber is greater than 0.
        * @param mS Maximun amount of an item that any ItemContainer can hold. Conventionally the stack sizes are 1, 16 and 64.
        * @param fL How much the item burns inside a furnace. One fuel will equal one smelted item. Most items are 0.
        * @param spr Sprite, or image, that will be called in the draw() method. In order to fit in the contaienr, the sprite must be 64x64 pixels.
        * @param iNa Display name for the item.
        */
        Item(int iN, int mS, int fL, ofImage spr, string iNa) {
            this->itemNumber = iN;
            this->maxStack = mS;
            this->fuelLevel = fL;
            this->sprite = spr;
            this->name = iNa;
        }
        /** Default constructor. Returns an air (empty) item. */
        Item() { this->setToAir(); } 
        // Getters
        int getItemNumber() { return this->itemNumber; }
        int getMaxStack() { return this->maxStack; } 
        int getFuelLevel() { return this->fuelLevel; }
        ofImage getSprite() { return this->sprite;}
        string getName() { return this->name; }

        // Setters
        //* Makes any given item air. In other words, it makes it empty. */
        void setToAir() {
            this->itemNumber = 0;
            this->maxStack = 1;
            this->fuelLevel = 0;
            ofImage airSpr;
            airSpr.load("C:/Users/Public/of_v20240930_msys2_mingw64_release/apps/myApps/minecraft/bin/data/images/sprites/sprites.png");
            airSpr.crop(0,0,64,64);
            this->sprite = airSpr;
            this->name = "air";
        }

        // Useful operators that enable direct comparison of items.
        bool operator==(const Item& other) const { return this->itemNumber == other.itemNumber; }
        bool operator!=(const Item& other) const { return this->itemNumber != other.itemNumber; }
};