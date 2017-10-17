#include "glut.h"
#include <stdio.h>
#include "cuadrado.h"

/******************************************************************/
/* Funcion de dibujado                                            */
/* Parametros: Ninguno                                            */
/* Salida: Ninguna                                                */
/******************************************************************/
void Dibuja(void)
{
	/* Establece el color de borrado */
	glClearColor (1.0f, 0.0f, 0.0f, 0.0f);

	/* Borra el buffer de color */
	glClear (GL_COLOR_BUFFER_BIT);
	
	/* Establece el color de dibujo */
	glColor3f (0.0f, 1.0f, 0.0f);

	/* Crea un poligono 2D (cuadrado) */
	glBegin (GL_POLYGON);
		glVertex2f (-0.5f, -0.5f);
		glVertex2f (-0.5f, 0.5f);
		glVertex2f (0.5f, 0.5f);
		glVertex2f (0.5f, -0.5f);
	glEnd ();

	//Cuadrado azul
	glColor3f(0.0f, 0.0f, 1.0f);

	
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(-0.5f, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(0.0f, 0.5f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(0.5f, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(0.0f, -0.5f);
	glEnd();

	//Triangulo negro
	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_POLYGON);
		glVertex2f(-0.5f, 0.0f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.0f, 0.5f);
	glEnd();

	//Triangulo amarillo
	glColor3f(1.0f, 1.0f, 0.0f);

	glBegin(GL_POLYGON);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, 0.0f);
	glEnd();

	//Triangulo blanco
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_POLYGON);
		glVertex2f(0.5f, 0.0f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.0f, -0.5f);
	glEnd();

	/* Se asegura de que se ejecutan todas las ordenes */
	glFlush ();
}

/******************************************************************/
/* Funcion de dibujado ejercicio 3                                */
/* Parametros: Ninguno                                            */
/* Salida: Ninguna                                                */
/******************************************************************/
void Dibuja2(void)

{
	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);

	/* Borra el buffer de color */
	glClear(GL_COLOR_BUFFER_BIT);

	//Cuadrados negro y verde
	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_POLYGON);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_POLYGON);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.3f);
		glVertex2f(0.3f, 0.3f);
		glVertex2f(0.3f, -0.5f);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_POLYGON);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.1f);
		glVertex2f(0.1f, 0.1f);
		glVertex2f(0.1f, -0.5f);
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_POLYGON);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, -0.1f);
		glVertex2f(-0.1f, -0.1f);
		glVertex2f(-0.1f, -0.5f);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_POLYGON);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, -0.3f);
		glVertex2f(-0.3f, -0.3f);
		glVertex2f(-0.3f, -0.5f);
	glEnd();

}


void Dibuja3(void)

{
	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);

	/* Borra el buffer de color */
	glClear(GL_COLOR_BUFFER_BIT);

	//Cuadrados negro y verde
	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_POLYGON);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_POLYGON);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-0.5f, 0.3f);
	glVertex2f(0.3f, 0.3f);
	glVertex2f(0.3f, -0.5f);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_POLYGON);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-0.5f, 0.1f);
	glVertex2f(0.1f, 0.1f);
	glVertex2f(0.1f, -0.5f);
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_POLYGON);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-0.5f, -0.1f);
	glVertex2f(-0.1f, -0.1f);
	glVertex2f(-0.1f, -0.5f);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_POLYGON);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-0.5f, -0.3f);
	glVertex2f(-0.3f, -0.3f);
	glVertex2f(-0.3f, -0.5f);
	glEnd();
}

/******************************************************************************************/
/* Establece el area visible                                                              */
/* Parametros: int ancho --> Ancho del area visible                                       */
/*             int alto --> Alto del area visible                                         */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void TamanyoVentana (int ancho, int alto)
{
	glViewport (0, 0, ancho, alto);
}


/******************************************************************************************/
/* Inicia las propiedades de la vista                                                     */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void IniciaVista (void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}


/******************************************************************************************/
/* Abre una ventana OpenGL                                                                */
/* Parametros: int numeroArgumentos --> El numero de argumentos en la llamada al programa */
/*             char ** listaArgumentos --> Vector de cadenas con cada argumento           */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void AbreVentana (int numeroArgumentos, char ** listaArgumentos)
{
	glutInit(&numeroArgumentos, listaArgumentos);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (listaArgumentos[0]);
	glutDisplayFunc (Dibuja);
	glutReshapeFunc (TamanyoVentana);
	IniciaVista ();
}

//Ventana para el ejercicio 3 primera parte
void AbreVentana2(int numeroArgumentos, char ** listaArgumentos)
{
	glutInit(&numeroArgumentos, listaArgumentos);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(listaArgumentos[0]);
	glutDisplayFunc(Dibuja2);
	glutReshapeFunc(TamanyoVentana);
	IniciaVista();
}

//Ventana para el ejercicio 3 segunda parte
void AbreVentana3(int numeroArgumentos, char ** listaArgumentos)
{
	glutInit(&numeroArgumentos, listaArgumentos);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(listaArgumentos[0]);
	glutDisplayFunc(Dibuja3);
	glutReshapeFunc(TamanyoVentana);
	IniciaVista();
}

/******************************************************************************************/
/* Funcion principal                                                                      */
/* Parametros: int numeroArgumentos --> El numero de argumentos en la llamada al programa */
/*             char ** listaArgumentos --> Vector de cadenas con cada argumento           */
/* Salida: Un entero que se devuelve al sistema al acabar la ejecucion del programa       */
/******************************************************************************************/
int main(int numArgumentos, char ** listaArgumentos)
{
	/* Crea la ventana de la aplicaci¢n */
	//Ejercicio 2
	AbreVentana (numArgumentos, listaArgumentos);
	//Ejercicio 3 primera parte
	AbreVentana2 (numArgumentos, listaArgumentos);
	//Ejercicio 3 segunda parte
	AbreVentana3(numArgumentos, listaArgumentos);

	/* Establece el bucle principal de control de OpenGL */
	glutMainLoop();

	return (0);
}