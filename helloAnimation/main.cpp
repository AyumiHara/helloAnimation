//
//  main.cpp
//  helloAnimation
//
//  Created by 原 あゆみ on 2018/04/24.
//  Copyright © 2018年 原あゆみ. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <math.h>

float r = 0.7; //半径
GLenum mode = GL_LINES; //描画のモード
float red = 0.0;
float divNum = 100;

//float t = 0.0; //theta


void display(){
    
    
    glClear(GL_COLOR_BUFFER_BIT); //draw background
    
    //draw rectangle
    glColor3f(red, 0.0, 1.0); //(red0.0~1.0, green0.0~1.0, blue0.0~1.0) 図形の色
    glLineWidth(8.0); //線の太さ
    // glBegin(GL_LINES); //線を描く
    //glBegin(GL_POLYGON); 塗り潰す
    //glBegin(GL_POINT);   点線になる
    glBegin(mode);
    float prev_x = 0.0;
    float prev_y = 0.0;
    
    
    //for(float t = 0.0; t<2*M_PI+0.05; t+=0.05){
    for (float f = 0.0; f < divNum+1.0; f+=1.0){
        
       // float x = r * cos(t);
       // float y = r * sin(t);
        
        float x = r * cos(2*M_PI*(f/divNum));
        float y = r * sin(2*M_PI*(f/divNum));
        
        
        //if(t != 0.0){   //!=0の意味：０でなければ
        if(f !=0.0){
            glVertex3f(prev_x, prev_y, 0.0);
            glVertex3f(x, y, 0.0);
        }
        prev_x = x;
        prev_y = y;
    }
    
    //glVertex3f(0.15, 0.15, 0.0); //頂点の座標
    //glVertex3f(0.85, 0.15, 0.0); //頂点の座標
    
    glEnd();
    glFlush();
}

void mouse(int x, int y){
    red = (float)x / 500.0;
    //↑のイコールは右を左に’代入’の意味
    glutPostRedisplay();
    std::cout << red << " \n";
    //バックスラッシュはoptionと¥を同時におす
    divNum = (float)y+ 1.0;
    
}

void keyboard(unsigned char key, int x, int y){
   //keyboardは必ず三つの変数をもつ　keyは現在押されたキーボードを、xはマウスのx座標を、yはy座標を表す
    if(key == 'q') {
        exit(0); //プログラムの終了
    } else if(key == '1') {
        mode = GL_POINTS;
        glutPostRedisplay();
    } else if(key == '2') {
        mode = GL_LINES;
        glutPostRedisplay();
    }else if (key == '3') {
        mode = GL_POLYGON;
        glutPostRedisplay();
    }
}




int main(int argc, char * argv[]) {
    glutInit(&argc, argv); //諸々を初期化する
    glutInitDisplayMode(GLUT_RGB); //フルカラーで描画
    glutInitWindowSize(500, 500); //表示するウィンドウサイズ
    // 0~500が入る　色は0~1 だからredに入る数値は500でわる
    glutCreateWindow("hello graphics");
    glutDisplayFunc(display);
    
    glutKeyboardFunc(keyboard);
    glutMotionFunc(mouse);
    
    glClearColor(1.0, 1.0, 1.0, 1.0); // 背景の色を設定
    glutMainLoop();
    
    // main = メイン関数　命令の塊
    return 0;
}
