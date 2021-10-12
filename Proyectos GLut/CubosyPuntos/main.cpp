/******* Inicio de las bibliotecas *******/


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

/******* Fin de las bibliotecas *******/









/******Prototipos de función void display(); ***/
void specialKeys();

// Variables globales
double rotate_y=0;
double rotate_x=0;


/*****Función de retrollamada “display()” *****/
void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);  // Borrar pantalla y Z-buffer y  Resetear //transformaciones
glLoadIdentity();

/*****  Rotar cuando el usuario cambie “rotate_x” y “rotate_y” *****/
glRotatef( rotate_x, 1.0, 0.0, 0.0 );
glRotatef( rotate_y, 0.0, 1.0, 0.0 );
/******* Fin de la función rotar  *******/

/*Inicio de la ubicación y pigmentación de las caras o tapas del cubo*/


//LADO FRONTAL: lado multicolor
glBegin(GL_POLYGON);
    glColor3f( 3.0, 0.0, 0.0 ); glVertex3f( 0.5, -0.5, -0.5 ); // P1 es rojo
    glColor3f( 4.0, 1.0, 0.0 ); glVertex3f( 0.5, 0.5, -0.5 ); // P2 es verde
    glColor3f( 3.0, 0.0, 1.0 ); glVertex3f( -0.5, 0.5, -0.5 ); // P3 es azul
    glColor3f( 1.0, 0.0, 1.0 ); glVertex3f( -0.5, -0.5, -0.5 ); // P4 es morado
glEnd();
/* las función glColor3f() es para asignar el color y en cambio las función glVertex3f() es para asignar vértices, con las dos combinadas podemos generar un mosaico  de colores*/
/*FIN DE LA CARA 1 */

// LADO posterior:
glBegin(GL_POLYGON);
    glColor3f( -8.0, 1.0, -1.6 ); // color de la cara o tapa
    glVertex3f( 0.5, -0.5, 0.5 );
    glVertex3f( 0.5, 0.5, 0.5 );
    glVertex3f( -0.5, 0.5, 0.5 );
    glVertex3f( -0.5, -0.5, 0.5 );
glEnd();

// LADO DERECHO:
glBegin(GL_POLYGON);
    glColor3f( 2.0, 0.5, 0.1 ); // color de la cara o tapa
    glVertex3f( 0.5, -0.5, -0.5 );
    glVertex3f( 0.5, 0.5, -0.5 );
    glVertex3f( 0.5, 0.5, 0.5 );
    glVertex3f( 0.5, -0.5, 0.5 );
glEnd();

