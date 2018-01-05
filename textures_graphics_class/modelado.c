/*************************************************************************/
/*                                                                       */
/*   modelado.c                                                          */
/*   Rev. 2.0  01/01/2002   AUTORES: O. Belmonte, M. Chover, J. Ribelles */
/*                                                                       */
/*************************************************************************/

/***************** INCLUDES DE LAS LIBRERIAS NECESARIAS ******************/

#include "glut.h"
#include "glig.h"
#include "textura.h"
#include "modelado.h"




/******************************************************************************************/
/* Crea la display list para la escena                                                    */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/


// 17 ...... TODO 17: CREATE ANOTHER SOLID CUBE. APPLY ONE TEXTURE TO EACH CUBE ........17 

void CreaEscenaIluminacion(void)
{
	escena = glGenLists (1);

	if (escena != 0)
	{
		glNewList (escena, GL_COMPILE);
		/*
		glPushMatrix();
		glScalef(1.5f, 1.5f, 1.5f);
		igSolidCube();
		glPopMatrix();
		*/

		glPushMatrix();
			glTranslatef(1.f, 0.f, 0.f);
			glScalef(1.5f, 1.5f, 1.5f);
			applyTexture(0);
			igSolidCube();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-1.5f, 0.f, 0.f);
			glScalef(1.5f, 1.5f, 1.5f);
			applyTexture(1);
			igSolidCube();
		glPopMatrix();
		glEndList ();
	}
}