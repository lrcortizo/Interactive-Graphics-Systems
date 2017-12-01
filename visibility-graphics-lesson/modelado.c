
#include <stdio.h>
#include "glig.h"
#include "modelado.h"


/******************************************************************************************/
/* Crea las distintas display lists                                                       */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void IniciaDisplayLists (void)
{

	CreaEscena ();
}


/******************************************************************************************/
/* Dibuja la escena                                                                       */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void DibujaEscena (void)
{
	
	glCallList (escena);
}


/******************************************************************************************/
/*  Crea una display list para toda la escena                                             */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CreaEscena(void)
{
	escena = glGenLists (1);

	if (escena != 0)
	{
		glNewList (escena, GL_COMPILE);

		//igWireCubo(10, 10);

		// TODO 2. Create two solid planes. One green in -4 z position and one blue in -3 in z position
		
		//Plano azul
		glPushMatrix();
			igSolidPlane();
			glColor3f(0.0f, 0.0f, 1.0f);
			glTranslatef(0.0f, 0.0f, -4.0f);
			//glRotatef(180, 0.0f, 1.0f, 0.0f);
		glPopMatrix();

		//Plano verde
		glPushMatrix();
			igSolidPlane();
			glColor3f(0.0f, 1.0f, 0.0f);
			glTranslatef(0.0f, 0.0f, -3.0f);
		glPopMatrix();


		// Now the rendering is based in the order of the instructions. Try to render the quads in inverse order.
		// ¿What's happening?
		
		// TODO 7. EACH POLYGON HAS TWO FACES. ROTATE THE BLUE PLANE IN ORDER TO PROBE THIS AND SEE THE OTHER SIDE. AFTER THAT
		// DELETE THE ROTATION OPERATION
		
		// TODO 10.3 USE A PLANE WITH COUNTER-CLOCKWISE VERTICES

		glEndList();
		
	}
	else puts ("Se ha producido un error creando la display list de la escena.");
}
