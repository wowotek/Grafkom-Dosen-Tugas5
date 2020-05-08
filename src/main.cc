/*
 * main program
 * Copyright (C) 2018  Erlangga Ibrahim
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <iostream>

#include "common.hh"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "scene.hh"

#define WIDTH 640
#define HEIGHT 640

std::vector<unsigned char> keyPresses;

color3f bgColor{0, 0, 1};
double translationTracker = 0;
double scale = 1;

void
RenderDisplay(void)
{
    glMatrixMode(GL_PROJECTION);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(unpack3(bgColor), 1);
    glLineWidth(2);

    DrawShip();

    glFlush();
}

void
ControlHandler(void)
{
    glMatrixMode(GL_PROJECTION);
    for(unsigned int i=0; i<keyPresses.size(); i++){
        if(keyPresses.at(i) == 'a' || keyPresses.at(i) == 'A'){
            glTranslatef(-0.01, 0, 0);
            translationTracker -= 0.01;
        }
        if(keyPresses.at(i) == 'd' || keyPresses.at(i) == 'D'){
            glTranslatef(0.01, 0, 0);
            translationTracker += 0.01;
        }
        if(keyPresses.at(i) == 'w' || keyPresses.at(i) == 'W'){
            glScalef(1.01, 1.01, 0);
            scale += 0.01;
        }
        if(keyPresses.at(i) == 's' || keyPresses.at(i) == 'S'){
            glScalef(0.99, 0.99, 0);
            scale -= 0.01;
        }
    }
}

void
UpdateScreen(GLint time)
{
    ControlHandler();

    glutPostRedisplay();
    glutTimerFunc(time, UpdateScreen, time);

    // rumus :
    // y = x - 2.45
    // dimana :
    //      x = scale
    //      y = left_bound
    //     -y = right_bound    

    if(translationTracker < (scale - 2.45)){
        glMatrixMode(GL_PROJECTION);
        glTranslatef(-((scale - 2.45) * 2), 0, 0);
        translationTracker -= (scale - 2.45) * 2;
    } else if (translationTracker > -(scale - 2.45)) {
        glMatrixMode(GL_PROJECTION);
        glTranslatef(((scale - 2.45) * 2), 0, 0);
        translationTracker += (scale - 2.45) * 2;
    }

    // std::cout << "s: " << scale  << " | "
        //   << "l: " << translationTracker << std::endl;
    fflush(stdout);
}

void
RandomizeBackgroundColor(void)
{
    bgColor = color3f{
        (float)(rand() % 101) / 100,
        (float)(rand() % 101) / 100,
        (float)(rand() % 101) / 100
    };
}

void
KeyboardDownEvent(unsigned char key, int, int)
{
    if(key == 'r' || key == 'R'){
        RandomizeBackgroundColor();
    } else if(key == 'b' || key == 'B'){
        RandomizeShipHullColor();
    } else {
        for(unsigned int i=0; i<keyPresses.size(); i++){
            if(keyPresses.at(i) == key){
                return;
            }
        }

        keyPresses.push_back(key);
    }
}

void
KeyboardUpEvent(unsigned char key, int, int)
{
    for(unsigned int i=0; i<keyPresses.size(); i++){
	    std::cout << keyPresses.at(i) << " " << keyPresses.size();
        if(keyPresses.at(i) == key){
            keyPresses.erase(keyPresses.begin()+i);
        }
    }
    std::cout << std::endl;
}

void
Init(void)
{
    glutDisplayFunc(RenderDisplay);
    glutKeyboardFunc(KeyboardDownEvent);
    glutKeyboardUpFunc(KeyboardUpEvent);
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0);

    UpdateScreen(1000/60);

    glPointSize(5);
}

int 
main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_MULTISAMPLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("UJIAN ASDOS");

    Init();
    glutMainLoop();

    return 0;
}
