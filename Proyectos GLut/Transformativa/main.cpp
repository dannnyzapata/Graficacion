/* Ejemplo sobre transformaciones afines con OpenGL para
   Macedonia Magazine'99.    por Oscar Garc�a Panyella.
   ADAPTACI�N para la clase de Graficaci�n MSI Ra�l Arturo Acosta Ch�vez
   Ejecucion en una resoluci�n de 1920 x 1080px
*/

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL\glut.h>

#define WIDTH 400		/* Ancho ventanas en pixels */
#define HEIGHT 400		/* Alto ventanas en pixels */

typedef GLfloat punto[3];

punto cubo[8]={{-10.0,0.0,10.0},{10.0,0.0,10.0},{10.0,0.0,-10.0},
{-10.0,0.0,-10.0},{-10.0,10.0,10.0},{10.0,10.0,10.0},{10.0,10.0,-10.0},
{-10.0,10.0,-10.0}};

/*********************************************************************/

/* SECCI�N DE DISPLAY */

/* Dibuja la cara que recibe */
void cara(GLint a, GLint b, GLint c, GLint d){
	glBegin(GL_POLYGON);
		glVertex3fv(cubo[a]);
		glVertex3fv(cubo[b]);
		glVertex3fv(cubo[c]);
		glVertex3fv(cubo[d]);
	glEnd();
}

/* Dibuja un cubo */
void objeto(void){

	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

	cara(0,3,7,4);
	cara(1,2,8,5);
	cara(2,3,9,6);
	cara(0,4,5,3);
	cara(4,5,2,3);
	cara(0,3,1,1);
}

/* Dibuja los ejes de referencia */
void ejes(void){
	glBegin(GL_LINES);
		glVertex3i(0,0,0);
		glVertex3i(0,40,0);

		glVertex3i(0,0,0);
		glVertex3i(40,0,0);

		glVertex3i(0,0,0);
		glVertex3i(0,0,40);
	glEnd();
}

/* Render de la ventana 1 */
void display1(void){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0,1.0,0.0);
	ejes();

	glColor3f(1.0,0.0,0.0);

	objeto();

	glColor3f(0.0,1.0,0.0);

	glPushMatrix();
	  glScalef(2.0,2.0,2.0);
	  objeto();
	glPopMatrix();

	glutSwapBuffers();
}

/* Render de la ventana 2 */
void display2(void){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0,1.0,0.0);
	ejes();

	glColor3f(1.0,0.0,0.0);

	objeto();

	glColor3f(0.0,1.0,0.0);

	glPushMatrix();
	  glTranslatef(30.0,0.0,0.0);
	  objeto();
	glPopMatrix();

	glutSwapBuffers();
}

/* Render de la ventana 3 */
void display3(void){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0,1.0,0.0);
	ejes();

	glColor3f(1.0,0.0,0.0);

	objeto();

	glColor3f(0.0,1.0,0.0);

	glPushMatrix();
	  glRotatef(45.0,0,1,0);
	  objeto();
	glPopMatrix();

	glutSwapBuffers();
}

/* Render de la ventana 4 */
void display4(void){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0,1.0,0.0);
	ejes();

	glColor3f(1.0,0.0,0.0);

	objeto();

	glColor3f(0.0,1.0,0.0);

	glPushMatrix();
	  glRotatef(45.0,0,1,0);
	  glTranslatef(30.0,0.0,0.0);
	  objeto();
	glPopMatrix();

	glutSwapBuffers();
}

/* Render de la ventana 5 */
void display5(void){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0,1.0,0.0);
	ejes();

	glColor3f(1.0,0.0,0.0);

	objeto();

	glColor3f(0.0,1.0,0.0);

	glPushMatrix();
	  glTranslatef(30.0,0.0,0.0);
	  glRotatef(45.0,0,1,0);
	  objeto();
	glPopMatrix();

	glutSwapBuffers();
}

/*********************************************************************/

/* VISI�N e INICIALIZACI�N */

/* Proyecci�n ortogr�fica asociada a las 5 ventanas */
/* Una vez creada la proyecci�n activamos e inicializamos la
matriz de transformaci�n - GL_MODELVIEW */
/* �Por qu� crees que tras inicializar a�ado 2 transformaciones que afectar�n
a toda la geometr�a? */
void ini(void){
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-50.0,50.0,-50.0,50.0,-50.0,50.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0,-10.0,0.0);
  glRotatef(45.0, 1.0, 1.0, 1.0);
}

/*********************************************************************/

/* MAIN */

int main(int argc, char** argv){

	glutInit(&argc, argv);

	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	/* Definici�n ventana 1 */

	glutInitWindowSize (WIDTH, HEIGHT);

	glutInitWindowPosition (0, 0);

	glutCreateWindow("MM: Escalar");

	glutDisplayFunc(display1);

	ini();

	/* Definici�n ventana 2 */

	glutInitWindowSize (WIDTH, HEIGHT);

	glutInitWindowPosition (250+WIDTH, 0);

	glutCreateWindow("MM: Trasladar");

	glutDisplayFunc(display2);

	ini();

	/* Definici�n ventana 3 */

	glutInitWindowSize (WIDTH, HEIGHT);

	glutInitWindowPosition (500+WIDTH*2, 0);

	glutCreateWindow("MM: Rotar");

	glutDisplayFunc(display3);

	ini();

	/* Definici�n ventana 4 */

	glutInitWindowSize (WIDTH, HEIGHT);

	glutInitWindowPosition (WIDTH, 275+HEIGHT);

	glutCreateWindow("MM: Rotar+Trasladar");

	glutDisplayFunc(display4);

	ini();

	/* Definici�n ventana 5 */

	glutInitWindowSize (WIDTH, HEIGHT);

	glutInitWindowPosition (425+WIDTH*2, 275+HEIGHT);

	glutCreateWindow("MM: Trasladar+Rotar");

	glutDisplayFunc(display5);

	ini();

	glutMainLoop();
	return 0;
}
