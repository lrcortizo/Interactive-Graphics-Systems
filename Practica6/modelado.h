/*************************************************************************/
/*                                                                       */
/*   modelado.h                                                          */
/*   Rev. 27/10/03   AUTORES: C.Rebollo
/*                                                                       */
/*************************************************************************/

#ifndef MODELADO_H
#define MODELADO_H

#include "glut.h"


/* Identificadores de las display list */
GLuint abeto,escalera,abetoPush;

/* Definici�n Funciones de modelado */
void IniciaDisplayLists (void);
void CreaAbeto(void);
void CreaAbetoPush(void);
void CreaEscalera(void);

#endif