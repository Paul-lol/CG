/*******************************************************
 * Homework 2: OpenGL                                  *
 *-----------------------------------------------------*
 * First, you should fill in problem1(), problem2(),   *
 * and problem3() as instructed in the written part of *
 * the problem set.  Then, express your creativity     *
 * with problem4()!                                    *
 *                                                     *
 * Note: you will only need to add/modify code where   *
 * it says "TODO".                                     *
 *                                                     *
 * The left mouse button rotates, the right mouse      *
 * button zooms, and the keyboard controls which       *
 * problem to display.                                 *
 *                                                     *
 * For Linux/OS X:                                     *
 * To compile your program, just type "make" at the    *
 * command line.  Typing "make clean" will remove all  *
 * computer-generated files.  Run by typing "./hw2"    *
 *                                                     *
 * For Visual Studio:                                  *
 * You can create a project with this main.cpp and     *
 * build and run the executable as you normally would. *
 *******************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = { 0,1,4,1 };
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 1; // TODO: change this number to try different examples

float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };

void problem1() {
	// TODO: Your code here!
	glPushMatrix();
	glTranslatef(1.0f, 0.0f, 0.0f);
	glutSolidTeapot(0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.9f, 0.5f, 0.0f);
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	glutSolidTeapot(0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5f, 0.8660254f, 0.0f);
	glRotatef(60.0f, 0.0f, 0.0f, 1.0f);
	glutSolidTeapot(0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5f, 0.8660254f, 0.0f);
	glRotatef(120.0f, 0.0f, 0.0f, 1.0f);
	glutSolidTeapot(0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.8660254f, 0.5f, 0.0f);
	glRotatef(150.0f, 0.0f, 0.0f, 1.0f);
	glutSolidTeapot(0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0f, 0.0f, 0.0f);
	glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
	glutSolidTeapot(0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.8660254f, -0.5f, 0.0f);
	glRotatef(210.0f, 0.0f, 0.0f, 1.0f);
	glutSolidTeapot(0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5f,-0.8660254f, 0.0f);
	glRotatef(240.0f, 0.0f, 0.0f, 1.0f);
	glutSolidTeapot(0.2);
	glPopMatrix();


	glPushMatrix();
	glTranslatef( 0.5f, -0.8660254f, 0.0f);
	glRotatef(300.0f, 0.0f, 0.0f, 1.0f);
	glutSolidTeapot(0.2);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.8660254f, -0.5f, 0.0f);
	glRotatef(330.0f, 0.0f, 0.0f, 1.0f);
	glutSolidTeapot(0.2);
	glPopMatrix();
	
}

void problem2() {
	// TODO: Your code here!
	float trans = -1.4f;
	float height = 0.0f;
	while (trans < 1.5f) {
		glPushMatrix();
		glTranslatef(trans, height/7, 1.0f);
		glScalef(1.0, height, 0.0);
		glutSolidCube(0.3);
		glPopMatrix();
		trans += 0.2f;
		height += 0.2f;
	}
	
}

void problem3() {
	// TODO: Your code here!
	int rows = 6;
	float trans = 1.3f;
	float start = 0.0f;
	for (int i = 0; i < rows; i++)
	{

		float spacing = 0.0f;
		for(int j=0; j<=i; j++)
		{
			if (j == 0) {
				glPushMatrix();
				glTranslatef(start, trans, 0.0f);
				glutSolidTeapot(0.3);
				glPopMatrix();
				
			}
			else {
				glPushMatrix();
				glTranslatef(spacing+start, trans, 0.0f);
				glutSolidTeapot(0.3);
				glPopMatrix();
			}
			spacing += 1.0f;
		}
		trans -= 0.6f;
		start -= 0.5f;
	}
}

void problem4() {
	// TODO: Your code here!
	glPushMatrix();
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 0.3f);
	glVertex2f(0.5f, 0.0f);
	glEnd();
	glFlush();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 0.3f);
	glVertex2f(-0.5f, 0.0f);
	glEnd();
	glFlush();
	glPopMatrix();

	//Nested glPushMatrix() function
	glPushMatrix();
	glutSolidCube(0.5);
	glPushMatrix();
	glTranslatef(0.0f, 0.47f, 0.0f);
	glutSolidSphere(0.2, 100, 20);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.068f, -0.3f, 0.0f);
	glRotatef(-90.0, 0.0f, 0.0f, 1.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 0.15);
	glVertex2f(0.4, 0.15);
	glVertex2f(0.6, 0.15);
	glVertex2f(0.4, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.2f, -0.3f, 0.0f);
	glRotatef(-90.0, 0.0f, 0.0f, 1.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 0.15);
	glVertex2f(0.4, 0.15);
	glVertex2f(0.6, 0.0);
	glVertex2f(0.4, 0.0);
	glEnd();
	glPopMatrix();


}

void display() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0); // x axis
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 1, 0); // y axis
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, windowWidth, windowHeight);

	float ratio = (float)windowWidth / (float)windowHeight;
	gluPerspective(50, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot, 0, 1, 0);

	if (curProblem == 1) problem1();
	if (curProblem == 2) problem2();
	if (curProblem == 3) problem3();
	if (curProblem == 4) problem4();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown) yRot += (x - lastPos[0]) * .1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1, (y - lastPos[1]) * .1);
	}


	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	curProblem = key - '0';
	if (key == 'q' || key == 'Q' || key == 27) {
		exit(0);
	}
	glutPostRedisplay();
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}
