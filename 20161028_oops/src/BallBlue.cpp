//
//  BallBlue.cpp
//  20161028_oops
//
//  Created by 卢周亨 on 10/28/16.
//
//

#include "BallBlue.hpp"

void BallBlue::draw(){
    ofSetColor(ofColor::blue);      // 这是设置蓝色的快捷方式
    ofDrawCircle(x, y, dim);
}