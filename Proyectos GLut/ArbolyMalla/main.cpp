#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>

GLUquadricObj *cilindro;
GLfloat girax = 0, giray = 0, zoom=0;
GLboolean malla = GL_TRUE, ejes= GL_FALSE;
//Rotacion XY y Zoom
void mover(void)
{
    glTranslated(0,0,zoom);
    glRotated(girax,1.0,0.0,0.0);
    glRotated(giray,0.0,1.0,0.0);

}
//Malla y ejes
void creaMalla(void)
{
    int i, long_eje=10;
    glColor3f(0.01, 0.6, 0.98);
    //glColor3b(1.0,0.0,0.0);
    glBegin(GL_LINES);

    for(i=-long_eje; i<=long_eje; i++)
    {
        glVertex3f(i, -long_eje, 0);
        glVertex3f(i, long_eje, 0);
        glVertex3f(-long_eje, i, 0);
        glVertex3f(long_eje, i, 0);
    }

    glEnd();
}

void creaEjes(void)
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(11.0,0.0,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,11.0,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,0.0,11.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(11.0,0.0,0.0);//eje x
    glVertex3f(10.5,0.0,-.50);
    glVertex3f(10.5,0.0,.50);
    glVertex3f(0.0,11.0,0.0);//eje y
    glVertex3f(-.50,10.5,0.0);
    glVertex3f(.50,10.5,0.0);
    glColor3f(1.0,0.0,1.0);//eje z
    glVertex3f(0.0,0.0,11.0);
    glVertex3f(-.50,0.0,10.5);
    glVertex3f(.50,0.0,10.5);
    glEnd();
}

void dibuja(void)
{
    cilindro = gluNewQuadric();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    mover();
    if(malla) creaMalla();
    if(ejes) creaEjes();
    glColor3f(0.35, 0.16, 0.14);
    gluQuadricDrawStyle(cilindro,GLU_FILL);
    gluCylinder(cilindro,1,1,5,20,20);
    glPopMatrix();
    glPushMatrix();
    mover();
    if (malla) creaMalla();
    if (ejes) creaEjes();
    glColor3f(0.196, 0.8, 0.196);
    glTranslatef(0.0, 0.0, 4.0);
    glutSolidCone(3,9,20,12);  //glutSolidCone(3, 3, 20, 20);
    glPopMatrix();
    glutSwapBuffers();
}

void teclado (unsigned char key,int x, int y)
{
    switch(key)
    {
    case 27:
        exit(0);
    case '+':
        zoom ++;
        break;
    case '-':
        zoom --;
        break;
    case 'p':
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45,1,10,100);
        zoom=-40;
        break;
    case 'o':
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-15,15,-15,15,-30,30);
        zoom=0;
        break;
    case 'm':
        malla = !malla;
        break;
    case 'e':
        ejes=!ejes;
    default:
        break;
    }
    glutPostRedisplay();
}

void flechas(int key,int x,int y)
{
    switch(key)
    {
    case GLUT_KEY_LEFT:
        giray-=15;
        break;
    case GLUT_KEY_RIGHT:
        giray+=15;
        break;
    case GLUT_KEY_UP:
        girax-=15;
        break;
    case GLUT_KEY_DOWN:
        girax+=15;
    default:
        break;
    }
    glutPostRedisplay();
}

// Reshape y main
void ajusta(int ancho, int alto)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-30,30,-30,30,-10,10);  //glOrtho(-15,15,-15,15,-30,30);
    // https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glOrtho.xml
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
}
int main(int argc,char** argv)
{
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutInit(&argc,argv);
    glutCreateWindow("ESCENA ARBOL Y  MALLA");
    glutDisplayFunc(dibuja);
    glutReshapeFunc(ajusta);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(flechas);
    glutMainLoop();
    return 0;

}
