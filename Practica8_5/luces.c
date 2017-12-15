/*************************************************************************/
/*                                                                       */
/*   luces.c		                                                     */
/*   Rev. 2.0  01/01/2002   AUTORES: O. Belmonte, M. Chover, J. Ribelles */
/*                                                                       */
/*************************************************************************/

/***************** INCLUDES DE LAS LIBRERIAS NECESARIAS ******************/

#include "glut.h"


/********************** RUTINA DE INICIO *************************/
/******************************************************************************************/
/* Inicia los parametros de iluminacion de OpenGL                                         */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void IniciaLuces(void)
{	
	//GLfloat lmodel_ambient [] = {0.4f, 0.4f, 0.4f, 1.0f};

	/* Par�metros del modelo de iluminaci�n */

	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	/* Activa la iluminaci�n de la escena */

	glEnable(GL_LIGHTING);	
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHT0);

}


/*********************** DEFINICION DE LUCES ****************************/

/******************************************************************************************/
/* Define y activa la luz 0                                                               */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Luz0 (void)
{

}

/******************************************************************************************/
/* Define y activa la luz 1                                                               */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Luz1 (void)
{
}

/******************************************************************************************/
/* Define y activa la luz 2                                                               */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Luz2 (void)
{
}

/******************************************************************************************/
/* Define y activa la niebla                                                              */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Niebla (void)
{
}