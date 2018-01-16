
#include <stdio.h>
#include <stdlib.h>
#include <glut.h>

void glDrawQuad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4 ){
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
}

void glDrawLine(float x1, float y1, float x2, float y2){
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void display(void)
{	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);
	/*  draw white polygon (rectangle) with corners at
	*  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/	
	glPointSize(10.0f);
	//pantalla
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glDrawQuad(-4, 5.2, 5, 5.2, 5, 0.2, -4, 0.2);

	glColor3f(0.5 , 0.5, 1);
	glDrawQuad(-3.8, 5, 4.8, 5, 4.8, 0.4, -3.8, 0.4);
	//base
	glColor3f(0, 0, 0);
	glDrawQuad(-3.8, -0.5, 5.2, -0.5, 1.2, -5.5, -8, -5.5);
	//teclado
	glColor3f(1, 0, 0);
	glDrawQuad(-4, 0, 5, 0, 1, -5, -8, -5);

	glColor3f(0, 0, 0);
	glDrawQuad(-4, -0.5, 4.2, -0.5, 1.7, -3.5, -6.5, -3.5);
	//lineas de las teclas
	glColor3f(1, 1, 1);
	for (size_t i = 0; i < 16; i++)	
		glDrawLine((-4+i*0.5125), -0.5, (-6.5+i*0.5125),-3.5);

	for (size_t i = 0; i < 6; i++) 
		glDrawLine((-4 - i*0.44), (-0.5 - i*0.5), (4.25 - i*0.44), (-0.5 - i*0.5));
	
	//teclas adicionales
	//tecla de touch

	//horizontales
	glDrawLine(-4,-4.5, -2.2, -4.5);
	glDrawLine(-4.2, -4.7, -2.4, -4.7);                                           
	//verticales
	glDrawLine(-4, -4.5, -4.2, -4.7);
	glDrawLine(-2.2, -4.5, -2.4, -4.7);

	glDrawLine(-3.1, -4.5, -3.3, -4.7);

	//touchpad area touch
	//...... sin resolver todavia
	

	//btn apagado
	glColor3f(0.5, 0.5, 0.5);
	glDrawQuad(-3, -0.2, -2, -0.2, -2.2, -0.35, -3.2, -0.35);

	glFlush();
}

void init(void)
{
	/*  select clearing (background) color       */
	glClearColor(0.5, 0.25, 0.25, 0.0);
	/*  initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}

int main()
{
	//glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(850, 50);
	glutCreateWindow("Computadora - Joaquin Ramrirez Martinez SOFTN_06_02, Matricula 1431110027");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;   /* ISO C requires main to return int. */
}
