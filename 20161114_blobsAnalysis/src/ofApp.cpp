#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    videoIn.setup(640, 480);
    
    width = videoIn.getWidth();
    height = videoIn.getHeight();
    
    videoColorCvImage.allocate(width, height);
    videoGrayscaleCvImage.allocate(width, height);
    videoPrevFrameImage.allocate(width, height);
    videoDiffImage.allocate(width, height);
    
    gui.setup();
    gui.add(thresholdValue.set("Threshold Value", 10, 0, 150));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    videoIn.update();
    
    if (videoIn.isFrameNew()) {
        
        videoColorCvImage.setFromPixels(videoIn.getPixels(), width, height);
        
        videoGrayscaleCvImage = videoColorCvImage;
        
        videoDiffImage.absDiff(videoGrayscaleCvImage, videoPrevFrameImage);
        videoDiffImage.threshold(thresholdValue);
        
        videoPrevFrameImage = videoGrayscaleCvImage;
        
        contourFinder.findContours(videoDiffImage, 20, (640*480)/3, 10, true);
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    printf("number of white pixels = %i \n", videoDiffImage.countNonZeroInRegion(0, 0, 320, 240));
    
    ofSetColor(255);
    
    videoGrayscaleCvImage.draw(20, 40, 320, 240);
    videoPrevFrameImage.draw(320+20, 40, 320, 240);
    videoDiffImage.draw(20, 240+40, 640, 480);
    
    for (int i = 0; i < contourFinder.nBlobs; i++) {
        contourFinder.blobs[i].draw(20, 280);
        
        ofSetColor(255);
        if (contourFinder.blobs[i].hole) {
            ofDrawBitmapStringHighlight("hole", contourFinder.blobs[i].boundingRect.getCenter().x + 20, contourFinder.blobs[i].boundingRect.getCenter().y + 280);
        }
    }
    
    string wPixelsNumStr = "";
    wPixelsNumStr += "Number of white pixels =";
    wPixelsNumStr += " " + ofToString(videoDiffImage.countNonZeroInRegion(0, 0, 320, 240));
    
    ofDrawBitmapStringHighlight(wPixelsNumStr, 30, 770);
    
    gui.draw();
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
