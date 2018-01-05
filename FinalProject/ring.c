
#include "glut.h"
#include <math.h>
#include <stdio.h>
#include "glig.h"
#include "ring.h"

#define PI 3.1415926535897932

void ringBase(void)
{
	glPushMatrix();
		glScalef(3.5, 0.5, 3.5);
		glColor3f(0.0, 0.0, 1.0, 1.0);
		igSolidCubo();
	glPopMatrix();
}

void ringPosts(void)
{
	glPushMatrix();
		glTranslatef(1.70, 0.60, 1.70);
		glScalef(0.1, 0.7, 0.1);
		glColor3f(1.0, 0.0, 0.0, 1.0);
		igSolidCubo();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.70, 0.60, 1.70);
		glScalef(0.1, 0.7, 0.1);
		glColor3f(1.0, 0.0, 0.0, 1.0);
		igSolidCubo();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.70, 0.60, -1.70);
		glScalef(0.1, 0.7, 0.1);
		glColor3f(1.0, 0.0, 0.0, 1.0);
		igSolidCubo();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.70, 0.60, -1.70);
		glScalef(0.1, 0.7, 0.1);
		glColor3f(1.0, 0.0, 0.0, 1.0);
		igSolidCubo();
	glPopMatrix();
}

void ringCornerPads(void)
{
	glPushMatrix();
		glTranslatef(1.5, 0.6875, 1.5);
			glScalef(0.1, 0.525, 0.1);
			glRotatef(-45.0, 0.0, 1.0, 0.0);
			glColor3f(0.0, 1.0, 0.0, 1.0);
		igSolidCubo();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.5, 0.6875, 1.5);
		glScalef(0.1, 0.525, 0.1);
		glRotatef(-45.0, 0.0, 1.0, 0.0);
		glColor3f(0.0, 1.0, 0.0, 1.0);
		igSolidCubo();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.5, 0.6875, -1.5);
		glScalef(0.1, 0.525, 0.1);
		glRotatef(-45.0, 0.0, 1.0, 0.0);
		glColor3f(0.0, 1.0, 0.0, 1.0);
		igSolidCubo();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.5, 0.6875, -1.5);
		glScalef(0.1, 0.525, 0.1);
		glRotatef(-45.0, 0.0, 1.0, 0.0);
		glColor3f(0.0, 1.0, 0.0, 1.0);
		igSolidCubo();
	glPopMatrix();
}

void ringTurnbuckles(void)
{
	
}

void ringRopes(void)
{
	float y_pos = 0.435;

	//front
	for(int i = 0; i < 4; i++) 
	{
		glPushMatrix();
			glTranslatef(-1.5, y_pos, 1.5);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glColor3f(1.0, 1.0, 1.0, 1.0);
			igSolidCilynder(0.01, 3.0);
		glPopMatrix();

		y_pos += 0.165;
	}

	//back
	y_pos = 0.435;

	for (int i = 0; i < 4; i++)
	{
		glPushMatrix();
		glTranslatef(-1.5, y_pos, -1.5);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glColor3f(1.0, 1.0, 1.0, 1.0);
		igSolidCilynder(0.01, 3.0);
		glPopMatrix();

		y_pos += 0.165;
	}

	//right
	y_pos = 0.435;

	for (int i = 0; i < 4; i++)
	{
		glPushMatrix();
		glTranslatef(1.5, y_pos, -1.5);
		glColor3f(1.0, 1.0, 1.0, 1.0);
		igSolidCilynder(0.01, 3.0);
		glPopMatrix();

		y_pos += 0.165;
	}

	//left
	y_pos = 0.435;

	for (int i = 0; i < 4; i++)
	{
		glPushMatrix();
		glTranslatef(-1.5, y_pos, -1.5);
		glColor3f(1.0, 1.0, 1.0, 1.0);
		igSolidCilynder(0.01, 3.0);
		glPopMatrix();

		y_pos += 0.165;
	}
}