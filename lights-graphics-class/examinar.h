#ifndef EXAMINAR_H
#define EXAMINAR_H

/* Funcion de conversion de grados a radianes */
#define  grad2rad(x)  ((float) (3.14159 * x) / 180.0)
#define PASO 0.5 /* Definicion del paso para el movimiento del observador */

/* Variables Globales del modulo */
int VentanaAncho = 500, VentanaAlto = 500; /* Tamanyo de la ventana */
int VentanaX = 100, VentanaY = 100; /* Posicion de la ventana */
GLdouble  alfa = 0.0, beta = 0.0, gamma=0.0, z=0.0;
GLuint cuadrica;
double ox=0.0, oy=0.0, oz= 35*PASO; /* Posicion del observador */
double ix=0.0, iy=0.0, iz= 34*PASO; /* Posicion del punto de interes */
int w=1, a=1;


void AbreVentana (int numeroArgumentos, char ** listaArgumentos);
void Dibuja(void);
void TamanyoVentana (GLsizei alto, GLsizei ancho);
void IniciaFuncionesCallback (void);
void IniciaOpenGL(void);

// TODO 01: DEFINE HEADER OF A FUNCTION CALLED "IniciaLuces" WHERE WE ARE GOING TO INITIALIZE OPENGL LIGHTNING
void IniciaLuces(void);

#endif
