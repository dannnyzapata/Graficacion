//Proyecto 1: Graficación de Función con OpenGL
//Por: Daniel Alberto Zapata Jimenez
//Matricula: 299474
//Clase: Graficación del logo de Batman eb yb semi 3D
//Bibliotecas usadas en este trabajo
#define GL_GLEXT_PROTOTYPES
/*#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include "D:\GLUT\GLUT.h"
#endif  */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>

#include<unistd.h>


float j=0;
int flag=0;
//Creación del frame para almacenar y girar el logo
void init()
{
    glClearColor(1,1,1,0.0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glShadeModel(GL_SMOOTH);

    float lightpos[]={0,0,30,0};
    glLightfv(GL_LIGHT0,GL_POSITION,lightpos);


    glMatrixMode(GL_PROJECTION|GL_MODELVIEW);
    glLoadIdentity();

    gluPerspective(100,640/480,1,30);
    gluLookAt(0,1,9,0.0,0.0,0.0,0.0,1.0,0.0);
    glPointSize(5);
}
//Movimientos tridimensionales
void drawrefx(double x, double y, double z){
    glVertex3d(-x,y,z);
}



void display()
{
    //Esta parte prepara los movimientos rotatorios  el lugar en el espacio de la figura
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(0,0,0);

    glRotatef(0.4,0,1,0);

    glTranslatef(0,.4,0);
    glutWireCube(5); glTranslatef(0,-.4,0);

    glBegin(GL_POLYGON);
        glVertex3d(0,1.4,0);
        glVertex3d(.1,1.37,0);
        glVertex3d(.2,1.35,0);
        glVertex3d(.2,0,0);
        glVertex3d(0,0,0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3d(.2,1.35,0);
        glVertex3d(.4,2,0);
        glVertex3d(.5,1,0);
        glVertex3d(.5,-1,0);
        glVertex3d(.2,0,0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3d(0,0,0);
        glVertex3d(.6,0,0);
        glVertex3d(.5,-1,0);
        glVertex3d(0,-2,0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3d(0.3,0.9,0);
        glVertex3d(0.8,0.9,0);
        glVertex3d(1.1,-0.6,0);
        glVertex3d(0.5,-1,0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3d(0,0,0);
        glVertex3d(0.85,-.75,0);
        glVertex3d(0.4,-1.15,0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3d(0.8,0.9,0);
        glVertex3d(1.2,1,0);
        glVertex3d(2.35,-0.1,0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3d(0.8,0.9,0);
        glVertex3d(1.1,-0.6,0);
        glVertex3d(2.35,-0.1,0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3d(1.2,1,0);
        glVertex3d(1.4,1.1,0);
        glVertex3d(3.9,0,0);
        glVertex3d(2.35,-0.1,0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3d(1.4,1.1,0);
        glVertex3d(1.6,1.3,0);
        glVertex3d(4.15,0.5,0);
        glVertex3d(3.9,0,0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3d(1.6,1.3,0);
        glVertex3d(1.75,1.6,0);
        glVertex3d(4.4,0.85,0);
        glVertex3d(4.15,0.5,0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3d(1.75,1.6,0);
        glVertex3d(1.85,1.9,0);
        glVertex3d(5,1.3,0);
            glVertex3d(4.4,0.85,0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3d(1.85,1.9,0);
        glVertex3d(1.9,2.2,0);
        glVertex3d(7,2.2,0);
        glVertex3d(5,1.3,0);
    glEnd();

//Esta parte se encarga de crear la parte izquierda de las alas del murcielago para despues hacer una versión espejo y crear el logo de Batman completo
    glBegin(GL_POLYGON);
        drawrefx(0,1.4,0);
        drawrefx(.1,1.37,0);
        drawrefx(.2,1.35,0);
        drawrefx(.2,0,0);
        drawrefx(0,0,0);
    glEnd();
    glBegin(GL_POLYGON);
        drawrefx(.2,1.35,0);
        drawrefx(.4,2,0);
        drawrefx(.5,1,0);
        drawrefx(.5,-1,0);
        drawrefx(.2,0,0);
    glEnd();
    glBegin(GL_POLYGON);
        drawrefx(0,0,0);
        drawrefx(.6,0,0);
        drawrefx(.5,-1,0);
        drawrefx(0,-2,0);
    glEnd();
    glBegin(GL_POLYGON);
        drawrefx(0.3,0.9,0);
        drawrefx(0.8,0.9,0);
        drawrefx(1.1,-0.6,0);
        drawrefx(0.5,-1,0);
    glEnd();
    glBegin(GL_POLYGON);
        drawrefx(0,0,0);
        drawrefx(0.85,-.75,0);
        drawrefx(0.4,-1.15,0);
    glEnd();
    glBegin(GL_POLYGON);
        drawrefx(0.8,0.9,0);
        drawrefx(1.2,1,0);
        drawrefx(2.35,-0.1,0);
    glEnd();
    glBegin(GL_POLYGON);
        drawrefx(0.8,0.9,0);
        drawrefx(1.1,-0.6,0);
        drawrefx(2.35,-0.1,0);
    glEnd();
    glBegin(GL_POLYGON);
        drawrefx(1.2,1,0);
        drawrefx(1.4,1.1,0);
        drawrefx(3.9,0,0);
        drawrefx(2.35,-0.1,0);
    glEnd();
    glBegin(GL_POLYGON);
        drawrefx(1.4,1.1,0);
        drawrefx(1.6,1.3,0);
        drawrefx(4.15,0.5,0);
        drawrefx(3.9,0,0);
    glEnd();
    glBegin(GL_POLYGON);
        drawrefx(1.6,1.3,0);
        drawrefx(1.75,1.6,0);
        drawrefx(4.4,0.85,0);
        drawrefx(4.15,0.5,0);
    glEnd();
    glBegin(GL_POLYGON);
        drawrefx(1.75,1.6,0);
        drawrefx(1.85,1.9,0);
        drawrefx(5,1.3,0);
        drawrefx(4.4,0.85,0);
    glEnd();
    glBegin(GL_POLYGON);
        drawrefx(1.85,1.9,0);
        drawrefx(1.9,2.2,0);
        drawrefx(7,2.2,0);
        drawrefx(5,1.3,0);
    glEnd();

    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

//Funcion main donde se inician las librererias de GLut y OpenGL
int main(int argc, char ** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);
glutInitWindowSize(700,700);
glutCreateWindow("Batman Proyecto Uno");
init();
glutDisplayFunc(display);

glutMainLoop();
return 0;
}
