#include <glut.h>
#include <math.h>


void init(void)
{
	/*  select clearing (background) color       */
	glClearColor(0.5, 0.25, 0.25, 0.0);
	/*  initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}

void circulo(float sx=1, float sy=1) 
{
	float x, y;
	const float PI = 3.1416;
	glBegin(GL_POLYGON);
	for (float i = 0; i < 200; i++)
	{
		x = sx*/*Multiplicacion para escalar*/cos(i * 2 * PI/60/*Numero de lados*/)/*sumar para trasladar*/;
		y = sy*/*Multiplicacion para escalar*/sin(i * 2 * PI/60/*Numero de lados*/)/*sumar para trasladar*/;
		glVertex2f(x,y);
	}
	glEnd();
}

void cuadrado(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y, float p4x, float p4y)
{
	glBegin(GL_POLYGON);
	glVertex2f(p1x, p1y);
	glVertex2f(p2x, p2y);
	glVertex2f(p3x, p3y);
	glVertex2f(p4x, p4y);
	glEnd();
}

void triangulo(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y)
{
	glBegin(GL_POLYGON);
	glVertex2f(p1x, p1y);
	glVertex2f(p2x, p2y);
	glVertex2f(p3x, p3y);
	glEnd();
}

void circuloMargen(float ex, float ey) {
	const float PI = 3.1416;
	float x, y; glBegin(GL_POINTS);
	for (float i = 0; i < 200; i++)
	{
		x = /*Multiplicacion para escalar*/ex*cos(i * 2 * PI / 150/*Numero de lados*/)/*sumar para trasladar*/;
		y = /*Multiplicacion para escalar*/ey*sin(i * 2 * PI / 150/*Numero de lados*/)/*sumar para trasladar*/;
		glVertex2f(x, y);
	}
	glEnd();
}

void display(void)
{
	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);
	/*  draw white polygon (rectangle) with corners at
	*  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/
	glPointSize(10.0f);
	
	//cabeza
	glColor3f(1, 1, 1);
	glTranslatef(0,3,0);
	circulo(3.5,2.8);
	glTranslatef(0, -3, 0);

	//circulo centro
	glTranslatef(0, 4, 0);
	glColor3f(0, 0, 1);
	circulo(1.4, 1.4);
	glTranslatef(0, -4, 0);

	////////////////////
	//zapatos
	glTranslatef(-1.2, -6.4, 0);
	glColor3f(0.35, 0.16, 0.14);
	circulo(1, .8);
	glTranslatef(1.2, 6.4, 0);


	glTranslatef(1.2, -6.4, 0);
	//glColor3f(0, 0, 0);
	circulo(1, .8);
	glTranslatef(-1.2, 6.4, 0);
	////////////////////////////////////////
	//cuerpo
	glColor3f(1, 0.802, 0.802);
	glTranslatef(0, -3.5, 0);
	circulo(2.6, 2.6);
	glTranslatef(0, 3.5, 0);

	//cara
	glTranslatef(0, .5, 0);
	glColor3f(1, 0.802, 1);
	circulo(1.7, 1.7);
	glColor3f(1, 1, 1);
	glTranslatef(0, -.6, 0);
	//
	glColor3f(1, 1, 1);
	glTranslatef(0, 1, 0);
	cuadrado(-2, 0,  2, 0,  2, 1.5,  -2, 1.5);
	glTranslatef(0, -1, 0);

	////////////////////
	//ojos
	
	//izquierdo
	glTranslatef(-.5, .5, 0);
	glColor3f(0, 0, 0);
	circulo(.2, .4);
	glTranslatef(.5, -.5, 0);

	//derecho
	glTranslatef(.5, .5, 0);
	//glColor3f(1, 0, 0);
	circulo(.2, .4);
	glTranslatef(-.5, -.5, 0);

	////////////////////////////////////////////
	//////pupilas
	//izquierdo
	glTranslatef(-.5, .7, 0);
	glColor3f(1, 1, 1);
	circulo(.1, .2);
	glTranslatef(.5, -.7, 0);

	//derecho
	glTranslatef(.5, .7, 0);
	//glColor3f(1, 0, 0);
	circulo(.1, .2);
	glTranslatef(-.5, -.7, 0);

	////////////////////BOCA////////////////////
	//NO IMPLEMENTADO
	//////////////////////////////////////////
	///chaleco
	//////////////////PARTE DORADA/////////////////
	//izquierdo
	glTranslatef(-1.7, -4, 0);
	glColor3f(.8, 0.498, .196);
	cuadrado(-1.5,0,   0,0,  .8,3.1,  -0.1,2.7);
	glTranslatef(1.7, 4, 0);
	
	//derecho
	glTranslatef(1.7, -4, 0);
	//glColor3f(1, 0, 1);
	cuadrado(1.5,0,   0,0,  -.8,3.1,  0.1,2.7);
	glTranslatef(-1.7, 4, 0);

	////////////////PARTE AZUL//////////////////

	//izquierdo
	glTranslatef(-2., -3.8, 0);
	glColor3f(0, 0, 1);
	cuadrado(-1.3,  0,0,  0,.6, 2.9, 0.1, 2.5);
	glTranslatef(2., 3.8, 0);

	//derecho
	glTranslatef(2, -3.8, 0);
	glColor3f(0, 0, 1);
	cuadrado(1.3, 0, 0, 0, -.6, 2.9, 0.1, 2.5);
	glTranslatef(-2, 3.8, 0);


	///escalar
	glScalef(1.5, 1.5, 0);


	glFlush();
}

int main(){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(850, 50);
	glutCreateWindow("Joaquin Ramirez Martinez; matricula: 1431110027;.... Examen de recuperacion 2do parcial.");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}