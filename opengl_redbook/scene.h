//
//  scene.h
//  opengl_redbook
//
//  Created by Josiah Ebhomenye on 29/11/2016.
//  Copyright (c) 2016 Josiah Ebhomenye. All rights reserved.
//
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <iostream>

#ifndef opengl_redbook_scene_h
#define opengl_redbook_scene_h

class scene{
public:
    scene(const char* t, const int w = DEFAULT_WIDTH, const int h = DEFAULT_HEIGHT):
    title(t), width(w), height(h){}
    
    ~scene(){}
    
    int getWidth() const{ return width; }
    int getHeight() const{ return height; }
    const char* getTitle() const{ return title; }
    
    virtual void init(){
        glClearColor(0.0, 0.0, 0.0, 0.0);
    }
    
    virtual void display() = 0;
    
    virtual void reshape(int w, int h){
        width = w;
        height = h;
        glViewport(0, 0, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(50, (double)w/h, 1, 200);
        glMatrixMode(GL_MODELVIEW);
    }
    
    virtual void onMouse(int button, int state, int x, int y){}
    
    virtual void onKeyPress(unsigned char key, int x, int y){
        switch (key) {
            case 'q':
                exit(0);
                break;
            default:
                break;
        }
    }
    
    virtual void specialKeyPress(int key, int x, int y){}
    
    static scene* instance;
 
private:
    const char* title;
    int width;
    int height;
    
    static const int DEFAULT_WIDTH = 500;
    static const int DEFAULT_HEIGHT = 500;    
};

#endif
