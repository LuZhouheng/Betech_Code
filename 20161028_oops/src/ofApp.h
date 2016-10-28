#pragma once

#include "ofMain.h"
#include "Ball.hpp"
#include "BallRed.hpp"
#include "BallBlue.hpp"
#include "BallGreen.hpp"

#define NBALLS 500

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
    
//        vector <Ball> myBall;
    
        BallRed redBall;
        BallGreen greenBall;
        BallBlue blueBall;
    
        /*
        Ball myBall[NBALLS];
         */
    
        /*
        Ball myBall;
        Ball myBall1;
        Ball myBall2;
        Ball myBall3;
         */
};
