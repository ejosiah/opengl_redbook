//
//  depth_testing.h
//  opengl_redbook
//
//  Created by Josiah Ebhomenye on 29/11/2016.
//  Copyright (c) 2016 Josiah Ebhomenye. All rights reserved.
//

#ifndef opengl_redbook_depth_testing_h
#define opengl_redbook_depth_testing_h

#include "scene.h"

class depth_testing : public scene{
public:
    using scene::scene;
    
    virtual void init() override{
        scene::init();
        glEnable(GL_DEPTH_TEST);
        glShadeModel(GL_SMOOTH);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    
    virtual void display() override{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
        
        glColor3f(1.0, 0, 0);
        glutSolidTeapot(1);
        
        glPushMatrix();
        glTranslatef(1, 0, -5);
        glColor3f(0.0, 0.0, 1.0);
        glutSolidTeapot(1);
        glPopMatrix();
        
        glFlush();
    }
};

scene* scene::instance = new depth_testing("Depth testing");

#endif
