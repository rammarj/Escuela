// OpenGLHolaMundo.cpp : main project file.

#include <stdio.h>
#include <stdlib.h>
#include <glut.h>
/**do not use*/
void drawQuad(float tam){
	glBegin(GL_POLYGON);
	glVertex2f(-tam, tam);
	glVertex2f(tam, tam);
	glVertex2f(tam, -tam);
	glVertex2f(-tam, -tam);
	glEnd();
}
/**do not use*/
void drawRomboide(float tamx, float tamy){
	glBegin(GL_POLYGON);
	glVertex2f(-tamx/2, tamy/2);
	glVertex2f(0, tamy);
	glVertex2f(tamx/2, tamy/2);
	glVertex2f(0, 0);
	glEnd();
}
/**do not use*/
void drawLine(float x1, float y1, float x2, float y2){
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}
/**para los cuadros rojos grandes*/
void drawDecoratedQuad(float mayor = 1.0f, float menor=0.3f, float tras=0.5f){
	glColor3f(1,0,0);
	drawQuad(mayor);
	glColor3f(1, 1, 1);
	//cuadros interiores
	glTranslatef(-tras, tras, 0);
	drawQuad(menor);
	glTranslatef(tras, -tras, 0);

	glTranslatef(tras, -tras, 0);
	drawQuad(menor);
	glTranslatef(-tras, tras, 0);

	glTranslatef(-tras, -tras, 0);
	drawQuad(menor);
	glTranslatef(tras, tras, 0);

	glTranslatef(tras, tras, 0);
	drawQuad(menor);
	glTranslatef(-tras, -tras, 0);

	//diagonales
	drawLine(1,1,-1,-1);
	drawLine(-1, 1, 1, -1);
}
/**para los cuadros cafes*/
void drawRotatedQuad( bool horizontal = true, float tam = 1){
	if (horizontal)
		glRotatef(45, 0, 0, 1);
	else
		glRotatef(-45, 0, 0, 1);
	glColor3f(0.64, 0.16, 0.16);
	drawQuad(tam);
	glColor3f(1, 1, 1);
	drawQuad(tam-0.3);
	drawLine(-1,1,1,-1);
	glRotatef(-0.45f, 0.0f, 0.0f, 0);
	if (horizontal)
		glRotatef(-45, 0, 0, 1);
	else
		glRotatef(45, 0, 0, 1);
}

void drawStar(){
	float sw = 0.75, rw = 0.3;
	glColor3f(1, 0.5, 0);
	glRotatef(-45, 0, 0, 1);
	drawQuad(sw);
	glRotatef(45, 0, 0, 1);
	drawQuad(sw);

	glColor3f(1, 0, 0);
	for (int i = 60; i < 360; i += 47*2)
	{
		glRotatef(-i, 0, 0, 1);
		drawRomboide(0.35, .85);
		glRotatef(i, 0, 0, 1);
	}
	///////////cuadrado del centro
	glColor3f(1, 0.5, 0);
	glRotatef(-60, 0, 0, 1);
	drawQuad(0.4);
	glRotatef(60, 0, 0, 1);
	//////////////
	glColor3f(1, 0, 0);
	for (int i = 15; i < 360; i+=47*2)
	{
		glRotatef(-i, 0, 0, 1);
		drawRomboide(0.35, 0.85);
		glRotatef(i, 0, 0, 1);
	}


	
}

void drawQuadsLine(float x, float y, int num = 2){
	int incx = 2, incy=0;
	for (int i = 0; i < num; i++)
	{
		glTranslatef(x+incy, y, 0);
		drawRotatedQuad(false, 0.6);
		glTranslatef(-(x+incy), -y, 0);
		glTranslatef(x+incx, y, 0);
		drawDecoratedQuad();
		glTranslatef(-(x + incx), y, 0);
		incx += 4;
		incy += 4;
	}

}

void drawQuadStarsLine(float x, float y, int num = 2){
	int incx = 2, incy = 0;
	for (int i = 0; i < num; i++)
	{
		glTranslatef(x + incy, y, 0);
		drawRotatedQuad(true, 0.6);
		glTranslatef(-(x + incy), -y, 0);
		glTranslatef(x + incx, y, 0);
		drawStar();
		glTranslatef(-(x + incx), y, 0);
		incx += 4;
		incy += 4;
	}

}

void display(void)
{	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);
	/*  draw white polygon (rectangle) with corners at
	*  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/	
	glPointSize(10.0f);
	//pantalla
	//drawDecoratedQuad();
	//drawRotatedQuad(1,false);
	glTranslatef(-2.1,-6.5,0);
	float y = 4, x = 2.1;
	for (size_t i = 0; i < 6; i++)
	{
		glTranslatef(0, y, 0);
		drawQuadsLine(-8, 0, 10);
		glTranslatef(0, -y, 0);
		glTranslatef(-2, x, 0);
		drawQuadStarsLine(-8, 0, 10);
		glTranslatef(2, -x, 0);
		y +=3.9;
		x += 3.9;
	}


	glFlush();
}

void init(void)
{
	/*  select clearing (background) color       */
	glClearColor(.95, .95, .95, .95);
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
	glutCreateWindow("Mosaico - Joaquin Ramrirez Martinez SOFTN_06_02, Matricula 1431110027");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;   /* ISO C requires main to return int. */
}
