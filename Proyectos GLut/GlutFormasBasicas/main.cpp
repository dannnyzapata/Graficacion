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

    glColor3f (1.137, 1.524, 1.0);
    glBegin(GL_POLYGON);
        glVertex3f (2.0, 0.0, 0.0);
        glVertex3f (3.0, 1.0, 0.0);
        //glVertex3f (1.0, 0.0, 0.0);
        glVertex3f (5.0, 1.0, 0.0);
        glVertex3f (1.0, 0.0, 0.0);
         //glVertex3f (0.85, 0.85, 0.0);
        //glVertex3f (0.250, 0.85, 0.0);
    glEnd();

   glColor3f (1.667, 0.627, 0.224);
    glBegin(GL_POLYGON);
        glVertex3f (0.25, 0.25, 0.0);
        glVertex3f (4.75, 0.25, 0.0);
        glVertex3f (5.75, 0.75, 0.0);
        glVertex3f (8.25, 0.75, 0.0);
    glEnd();

    glColor3f (0.937, 0.424, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f (0.50, 0.50, 0.0);
        glVertex3f (0.95, 0.50, 0.0);
        glVertex3f (0.95, 0.95, 0.0);
        glVertex3f (0.50, 0.95, 0.0);
    glEnd();

    glColor3f (3.886, 0.125, 0.557);
    glBegin(GL_POLYGON);
        glVertex3f (0.150, 0.150, 0.0);
        glVertex3f (0.65, 0.55, 0.0);
        glVertex3f (0.65, 0.75, 0.0);

    glEnd();
    glFlush ();
}
void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
//  https://docs.microsoft.com/en-us/windows/win32/opengl/glortho
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

