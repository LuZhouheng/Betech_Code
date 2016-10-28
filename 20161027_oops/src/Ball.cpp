//
//  Ball.cpp
//  20161027_oops_1
//
//  Created by 卢周亨 on 10/27/16.
//
//

#include "Ball.hpp"

Ball::Ball(){
}

void Ball::setup(float _x, float _y, int _dim){
    /*
    x = ofRandom(0, ofGetWidth());      // 创建一些随机的位置
    y = ofRandom(0, ofGetHeight());
    dim = 20;
     */
    
    x = _x;
    y = _y;
    dim = _dim;
    
    speedX = ofRandom(-10, 10);           // 创建随机速度与方向
    speedY = ofRandom(-10, 10);
    

    
    //定义数字颜色的一种方法是通过以0-255的值单独寻址其3个组件（红色, 绿色, 蓝色）, 在此示例中, 我们将每个组件设置为随机值
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    
}

void Ball::update(){
    if (x < 0) {
        x = 0;
        speedX *= -1;
    } else if (x > ofGetWidth()){
        x = ofGetWidth();
        speedX *= -1;
    }
    
    if (y < 0) {
        y = 0;
        speedY *= -1;
    } else if (y > ofGetHeight()){
        y = ofGetHeight();
        speedY *= -1;
    }
    
    x += speedX;
    y += speedY;
}

void Ball::draw(){
    ofSetColor(color);
    ofDrawCircle(x, y, dim);
}