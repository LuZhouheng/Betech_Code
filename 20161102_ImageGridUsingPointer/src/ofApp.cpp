#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    bikers.load("images/bikers.jpg");
    int i = 5;
    int j = 5;
    gridWidth.push_back(i);
    gridHeight.push_back(j);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::draw(){
    //use for loop to draw grids
    for (int i = 0; i < gridWidth.size(); i++) {
        for (int j = 0; j < gridHeight.size(); j++) {
            int imgGridWidth = ofGetWidth()/gridWidth.size();
            int imgGridHeight = ofGetHeight()/gridHeight.size();
            bikers.draw(i*imgGridWidth, j*imgGridHeight, ofGetWidth()/gridHeight.size(), ofGetHeight()/gridHeight.size());
        }
    }
    
    string debugStr = "";
    debugStr += "FPS: " + ofToString(ofGetFrameRate()) + '\n';
    debugStr += "Press 1 to add grids.";
    debugStr += '\n';
    debugStr += "or press 2 to decrease grids.";
    ofDrawBitmapStringHighlight(debugStr, 20, 20);
    
    cout << ofToString(gridWidth) << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') {
        int i = i + 1;
        gridWidth.push_back(i);
        int j = j + 1;
        gridHeight.push_back(j);
    }
    
    if (key == '2') {
        gridWidth.pop_back();
        gridHeight.pop_back();
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