// LADO IZQUIERDO:
glBegin(GL_POLYGON);
    glColor3f( 1.0, -2.8, 1.0 ); // color de la cara o tapa
    glVertex3f( -0.5, -0.5, 0.5 );
    glVertex3f( -0.5, 0.5, 0.5 );
    glVertex3f( -0.5, 0.5, -0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
glEnd();

// LADO SUPERIOR:
glBegin(GL_POLYGON);
    glColor3f( 1.0, -3.0, -1.0 ); // color de la cara o tapa
    glVertex3f( 0.5, 0.5, 0.5 );
    glVertex3f( 0.5, 0.5, -0.5 );
    glVertex3f( -0.5, 0.5, -0.5 );
    glVertex3f( -0.5, 0.5, 0.5 );
glEnd();
/*
glBegin(GL_POLYGON);
    glColor3f( 1.0, -4.0, -1.0 ); // color de la cara o tapa
    glVertex3f( 0.8, 0.8, 0.8 );
    glVertex3f( 0.8, 0.8, -0.8 );
    glVertex3f( -0.8, 0.8, -0.8 );
    glVertex3f( -0.8, 0.8, 0.8 );
//glColor3f( 1.0, -2.8, 1.0 ); //
//glVertex3f( -0.3, 0.3, 0.9 ); //
glEnd();

*/
/*
// LADO INFERIOR:
glBegin(GL_POLYGON);
    glColor3f( 1.0, 1.0, 0.0); // color de la cara o tapa
    glVertex3f( 0.5, -0.5, -0.5 );
    glVertex3f( 0.5, -0.5, 0.5 );
    glVertex3f( -0.5, -0.5, 0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
glEnd();
*/
/*
glBegin(GL_POLYGON);
    glColor3f( 1.0, 1.0, 0.0); // color de la cara o tapa
    glVertex3f( 0.3, -0.3, -0.3 );
    glVertex3f( 0.3, -0.3, 0.3 );
    glVertex3f( -0.3, -0.3, 0.3 );
    glVertex3f( -0.3, -0.3, -0.3 );
glEnd();
*/

// crear un poligono es cinco lados


glPointSize(20);
glBegin(GL_POINTS);

    glColor3f( 1.0, 1.0, 1.0 );  // P1 es blanco
    glVertex3f( 0.0,0.1,0.0 ); // P1 es (x=0.0,y=0.0,z=0.0) es el centro

    glColor3f( 0.0, 4.0, 3.0 );  // P2 es verde
    glVertex3f( 0.50,0.50,0.0 ); // P2 es (x=0.5,y=0.5,z=0.0)

    glColor3f( 1.0, 0.0, 0.0 );  // P3 es rojo
    glVertex3f( 1.0,1.0,0.0 ); // P3 es  (x=1.0,y=1.0,z=0)

    glColor3f( 0.0, 0.0, 1.0 );  // P4 es azul
    glVertex3f( -1.0,-1.0,0.0 ); // P4 es  (x=-1.0,y=-1.0,z=0)

    glColor3f( 0.0, 1.0, 1.0 );  // P5 es cian
    glVertex3f( -0.50,-0.50,0.0 ); // P5 es (x=-0.5,y=-0.5,z=0.0)

    glColor3f( 1.0, 0.0, 1.0 );  // P6 es magenta
    glVertex3f( -1.0,1.0,0.0 ); // P6 es (x=-0.5,y=-0.5,z=0.0)

    glColor3f( 2.0, 0.50, 0.0 );  // P7 es naranja
    glVertex3f( 1.0,-1.0,0.0 ); // P7 es (x=-0.5,y=-0.5,z=0.0)

glEnd();


/*glPointSize(20);
glBegin(GL_POINTS);

    glColor3f( 1.0, 1.0, 1.0 );  // P1 es blanco
    glVertex3f( 0.0,0.0,0.0 ); // P1 es (x,y,z) es el centro

    glColor3f( 0.0, 1.0, 0.0 );  // P2 es verde
    glVertex3f( 0.50,0.50,0.0 ); // P2 es (x=0.5,y=0.5,z=0.0)

    glColor3f( 1.0, 0.0, 0.0 );  // P3 es rojo
    glVertex3f( 1.0,1.0,0.0 ); // P3 es  (x=1.0,y=1.0,z=0)

    glColor3f( 0.0, 0.0, 1.0 );  // P4 es azul
    glVertex3f( -1.0,-1.0,0.0 ); // P4 es  (x=-1.0,y=-1.0,z=0)

    glColor3f( 0.0, 1.0, 1.0 );  // P5 es cian
    glVertex3f( -0.50,-0.50,0.0 ); // P5 es (x=-0.5,y=-0.5,z=0.0)

    glColor3f( 1.0, 0.0, 1.0 );  // P6 es magenta
    glVertex3f( -1.0,1.0,0.0 ); // P6 es (x=-0.5,y=-0.5,z=0.0)

    glColor3f( 1.0, 0.50, 0.0 );  // P7 es naranja
    glVertex3f( 1.0,-1.0,0.0 ); // P7 es (x=-0.5,y=-0.5,z=0.0)

glEnd();*/

/*glLineWidth(2);
glBegin(GL_LINE);

    glColor3f( 1.0, 1.0, 1.0 );  // P1 es blanco
    glVertex3f( 0.0,0.0,0.0 ); // P1 es (x,y,z) es el centro

    glColor3f( 0.0, 1.0, 0.0 );  // P2 es verde
    glVertex3f( 0.50,0.50,0.0 ); // P2 es (x=0.5,y=0.5,z=0.0)

    glColor3f( 1.0, 0.0, 0.0 );  // P3 es rojo
    glVertex3f( 1.0,1.0,0.0 ); // P3 es  (x=1.0,y=1.0,z=0)

    glColor3f( 0.0, 0.0, 1.0 );  // P4 es azul
    glVertex3f( -1.0,-1.0,0.0 ); // P4 es  (x=-1.0,y=-1.0,z=0)

    glColor3f( 0.0, 1.0, 1.0 );  // P5 es cian
    glVertex3f( -0.50,-0.50,0.0 ); // P5 es (x=-0.5,y=-0.5,z=0.0)

    glColor3f( 1.0, 0.0, 1.0 );  // P6 es magenta
    glVertex3f( -1.0,1.0,0.0 ); // P6 es (x=-0.5,y=-0.5,z=0.0)

    glColor3f( 1.0, 0.50, 0.0 );  // P7 es naranja
    glVertex3f( 1.0,-1.0,0.0 ); // P7 es (x=-0.5,y=-0.5,z=0.0)

glEnd();*/

//glPolygonMode(GL_FRONT, GL_FILL);

/* glBegin(GL_POLYGON);

		// Color azul para el primer vertice
		glColor3f(0.0, 0.0, 1.0);
		glVertex3i(-1, -1, 5);

		// Color verde para el segundo vertice
		glColor3f(0.0, 1.0, 0.0);
		glVertex3i(-1, 1, 5);

		// Color rojo para el tercer vertice
		glColor3f(1.0, 0.0, 0.0);
		glVertex3i(1, 1, 5);

		// Color amarillo para el cuarto vertice
		glColor3f(1.0, 1.0, 0.0);
		glVertex3i(1, -1, 5);

	glEnd();
*/

/*
glBegin(GL_POLYGON);
    glColor3f( 1.0, 1.0, 0.0 ); glVertex3f( -1.0,1.0, 0.0 ); // P1 es rojo
    glColor3f( 0.8, 1.0, 0.0 ); glVertex3f( 0.2, -0.2, 0.0 ); // P2 es verde
    glColor3f( 0.0, 1.0, 0.0 ); glVertex3f( -0.3, 0.3, 0.0 ); // P3 es azul
    glColor3f( 1.5, 1.0, 0.0 ); glVertex3f( 0.4, 0.4, 0.0 ); // P4 es blanco
    glColor3f( 2.0, 1.0, 0.0 ); glVertex3f( -0.6, -0.6,0.0 ); // P5 es amarillo
glEnd();
*/

glFlush(); //NOTA: dan el efecto de doble-buffer.
glutSwapBuffers(); //NOTA: dan el efecto de doble-buffer.
}
/*fin de la ubicación y pigmentación de las caras o tapas del cubo*/


