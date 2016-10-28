//
//  Ball.hpp
//  20161027_oops_1
//
//  Created by 卢周亨 on 10/27/16.
//
//

#ifndef Ball_hpp
#define Ball_hpp

#include "ofMain.h"

class Ball{
    
    public: // 在这里放置公共函数和变量声明
    
    //方法, 等同于你创建的类对象的具体函数
    void setup(float _x, float _y, int _dim);  // setup() 方法, 使用它来设置对象的初始状态
    void update(); // update() 方法, 用它来刷新你的对象属性
    void draw();   // draw() 方法, 你将在这里做对象的绘制
    
    // 变量
    float x;       // 位置
    float y;
    float speedY;  // 速度和方向
    float speedX;
    int dim;       // 大小
    ofColor color; // 使用 ofColor 类的 color
    
    Ball();        // constructor 用于初始化对象, 如果没有传递属性, 程序会将它们设置为默认值
    
    private:       // 这里放置私有函数或变量声明
};// 别忘了分号

#endif /* Ball_hpp */
