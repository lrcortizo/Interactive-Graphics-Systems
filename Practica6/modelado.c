/*************************************************************************/
/*                                                                       */
/*   modelado.c                                                          */
/*   27/10/03  AUTORES: C.Rebollo                                        */
/*                                                                       */
/*************************************************************************/

/***************** INCLUDES DE LAS LIBRERIAS NECESARIAS ******************/
#include "glig.h"
#include "modelado.h"


/******************************************************************************************/
/* Crea los distintos objetos. En este caso iun abeto, si tuviese mas objetos, los pòndría*/
/* a continuación.                                                                        */
/* Parametros: ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void IniciaDisplayLists (void)
{
    CreaAbeto ();
	CreaAbetoPush();
	CreaEscalera();
}

/******************************************************************************************/
/* Crea una display list para dibujar un abeto                                            */
/* Parametros: ninguno */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/

void CreaEscalera() {
	escalera=glGenLists(1);  
	if (escalera !=0) /* Cero no es un identificador valido para una display list */
		{  
	  			glNewList(escalera, GL_COMPILE); 
					glPushMatrix();
						glScalef(0.2, 2.0, 0.2);
						igWireCubo(1, 1);
					glPopMatrix();
					for (int i = 0; i <= 10; i++) {
						glPushMatrix();
							glTranslatef(0.35, -0.975, 0.0);
							glScalef(0.5, 0.05, 0.1);
							igWireCubo(1,1);
						glPopMatrix();
					}
	   			glEndList ();  
 			}  


}

void CreaAbeto(void)
{
	abeto = glGenLists(1);
	if (abeto != 0) 
	{

		glNewList(abeto, GL_COMPILE);
			glColor3f(0, 0, 1);
			glScalef(0.75, 1.0, 0.75);
			igWireCone(10, 10);
			glTranslatef(0.0, 0.25, 0.0);
			glScalef(0.75, 1.0, 0.75);
			igWireCone(10, 10);
			glTranslatef(0.0, 0.25, 0.0);
			glScalef(0.75, 1.0, 0.75);
			igWireCone(10, 10);
			glScalef(0.1, 1.0, 0.1);
			igWireRulo(10, 10);
		glEndList();
	}
}

void CreaAbetoPush (void)
{
	abetoPush = glGenLists(1);
	if (abetoPush != 0) /* Cero no es un identificador valido para una display list */
	{
		glNewList(abetoPush, GL_COMPILE);
		glColor3f(1, 0, 0);
			glPushMatrix();
				glTranslatef(0.0, 0.5, 0.0);
				glScalef(0.42, 1.0, 0.42);
				igWireCone(10, 10);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0, 0.25, 0.0);
				glScalef(0.56, 1.0, 0.56);
				igWireCone(10, 10);
			glPopMatrix();
			glPushMatrix();
				glScalef(0.75, 1.0, 0.75);
				igWireCone(10, 10);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0, 0.5, 0.0);
				glScalef(0.042, 1.0, 0.042);
				igWireRulo(10, 10);
			glPopMatrix();
		glEndList();
	}
}


