
#include "glut.h"
#include <math.h>
#include <stdio.h>
#include "glig.h"


 	void igWireCubo (int pu, int pv)  /* s1 y s2 a 1 */
 	{
		
		float p0[3]={-0.5f, -0.5f, 0.5f};
		float p1[3]={-0.5f, 0.5f, 0.5f};
		float p2[3]={0.5f, 0.5f, 0.5f};
		float p3[3]={0.5f, -0.5f, 0.5f};
		float p4[3]={-0.5f, -0.5f, -0.5f};
		float p5[3]={-0.5f, 0.5f, -0.5f};
		float p6[3]={0.5f, 0.5f, -0.5f};
		float p7[3]={0.5f, -0.5f, -0.5f};


		glBegin (GL_LINE_STRIP);
			glVertex3fv(p0);
			glVertex3fv(p1);
			glVertex3fv(p2);
			glVertex3fv(p3);
			glVertex3fv(p0);
			glVertex3fv(p4);
			glVertex3fv(p5);
			glVertex3fv(p6);
			glVertex3fv(p7);
			glVertex3fv(p4);
		glEnd();

		glBegin (GL_LINE_STRIP);
			glVertex3fv(p1);
			glVertex3fv(p5);
		glEnd();

		glBegin (GL_LINE_STRIP);
			glVertex3fv(p2);
			glVertex3fv(p6);
		glEnd();

		glBegin (GL_LINE_STRIP);
			glVertex3fv(p3);
			glVertex3fv(p7);
		glEnd();
	} 

	
	// TODO 1. DEFINE A SOLID PLANE "igSolidPlane"
	void igSolidPlane(void)
	{
		float p0[3] = { -0.5f, -0.5f, 0.0f };
		float p1[3] = { -0.5f, 0.5f, 0.0f };
		float p2[3] = { 0.5f, -0.5f, 0.0f };
		float p3[3] = { 0.5f, 0.5f, 0.0f };

		glBegin(GL_TRIANGLE_STRIP);
			glVertex3fv(p2);
			glVertex3fv(p3);
			glVertex3fv(p0);
			glVertex3fv(p1);
		glEnd();
	}

	// TODO 10.3 DEFINE A SOLID PLANE "igSolidPlaneCCW" WITH COUNTER-CLOCKWISE VERTICES
