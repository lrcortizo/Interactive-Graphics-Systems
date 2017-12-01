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



// TODO 07: DEFINE NORMALS FOR CUBE


	void igSolidCubo(void)  /* s1 y s2 a 1 */
	{

		float p0[3] = { -0.5f, -0.5f, -0.5f };
		float p1[3] = { -0.5f, 0.5f, -0.5f };
		float p2[3] = { 0.5f, 0.5f, -0.5f };
		float p3[3] = { 0.5f, -0.5f, -0.5f };
		float p4[3] = { -0.5f, -0.5f, 0.5f };
		float p5[3] = { -0.5f, 0.5f, 0.5f };
		float p6[3] = { 0.5f, 0.5f, 0.5f };
		float p7[3] = { 0.5f, -0.5f, 0.5f };

		glBegin(GL_QUAD_STRIP);
		
		
		glVertex3fv(p0);
		glVertex3fv(p1);
		glVertex3fv(p3);
		glVertex3fv(p2);
		glVertex3fv(p7);
		glVertex3fv(p6);
		glVertex3fv(p4);
		glVertex3fv(p5);
		glVertex3fv(p0);
		glVertex3fv(p1);
		
		glEnd();

		
		glBegin(GL_QUADS);

		// Top

		glNormal3fv(p1);
		glVertex3fv(p1);
		glNormal3fv(p5);
		glVertex3fv(p5);
		glNormal3fv(p6);
		glVertex3fv(p6);
		glNormal3fv(p2);
		glVertex3fv(p2);
		

		//Bottom

		glNormal3fv(p3);
		glVertex3fv(p3);
		glNormal3fv(p7);
		glVertex3fv(p7);
		glNormal3fv(p4);
		glVertex3fv(p4);
		glNormal3fv(p0);
		glVertex3fv(p0);
		

		glEnd();
		

	}

	// TODO 08: COMPLETE A NEW FUNCTION CALLED "igSolidCubo_2" THAT CREATES A SOLID CUBE WITH NORMALS PER FACE 
