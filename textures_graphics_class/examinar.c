/*************************************************************************/
/*                                                                       */
/*   examinar.c                                                          */
/*   Rev. 2.0  01/01/2002   AUTORES: O. Belmonte, M. Chover, J. Ribelles */
/*                                                                       */
/*************************************************************************/

/***************** INCLUDES DE LAS LIBRERIAS NECESARIAS ******************/
#include "glut.h"
#include <stdio.h>
#include <math.h>
#include "examinar.h"
#include "glig.h"
#include "textura.h"
#include "modelado.h"


/******************************************************************************************/
/* Establece el area visible y el tipo de proyeccion                                      */
/* Parametros: int ancho --> Ancho del area visible                                       */
/*             int alto --> Alto del area visible                                         */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void TamanyoVentana (GLsizei ancho, GLsizei alto)
{
    /* Definicion del viewport */
	glViewport(0, 0, ancho, alto);  

    /* Definicion de la vista */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective (60.0, (GLdouble)alto/(GLdouble)ancho, 1.0, 400.0);
}


void AbreVentana (int numeroArgumentos, char ** listaArgumentos)
{
	glutInit(&numeroArgumentos, listaArgumentos);
	/* Cambia los parametros para utilizar doble buffer */
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (VentanaAncho, VentanaAlto);
	glutInitWindowPosition (VentanaX, VentanaY);
	glutCreateWindow (listaArgumentos[0]);
	glutDisplayFunc (Dibuja);
	glutReshapeFunc (TamanyoVentana);
}


void TecladoAmpliado (int tecla, int x, int y)
{
	switch (tecla)
	{
	case GLUT_KEY_UP:
		alfa = alfa + 15;
		if (alfa > 360) alfa -= 360;
		break;

	case GLUT_KEY_DOWN:
		alfa = alfa - 15;
		if (alfa < 0) alfa += 360;
		break;

	case GLUT_KEY_RIGHT:
		beta = beta + 15;
		if (beta > 360) beta -= 360;
		break;

	case GLUT_KEY_LEFT:
		beta = beta - 15;
		if (beta < 0) beta += 360;
		break;
	}
	glutPostRedisplay ();
}


/* Rutina de definición de eventos */
/******************************************************************************************/
/* Inicia las funciones de callback                                                       */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void IniciaFuncionesCallback (void)
{
	glutSpecialFunc (TecladoAmpliado);
}


/******************************************************************************************/
/* Funcion de dibujado                                                                    */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Dibuja (void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
    /* Transformacion de la camara */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt (ox, oy, oz, ix, iy, iz, 0, 1, 0);

	glRotatef(beta, 0.f, 1.f, 0.f);
	glRotatef(alfa, 1.f, 0.f, 0.f);

	/* Llamadas a las display lists */
	glCallList (escena);

	/* Utiliza la funcion de la glut que intercambia los buffers */
	glutSwapBuffers();
}


/******************************************************************************************/
/* Inicia caracteristicas de la visualizacion OpenGL                                      */
/* Parametros: Ninguno.                                                                   */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void IniciaOpenGL (void)
{
	glClearColor (0.0f, 0.0f, 0.0f, 0.0f); /* Establece el color de borrado */
	
	glEnable (GL_DEPTH_TEST);
	glEnable (GL_CULL_FACE);
	
	GLfloat lmodel_ambient[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHT0);


	// 1..... TODO 01 ............ENABLE TEXTURING .............1
	glEnable(GL_TEXTURE_2D);

}



/******************************************************************************************/
/* Funcion principal                                                                      */
/* Parametros: int numeroArgumentos --> El numero de argumentos en la llamada al programa */
/*             char ** listaArgumentos --> Vector de cadenas con cada argumento           */
/* Salida: Un entero que se devuelve al sistema al acabar la ejecucion del programa       */
/******************************************************************************************/
int main(int numArgumentos, char ** listaArgumentos)
{	
	/* Creación de la ventana de la aplicación */
	AbreVentana (numArgumentos, listaArgumentos);

	/* Llamada a las funciones de inicializacion */
	IniciaOpenGL ();

	/* Rutinas para el control de eventos */
    IniciaFuncionesCallback ();

	// 8...... TODO 08 ............... INIT TEXTURE CREATION .................8
	initTextureWithIndex("ivan.tga", 0);
	initTextureWithIndex("estrellas256.tga", 1);
	// 17 ........ TODO 17: COMMENT initTextura AND CREATE NEW TEXTURES ..............17

	/* Creo la display list de la escena */
	CreaEscenaIluminacion ();

	/* A la espera de eventos.... */
	glutMainLoop();

	return (0);
}

