#pragma once
#include "Item.h"
#include <map>
using namespace std;

class ItemHandler {
    private:
        ofImage sheet;
        const int SPRITE_WIDTH = 64;
        const int SPRITE_HEIGHT = 64;
        vector<Item> itemList;
    public:
        ofImage getSpriteFromSheet(int col, int row) {
            ofImage sprite;
            sprite.cropFrom(sheet,col*SPRITE_WIDTH,row*SPRITE_HEIGHT,SPRITE_WIDTH,SPRITE_HEIGHT);
            return sprite;
    }
        Item getItemFromNumber(int itemNum) {
            if (itemNum < 0 || itemNum >= (int)this->itemList.size()) { return Item(); }
            return itemList[itemNum];
    }
        ItemHandler() {
            sheet.load("C:/Users/Public/of_v20240930_msys2_mingw64_release/apps/myApps/minecraft/bin/data/images/sprites/sprites.png");
            /* 
                The handler (a.k.a instantiator) will store all the possible items.
            */
            //Item(#, maxStack, fuelLevel, getSpriteFromSheet(col,row), name)
            itemList.push_back(Item(0, 1, 0, getSpriteFromSheet(0,0), "Air"));
        }
        
};      