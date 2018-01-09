#include "glut.h"
#include "glig.h"
#include "luces.h"
#include "stadium.h"


void stadiumFloor(void)
{
	sfloor = glGenLists(1);
	if (sfloor != 0)
	{
		glNewList(sfloor, GL_COMPILE);
		glBegin(GL_QUADS);
			glColor3f(1.0f, 1.0f, 1.0f, 1.0f);
			glNormal3f(21.25f, -0.25f, 21.25f);
			glVertex3f(21.25f, -0.25f, 21.25f);
			glNormal3f(-21.25f, -0.25f, 21.25f);
			glVertex3f(-21.25f, -0.25f, 21.25f);
			glNormal3f(-21.25f, -0.25f, -21.25f);
			glVertex3f(-21.25f, -0.25f, -21.25f);
			glNormal3f(21.25f, -0.25f, -21.25f);
			glVertex3f(21.25f, -0.25f, -21.25f);
		glEnd();
		glEndList();
	}
}

void stadiumWalls(void)
{
	walls = glGenLists(1);
	if (walls != 0)
	{
		glNewList(walls, GL_COMPILE);
		glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f, 1.0f);
			glTranslatef(0.0f, 4.0f, 21.25f);
			glScalef(42.5f, 8.0f, 0.5f);
			igSolidCubo();
		glPopMatrix();
		glEndList();
	}
}