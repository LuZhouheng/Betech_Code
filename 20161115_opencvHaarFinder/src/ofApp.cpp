#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    videoIn.setup(320, 240);
    
    width = videoIn.getWidth();
    height = videoIn.getHeight();
    
    cvHaarFinder.setup("haarcascade_frontalface_default.xml");
    
    videoColorCvImage.allocate(width, height, OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){
    videoIn.update();
    
    if (videoIn.isFrameNew()) {
        ofPixels & colorImg = videoIn.getPixels();
        videoColorCvImage.setFromPixels(colorImg);
        
        cvHaarFinder.findHaarObjects(videoColorCvImage);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    videoColorCvImage.draw(0, 0);
    ofNoFill();
    for (unsigned int i = 0; i < cvHaarFinder.blobs.size(); i++) {
        ofRectangle cur = cvHaarFinder.blobs[i].boundingRect;
        ofDrawRectangle(cur.x, cur.y, cur.width, cur.height);
    }
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
