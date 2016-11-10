#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    Set camera resolution
    camWidth = 320;
    camHeight = 240;
    
//    List webcam devices & output devices' number
    vector<ofVideoDevice> devices = videoIn.listDevices();
    
    for (int i = 0; i < devices.size(); i++) {
        if (devices[i].bAvailable) {
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        } else {
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    
//    Set webcam by number, like 0, 1, 2 ect..
    videoIn.setDeviceID(0);
    
    totalPixels = camWidth * camHeight * 3;
    videoIn.initGrabber(camWidth, camHeight);
    
//    It allocates an image of width (w) and height (h). The type can be of three types: OF_IMAGE_GRAYSCALE, OF_IMAGE_COLOR, OF_IMAGE_COLOR_ALPHA. You don't need to call this before loading an image, but for when you want to allocate space ahead of when you are going to use the image.
    lastFrame.allocate(camWidth, camHeight, OF_IMAGE_COLOR);
    movement.allocate(camWidth, camHeight, OF_IMAGE_COLOR);
    
//    [warning] ofQTKitGrabber: setDesiredFrameRate(): cannot set framerate for QTKitGrabber
//    videoIn.setDesiredFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
//    Need to call update() to update the texture after updating the pixels manually.
    videoIn.update();
    
    if (videoIn.isFrameNew()) {
        
//        declares a reference to lastFrame.getPixels(), called lastFramePix.
        ofPixels & lastFramePix = lastFrame.getPixels();
//        declares a reference to movement.getPixels(), called videoPix.
        ofPixels & videoPix = videoIn.getPixels();
//        declares a reference to movement.getPixels(), called movementPix.
        ofPixels & movementPix = movement.getPixels();
        
//        abs two frames & get diff value.
        for (int i = 0; i < totalPixels; i+=3) {
            unsigned char r = abs(lastFramePix[i] - videoPix[i]);
            unsigned char g = abs(lastFramePix[i+1] - videoPix[i+1]);
            unsigned char b = abs(lastFramePix[i+2] - videoPix[i+2]);
            
            int diff = r+g+b;
//            make diff pixels to black or white
            if (diff > 40) {
                movementPix[i] = 255;
                movementPix[i+1] = 255;
                movementPix[i+2] = 255;
            } else {
                movementPix[i] = 0;
                movementPix[i+1] = 0;
                movementPix[i+2] = 0;
            }
        }
        
//        make lastFramePix is less 1 frame to others
        movement.setFromPixels(movementPix, camWidth, camHeight, OF_IMAGE_COLOR);
        lastFrame.setFromPixels(videoPix, camWidth, camHeight, OF_IMAGE_COLOR);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0xffffff);
    videoIn.draw(0, 0, 640, 480);
    movement.draw(640, 0, 640, 480);
    
    string frameRateStr = "";
    frameRateStr += "FPS: " + ofToString(ofGetFrameRate()) + '\n';
    ofDrawBitmapString(frameRateStr, 20, 20);
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
