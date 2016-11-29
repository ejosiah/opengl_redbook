//
//  smooth.h
//  opengl_redbook
//
//  Created by Josiah Ebhomenye on 29/11/2016.
//  Copyright (c) 2016 Josiah Ebhomenye. All rights reserved.
//

#ifndef opengl_redbook_smooth_h
#define opengl_redbook_smooth_h

#include "scene.h"

class smooth: public scene{
public:
    using scene::scene;
    virtual void init() override{
        scene::init();
        glShadeModel(GL_SMOOTH);
    }
    
    virtual void display() override {
        glClear (GL_COLOR_BUFFER_BIT);
        triangle ();
        glFlush ();
    }
    
    virtual void reshape(int w, int h) override {
        scene::reshape(w, h);
        glMatrixMode (GL_PROJECTION);
        glLoadIdentity ();
        if (w <= h){
            gluOrtho2D (0.0, 30.0, 0.0, 30.0*(GLfloat) h/(GLfloat) w);
        }
        else{
            gluOrtho2D (0.0, 30.0*(GLfloat) w/(GLfloat) h, 0.0, 30.0);
            glMatrixMode(GL_MODELVIEW);
        }
    }
    
protected:
    void triangle(){
        glBegin (GL_TRIANGLES);
        glColor3f (1.0, 0.0, 0.0);
        glVertex2f (5.0, 5.0);
        glColor3f (0.0, 1.0, 0.0);
        glVertex2f (25.0, 5.0);
        glColor3f (0.0, 0.0, 1.0);
        glVertex2f (5.0, 25.0);
        glEnd();
    }
};

scene* scene::instance = new smooth("smooth shading");

#endif
