// OpenGLHolaMundo.cpp : main project file.

#include <stdio.h>
#include <stdlib.h>
#include <glut.h>

void display(void)
{
	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);
	/*  draw white polygon (rectangle) with corners at
	*  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/

	/*  don�t wait!
	*  start processing buffered OpenGL routines
	*/
	
	glPointSize(10.0f);
	/*glBegin(GL_POLYGON);
	glColor3ub(0, 111, 0);
	glVertex2f(-3,3);
	glColor3ub(133, 2, 0);
	glVertex2f(-2.5,2.5);
	glVertex2f(-3.5, 2.5);
	glEnd();*/

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(-5, 5);
	glVertex2f(5, 5);
	glVertex2f(5, -5);
	glVertex2f(-5, -5);
	glEnd();
	//boca
	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex2f(-3, -2);
	glVertex2f(3, -2);	
	glEnd();
	//nariz
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex2f(0, 1);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glEnd();

	//ojo izq
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex2f(-4, 3);
	glVertex2f(-2, 3);
	glVertex2f(-2, 1);
	glVertex2f(-4, 1);
	glEnd();
	//ojo der
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex2f(4, 3);
	glVertex2f(2, 3);
	glVertex2f(2, 1);
	glVertex2f(4, 1);
	glEnd();
	//palitos
	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex2f(-3, -1);
	glVertex2f(-3, -3);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex2f(3, -1);
	glVertex2f(3, -3);
	glEnd();
	//palitos entre
	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex2f(-2, -1.5);
	glVertex2f(-2, -2.5);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex2f(-1, -1.5);
	glVertex2f(-1, -2.5);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex2f(0, -1.5);
	glVertex2f(0, -2.5);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex2f(1, -1.5);
	glVertex2f(1, -2.5);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex2f(2, -1.5);
	glVertex2f(2, -2.5);
	glEnd();

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
/*
*  Declare initial window size, position, and display mode
*  (single buffer and RGBA).  Open window with �hello�
*  in its title bar.  Call initialization routines.
*  Register callback function to display graphics.
*  Enter main loop and process events.
*/
int main()
{
	//glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(850, 50);
	glutCreateWindow("Hola Mundo");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;   /* ISO C requires main to return int. */
}