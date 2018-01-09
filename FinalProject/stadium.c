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
			glNormal3f(26.25f, -0.25f, 26.25f);
			glVertex3f(26.25f, -0.25f, 26.25f);
			glNormal3f(-26.25f, -0.25f, 26.25f);
			glVertex3f(-26.25f, -0.25f, 26.25f);
			glNormal3f(-26.25f, -0.25f, -26.25f);
			glVertex3f(-26.25f, -0.25f, -26.25f);
			glNormal3f(26.25f, -0.25f, -26.25f);
			glVertex3f(26.25f, -0.25f, -26.25f);
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
		//front
		glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f, 1.0f);
			glTranslatef(0.0f, 3.75f, 23.75f);
			glScalef(42.5f, 8.0f, 5.0f);
			igSolidCubo();
		glPopMatrix();
		//back
		glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f, 1.0f);
			glTranslatef(0.0f, 3.75f, -23.75f);
			glScalef(42.5f, 8.0f, 5.0f);
			igSolidCubo();
		glPopMatrix();
		//right
		glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f, 1.0f);
			glTranslatef(23.75f, 3.75f, 0.0f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			glScalef(52.5f, 8.0f, 5.0f);
			igSolidCubo();
		glPopMatrix();
		//left
		glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f, 1.0f);
			glTranslatef(-23.75f, 3.75f, 0.0f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			glScalef(52.5f, 8.0f, 5.0f);
			igSolidCubo();
		glPopMatrix();
		glEndList();
	}
}