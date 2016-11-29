//
//  light_test.h
//  opengl_redbook
//
//  Created by Josiah Ebhomenye on 29/11/2016.
//  Copyright (c) 2016 Josiah Ebhomenye. All rights reserved.
//

#ifndef opengl_redbook_light_test_h
#define opengl_redbook_light_test_h

#include "scene.h"

class light_test : public scene{
public:
    using scene::scene;
    
    virtual void init() override {
        GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
        GLfloat mat_shininess[] = { 50.0 };
        
        GLfloat light_color[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
        
        
        glShadeModel(GL_SMOOTH);
        
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
        
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glLightfv(GL_LIGHT0, GL_AMBIENT_AND_DIFFUSE, light_color);
        
        // light 1
//        GLfloat light1_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
//        GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
//        GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//        GLfloat light1_position[] = { -2.0, 2.0, 1.0, 1.0 };
//        GLfloat spot_direction[] = { -1.0, -1.0, 0.0 };
        
//        glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
//        glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
//        glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
//        glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
//        glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.5);
//        glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.5);
//        glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2);
//        
//        glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
//        glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
//        glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);
        
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);
    }
    
    virtual void display() override {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glutSolidSphere(1.0, 20, 16);
        glFlush();
    }
    
    virtual void reshape(int w, int h) override {
        scene::reshape(w, h);
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        if( w <= h){
            glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
                     1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
        }else{
            glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
                     1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
        }
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
    
};

scene* scene::instance = new light_test("Light test");

#endif
