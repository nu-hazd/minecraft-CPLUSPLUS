#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup() {
    this->instantiator = new ItemHandler();
    this->player = new Player();
    this->chestState = new ChestState(player);
    this->craftingState = new CraftingState(player,instantiator);
    this->furnaceState = new FurnaceState(player,instantiator);

    giveItems();
    this->currentState = chestState;
}

//--------------------------------------------------------------
void ofApp::update() {
    currentState->update();
}

//--------------------------------------------------------------
void ofApp::draw() {
    currentState->draw();
}


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
    currentState->mouseMoved(x,y);
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    currentState->mousePressed(x,y,button);
    if (button == 0) {
        for (auto stateButton : player->getStateButtons()) {
            if (stateButton.onPress(x,y)) {
                if (stateButton.getTargetState() == "chest") {
                    this->currentState = chestState;
                }
                else if (stateButton.getTargetState() == "crafting") {
                    this->currentState = craftingState;
                }
                else if (stateButton.getTargetState() == "furnace") {
                    this->currentState = furnaceState;
                }
                stateButton.playSoundEffect();
            }
        }
    }
}

void ofApp::giveItems() {
    player->addItem(instantiator->getItemFromNumber(1),64);
    player->addItem(instantiator->getItemFromNumber(13),9);
    player->addItem(instantiator->getItemFromNumber(14),9);
    player->addItem(instantiator->getItemFromNumber(15),9);
    

    chestState->addItem(instantiator->getItemFromNumber(1),1);
    chestState->addItem(instantiator->getItemFromNumber(1),1);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    currentState->keyPressed(key);
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}
//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}
//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
//--------------------------------------------------------------