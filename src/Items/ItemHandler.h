#pragma once
#include "Item.h"

/*
    Instantiator class that will facilitate item creation.
    Holds an array of all possibles items.
*/
class ItemHandler {
    private:
        ofImage sheet;
        const int SPRITE_WIDTH = 64;
        const int SPRITE_HEIGHT = 64;
        vector<Item> itemList;
    public:
        // Helper function that returns the sprite given its zero index coordinate on sprites.png
        ofImage getSpriteFromSheet(int col, int row) {
            ofImage sprite;
            sprite.cropFrom(sheet,col*SPRITE_WIDTH,row*SPRITE_HEIGHT,SPRITE_WIDTH,SPRITE_HEIGHT);
            return sprite;
    }
        // Returns the item at index itemNum. itemList items must be added in order, or this function will not work.                   
        Item getItemFromNumber(int itemNum) {
            if (itemNum < 0 || itemNum >= (int)this->itemList.size()) { return Item(); }
            return itemList[itemNum];
    }
        // Within the constrcutor, all possible items must be created and added to the list
        ItemHandler() {
            sheet.load("C:/Users/Public/of_v20240930_msys2_mingw64_release/apps/myApps/minecraft/bin/data/images/sprites/sprites.png");
            itemList.push_back(Item(0   , 1, 0, getSpriteFromSheet(0,0), "air"));

            itemList.push_back(Item(1   , 64, 0, getSpriteFromSheet(1,0), "Grass"));
            itemList.push_back(Item(2   , 64, 4, getSpriteFromSheet(15,0), "Log"));
            itemList.push_back(Item(3   , 64, 1, getSpriteFromSheet(4,0), "Plank"));
            itemList.push_back(Item(4   , 64, 1, getSpriteFromSheet(8,13), "Sticks"));

            itemList.push_back(Item(5   , 1, 1, getSpriteFromSheet(5,15), "Wooden Pickaxe"));
            itemList.push_back(Item(6   , 1, 0, getSpriteFromSheet(6,15), "Stone Pickaxe"));
            itemList.push_back(Item(7   , 1, 0, getSpriteFromSheet(7,15), "Iron Pickaxe"));
            itemList.push_back(Item(8   , 1, 0, getSpriteFromSheet(8,15), "Diamond Pickaxe"));
            itemList.push_back(Item(9   , 1, 0, getSpriteFromSheet(9,15), "Gold Pickaxe"));
            itemList.push_back(Item(10  , 1, 1, getSpriteFromSheet(12,14), "Wooden Shovel"));
            itemList.push_back(Item(11  , 1, 0, getSpriteFromSheet(13,14), "Stone Shovel"));
            itemList.push_back(Item(12  , 1, 0, getSpriteFromSheet(14,14), "Iron Shovel"));
            itemList.push_back(Item(13  , 1, 0, getSpriteFromSheet(15,14), "Diamond Shovel"));
            itemList.push_back(Item(14  , 1, 0, getSpriteFromSheet(16,14), "Gold Shovel"));
            itemList.push_back(Item(15  , 1, 1, getSpriteFromSheet(19,13), "Wooden Sword"));
            itemList.push_back(Item(16  , 1, 0, getSpriteFromSheet(20,13), "Stone Sword"));
            itemList.push_back(Item(17  , 1, 0, getSpriteFromSheet(21,13), "Iron Sword"));
            itemList.push_back(Item(18  , 1, 0, getSpriteFromSheet(22,13), "Diamond Sword"));
            itemList.push_back(Item(19  , 1, 0, getSpriteFromSheet(0,14), "Gold Sword"));
            itemList.push_back(Item(20  , 1, 1, getSpriteFromSheet(21,15), "Wooden Axe"));
            itemList.push_back(Item(21  , 1, 0, getSpriteFromSheet(22,15), "Stone Axe"));
            itemList.push_back(Item(22  , 1, 0, getSpriteFromSheet(0,16), "Iron Axe"));
            itemList.push_back(Item(23  , 1, 0, getSpriteFromSheet(1,16), "Diamond Axe"));
            itemList.push_back(Item(24  , 1, 0, getSpriteFromSheet(2,16), "Gold Axe"));
            itemList.push_back(Item(25  , 1, 1, getSpriteFromSheet(14,16), "Wooden Hoe"));
            itemList.push_back(Item(26  , 1, 0, getSpriteFromSheet(15,16), "Stone Hoe"));
            itemList.push_back(Item(27  , 1, 0, getSpriteFromSheet(16,16), "Iron Hoe"));
            itemList.push_back(Item(28  , 1, 0, getSpriteFromSheet(17,16), "Diamond Hoe"));
            itemList.push_back(Item(29  , 1, 0, getSpriteFromSheet(18,16), "Gold Hoe"));

            itemList.push_back(Item(30  , 64, 0, getSpriteFromSheet(3,0), "Cobblestone"));
            itemList.push_back(Item(31  , 64, 0, getSpriteFromSheet(12,0), "Gold Ore"));
            itemList.push_back(Item(32  , 64, 0, getSpriteFromSheet(13,0), "Iron Ore"));
            itemList.push_back(Item(33  , 64, 9, getSpriteFromSheet(8,11), "Coal"));
            itemList.push_back(Item(34  , 64, 0, getSpriteFromSheet(1,12), "Iron Ingot"));
            itemList.push_back(Item(35  , 64, 0, getSpriteFromSheet(17,12), "Gold Ingot"));
            itemList.push_back(Item(36  , 64, 0, getSpriteFromSheet(10,13), "Diamond"));

        }    
};      