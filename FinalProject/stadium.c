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

void door(void)
{
	glPushMatrix();
		glScalef(1.0f, 1.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f, 1.0f);
		igSolidCubo();
	glPopMatrix();
	
	//lock
	glPushMatrix();
		glTranslatef(-0.4f, 0.0f, 0.01f);
		glScalef(0.04f, 0.15f, 0.02f);
		glColor3f(1.0f, 0.0f, 0.0f, 1.0f);
		igSolidCubo();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.4f, 0.0f, 0.0135f);
		glScalef(0.01f, 0.01f, 0.025f);
		glColor3f(1.0f, 0.0f, 0.0f, 1.0f);
		igSolidCubo();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.375f, 0.0f, 0.035f);
		glScalef(0.05f, 0.01f, 0.01f);
		glColor3f(1.0f, 0.0f, 0.0f, 1.0f);
		igSolidCubo();
	glPopMatrix();
}

void outsideDoors(void)
{
	outsidedoors = glGenLists(1);
	if (outsidedoors != 0)
	{
		glNewList(outsidedoors, GL_COMPILE);

		//front
		//doors
		float pos = -5.0;

		for (int i = 0; i < 3; i++)
		{
			glPushMatrix();
			glTranslatef(pos, 0.25f, 26.2775f);
			door();
			glPopMatrix();

			pos += 5.0;
		}

		//window
		glPushMatrix();
		glTranslatef(0.0f, 2.25f, 26.2775f);
		glScalef(12.5f, 1.0f, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f, 1.0f);
		igSolidCubo();
		glPopMatrix();

		//back
		//doors
		pos = -5.0;

		for (int i = 0; i < 3; i++)
		{
			glPushMatrix();
			glTranslatef(pos, 0.25f, -26.2775f);
			glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
			door();
			glPopMatrix();

			pos += 5.0;
		}

		//window
		glPushMatrix();
		glTranslatef(0.0f, 2.25f, -26.2775f);
		glScalef(12.5f, 1.0f, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f, 1.0f);
		igSolidCubo();
		glPopMatrix();

		//right
		//doors
		pos = -5.0;

		for (int i = 0; i < 3; i++)
		{
			glPushMatrix();
			glTranslatef(26.2775f, 0.25f, pos);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			door();
			glPopMatrix();

			pos += 5.0;
		}

		//window
		glPushMatrix();
		glTranslatef(26.2775f, 2.25f, 0.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(12.5f, 1.0f, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f, 1.0f);
		igSolidCubo();
		glPopMatrix();

		//left
		//doors
		pos = -5.0;

		for (int i = 0; i < 3; i++)
		{
			glPushMatrix();
			glTranslatef(-26.2775f, 0.25f, pos);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			door();
			glPopMatrix();

			pos += 5.0;
		}

		//window
		glPushMatrix();
		glTranslatef(-26.2775f, 2.25f, 0.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(12.5f, 1.0f, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f, 1.0f);
		igSolidCubo();
		glPopMatrix();

		glEndList();
	}
}

void insideDoors(void)
{
	insidedoors = glGenLists(1);
	if (insidedoors != 0)
	{
		glNewList(insidedoors, GL_COMPILE);

		//back
		glPushMatrix();
		glTranslatef(5.30f, 0.25f, -5.75);
		glRotatef(48.0f, 0.0f, 1.0f, 0.0f);
		door();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(10.70f, 0.25f, -11.75);
		glRotatef(48.0f, 0.0f, 1.0f, 0.0f);
		door();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-5.30f, 0.25f, -5.75);
		glRotatef(-48.0f, 0.0f, 1.0f, 0.0f);
		door();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10.70f, 0.25f, -11.75);
		glRotatef(-48.0f, 0.0f, 1.0f, 0.0f);
		door();
		glPopMatrix();

		//front
		glPushMatrix();
		glTranslatef(5.30f, 0.25f, 5.75);
		glRotatef(132.0f, 0.0f, 1.0f, 0.0f);
		door();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(10.70f, 0.25f, 11.75);
		glRotatef(132.0f, 0.0f, 1.0f, 0.0f);
		door();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-5.30f, 0.25f, 5.75);
		glRotatef(-132.0f, 0.0f, 1.0f, 0.0f);
		door();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10.70f, 0.25f, 11.75);
		glRotatef(-132.0, 0.0f, 1.0f, 0.0f);
		door();
		glPopMatrix();

		//left
		glPushMatrix();
		glTranslatef(-5.75f, 0.25f, 5.30);
		glRotatef(42.0f, 0.0f, 1.0f, 0.0f);
		door();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-11.75f, 0.25f, 10.70f);
		glRotatef(42.0f, 0.0f, 1.0f, 0.0f);
		door();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-5.75f, 0.25f, -5.30);
		glRotatef(138.0f, 0.0f, 1.0f, 0.0f);
		door();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-11.75f, 0.25f, -10.70f);
		glRotatef(138.0f, 0.0f, 1.0f, 0.0f);
		door();
		glPopMatrix();

		//right
		glPushMatrix();
		glTranslatef(5.75f, 0.25f, 5.30);
		glRotatef(-42.0f, 0.0f, 1.0f, 0.0f);
		door();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(11.75f, 0.25f, 10.70f);
		glRotatef(-42.0f, 0.0f, 1.0f, 0.0f);
		door();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(5.75f, 0.25f, -5.30);
		glRotatef(-138.0f, 0.0f, 1.0f, 0.0f);
		door();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(11.75f, 0.25f, -10.70f);
		glRotatef(-138.0f, 0.0f, 1.0f, 0.0f);
		door();
		glPopMatrix();

		glEndList();
	}
}