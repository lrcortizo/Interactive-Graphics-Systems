#include "glut.h"
#include "glig.h"
#include "luces.h"
#include "stadium.h"

void stadiumFloor(void)
{
	glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0, 1.0);
		glNormal3f(21.25f, -0.25f, 21.25f);
		glVertex3f(21.25f, -0.25f, 21.25f);
		glNormal3f(-21.25f, -0.25f, 21.25f);
		glVertex3f(-21.25f, -0.25f, 21.25f);
		glNormal3f(-21.25f, -0.25f, -21.25f);
		glVertex3f(-21.25f, -0.25f, -21.25f);
		glNormal3f(21.25f, -0.25f, -21.25f);
		glVertex3f(21.25f, -0.25f, -21.25f);
	glEnd();
}

void grandstandStep(float p0[3], float p1[3], float p2[3], float p3[3], float p4[3], float p5[3], float p6[3], float p7[3])
{
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0, 1.0);
	//BACK
	glNormal3f(0, 0, -1);
	glVertex3fv(p0);
	glVertex3fv(p1);
	glVertex3fv(p2);
	glVertex3fv(p3);

	//RIGHT
	glNormal3f(1, 0, 0);
	glVertex3fv(p3);
	glVertex3fv(p2);
	glVertex3fv(p6);
	glVertex3fv(p7);

	//LEFT
	glNormal3f(-1, 0, 0);
	glVertex3fv(p4);
	glVertex3fv(p5);
	glVertex3fv(p1);
	glVertex3fv(p0);

	//FRONT
	glNormal3f(0, 0, 1);
	glVertex3fv(p7);
	glVertex3fv(p6);
	glVertex3fv(p5);
	glVertex3fv(p4);

	//TOP
	glNormal3f(0, 1, 0);
	glVertex3fv(p1);
	glVertex3fv(p5);
	glVertex3fv(p6);
	glVertex3fv(p2);

	//BOTTOM
	glNormal3f(0, -1, 0);
	glVertex3fv(p3);
	glVertex3fv(p7);
	glVertex3fv(p4);
	glVertex3fv(p0);

	glEnd();
}

void stadiumGrandstands(void)
{
	float p0[3] = { -3.7f, -0.25f, -0.5f };
	float p1[3] = { -3.7f, -0.05f, -0.5f };
	float p2[3] = { 3.7f, -0.05f, -0.5f };
	float p3[3] = { 3.7f, -0.25f, -0.5f };
	float p4[3] = { -3.25f, -0.25f, 0.0f };
	float p5[3] = { -3.25f, -0.05f, 0.0f };
	float p6[3] = { 3.25f, -0.05f, 0.0f };
	float p7[3] = { 3.25f, -0.25f, 0.0f };

	for (int i = 1; i < 36; i++) 
	{
		grandstandStep(p0, p1, p2, p3, p4, p5, p6, p7);
		p0[0] -= 0.45;
		p0[2] -= 0.5;
		p1[0] -= 0.45;
		p1[1] += 0.2;
		p1[2] -= 0.5;
		p2[0] += 0.45;
		p2[1] += 0.2;
		p2[2] -= 0.5;
		p3[0] += 0.45;
		p3[2] -= 0.5;
		p4[0] -= 0.45;
		p4[2] -= 0.5;
		p5[0] -= 0.45;
		p5[1] += 0.2;
		p5[2] -= 0.5;
		p6[0] += 0.45;
		p6[1] += 0.2;
		p6[2] -= 0.5;
		p7[0] += 0.45;
		p7[2] -= 0.5;
	}
	
}

void placeGrandstands(void)
{
	//back
	glPushMatrix();
		glTranslatef(0.0, 0.0, -3.75);
		stadiumGrandstands();
	glPopMatrix();

	//front
	glPushMatrix();
		glTranslatef(0.0, 0.0, 3.75);
		glRotatef(180.0, 0.0, 1.0, 0.0);
		stadiumGrandstands();
	glPopMatrix();

	//right
	glPushMatrix();
		glTranslatef(3.75, 0.0, 0.0);
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		stadiumGrandstands();
	glPopMatrix();

	//left
	glPushMatrix();
	glTranslatef(-3.75, 0.0, 0.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	stadiumGrandstands();
	glPopMatrix();
}