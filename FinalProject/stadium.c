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
		glPushMatrix();
			glColor3f(1.0f, 1.0f, 0.0f, 1.0f);
			glTranslatef(0.0f, 5.75f, 27.25f);
			glScalef(52.5f, 4.0f, 2.0f);
			igSolidCubo();
		glPopMatrix();
		//back
		glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f, 1.0f);
			glTranslatef(0.0f, 3.75f, -23.75f);
			glScalef(42.5f, 8.0f, 5.0f);
			igSolidCubo();
		glPopMatrix();
		glPushMatrix();
			glColor3f(1.0f, 1.0f, 0.0f, 1.0f);
			glTranslatef(0.0f, 5.75f, -27.25f);
			glScalef(52.5f, 4.0f, 2.0f);
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
		glPushMatrix();
			glColor3f(1.0f, 1.0f, 0.0f, 1.0f);
			glTranslatef(27.25f, 5.75f, 0.0f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			glScalef(56.5f, 4.0f, 2.0f);
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
		glPushMatrix();
			glColor3f(1.0f, 1.0f, 0.0f, 1.0f);
			glTranslatef(-27.25f, 5.75f, 0.0f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			glScalef(56.5f, 4.0f, 2.0f);
			igSolidCubo();
		glPopMatrix();

		glEndList();
	}

}

void cornerColumns(void)
{
	glPushMatrix();
		glTranslatef(-27.20f, 1.75f, 27.20f);
		glScalef(1.0f, 2.0f, 1.0f);
		glColor3f(0.0f, 1.0f, 0.0f, 1.0f);
		igSolidCilynder2(10, 10);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(27.20f, 1.75f, 27.20f);
		glScalef(1.0f, 2.0f, 1.0f);
		glColor3f(0.0f, 1.0f, 0.0f, 1.0f);
		igSolidCilynder2(10, 10);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-27.20f, 1.75f, -27.20f);
		glScalef(1.0f, 2.0f, 1.0f);
		glColor3f(0.0f, 1.0f, 0.0f, 1.0f);
		igSolidCilynder2(10, 10);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(27.20f, 1.75f, -27.20f);
		glScalef(1.0f, 2.0f, 1.0f);
		glColor3f(0.0f, 1.0f, 0.0f, 1.0f);
		igSolidCilynder2(10, 10);
	glPopMatrix();
}

void stadiumColumns(void)
{
	columns = glGenLists(1);
	if (columns != 0)
	{
		glNewList(columns, GL_COMPILE);

		//corner columns
		cornerColumns();

		float pos = -25.25;
		float max = 25.25;

		//front
		while (pos <= max) 
		{
			if (pos < -7.72 || pos > 7.72)
			{
				
				glPushMatrix();
				glTranslatef(pos, 1.75f, 27.25f);
				glScalef(0.5f, 2.0f, 0.5f);
				glColor3f(0.0f, 1.0f, 0.0f, 1.0f);
				igSolidCilynder2(10, 10);
				glPopMatrix();
			}

			pos += 2.0;
		}

		//back
		pos = -25.25;

		while (pos <= max)
		{
			if (pos < -7.72 || pos > 7.72)
			{

				glPushMatrix();
				glTranslatef(pos, 1.75f, -27.25f);
				glScalef(0.5f, 2.0f, 0.5f);
				glColor3f(0.0f, 1.0f, 0.0f, 1.0f);
				igSolidCilynder2(10, 10);
				glPopMatrix();
			}

			pos += 2.0;
		}

		//right
		pos = -25.25;

		while (pos <= max)
		{
			if (pos < -7.72 || pos > 7.72)
			{

				glPushMatrix();
				glTranslatef(27.25f, 1.75f, pos);
				glScalef(0.5f, 2.0f, 0.5f);
				glColor3f(0.0f, 1.0f, 0.0f, 1.0f);
				igSolidCilynder2(10, 10);
				glPopMatrix();
			}

			pos += 2.0;
		}

		//left
		pos = -25.25;

		while (pos <= max)
		{
			if (pos < -7.72 || pos > 7.72)
			{

				glPushMatrix();
				glTranslatef(-27.25f, 1.75f, pos);
				glScalef(0.5f, 2.0f, 0.5f);
				glColor3f(0.0f, 1.0f, 0.0f, 1.0f);
				igSolidCilynder2(10, 10);
				glPopMatrix();
			}

			pos += 2.0;
		}

		glEndList();
	}
}