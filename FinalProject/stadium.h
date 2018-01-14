#ifndef STADIUM_H
#define STADIUM_H

#include "glut.h"

GLuint sfloor, walls, columns, outsidedoors;
void stadiumFloor(void);
void stadiumWalls(void);
void stadiumColumns(void);
void cornerColumns(void);
void outsideDoors(void);
void door(void);
#endif