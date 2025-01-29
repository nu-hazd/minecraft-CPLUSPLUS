#include "ItemContainer.h"
// Inventory, chest and crafting table containers use this constructor

ItemContainer::ItemContainer(Item item, int pX, int pY, bool eO, bool fO) {
    this->currentItem = item;
    this->currentItemCount = 1;
    this->extractOnly = eO;
    this->fuelOnly = fO;
    this->mouseHovering = false;

    this->hoverHighlighter.load("images/sprites/containerHover.png");;
    this->collider.setX(pX);
    this->collider.setY(pY);
    // Each container is 64x64 pixels
    this->collider.height = 64;
    this->collider.width = 64;
    this->mouseHovering = false;
    
} 
ItemContainer::ItemContainer(int pX, int pY) {
    this->currentItem = Item();
    this->currentItemCount = 0;
    this->extractOnly = false;
    this->fuelOnly = false;
    this->mouseHovering = false;
    
    this->hoverHighlighter.load("images/sprites/containerHover.png");
    this->collider.setX(pX);
    this->collider.setY(pY);
    // Each container is 64x64 pixels
    this->collider.height = 64;
    this->collider.width = 64;
}

void ItemContainer::mouseEntered(int x, int y) {
    if(this->collider.inside(x,y)) {this->mouseHovering = true; } else {this->mouseHovering = false; }

}
void ItemContainer::leftMousePressed(int x, int y, ItemContainer& playerCursor) {
    if (isMouseHovering()) { leftWasPressed(playerCursor);}
};
void ItemContainer::rightMousePressed(int x, int y, ItemContainer& playerCursor) {
    if (isMouseHovering()) { rightWasPressed(playerCursor);}
};
void ItemContainer::leftWasPressed(ItemContainer& playerCursor) {
    //  The two interacting containers are empty. Do nothing.
    if (this->isEmpty() && playerCursor.isEmpty()) {
        return;
    }
    //  The items are the same, add them.
    if ((this->getCurrentItem() == playerCursor.getCurrentItem())) {
            // One of the containers is maxed. Swap the counts.
            if (this->getCurrentItem().getMaxStack() == this->getItemCount() || playerCursor.getCurrentItem().getMaxStack() == playerCursor.getItemCount()) {
                int refCount = this->getItemCount();
                this->setItemCount(playerCursor.getItemCount());
                playerCursor.setItemCount(refCount);
            }else {
                int newItemCount = playerCursor.getItemCount() + this->getItemCount();
                if (newItemCount > this->getCurrentItem().getMaxStack()) {
                    int residue = newItemCount - this->getCurrentItem().getMaxStack();
                    newItemCount = this->getCurrentItem().getMaxStack();
                    this->setItemCount(newItemCount);
                    playerCursor.setItemCount(residue);
                }else {
                    this->setItemCount(newItemCount);
                    playerCursor.empty();
                }
            }
    }
    // The items are different, swap the contents of the containers.
    else {
        Item itmRef = this->getCurrentItem();
        int countRef = this->getItemCount();
        this->setCurrentItem(playerCursor.getCurrentItem());
        this->setItemCount(playerCursor.getItemCount());
        playerCursor.setCurrentItem(itmRef);
        playerCursor.setItemCount(countRef);
    }
    
    };


void ItemContainer::rightWasPressed(ItemContainer& playerCursor) {
    // Player container is empty
    if (playerCursor.isEmpty()) {
        if (this->isEmpty()) {
            return;
        }
        // If it's only one, simply pick it up
        if (this->getItemCount() == 1) {
            leftWasPressed(playerCursor);
        }
        // If its more than one, pick up half of the items
        else {
            int half = this->getItemCount()/2;
            this->setItemCount(this->getItemCount()-half);
            playerCursor.setItemCount(half);
            playerCursor.setCurrentItem(this->getCurrentItem());
        }
    // The player container is not empty
    }else {
        // If the target container is empty, place one item
        if (this->isEmpty()) {
            this->setItemCount(1);
            this->setCurrentItem(playerCursor.getCurrentItem());
            // Deduct one from the player container. Check if it has no more items.
            playerCursor.setItemCount(playerCursor.getItemCount()-1);
            if (playerCursor.getItemCount()==0) {
                playerCursor.empty();
            }
        }
        // If the target container has the same item as the player container, add one to it.
        else if (this->getCurrentItem() == playerCursor.getCurrentItem()) {
            // Check if adding one exceeds the items max stack size.
            if (this->getItemCount() + 1 <= this->getCurrentItem().getMaxStack()) {
                this->setItemCount(this->getItemCount() + 1);
            }else { return; }
            // Deduct one from the player container. Check if it has no more items.
            playerCursor.setItemCount(playerCursor.getItemCount()-1);
            if (playerCursor.getItemCount()==0) {
                playerCursor.empty();
            }
        }
    }
}

void ItemContainer::empty() {
    this->currentItem.setToAir();
    this->currentItemCount = 0;
}
void ItemContainer::draw() {
    if (isMouseHovering()) { 
        this->hoverHighlighter.draw(this->collider.getMinX(),this->collider.getMinY());
        if (this->getCurrentItem().getItemNumber() != 0) { ofDrawBitmapStringHighlight(this->currentItem.getName(), this->collider.getMinX(), this->collider.getMinY()-10,ofColor::darkBlue);}
    }
    this->currentItem.getSprite().draw(this->collider.getMinX(),this->collider.getMinY(),1);
    if (this->currentItemCount >= 10) { ofDrawBitmapString(this->currentItemCount,(this->collider.getMinX())+48,(this->collider.getMinY()+62));}
    else if (this->currentItemCount > 1) { ofDrawBitmapString(this->currentItemCount,(this->collider.getMinX())+56,(this->collider.getMinY()+62));}
}