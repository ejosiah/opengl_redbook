//
//  main.cpp
//  opengl_redbook
//
//  Created by Josiah Ebhomenye on 29/11/2016.
//  Copyright (c) 2016 Josiah Ebhomenye. All rights reserved.
//

#include <iostream>
#include "color_mat.h"

scene& app = *scene::instance;

void init(){
    app.init();
}

void display(){
    app.display();
}

void reshape(int w, int h){
    app.reshape(w, h);
}

void onMouse(int button, int state, int x, int y){
    app.onMouse(button, state, x, y);
}

void onKeyPress(unsigned char key, int x, int y){
    app.onKeyPress(key, x, y);
}

void onSpecialKey(int key, int x, int y){
    app.specialKeyPress(key, x, y);
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
  
    glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
    
    glutInitWindowSize(app.getWidth(), app.getHeight());
    glutInitWindowPosition(100, 100);
    glutCreateWindow(app.getTitle());
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(onMouse);
    glutKeyboardFunc(onKeyPress);
    glutSpecialFunc(onSpecialKey);
    
    app.init();
    
    glutMainLoop();
    
    delete scene::instance;
    return 0;

}
