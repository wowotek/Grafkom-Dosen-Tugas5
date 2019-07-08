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

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "scene.hh"

#define WIDTH 640
#define HEIGHT 640


std::vector<unsigned char> keyPresses;

color3f bgColor{0, 0, 1};

void
RenderDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(unpack3(bgColor), 1);
    glLineWidth(2);

    DrawShip();

    glutSwapBuffers();
}

void
ControlHandler(void)
{
    std::vector<std::string> commCalled;
    for(uint i=0; i<keyPresses.size(); i++){
        if(keyPresses.at(i) == 'r' || keyPresses.at(i) == 'R'){
            commCalled.push_back("RandBgColor");
        }
        if(keyPresses.at(i) == 'b' || keyPresses.at(i) == 'B'){
            commCalled.push_back("RandHullColor");
        }
        if(keyPresses.at(i) == 'a' || keyPresses.at(i) == 'A'){
            commCalled.push_back("KapalGerakKiri");
        }
        if(keyPresses.at(i) == 'd' || keyPresses.at(i) == 'D'){
            commCalled.push_back("KapalGerakKanan");
        }
        if(keyPresses.at(i) == 'w' || keyPresses.at(i) == 'W'){
            commCalled.push_back("ZoomIn");
        }
        if(keyPresses.at(i) == 's' || keyPresses.at(i) == 'S'){
            commCalled.push_back("ZoomOut");
        }
    }

    for(uint i=0; i<commCalled.size(); i++){
        std::cout << commCalled.at(i) << " ";
        fflush(stdout);
    }
    std::cout << "                     \r";
}

void
UpdateScreen(GLint time)
{
    ControlHandler();

    glutPostRedisplay();
    glutTimerFunc(time, UpdateScreen, time);
}

void
RandomizeBackgroundColor(void)
{
    bgColor = color3f{
        (float)((rand() % 101)/100),
        (float)((rand() % 101)/100),
        (float)((rand() % 101)/100)
    };
}

void
KeyboardDownEvent(unsigned char key, int, int)
{
    keyPresses.push_back(key);
}

void
KeyboardUpEvent(unsigned char key, int, int)
{
    for(uint i=0; i<keyPresses.size(); i++){
        if(keyPresses.at(i) == key){
            keyPresses.erase(keyPresses.begin()+i);
        }
    }
}

void
Init(void)
{
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    glutSetOption(GLUT_MULTISAMPLE, 16);

    glEnable(GL_MULTISAMPLE);
    glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);

    glutDisplayFunc(RenderDisplay);
    glutKeyboardFunc(KeyboardDownEvent);
    glutKeyboardUpFunc(KeyboardUpEvent);
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0);

    UpdateScreen(1000/120);

    glPointSize(5);
}

int 
main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(2500, 240);
    glutCreateWindow("TUGAS 4 GRAFKOM");

    Init();
    glutMainLoop();

    return 0;
}