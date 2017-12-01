/*************************************************************************/
/*                                                                       */
/*   modelado.h                                                          */
/*   Rev. 2.0  01/01/2002   AUTORES: O. Belmonte, M. Chover, J. Ribelles */
/*                                                                       */
/*************************************************************************/

#ifndef MODELADO_H
#define MODELADO_H

#include <gl/glut.h>

/* Identificadores de las display lists */
GLuint escena;


/* Funciones de modelado */
/* Crea las distintas display lists */
void IniciaDisplayLists (void);

/* Dibuja la escena */
void DibujaEscena (void);

/*  Crea una display list para toda la escena */
void CreaEscena(void);



#endif
