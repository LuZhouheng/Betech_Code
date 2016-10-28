#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*
    myBall.setup();     // 调用对象的设置方法
    myBall1.setup();
    myBall2.setup();
    myBall3.setup();
     */
//----------------------------------------
    /*
    for (int i = 0; i < NBALLS; i++) {
        myBall[i].setup();
    }
     */
//----------------------------------------
    /*
    for (int i = 0 ; i < NBALLS; i++) {
        //根据它在数组中的位置定义每个球的大小
        int size = (i+1) * 0.1;
        //生成大于0且小于应用程序屏幕宽度的随机值
        int randomX = ofRandom(0, ofGetWidth());
        //生成大于0并小于我们的应用程序屏幕高度的随机值
        int randomY = ofRandom(0, ofGetHeight());
        
        myBall[i].setup(randomX, randomY, size);
    }
     */
}

//--------------------------------------------------------------
void ofApp::update(){
    /*
    myBall.update();    // 调用对象的update方法
    myBall1.update();
    myBall2.update();
    myBall3.update();
     */
//----------------------------------------
    /*
    for (int i = 0; i < NBALLS; i++) {
        myBall[i].update();
    }
     */
//----------------------------------------
    for (int i = 0; i < myBall.size(); i++) {
        myBall[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    /*
    myBall.draw();      // 调用 draw 方法来绘制对象
    myBall1.draw();
    myBall2.draw();
    myBall3.draw();
     */
//----------------------------------------
    /*
    for (int i = 0; i < NBALLS; i++) {
        myBall[i].draw();
    }
     */
//----------------------------------------
    for (int i = 0; i < myBall.size(); i++) {
        myBall[i].draw();
    }
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
    Ball tempBall;                          // 创建球对象
    tempBall.setup(x, y, ofRandom(10, 40)); // 设置初始状态
    myBall.push_back(tempBall);             // 将其添加到向量
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for (int i = 0; i < myBall.size(); i++) {
        // ofDist 方法让我们检测两个坐标之间的距离
        float distance = ofDist(x, y, myBall[i].x, myBall[i].y);
        if (distance < myBall[i].dim) {
            // 我们需要使用迭代器来引用我们需要删除的向量
            myBall.erase(myBall.begin()+i);
        }
    }
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
