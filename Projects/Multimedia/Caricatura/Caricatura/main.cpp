#include <glut.h>
#include <math.h>

const float PI = 3.14159265358;

void init(void)
{
	/*  select clearing (background) color*/
	glClearColor(1, 1, 1, 1);
	/*  initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50, 50, -50, 50, -50, 50);
	
}

void glColorInt(int r, int g, int b){
	float fr = r / 255.0, fg = g / 255.0, fb = b / 255.0;
	glColor3f(fr,fg,fb);
}

void circulo(float ex, float ey, float tx, float ty, float total = 200, bool invert = false) {
	float x, y;
	glBegin(GL_POLYGON);
	if (!invert)
	{
		for (int i = 0; i < total; i++)	{
			x = /*Multiplicacion para escalar*/ex*cos(i * 2 * PI / 50/*Numero de lados*/) + tx/*sumar para trasladar*/;
			y = /*Multiplicacion para escalar*/ey*sin(i * 2 * PI / 50/*Numero de lados*/) + ty/*sumar para trasladar*/;
			glVertex2f(x, y);
		}
	}
	else{
		for (int i = total*1.5; i > total; i--)	{
			x = /*Multiplicacion para escalar*/ex*cos(i * 2 * PI / 50/*Numero de lados*/) + tx/*sumar para trasladar*/;
			y = /*Multiplicacion para escalar*/ey*sin(i * 2 * PI / 50/*Numero de lados*/) + ty/*sumar para trasladar*/;
			glVertex2f(x, y);
		}
	}
	glEnd();
}

void circuloMargen(float ex, float ey, float tx, float ty) {
	float x, y;glBegin(GL_POINTS);
	for (float i = 0; i < 200; i++)
	{
		x = /*Multiplicacion para escalar*/ex*cos(i * 2 * PI / 150/*Numero de lados*/) + tx/*sumar para trasladar*/;
		y = /*Multiplicacion para escalar*/ey*sin(i * 2 * PI / 150/*Numero de lados*/) + ty/*sumar para trasladar*/;
		glVertex2f(x, y);
	}
	glEnd();
}

void display(void){
	//auxs
	float x = 0, y = 0, x1=0;
	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);
	/*  draw white polygon (rectangle) with corners at
	*  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/
	glPointSize(10.0f);

	///cuerpo   
	glColor3f(0.1f, 1.0f, 0.0f);
	x = -2.7f; y = -6.5f;
	while (x >= -6.0f){
		y -= 1.0f;
		x -= 0.24f;
		circulo(3,3, x, y);
	}
	///brazo izquierdo   
	//glColor3f(0.1, 1, 0);
	x = -1.0f; y = -6.5f;
	while (x <= 7){
		y -= 0.5f;
		x += 1.3f;
		circulo(1.5f, 1.2f, x, y);
	}
	/////-----------------
	x = 8.5f; y = -10.0f;
	while (x >= -1){
		y += 0.8f;
		x -= 0.8f;
		circulo(1, 1, x, y);
	}

	///brazo derecho   
	//glColor3f(0.1, 1, 0);
	x = -5.0f; y = -6.5f;
	while (x >= -12){
		y -= 0.3f;
		x -= 0.5f;
		circulo(1.5f, 1.2f, x, y);
	}
	//------------------
	x = -12.0f; y = -11.5f;
	while (x <= -6){
		y -= 0.5f;
		x += 0.5f;
		circulo(1.5f, 1.2f, x, y);
	}
	//mano
	glColorInt(206, 56, 236);
	circulo(2,3,1,-2,200);
	glColor3f(1,1, 1);
	glBegin(GL_LINES);
	glVertex2f(-1,-1);
	glVertex2f(1,-3);

	glVertex2f(0, 0);
	glVertex2f(2, -2);

	glVertex2f(1, 1);
	glVertex2f(3, -1);

	glEnd();
	glColor3f(0, 0, 0);
	///pompa
	glBegin(GL_POLYGON);
	glVertex2f(-9.5, -21);
	glVertex2f(-3, -21);
	glVertex2f(-3,  -28);
	glVertex2f(-9.5,-28);
	glEnd();
	circulo(4.2,4.2,-6,-25);

	//pie izquierdo
	glBegin(GL_POLYGON);
	glVertex2f(-4.5, -21);
	glVertex2f(4, -35);
	glVertex2f(-2.5, -35);
	glEnd();
	//pie derecho
	glBegin(GL_POLYGON);
	glVertex2f(-7, -21);
	glVertex2f(-4.5, -21);
	glVertex2f(-3, -35);
	glVertex2f(-10.5, -35);
	glEnd();
	/*glBegin(GL_POLYGON);*/
	glColorInt(206,56,236);
	///cara   
	glBegin(GL_POLYGON);
	glVertex2f(-5,9);
	glVertex2f(1, 1);
	glVertex2f(-5, -6);
	glEnd();
	///boca   
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(3, 7);
	glVertex2f(-3, -1);
	glVertex2f(3, 1);
	glEnd();
	///nariz  
	glColorInt(206, 56, 236);
	x = 5.0f; y = 2.0f;
	while (x >= -2){
		y += 0.13;
		x -= 0.2;
		circulo(1.3, 1.3, x, y);
	}
	///////////////
	circulo(2, 2.2, -4,  8);
	circulo(2, 2.2, -2, 9);
	glColor3f(1,1,1);
	glPointSize(0.6f);
	circulo(1.7, 1.9, -1.6, 9);
	glColor3f(0, 0, 0);
	circuloMargen(1.7, 1.9, -1.6, 9);
	glColor3f(1, 1, 1);
	circulo(1.7, 1.9, -3.1, 8);
	glColorInt(19, 98, 32);
	circuloMargen(1.7, 1.9, -3.1, 8);

	//cejas
	glColor3f(0, 0, 0);
	circulo(2.5, 2.8, -6.2, 10.3, 35,true);
	circulo(2, 1.8, -2.6, 11.2, 26);
	//linea saliente de la cabeza (pelo)
	glBegin(GL_POINTS);
	x1 = 2;
	for (float i = 0; i < 210; i++)
	{
		x = /*Multiplicacion para escalar*/x1*cos(i * 2 * PI / 150/*Numero de lados*/) + 18.2/*sumar para trasladar*/;
		y = /*Multiplicacion para escalar*/x1*sin(i * 2 * PI / 150/*Numero de lados*/) + -10.3/*sumar para trasladar*/;
		glVertex2f(y,x);
		x1 += 0.015;
	}
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-7,14);
	glVertex2f(-6,8);
	glEnd();
	//ojos negros
	circulo(0.5, 0.5, -.6, 9);
	circulo(0.5, 0.5, -2.1, 8);
	circuloMargen(0.5, 0.5, -.6, 9);
	circuloMargen(0.5, 0.5, -2.1, 8);

	//mano
	glColorInt(206, 56, 236);
	circulo(2, 3, -4, -20, 200);
	glColor3f(0, 0, 0);

	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(-5, -19);
	glVertex2f(-6, -21.7);

	glVertex2f(-4, -19);
	glVertex2f(-5, -22.7);

	glVertex2f(-3, -19);
	glVertex2f(-4, -22.7);

	glEnd();
	//moño
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-1.7, -4);
	glVertex2f(-4.7, -9);
	glVertex2f(-4.7, -4);

	glVertex2f(-1.7, -9);


	glEnd();
	glTranslatef(0,10,0);
	glFlush();

}

int main(){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(850, 50);
	glutCreateWindow("Dibujo  - Joaquin Ramrirez Martinez SOFTN_06_02, Matricula 1431110027");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}