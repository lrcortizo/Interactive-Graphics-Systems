
#include "glut.h"
#include <math.h>
#include <stdio.h>
#include "glig.h"
#include "ring.h"

void ringBase(void)
{
	base = glGenLists(1);
	if (base != 0) 
	{
		glNewList(base, GL_COMPILE);
		glPushMatrix();
			glScalef(3.5, 0.5, 3.5);
			glColor3f(0.0, 0.0, 1.0, 1.0);
			igSolidCubo();
			glPopMatrix();
		glEndList();
	}
}

void ringPosts(void)
{
	posts = glGenLists(1);
	if (posts != 0)
	{
		glNewList(posts, GL_COMPILE);

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
			glTranslatef(-1.70, 0.60, -1.70);
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

		glEndList();
	}

}

void ringCornerPads(void)
{
	corner_pads = glGenLists(1);
	if (corner_pads != 0)
	{
		glNewList(corner_pads, GL_COMPILE);

		glPushMatrix();
			glTranslatef(1.5, 0.6875, 1.5);
				glScalef(0.1, 0.525, 0.1);
				glRotatef(45.0, 0.0, 1.0, 0.0);
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
		glTranslatef(-1.5, 0.6875, -1.5);
			glScalef(0.1, 0.525, 0.1);
			glRotatef(-135.0, 0.0, 1.0, 0.0);
			glColor3f(0.0, 1.0, 0.0, 1.0);
			igSolidCubo();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1.5, 0.6875, -1.5);
			glScalef(0.1, 0.525, 0.1);
			glRotatef(135.0, 0.0, 1.0, 0.0);
			glColor3f(0.0, 1.0, 0.0, 1.0);
			igSolidCubo();
		glPopMatrix();

		glEndList();
	}
}

void ringTurnbuckles(void)
{
	float y_pos = 0.435;
	turnbuckles = glGenLists(1);
	if (turnbuckles != 0)
	{
		glNewList(turnbuckles, GL_COMPILE);

		for (int i = 0; i < 4; i++)
		{
			glPushMatrix();
				glTranslatef(1.5, y_pos, 1.5);
				glRotatef(45.0, 0.0, 1.0, 0.0);
				glColor3f(1.0f, 1.0f, 0.0f, 1.0f);
				igSolidCilynder(0.01, 0.25);
			glPopMatrix();

			y_pos += 0.165;
		}

		y_pos = 0.435;

		for (int i = 0; i < 4; i++)
		{
			glPushMatrix();
				glTranslatef(-1.5, y_pos, 1.5);
				glRotatef(-45.0, 0.0, 1.0, 0.0);
				glColor3f(1.0, 1.0, 0.0, 1.0);
				igSolidCilynder(0.01, 0.25);
			glPopMatrix();

			y_pos += 0.165;
		}

		y_pos = 0.435;

		for (int i = 0; i < 4; i++)
		{
			glPushMatrix();
				glTranslatef(-1.5, y_pos, -1.5);
				glRotatef(-135.0, 0.0, 1.0, 0.0);
				glColor3f(1.0, 1.0, 0.0, 1.0);
				igSolidCilynder(0.01, 0.25);
			glPopMatrix();

			y_pos += 0.165;
		}

		y_pos = 0.435;

		for (int i = 0; i < 4; i++)
		{
			glPushMatrix();
				glTranslatef(1.5, y_pos, -1.5);
				glRotatef(135.0, 0.0, 1.0, 0.0);
				glColor3f(1.0, 1.0, 0.0, 1.0);
				igSolidCilynder(0.01, 0.25);
			glPopMatrix();

			y_pos += 0.165;
		}
		glEndList();
	}
}

void ringRopes(void)
{
	float y_pos = 0.435;
	ropes = glGenLists(1);
	if (ropes != 0)
	{
		glNewList(ropes, GL_COMPILE);

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
		glEndList();
	}
}