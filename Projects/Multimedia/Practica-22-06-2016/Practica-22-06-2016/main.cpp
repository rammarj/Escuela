#include <glut.h>
#include <math.h>

const float PI = 3.14159265358;

void init(void)
{
	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-30, 30, -30, 30, -30, 30);
}

void circulo2(float k, float h, float r, float n = 1){
	float alfa = 0,x,y;
	glBegin(GL_POLYGON);
	while (alfa < (2 * 3.14159265359/n)) {
		x = r*cos(alfa) + h;
		y = r*sin(alfa) + k;
		glVertex2f(x, y);
		alfa +=0.01;
	}
	glEnd();
}

void circulo(float ex, float ey, float tx, float ty, int n = 200) {
	float x, y; glBegin(GL_POLYGON);
	for (float i = 0; i < n; i++)
	{
		x = /*Multiplicacion para escalar*/ex*cos(i * 2 * PI / 150/*Numero de lados*/) + tx/*sumar para trasladar*/;
		y = /*Multiplicacion para escalar*/ey*sin(i * 2 * PI / 150/*Numero de lados*/) + ty/*sumar para trasladar*/;
		glVertex2f(x, y);
	}
	glEnd();
}

void cara(){
	//cuadrado
	glColor3f(0.73, 0.56, 0.56);
	glBegin(GL_POLYGON);
	glVertex2f(6.5,5.5);
	glVertex2f(-6,9);
	glVertex2f(-2.5,-6);
	glVertex2f(1.8,-6);
	glEnd();
	//circulo cara
	glTranslatef(0,1.7,0);
	glRotatef(50, 0, 0, 1);
	circulo(7,7,-1.7,1,100);
	glRotatef(-50, 0, 0, 1);
	glTranslatef(0, -1.7, 0);

	glColor3f(1,1,1);//color ojos
	glRotatef(-45,0,0,1);
	circulo(2.3,3,-5.6, -1);
	glRotatef(45, 0, 0, 1);
	
	glRotatef(-45, 0, 0, 1);
	circulo(2.3, 3, -2, 2.5);
	glRotatef(45, 0, 0, 1);

	//pupilas 
	glColor3f(0, 0, 0);
	glRotatef(-45, 0, 0, 1);
	circulo(1.4, 2, -4.6, -.8);
	glRotatef(45, 0, 0, 1);

	glRotatef(-45, 0, 0, 1);
	circulo(1.4, 2, -1.1, 2.8);
	glRotatef(45, 0, 0, 1);

	//pupilas centro
	glColor3f(1, 1, 1);
	glRotatef(-45, 0, 0, 1);
	circulo(0.9, 1.2, -4.6, -.8);
	glRotatef(45, 0, 0, 1);

	glRotatef(-45, 0, 0, 1);
	circulo(0.9, 1.2, -1.1, 2.8);
	glRotatef(45, 0, 0, 1);
	/////////////////////////////
	
	glColor3f(0, 1, 0);

	circulo2(8, -10, 10, 4);

}

void cabello(){

}

void cejas(){

}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10.0f);
	cara();
	glFlush();
}

int main(){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(850, 50);
	glutCreateWindow("Padrino magico  - Joaquin Ramrirez Martinez SOFTN_06_02, Matricula 1431110027");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}