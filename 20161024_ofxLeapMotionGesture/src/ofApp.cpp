#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofBackground(31);
    
    leap.open();
    
    ofEnableLighting();
    light.setPosition(200, 300, 50);
    light.enable();
    cam.setOrientation(ofPoint(-20, 0, 0));
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

}

//--------------------------------------------------------------
void ofApp::update(){
    fingersFound.clear();
    
    simpleHands = leap.getSimpleHands();
    
    if (leap.isFrameNew() && simpleHands.size()) {
        fingerPos.clear();
        
        leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
        leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        leap.setMappingZ(-150, 150, -200, 200);
        
        fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
        
        for (int i = 0; i < simpleHands.size(); i++) {
            for (int f = 0; f < 5; f++) {
                
                ofVec3f pos = simpleHands[i].fingers[ fingerTypes[f] ].pos;
                int id = simpleHands[i].fingers[ fingerTypes[f] ].id;
                ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp; // metacarpal
                ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip; // proximal
                ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip; // distal
                ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip; // fingertip

                fingersFound.push_back(id);
                fingerPos.push_back(pos);
            }
        }
    }
    
    leap.markFrameAsOld();

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    
    ofBackgroundGradient(ofColor(90, 90, 90), ofColor(30, 30, 30),  OF_GRADIENT_BAR);
    
    ofSetColor(200);
    ofDrawBitmapString("ofxLeapMotion Example App\nLeap Connected? " + ofToString(leap.isConnected()), 20, 20);
    
    cam.begin();
    
    ofPushMatrix();
    ofRotate(90, 0, 0, 1);
    ofSetColor(20);
    ofDrawGridPlane(800, 20, false);
    ofPopMatrix();
    
    
    fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
    
    for(int i = 0; i < simpleHands.size(); i++){
        bool isLeft        = simpleHands[i].isLeft;
        ofPoint handPos    = simpleHands[i].handPos;
        ofPoint handNormal = simpleHands[i].handNormal;
        
        ofSetColor(0, 0, 255);
        ofDrawSphere(handPos.x, handPos.y, handPos.z, 20);
        ofSetColor(255, 255, 0);
        ofDrawArrow(handPos, handPos + 100*handNormal);
        
        for (int f=0; f<5; f++) {
            ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp;  // metacarpal
            ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip;  // proximal
            ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip;  // distal
            ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip;  // fingertip
            
            ofSetColor(0, 255, 0);
//            ofDrawSphere(mcp.x, mcp.y, mcp.z, 12);
//            ofDrawSphere(pip.x, pip.y, pip.z, 12);
//            ofDrawSphere(dip.x, dip.y, dip.z, 12);
//            ofDrawSphere(tip.x, tip.y, tip.z, 12);
            
            ofSetColor(255, 0, 0);
            ofSetLineWidth(20);
//            ofDrawLine(mcp.x, mcp.y, mcp.z, pip.x, pip.y, pip.z);
//            ofDrawLine(pip.x, pip.y, pip.z, dip.x, dip.y, dip.z);
//            ofDrawLine(dip.x, dip.y, dip.z, tip.x, tip.y, tip.z);
            ofDrawLine(handPos.x, handPos.y, handPos.z, tip.x, tip.y, tip.z);
            
            fingerDis[i] = ofDist(handPos.x, handPos.y, handPos.z, tip.x, tip.y, tip.z);

            cout << fingerDis[i] << endl;
        }
    }

    for(int i = 0; i < fingerPos.size(); i++){
        ofBoxPrimitive box;
        box.setPosition(fingerPos[i].x, fingerPos[i].y, fingerPos[i].z);
        box.set(20);
        box.draw();
        ofDrawBitmapString("FingerNumber " + ofToString(fingerPos.size()), 20, 20);
    }
    cam.end();
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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

//--------------------------------------------------------------
void ofApp::exit(){
    leap.close();
}
