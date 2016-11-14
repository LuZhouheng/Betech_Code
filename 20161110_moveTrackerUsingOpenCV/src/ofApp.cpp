#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    videoIn.setup(320, 240);
    
    gui.setup();
    gui.add(resetBackground.set("Reset Background, false"));
    gui.add(learningTime.set("Learning Time", 1.2, 0, 30));
    gui.add(thresholdValue.set("Threshold Value", 50, 0, 255));
    
    // imitate() will set up previous and diff
    // so they have the same size and type as videoIn
    imitate(previous, videoIn);
    imitate(diff, videoIn);
}

//--------------------------------------------------------------
void ofApp::update(){
    videoIn.update();
    
    if (resetBackground) {
        background.reset();
        resetBackground = false;
    }
    
    if (videoIn.isFrameNew()) {
        background.setLearningTime(learningTime);
        background.setThresholdValue(thresholdValue);
        background.update(videoIn, thresholded);
        thresholded.update();
        
        // take the sbsolute difference of prev and cam and save it inside diff
        absdiff(videoIn, previous, diff);
        diff.update();
        
        // like ofSetPixels, but more concise and cross-toolkit
        copy(videoIn, previous);
        
        // this is the key line: get the average of each column
        columnMean = meanCols(diff);
        
        // mean() returns a Scalar. it's a cv:: function so we have to apss a Mat
        diffMean = mean(toCv(diff));
        
        // youcan only do math between Scalars,
        // but is's easy to make a Scalar from an int (shown here)
        diffMean *= Scalar(50);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    videoIn.draw(0, 0, 640, 480);
    gui.draw();
    
    videoIn.draw(0, 480, 640, 480);

    if (thresholded.isAllocated()) {
        thresholded.draw(640, 0, 640, 480);
    }
    
    diff.draw(640, 480, 640, 480);
    
    // use the [] operator to get elements from a Scalar
    float diffRed = diffMean[0];
    float diffGreen = diffMean[1];
    float diffBlue = diffMean[2];
    
    ofSetColor(255, 0, 0);
    ofDrawRectangle(0, 480, diffRed, 10);
    ofSetColor(0, 255, 0);
    ofDrawRectangle(0, 480+15, diffGreen, 10);
    ofSetColor(0, 0, 255);
    ofDrawRectangle(0, 480+30, diffBlue, 10);
    
    int nWhitePixels = countNonZero(thresholded);
    cout << ofToString(nWhitePixels) << endl;
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
