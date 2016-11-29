//
//  color_mat.h
//  opengl_redbook
//
//  Created by Josiah Ebhomenye on 29/11/2016.
//  Copyright (c) 2016 Josiah Ebhomenye. All rights reserved.
//

#ifndef opengl_redbook_color_mat_h
#define opengl_redbook_color_mat_h

#include "scene.h"

static GLfloat diffuseMaterial[4] = {0.5, 0.5, 0.5, 1.0};

class color_mat : public scene{
public:
    using scene::scene;
    
    virtual void init() override {
        GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0 };
        GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
        
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glShadeModel(GL_SMOOTH);
        glEnable(GL_DEPTH_TEST);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialf(GL_FRONT, GL_SHININESS, 25.0);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        
        glColorMaterial(GL_FRONT, GL_DIFFUSE);
        glEnable(GL_COLOR_MATERIAL);
    }
    
    virtual void display(){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glutSolidSphere(1.0, 20, 16);
        glFlush();
    }
    
    virtual void reshape(int w, int h) override {
        glViewport (0, 0, (GLsizei) w, (GLsizei) h);
        glMatrixMode (GL_PROJECTION);
        glLoadIdentity();
        if (w <= h){
            glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
                     1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
        }else{
                glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
                         1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
            }
    }
    
    virtual void onMouse(int button, int state, int x, int y) override {
        switch (button) {
            case GLUT_LEFT_BUTTON:
                if (state == GLUT_DOWN) {       /*  change red  */
                    diffuseMaterial[0] += 0.1;
                    if (diffuseMaterial[0] > 1.0)
                        diffuseMaterial[0] = 0.0;
                    glColor4fv(diffuseMaterial);
                    glutPostRedisplay();
                }
                break;
            case GLUT_MIDDLE_BUTTON:
                if (state == GLUT_DOWN) {       /*  change green  */
                    diffuseMaterial[1] += 0.1;
                    if (diffuseMaterial[1] > 1.0)
                        diffuseMaterial[1] = 0.0;
                    glColor4fv(diffuseMaterial);
                    glutPostRedisplay();
                }
                break;
            case GLUT_RIGHT_BUTTON:
                if (state == GLUT_DOWN) {      /*  change blue  */
                    diffuseMaterial[2] += 0.1;
                    if (diffuseMaterial[2] > 1.0)
                        diffuseMaterial[2] = 0.0;
                    glColor4fv(diffuseMaterial);
                    glutPostRedisplay();
                }
                break;
            default:
                break;
        }
    }
    
};

scene* scene::instance = new color_mat("Color material test");

#endif
