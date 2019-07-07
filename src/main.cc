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
UpdateScreen(GLint time)
{
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
MouseEvent(int button, int state, int posx, int posy)
{
}

void
KeyboardEvent(unsigned char key, int, int)
{
    if(key == )
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
    glutMouseFunc(MouseEvent);
    glutKeyboardFunc(KeyboardEvent);
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