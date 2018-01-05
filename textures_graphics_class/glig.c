/*************************************************************************/
/*                                                                       */
/*                 glig.c LIBRERIA DE MODELADO GEOMETRICO	             */
/*                                                                       */
/*   Rev. 2.0  01/01/2002   AUTORES: O. Belmonte, M. Chover, J. Ribelles */
/*                                                                       */
/*************************************************************************/

/***************** INCLUDES DE LAS LIBRERIAS NECESARIAS ******************/

#include "glut.h"
#include <math.h>
#include <stdio.h>
#include "glig.h"

#define PI 3.1415926535897932
#define ALFA (0.5-v)*PI
#define BETA 2*PI*u
#define E 0.001
#define F 0.002



// 2..... TODO 02 ............ADD TEXTURES COORDINATES to GEOMETRY .............2

/*
 *
 *	WE NEED PAIR THE GEOMETRY VERTICES WITH THE TEXTURES ENDPOINTS
 *  EACH TEXTURE HAS TWO COORDINATES:
 *	+ S: HOTIZONTAL AXIS
 *  + T: VERTICAL AXIS
 *
 *		 (0, 1) +-----------------+ (1, 1)
 *				|				  |
 *				|				  |
 *				|				  |
 *				|				  |
 *				|				  |
 *				|				  |
 *		 (0, 0) +-----------------+ (1, 0)
 */


void igSolidCube (void)
{
	
	float p0[] = { -0.5f, -0.5f, 0.5f };
	float p1[] = { 0.5f, -0.5f, 0.5f };
	float p2[] = { 0.5f, 0.5f, 0.5f };
	float p3[] = { -0.5f, 0.5f, 0.5f };
	float p4[] = { -0.5f, -0.5f, -0.5f };
	float p5[] = { 0.5f, -0.5f, -0.5f };
	float p6[] = { 0.5f, 0.5f, -0.5f };
	float p7[] = { -0.5f, 0.5f, -0.5f };

	// 11...... TODO 11 ............... TEXTURES ARE SHOW UPSIDE DOWN, WHAT CAN WE DO? .................11

	// 12...... TODO 12 ............... CHANGE ST COORDINATES IN ORDER TO TRY THE REPEAT WRAPPING ......12

	glBegin(GL_QUADS);
		
		// Front

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2d(0, 0);
		glVertex3fv(p0);
		glTexCoord2d(-1, 0);
		glVertex3fv(p1);
		glTexCoord2d(-1, -1);
		glVertex3fv(p2);
		glTexCoord2d(0, -1);
		glVertex3fv(p3);

		// Back

		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2d(0, 0);
		glVertex3fv(p5);
		glTexCoord2d(-1, 0);
		glVertex3fv(p4);
		glTexCoord2d(-1, -1);
		glVertex3fv(p7);
		glTexCoord2d(0, -1);
		glVertex3fv(p6);

		// Left

		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2d(0, 0);
		glVertex3fv(p4);
		glTexCoord2d(-1, 0);
		glVertex3fv(p0);
		glTexCoord2d(-1, -1);
		glVertex3fv(p3);
		glTexCoord2d(0, -1);
		glVertex3fv(p7);
		
		// Right

		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2d(0, 0);
		glVertex3fv(p1);
		glTexCoord2d(-1, 0);
		glVertex3fv(p5);
		glTexCoord2d(-1, -1);
		glVertex3fv(p6);
		glTexCoord2d(0, -1);
		glVertex3fv(p2);

		// Top

		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2d(0, 0);
		glVertex3fv(p3);
		glTexCoord2d(-1, 0);
		glVertex3fv(p2);
		glTexCoord2d(-1, -1);
		glVertex3fv(p6);
		glTexCoord2d(0, -1);
		glVertex3fv(p7);

		// Bottom

		glNormal3f(0.0f, -1.0f, 0.0f);
		glTexCoord2d(0, 0);
		glVertex3fv(p4);
		glTexCoord2d(-1, 0);
		glVertex3fv(p5);
		glTexCoord2d(-1, -1);
		glVertex3fv(p1);
		glTexCoord2d(0, -1);
		glVertex3fv(p0);

	glEnd();

}