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



void TamanyoVentana (GLsizei ancho, GLsizei alto)
{
	
    glViewport(0, 0, ancho, alto);  
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (45.0, (GLdouble)alto/(GLdouble)ancho, 0.0, 400.0);
	
	
}


void AbreVentana (int numeroArgumentos, char ** listaArgumentos)
{
	glutInit(&numeroArgumentos, listaArgumentos);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
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
		case GLUT_KEY_UP : 
			alfa = alfa + 15;
			if (alfa > 360) alfa -= 360;
			break;

		case GLUT_KEY_DOWN : 
				alfa = alfa - 15;
				if (alfa < 0) alfa += 360;
				break;

		case GLUT_KEY_RIGHT : 
			beta = beta + 15;
			if (beta > 360) beta -= 360;
			break;

		case GLUT_KEY_LEFT : 
			beta = beta - 15;
			if (beta < 0) beta += 360;
			break;
	}
	glutPostRedisplay ();
}


void IniciaFuncionesCallback (void)
{
	glutSpecialFunc (TecladoAmpliado);
}


void Dibuja (void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
	gluLookAt(ox, oy, oz, ix, iy, iz, 0, 1, 0);

	glPushMatrix();
		glRotatef(beta, 0.f, 1.f, 0.f);
		glRotatef(alfa, 1.f, 0.f, 0.f);
		DibujaEscena ();
	glPopMatrix();

	glutSwapBuffers();
}

// TODO 02: BODY OF "IniciaLuces" FUNCTION
void IniciaLuces(void)
{

	// IN OPENGL THE LIGHT OF A SCENE COMES FROM SEVERAL SOURCES: SOME DIRECTIONAL, SOME SCATTERED (SE HAN DISPERSADO) AND AN AMBIENT ONE
	// Example: A BULB PRODUCES TWO KIND OF LIGHTS: THE LIGHT THAT COMES FROM THE BULB, AND THE LIGHT THAT COMES FROM THE WALLS AFTER BOUNCE 



	// TODO 04: DEFINE A NEW LIGHT WITH THREE PROPERTIES: POSITION, AMBIENTE COLOR AND DIFFUSE COLOR

	// WE CREATE A POSITIONAL LIGHT SOURCE: EMITS LIGHT FROM A PARTICULAR LOCATION IN ALL DIRECTIONS

	/*
	NOTE: The fourth value of the vector used as GL_POSITION(called 'w') is very important.
	If w == 0 the light is DIRECTIONAL. If w != 0 the light is POSITIONAL.

	+ POSITIONAL: the light received by an object depends on the position of the light source
	+ DIRECTIONAL: the light received by an object is independent of the position of the light.

	*/

	// TODO 04.1: DEFINE POSTITION OF THE LIGHT SOURCE
	GLfloat light_position[] = { 2.f, 2.f, -7.f, 1.f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	// TODO 04.2 USE YELLOW AS THE DIFFUSE COLOR: COLOR WHERE LIGHT HIT DIRECTLY THE OBJECT SURFACE
	GLfloat diffuse_color[] = { 1.f, 1.f, 0.f, 1.f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_color);

	// TODO 04.3 USE RED AS AMBIENT COLOR: COLOR APPLIED TO EVERYWHERE
	GLfloat ambient_color[] = { 1.f, 0.f, 0.f, 1.f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_color);

	// TODO 11: DEFINE A SPOT LIGHT (LIGHT1), A PARTICULAR POSITIONAL LIGHT SOURCE
	GLfloat spot_position[] = { 0.f, 0.f, 0.f, 1.f };
	GLfloat spot_diffusse[] = { 1.f, 1.f, 1.f, 1.f };
	glLightfv(GL_LIGHT1, GL_POSITION, spot_position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, spot_diffusse);
	// THE RAY EMISSION IS RESTRICTED TO A CONE AREA

	// TODO 11.1. DEFINE COMMON LIGHT PROPERTIES: POSITION, DIFFUSE, NO AMBIENT

	// TODO 11.2 DEFINE LIGHT PROPERTIES SPECIFIC OF SPOT LIGHTS: direction, cutoff, exponent

	// SPOT DIRECTION: THE EMISSION CONE CENTER
	GLfloat spot_direction[] = { 0.5f, 1.f, -10.f };
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
	// SPOT CUTOFF: ANGLE OF THE EMISSION CONE 0 -180
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 8.f);
	// SPOT EXPONENT: THE CONCENTRATION OF THE LIGHT 0 - 90
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 90);
}

void IniciaOpenGL(void)
{
	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glShadeModel(GL_SMOOTH);

	// TODO 03: ENABLE LIGHTNING. WHAT DOES IT HAPPEN?
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	// TODO 05: ENABLE LIGHT 0
	glEnable(GL_LIGHT0);
	// TODO 12: ENABLE LIGHT 1
	glEnable(GL_LIGHT1);
	// TODO 13: DISABLE LIGHT 1

	
}


/******************************************************************************************/
/* Funcion principal                                                                      */
/* Parametros: int numeroArgumentos --> El numero de argumentos en la llamada al programa */
/*             char ** listaArgumentos --> Vector de cadenas con cada argumento           */
/* Salida: Un entero que se devuelve al sistema al acabar la ejecucion del programa       */
/******************************************************************************************/
int main(int numArgumentos, char ** listaArgumentos)
{	
	AbreVentana (numArgumentos, listaArgumentos);

	// TODO 03: CALL "IniciaLuces" IN ORDER TO INITIALIZE THE DIFFERENT LIGHTS
	IniciaLuces();

	IniciaOpenGL();

    IniciaFuncionesCallback ();

	IniciaDisplayLists ();

	glutMainLoop();

	return (0);
}


