//
//  moving_light.h
//  opengl_redbook
//
//  Created by Josiah Ebhomenye on 29/11/2016.
//  Copyright (c) 2016 Josiah Ebhomenye. All rights reserved.
//

#ifndef opengl_redbook_moving_light_h
#define opengl_redbook_moving_light_h

#include "scene.h"

class moving_light : public scene{
public:
    using scene::scene;
    
    virtual void init() override {
        scene::init();
        glShadeModel(GL_SMOOTH);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);
    }
    
    virtual void display() override {
        GLfloat position[] = {0.0, 0.0, 1.5, 1.0};
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();{
            glTranslatef(0.0, 0.0, -5.0);
            
            glPushMatrix();{
                glRotated(spin, 1.0, 0.0, 0.0);
                glLightfv(GL_LIGHT0, GL_POSITION, position);
                
                glTranslatef(0.0, 0.0, 1.5);
                glDisable(GL_LIGHTING);
                glColor3f(0.0, 1.0, 1.0);
                glutWireCube(0.1);
                glEnable(GL_LIGHTING);
                glPopMatrix();
            }
            
            glutSolidTorus(0.275, 0.85, 8, 15);
            glPopMatrix();
        }
        glFlush();
        
    }
    
    virtual void reshape(int w, int h) override {
        glViewport (0, 0, (GLsizei) w, (GLsizei) h);
        glMatrixMode (GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
    
    virtual void onMouse(int button, int state, int x, int y) override {
        switch(button){
            case GLUT_LEFT_BUTTON:
                if(state == GLUT_DOWN){
                    spin = (spin + 30)% 360;
                    glutPostRedisplay();
                }
                break;
            default:
                break;
        }
    }
    
private:
    int spin;
};

scene* scene::instance = new moving_light("Moving light");

#endif
