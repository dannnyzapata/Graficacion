#include <stdlib.h>
#include <math.h>
#include <windows.h> // Standard header for MS Windows applications
#include <GL/gl.h> // Open Graphics Library (OpenGL) header
#include <GL/glu.h>
#include <GL/glut.h>

/* contenido dinamico */

static GLfloat spin = 0.0;
void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   glRotatef(spin, 0.0, 0.0, 1.0);
   glColor3f(0.333, 0.0, 0.333);
   glRectf(-45.0, -45.0, 45.0, 45.0);
   glRotatef(spin, 0.0, 0.0, 1.0);
   glColor3f(0.333, 0.0, 1.0);
   glRectf(-25.0, -25.0, 25.0, 25.0);
   glRotatef(spin, 0.0, 0.0, 1.0);
   glColor3f(0.333, 0.456, 1.0);
   glRectf(-15.0, -15.0, 15.0, 15.0);

   glPopMatrix();
   glutSwapBuffers();
}
void spinDisplay(void)
{

   spin = spin + 2.0;
   if (spin > 360.0)
      spin = spin - 360.0;

   glutPostRedisplay();
}
void reshape(int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
void mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
         break;
      case GLUT_MIDDLE_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
         break;
      default:
         break;
   }
}
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE |
           GLUT_RGB);
   glutInitWindowSize (250, 250);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMouseFunc(mouse);
   glutMainLoop();
   return 0;
}
