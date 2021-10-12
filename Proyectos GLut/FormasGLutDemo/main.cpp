/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#include <stdlib.h>
#include <math.h>
#include <windows.h> // Standard header for MS Windows applications
#include <GL/gl.h> // Open Graphics Library (OpenGL) header
#include <GL/glu.h>
#include <GL/glut.h>

/* contenido estático */

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 2.0, -1.0);
    glBegin(GL_POLYGON);
        glVertex3f (0.20, 0.25, 0.0);
        glVertex3f (0.6, 0.25, 0.0);
        glVertex3f (1.75, 0.75, 0.0);
        glVertex3f (2.25, 0.75, 0.0);
    glEnd();

    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f (0.50, 0.50, 0.0);
        glVertex3f (0.95, 0.50, 0.0);
        glVertex3f (0.95, 0.95, 0.0);
        glVertex3f (0.50, 0.95, 0.0);
    glEnd();
    glFlush ();
}
void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1250, 750);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
