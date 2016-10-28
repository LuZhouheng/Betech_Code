//
//  BallRed.cpp
//  20161028_oops
//
//  Created by 卢周亨 on 10/28/16.
//
//

#include "BallRed.hpp"

void BallRed::draw(){
    ofSetColor(ofColor::red);
    ofDrawCircle(x, y, dim);
}
