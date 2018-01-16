#include <glut.h>
#include <math.h>


void init(void)
{
	/*  select clearing (background) color       */
	glClearColor(0.5, 0.25, 0.25, 0.0);
	/*  initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.5, 10.5, -10.5, 10.5, -10.5, 10.5);
}

void petalo(){
	float PI = 3.1416;
	float x, y;
	float azul = 0;
	glBegin(GL_POLYGON);
	for (double i = 0; i < 100; i++)
	{
		x = -.5 + -.3*cos(i*(2)*PI / 100);
		y = -.3 + -.6*sin(i*(2)*PI / 100);
		glColor3f(0, 0, azul);
		glVertex2f(x, y);
		azul += 0.01;
	}
	glEnd();
}

void flor(){

}

void barda(){
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(0, 0);
	glVertex2f(0.5, 0);
	glVertex2f(0.5, 0.5);
	glVertex2f(0, 0.5);
	glEnd();
}

void mbarda(){
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(0, 0);
	glVertex2f(2, 0);
	glVertex2f(2, 2);
	glVertex2f(0, 2);
	glEnd();
}

void display(void){
	float y = 0;
	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);
	/*  draw white polygon (rectangle) with corners at
	*  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/
	glPointSize(10.0f);
	/*glBegin(GL_POLYGON);*/
	//glTranslatef(.5,.5,0);
	/*for (size_t i = 0; i < 10; i++)
	{
		petalo();
		glRotated(-35, 0, 0, 1);
		glTranslated(0, -.3, 0);

	}*/
	glTranslatef(-2.5, -.5, 0);
	for (size_t j = 0; j < 2; j++)
	{
		for (size_t i = 0; i < 6; i++)
		{
			barda();
			glTranslatef(.6, 0, 0);
		}
		glTranslatef(-3.3, 0.6, 0);
	}
	mbarda();
	//glTranslatef(-0.6, -.01, 0);

	glTranslatef(-0.6, -.01, 0);
	for (size_t j = 0; j < 2; j++)
	{
		for (size_t i = 0; i < 6; i++)
		{
			barda();
			glTranslatef(.6, 0, 0);

		}
		glTranslatef(-3.3, 0.6, 0);
	}


	glTranslatef(-0.6, -.01, 0);
	for (size_t j = 0; j < 2; j++)
	{
		for (size_t i = 0; i < 6; i++)
		{
			barda();
			glTranslatef(.6, 0, 0);

		}
		glTranslatef(-3.3, 0.6, 0);
	}


	glFlush();
}



int main(){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(850, 50);
	glutCreateWindow("Crculo");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}