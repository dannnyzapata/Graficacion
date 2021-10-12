/******* Inicio de las bibliotecas *******/


//#include <stdio.h>
//#include <stdlib.h>
#include <math.h>
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>

/*
Este programa se basa en ../../common/January1998/../../common/January1998/example1.c,
la principal diferencia es que la ventana se abre en modo de doble buffer, y el par�metro K de la transformaci�n es
una variable que cambia durante la ejecuci�n del programa. Hay una nueva funci�n callback idle() registrada para el
procesador de eventos de GLUT por glutIdleFunc().Esta funci�n tiene un significado especial, es ejecutada por el
procesador de eventos en todo momento que no hay entrada del usuario. La funci�n callback idle() es ideal para
animaciones de programas. En ../../common/January1998/example2, se utiliza para cambiar ligeramente el valor del
par�metro de la transformaci�n. Al final de idle() hay otra funci�n de GLUT �til, glutPostResDisplay() que redibuja
la ventana conservando la inicializaciones anteriores, en general es m�s eficiente que llamar a display() de nuevo.

Otra diferencia a se�alar es el uso de glutSwapBuffers() al final de display(). La ventana se inici� en modo doble
buffer por lo que todas las directivas de trazado se aplican al buffer oculto, el usuario no ve c�mo se dibuja la
imagen en este caso. Cuando se ha finalizado la imagen completa (frame), entonces se hace visible intercambiando
los buffers visible e invisible con glutSwapBuffers(). Sin esta t�cnica la animaci�n no ir�a suave.


*/



const  double  pi2 = 6.28318530718;
const  double  K_max = 3.5;
const  double  K_min = 0.1;
static double  Delta_K = 0.01;
static double  K = 0.1;





void NonlinearMap(double *x, double *y){

    /* Transformaci�n estandar */

    *y += K * cos(*x);
    *x += *y;

    /* El �ngulo x es m�dulo 2Pi */

    *x = fmod(*x, pi2);
    if (*x < 0.0) *x += pi2;

};





/* Funci�n callback:

   Qu� hacer en ausencia de entradas */

void  idle(void){

    /* Incrementar el par�metro estoc�stico */

    K += Delta_K;
    if(K > K_max) K = K_min;


    /* Redibujar el display */
    glutPostRedisplay();

};





/* Inicializaci�n de la ventana gr�fica */

void winInit(void){

    gluOrtho2D(0.0, pi2, 0.0, pi2);

};



/* Funci�n callback:

    Qu� hacer cuando el display se ha de redibujar */

void display(void){

    const int    NumberSteps = 1000;
    const int    NumberOrbits = 50;
    const double Delta_x = pi2/(NumberOrbits-1);
    int step, orbit;

    glColor3f(0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);

    for (orbit = 0; orbit < NumberOrbits; orbit++){
	 double x, y;
	 y = 3.1415;
	 x = Delta_x * orbit;

	 glBegin(GL_POINTS);
	  for (step = 0; step < NumberSteps; step++){
	    NonlinearMap(&x, &y);
   	    glVertex2f(x, y);
   	    glColor3f(-3.0,2.0, 1.0);  //   agregar
	    };
	  glEnd();
    };



     for (orbit = 0; orbit < NumberOrbits; orbit++){
	  double x, y;
	  x = 4.1415;
	  y = Delta_x * orbit;
      glBegin(GL_POINTS);
	    for (step = 0; step < NumberSteps; step++){
	      NonlinearMap(&x, &y);
	      glVertex2f(x, y);
	      glColor3f(0.0, 1.0, 1.0);  // agregar
        };
	  glEnd();
    };

     glutSwapBuffers();
};





int main(int argc, char **argv)  {

  /* Inicializaciones de GLUT */

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(5,5);
  glutInitWindowSize(600,600);
  /* Abrir ventana*/
  glutCreateWindow("Ordernar el Caos");

  /* Inicializaci�n de la ventana */
  winInit();

  /* Registrar funciones callback */
  glutDisplayFunc(display);
  glutIdleFunc(idle);

  /* Iniciar el proceso de eventos */
  glutMainLoop();
  return 0;
}
