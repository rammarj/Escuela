#include <glut.h>
#include <math.h>


void init(void)
{
	/*  select clearing (background) color       */
	glClearColor(0.5, 0.25, 0.25, 0.0);
	/*  initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-25.0, 25.0, -25.0, 25.0, -25.0, 25.0);
}

void circulo(float px, float py, float tx, float ty) {
	float x, y;
	const float PI = 3.1416;
	glBegin(GL_POLYGON);
	for (float i = 0; i < 200; i++)
	{
		x = tx*cos(i * 2 * PI /*Numero de lados*/)+px;
		y = ty*sin(i * 2 * PI /*Numero de lados*/)+py;
		glVertex2f(x,y);
	}
	glEnd();
}

void cuerpo(){
	//glTranslatef(1,3,1);//translate
	glColor3f(0.5, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-3, 8);
	glVertex2f(-2, 9.5);
	glVertex2f(0, 11);
	glVertex2f(1.2, 11.5);
	glVertex2f(3.5, 11.2);
	glVertex2f(6, 9.8);
	glVertex2f(6.8, 7.7);
	glVertex2f(6.4, 6);
	glVertex2f(6, 0);
	glVertex2f(6.1, -2);
	glVertex2f(7.3, -4);
	glVertex2f(6, -6);
	glVertex2f(6, -8);
	glVertex2f(7, -11);
	glVertex2f(7.8, -12.5);
	glVertex2f(7.3, -15.1);
	glVertex2f(9.5, -14.7);
	glVertex2f(10, -13);
	glVertex2f(10.5, -13.5);
	glVertex2f(11, -15);
	glVertex2f(8.2, -17);
	glVertex2f(6, -18.1);
	glVertex2f(4.4, -18.1);
	glVertex2f(3, -17.4);
	glVertex2f(1.5, -16);
	glVertex2f(0, -16);
	glVertex2f(-1.2, -16.7);
	glVertex2f(-3, -15.4);
	glVertex2f(-4.2, -13);
	glVertex2f(-4.1, -11.3);
	glVertex2f(-2, -7.2);
	glVertex2f(-5, -9);
	glVertex2f(-6.1, -10.5);
	glVertex2f(-7.5, -9.5);
	glVertex2f(-7.8, -7.8);
	glVertex2f(-7.6, -3.5);
	glVertex2f(-7.5, -2.7);
	glVertex2f(-7.5, -1.6);
	glVertex2f(-6.5, -3);
	glVertex2f(-5.5, -2.5);
	glVertex2f(-3.8, -4.7);
	glVertex2f(-4.5, -4.5);
	glVertex2f(-4.5, -6.5);
	glVertex2f(-5.5, -7.7);
	glVertex2f(0, -2);
	glVertex2f(1.5, 0);
	glVertex2f(0.8, 4);
	glVertex2f(-2, 5.1);
	glVertex2f(-3, 8);
	glEnd();
}

void display(void){
	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);
	/*  draw white polygon (rectangle) with corners at
	*  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/
	glPointSize(10.0f);
	//cuerpo
	cuerpo();
	//ojos
	//glColor3f(0.5, 1, 1);
		//glTranslatef(8,8,1);
	circulo(3.5, 6.5, 1080, 1080); //nosa le /dll secuestrado!!!/


	glFlush();
}

int main(){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(850, 50);
	glutCreateWindow("Nombre: Joaquin Ramirez Martinez;Matrincula: 1431110027;Fecha: 07/07/2016");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}