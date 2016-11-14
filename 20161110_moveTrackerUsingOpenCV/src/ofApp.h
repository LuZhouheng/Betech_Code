#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"

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
    
        ofVideoGrabber videoIn;
        ofPixels previous;
        ofImage diff;
        ofImage thresholded;
    
        // a scalar is like an ofVec4f but normallly used for storing color information
        cv::Scalar diffMean;
        cv::Mat columnMean;
        ofxCv::RunningBackground background;
    
        ofxPanel gui;
        ofParameter<bool> resetBackground;
        ofParameter<float> learningTime, thresholdValue;
    
    int TotalNumberofPixels;
    int ZeroPixels;
};
