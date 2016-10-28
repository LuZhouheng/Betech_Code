//
//  BallGreen.cpp
//  20161028_oops
//
//  Created by 卢周亨 on 10/28/16.
//
//

#include "BallGreen.hpp"



void BallGreen::draw(){
    ofSetColor(ofColor::green);
    ofDrawCircle(x, y, dim);
}