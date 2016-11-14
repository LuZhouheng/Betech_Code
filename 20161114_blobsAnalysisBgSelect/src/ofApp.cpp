#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    #ifdef _USE_LIVE_VIDEO
        ofSetVerticalSync(true);
        videoIn.setup(640, 480);
    
        width = videoIn.getWidth();
        height = videoIn.getHeight();
    #else
        videoPlayer.load("video.mov");
        videoPlayer.play();
        videoPlayer.setLoopState(OF_LOOP_NORMAL);
    
        width = videoPlayer.getWidth();
        height = videoPlayer.getHeight();
    #endif
    
    
    videoColorCvImage.allocate(width, height);
    videoGrayscaleCvImage.allocate(width, height);
    videoPrevFrameImage.allocate(width, height);
    videoDiffImage.allocate(width, height);
    
    gui.setup();
    gui.add(thresholdValue.set("Threshold Value", 10, 0, 150));
    gui.add(bLearnBackground.set("bLearnBackground", true));
}

//--------------------------------------------------------------
void ofApp::update(){
    bool bNewFrame = false;
    
    #ifdef _USE_LIVE_VIDEO
        videoIn.update();
        bNewFrame = videoIn.isFrameNew();
    #else
        videoPlayer.update();
        bNewFrame = videoPlayer.isFrameNew();
    #endif
    
    if (bNewFrame) {
        #ifdef _USE_LIVE_VIDEO
            videoColorCvImage.setFromPixels(videoIn.getPixels(), width, height);
        #else
            videoColorCvImage.setFromPixels(videoPlayer.getPixels(), width, height);
        #endif
        
        videoGrayscaleCvImage = videoColorCvImage;
        
        if (bLearnBackground == true) {
            videoPrevFrameImage = videoGrayscaleCvImage;
            bLearnBackground = false;
        }
        
        videoDiffImage.absDiff(videoGrayscaleCvImage, videoPrevFrameImage);
        videoDiffImage.threshold(thresholdValue);
        
        contourFinder.findContours(videoDiffImage, 20, (640*480)/3, 10, true);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    printf("number of white pixels = %i \n", videoDiffImage.countNonZeroInRegion(0, 0, 320, 240));
    
    ofSetColor(255);
    
    videoGrayscaleCvImage.draw(20, 40, 320, 240);
    ofDrawBitmapStringHighlight("videoIn", 20, 280);
    videoPrevFrameImage.draw(320+20, 40, 320, 240);
    ofDrawBitmapStringHighlight("selectedBgImage", 320+20, 280);
    videoDiffImage.draw(20, 300, 640, 480);
    
    for (int i = 0; i < contourFinder.nBlobs; i++) {
        contourFinder.blobs[i].draw(20, 300);
        
        ofSetColor(255);
        if (contourFinder.blobs[i].hole) {
            ofDrawBitmapStringHighlight("hole", contourFinder.blobs[i].boundingRect.getCenter().x + 20, contourFinder.blobs[i].boundingRect.getCenter().y + 300);
        }
    }
    
    string wPixelsNumStr = "";
    wPixelsNumStr += "Number of white pixels =";
    wPixelsNumStr += " " + ofToString(videoDiffImage.countNonZeroInRegion(0, 0, 320, 240));
    
    ofDrawBitmapStringHighlight(wPixelsNumStr, 30, 770);
    
    ofSetHexColor(0xffffff);
    stringstream reportStr;
    reportStr << "bg subtraction and blob detection" << endl
    << "press ' ' to capture bg" << endl
    << "threshold " << thresholdValue << " (drag GUI: Threshold Value)" << endl
    << "num blobs found " << contourFinder.nBlobs << ", fps: " << ofGetFrameRate();
    ofDrawBitmapStringHighlight(reportStr.str(), 30, 800);
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
        case ' ':
            bLearnBackground = true;
            break;
            
        default:
            break;
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
