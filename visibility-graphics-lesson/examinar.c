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
    gluPerspective (45.0, (GLdouble)alto/(GLdouble)ancho, 1.0, 400.0);
	
	
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
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	// TODO 3. WINDOW CREATION WITH SUPPORT FOR THE Z-BUFFER ALGORITHM -------------------------------
	// RIGHT NOW THE VISUALIZATION IS INCORRECT. WE MUST ENABLE THE Z-BUFFER ALGORITHM

	// TODO 11. WINDOW CREATION WITH SUPPORT FOR DOUBLE BUFFER

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize (VentanaAncho, VentanaAlto);
	glutInitWindowPosition (VentanaX, VentanaY);
	glutCreateWindow (listaArgumentos[0]);
	glutDisplayFunc (Dibuja);
	glutReshapeFunc (TamanyoVentana);
	
}


/******************************************************************************************/
/* Define las acciones tras una pulsacion del teclado                                     */
/* Parametros: unsigned char key --> Codigo de la tecla pulsada                           */
/*             int x --> Coordenada x del cursor en el momento de pulsar la tecla         */
/*             int y --> Coordenada y del cursor en el momento de pulsar la tecla         */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Teclado (unsigned char tecla, int x, int y)
{
	switch (tecla)
	{
		case 27 : /* Codigo de la tecla de Escape */
			exit (0);
			break;

		case 'w' :
			modo = WALK;
			printf ("Modo = WALK      \r");
			break;

		case 'e' :
			modo = EXAMINAR;
			printf ("Modo = EXAMINAR    \r");
			break;

		case 'f' :
			modo = FLY;
			printf ("Modo = FLY      \r");
			break;
	}
}


/******************************************************************************************/
/* Define las acciones tras una pulsacion del teclado ampliado                            */
/* Parametros: unsigned char key --> Codigo de la tecla pulsada                           */
/*             int x --> Coordenada x del cursor en el momento de pulsar la tecla         */
/*             int y --> Coordenada y del cursor en el momento de pulsar la tecla         */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void TecladoAmpliado (int tecla, int x, int y)
{
	switch (tecla)
	{
		case GLUT_KEY_UP : // Pulsacion cursor arriba del teclado ampliado

			switch (modo) {

			case WALK:	ox = ix;
						oz = iz;
						ix = ox + PASO*sin(grad2rad(alfa));
						iz = oz - PASO*cos(grad2rad(alfa));
						break;
			case EXAMINAR:	beta = beta + 1.50;
							if (beta > 360.0) beta = beta - 360.0;
							iy = oy + PASO*sin(grad2rad(beta));
							break;
			case FLY:	ox = ix;
						oz = iz;
						oy = iy;
						ix = ox + PASO*sin(grad2rad(alfa));
						iz = oz - PASO*cos(grad2rad(alfa));
						iy = oy + PASO*sin(grad2rad(beta));
						break;

			}
			
			break;

		case GLUT_KEY_DOWN : // Pulsacion cursor abajo del teclado ampliado

				switch (modo) {

				case WALK:	
					ox = ox - (ix - ox);
					oz = oz - (iz - oz);
					ix = ox + PASO*sin(grad2rad(alfa));
					iz = oz - PASO*cos(grad2rad(alfa));
					break;

				case EXAMINAR:	
					beta = beta - 1.50;
					if (beta < 0.0) beta = beta + 360.0;
					iy = oy + PASO*sin(grad2rad(beta));
					break;

				case FLY:	
					ox = ox - (ix - ox);
					oz = oz - (iz - oz);
					oy = oy - (iy - oy);
					ix = ox + PASO*sin(grad2rad(alfa));
					iz = oz - PASO*cos(grad2rad(alfa));
					iy = oy + PASO*sin(grad2rad(beta));
					break;
				}

				break;

		case GLUT_KEY_RIGHT : // Pulsacion cursor derecha del teclado ampliado
			


			alfa = alfa + 15.0;
			if (alfa > 360.0) alfa = alfa - 360.0;
			ix = ox + PASO * sin(grad2rad(alfa));
			iz = oz - PASO * cos(grad2rad(alfa));
			
			break;

		case GLUT_KEY_LEFT : // Pulsacion cursor izquierda del teclado ampliado

				alfa = alfa - 15.0;
				if (alfa < 0.0) alfa = alfa + 360.0;

				// we update the point of interest

				ix = ox + PASO*sin(grad2rad(alfa));
				iz = oz - PASO*cos(grad2rad(alfa));
			
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
	glutKeyboardFunc (Teclado);
	glutSpecialFunc (TecladoAmpliado);
}


/******************************************************************************************/
/* Funcion de dibujado                                                                    */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Dibuja (void)
{
	
	// TODO 6. INIT Z-BUFFER VALUE

	glClear(GL_DEPTH_BUFFER_BIT);
	glClear (GL_COLOR_BUFFER_BIT);
 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
	gluLookAt(ox, oy, oz, ix, iy, iz, 0, 1, 0);
	DibujaEscena ();

	// TODO 12. SWAP BUFFERS AS THE LAST STEP BEFORE SCREEN RENDERING

	//glFlush();
	glutSwapBuffers();
	
}

void IniciaOpenGL(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); /* Establece el color de borrado */
	
	
	// TODO 4. ENABLE THE Z-BUFFER ALGORITHM IN OPENGL

	glEnable(GL_DEPTH_TEST);

	// TODO 5. WE MUST SPECIFY WHICH DEPTH COMPARISON WE PREFFER FOR THE ALGORITHM

	glDepthFunc(GL_LEQUAL);

	// TODO 8. ENABLE DELETION OF BACK FACES. BY DEFAULT DELETES BACK FACES

	glEnable(GL_CULL_FACE);

	// TODO 9. What happens?????

	// TODO 10. Three options

	// TODO 10.1. SET IN OPENGL THAT WE ARE GOING TO DELETE THE FRONT FACES

	//glCullFace(GL_FRONT);

	// TODO 10.2 DEFINE THAT THE FRONT FACE OF THE POLYGONS  IS DEFINED IN CLOCKWISE ORDER

	//glFrontFace(GL_CW);
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


	IniciaOpenGL();

	/* Rutinas para el control de eventos */
    IniciaFuncionesCallback ();

	/* Crea las display list de cada cuadrica */
	IniciaDisplayLists ();

	printf ("Modo = WALK\r");
	
	/* A la espera de eventos.... */
	glutMainLoop();

	return (0);
}


