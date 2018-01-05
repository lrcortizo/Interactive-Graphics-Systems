/*************************************************************************/
/*                                                                       */
/*                 glig.h LIBRERIA DE MODELADO GEOMETRICO	             */
/*                                                                       */
/*   Rev. 3.0  01/09/2012   Universidad Jaume I de Castellón             */
/*                                                                       */
/*************************************************************************/



#ifndef GLIG_H
#define GLIG_H
#define E 0.001
#define F 0.002

/* Devuelve la coordenada x de un punto en R3 a partir de un punto (u,v) */
float xSuperQuadric(float u, float v, float R, float s1, float s2);

/* Devuelve la coordenada y de un punto en R3 a partir de un punto (u,v) */
float ySuperQuadric(float u, float v, float R, float s1, float s2);

/* Devuelve la coordenada z de un punto en R3 a partir de un punto (u,v) */
float zSuperQuadric(float u, float v, float R, float s1, float s2);

float dxuSuperQuadric(float u, float v, float R, float s1, float s2);
float dyuSuperQuadric(float u, float v, float R, float s1, float s2);
float dzuSuperQuadric(float u, float v, float R, float s1, float s2);
float dxvSuperQuadric(float u, float v, float R, float s1, float s2);
float dyvSuperQuadric(float u, float v, float R, float s1, float s2);
float dzvSuperQuadric(float u, float v, float R, float s1, float s2);
float nxSuperQuadric(float u, float v, float R, float s1, float s2);
float nySuperQuadric(float u, float v, float R, float s1, float s2);
float nzSuperQuadric(float u, float v, float R, float s1, float s2);

void igCreateQuadricObject(int pu, int pv, float uMax, float vMax, float R, float s1, float s2);
void igWireCube(void);
void igWireCone(int pu, int pv);
void igWireRulo(int pu, int pv);
void Arco(void);

void igCreateSolidQuadricObject(int pu, int pv, float uMax, float vMax, float R, float s1, float s2);
void igSolidSphere(int pu, int pv); /* s1 y s2 a 1 */
void igSolidRulo(int pu, int pv); /* s1= 0.5, s2= 1 */
void igSolidDado(int pu, int pv); /* s1= 0.5, s2 =0.5 */
void igSolidSemiSphere(int pu, int pv); /* s1 y s2 a 1, uMax= 1, vMax= 0.5 */
void igSolidCone(int pu, int pv); /* s1= 2.0, s2= 1.0, uMax= 1.0, vMax= 0.5 */
void igSolidCubo(void);
void igSolidCilynder(GLfloat radius, GLfloat height);
void igSolidCubo_2(void);
#endif

