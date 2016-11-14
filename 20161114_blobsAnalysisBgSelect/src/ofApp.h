#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxOpenCv.h"
#include "ofxGui.h"

//uncomment this to use a live web cam.
//otherwise, use a video file.
#define _USE_LIVE_VIDEO

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    #ifdef _USE_LIVE_VIDEO
        ofVideoGrabber videoIn;
    #else
        ofVideoPlayer videoPlayer;
    #endif
    
    ofxCvColorImage videoColorCvImage;
    
    ofxCvGrayscaleImage videoGrayscaleCvImage;
    ofxCvGrayscaleImage videoPrevFrameImage;
    
    ofxCvGrayscaleImage videoDiffImage;
    
    ofxCvContourFinder contourFinder;
    
    ofxPanel gui;
    ofParameter<float> thresholdValue;
    ofParameter<bool> bLearnBackground;
    
    int width, height;
};
