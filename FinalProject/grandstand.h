#ifndef GRANDSTAND_H
#define GRANDSTAND_H

#include "glut.h"

GLuint pgrandstands, gseats;

void grandstandStep(float p0[3], float p1[3], float p2[3], float p3[3], float p4[3], float p5[3], float p6[3], float p7[3]);
void stadiumGrandstands(void);
void placeGrandstands(void);
void seat(void);
void grandstandSeats(void);
#endif