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
				 /*  Código para dibujar el abeto */
				 /*  Primero dibujo del eje */
			
	   			glEndList ();  
 			}  


}


void CreaAbeto (void)
{
     abeto=glGenLists(1);  
	if (abeto !=0) /* Cero no es un identificador valido para una display list */
		{  
	  			glNewList(abeto, GL_COMPILE);  
				 /*  Código para dibujar el abeto */
				 /*  Primero dibujo la copa */
				igWireCone(50, 50);
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glPushMatrix();
					glTransla
	   			glEndList ();  
 			}  
}


