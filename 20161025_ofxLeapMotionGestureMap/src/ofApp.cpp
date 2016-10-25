#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofBackground(90);
    
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
    
    
    ofBackgroundGradient(ofColor(90, 90, 90), ofColor(30, 30, 30),  OF_GRADIENT_BAR);
    
    ofSetColor(200);
    ofDrawBitmapString("ofxLeapMotionGestureMap App\nLeap Connected? " + ofToString(leap.isConnected()), 20, 20);
    
    cam.begin();
    
    ofPushMatrix();
    ofRotate(90, 0, 0, 1);
    ofSetColor(20);
    ofDrawGridPlane(800, 20, false);
    ofPopMatrix();
    
    
    fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
    
    handDist.clear();
    fingerNumber.clear();
    
    for(int i = 0; i < simpleHands.size(); i++){
        bool isLeft        = simpleHands[i].isLeft;
        ofPoint handPos    = simpleHands[i].handPos;
        ofPoint handNormal = simpleHands[i].handNormal;
        
        ofSetColor(0, 0, 255);
        ofDrawSphere(handPos.x, handPos.y, handPos.z, 20);
        ofSetColor(255, 255, 0);
        ofDrawArrow(handPos, handPos + 100*handNormal);
        
//        ofBoxPrimitive box;
//        box.setPosition(fingerPos[i].x, fingerPos[i].y, fingerPos[i].z);
//        box.set(20);
//        box.draw();
        ofDrawBitmapString("FingerNumber " + ofToString(fingerPos.size()), -400, 300);
        
        for (int f=0; f<5; f++) {
            ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp;  // metacarpal
            ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip;  // proximal
            ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip;  // distal
            ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip;  // fingertip
            
            float myDist = tip.distance(handPos);
            handDist.push_back(myDist);
            
            ofSetColor(0, 255, 0);
            ofDrawSphere(mcp.x, mcp.y, mcp.z, 8);
            ofDrawSphere(pip.x, pip.y, pip.z, 8);
            ofDrawSphere(dip.x, dip.y, dip.z, 8);
            ofDrawSphere(tip.x, tip.y, tip.z, 8);
            
            ofSetColor(255, 0, 0);
            ofSetLineWidth(20);
            ofDrawLine(mcp.x, mcp.y, mcp.z, pip.x, pip.y, pip.z);
            ofDrawLine(pip.x, pip.y, pip.z, dip.x, dip.y, dip.z);
            ofDrawLine(dip.x, dip.y, dip.z, tip.x, tip.y, tip.z);
            //            ofDrawLine(handPos.x, handPos.y, handPos.z, tip.x, tip.y, tip.z);
            
            ofSetColor(255, 255, 0);
            ofDrawRectangle(-200, 10, -100, 80, ofMap(handDist[0], 80, 200, 0, 200));
            ofDrawRectangle(-100, 10, -100, 80, ofMap(handDist[1], 80, 200, 0, 200));
            ofDrawRectangle(0, 10, -100, 80, ofMap(handDist[2], 80, 200, 0, 200));
            ofDrawRectangle(100, 10, -100, 80, ofMap(handDist[3], 80, 200, 0, 200));
            ofDrawRectangle(200, 10, -100, 80, ofMap(handDist[4], 80, 200, 0, 200));
            
            //            fingerDis[i] = ofDist(handPos.x, handPos.y, handPos.z, tip.x, tip.y, tip.z);
            
            //            cout << fingerDis[i] << endl;
        }
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
