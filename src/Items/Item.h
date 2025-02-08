#pragma once
#include "ofMain.h"

/**
 * @class Item
 * @brief Represents an item in the game with various properties.
 */
class Item {
    private:
        int itemNumber; ///< Unique item identifier.
        int maxStack; ///< Maximum stack size.
        int fuelLevel; ///< Fuel level for smelting.
        ofImage sprite; ///< Sprite image for the item.
        string name; ///< Display name of the item.
    public:
        /**
         * @brief Constructs an Item object.
         * @param iN Unique item identifier.
         * @param mS Maximum stack size.
         * @param fL Fuel level for smelting.
         * @param spr Sprite image.
         * @param iNa Display name.
         */
        Item(int iN, int mS, int fL, ofImage spr, string iNa) {
            this->itemNumber = iN;
            this->maxStack = mS;
            this->fuelLevel = fL;
            this->sprite = spr;
            this->name = iNa;
        }

        /**
         * @brief Default constructor. Initializes an air (empty) item.
         */
        Item() { this->setToAir(); }

        // Getters
        int getItemNumber() { return this->itemNumber; }
        int getMaxStack() { return this->maxStack; }
        int getFuelLevel() { return this->fuelLevel; }
        ofImage getSprite() { return this->sprite; }
        string getName() { return this->name; }

        // Setters
        /**
         * @brief Makes the item an air (empty) item.
         */
        void setToAir() {
            this->itemNumber = 0;
            this->maxStack = 1;
            this->fuelLevel = 0;
            ofImage airSpr;
            airSpr.load("C:/Users/Public/of_v20240930_msys2_mingw64_release/apps/myApps/minecraft/bin/data/images/sprites/sprites.png");
            airSpr.crop(0, 0, 64, 64);
            this->sprite = airSpr;
            this->name = "air";
        }

        // Operators
        bool operator==(const Item& other) const { return this->itemNumber == other.itemNumber; }
        bool operator!=(const Item& other) const { return this->itemNumber != other.itemNumber; }
};