// Función de retrollamada “specialKeys()”
void specialKeys( int key, int x, int y )
{
if (key == GLUT_KEY_RIGHT)    // La flecha derecha: incrementa su rotación en 5 grados
rotate_y += 5;
     else if (key == GLUT_KEY_LEFT)  // La flecha izquierda: disminuye su rotación en 5 grados
rotate_y -= 5;
        else if (key == GLUT_KEY_UP)
rotate_x += 5;
            else if (key == GLUT_KEY_DOWN)
rotate_x -= 5;
glutPostRedisplay();  // Solicitud para actualizar la pantalla

}




// Función main()
int main(int argc, char* argv[])
{
glutInit(&argc,argv);  // InChecar el código de la simulación de un péndulo. Hay que poner pantalla de que lo hicieronicializar los parámetros GLUT y de usuario proceso

glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  // Solicitar ventana con color     // real y doble buffer con Z-buffer
glutInitWindowSize(600,600);
glutCreateWindow("Practica cubo con puntos"); //  Crear ventana  título del cuadro de ejecución
glEnable(GL_DEPTH_TEST);  // Habilitar la prueba de profundidad de Z-buffer


// Funciones de retrollamada
glutDisplayFunc(display);
glutSpecialFunc(specialKeys); // Pasar el control de eventos a GLUT
glutMainLoop();    // Regresar al sistema operativo
return 0;
}
