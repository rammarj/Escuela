#include <glut.h>
#include <math.h>


void init(void)
{
	/*  select clearing (background) color       */
	glClearColor(0.5, 0.25, 0.25, 0.0);
	/*  initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
}

void circulo() {
	float x, y;
	const float PI = 3.1416;
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (float i = 0; i < 200; i++)
	{
		x = /*Multiplicacion para escalar*/cos(i * 2 * PI / 4/*Numero de lados*/)/*sumar para trasladar*/;
		y = /*Multiplicacion para escalar*/sin(i * 2 * PI / 4/*Numero de lados*/)/*sumar para trasladar*/;
		glVertex2f(x,y);
	}
	glEnd();
	glFlush();
}

void display(void){
	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);
	/*  draw white polygon (rectangle) with corners at
	*  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/
	glPointSize(10.0f);
	/*glBegin(GL_POLYGON);*/	
	circulo();
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