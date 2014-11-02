#include <iostream>
#include <stdlib.h>
//#include "objects.h"
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

void lecture();
void drawWall(float a, float b, float c, float d, float e);
void drawCycleWall(float a, float b, float c, float d, float e);
void drawCycleRoof(float a, float b, float c, float d, float e);
void stairs();
void drawHall(float a, float b, float c, float d);
void drawCap();

GLfloat d[3] = {0.0, 0.0, 0.0};
GLfloat  xAngle = 0.0, yAngle = 0.0, zAngle = 0.0;
//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {

       case 'a' : d[0] += 0.1;  break;
       case 'd' : d[0] -= 0.1;  break;
       case 'k' : d[1] += 0.1;  break;
       case 'w' : d[2] += 0.1;  break;
       case 'x' : d[2] -= 0.1;  break;

       case 'g' : xAngle += 2;  break;
       
       case 'q' : yAngle += 1;  break;
       case 'e' : yAngle -= 1;  break;
       
       case 'j' : zAngle += 2;  break;
 
       //default: printf ("   Keyboard %c == %d\n", key, key);
    }
glutPostRedisplay();
}

void drawCap()
{
	glPushMatrix();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -10.3f);
	glutWireSphere(1.95, 8, 8);
	glPopMatrix();

}

void drawWall(float a, float b, float c, float d, float e)
{
	glPushMatrix();
	glTranslatef(a, b, c);
	glScalef(e, 1.0f, 1.0f);
	glRotatef(d, 0.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -2.5f);
	glVertex3f(0.0f, 0.0f, 2.5f);
	glVertex3f(0.0f, 8.0f, 2.5f);
	glVertex3f(0.0f, 8.0f, -2.5f);
	glEnd();
	glBegin(GL_QUADS);
	glNormal3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 8.0f, 2.5f);
	glVertex3f(0.0f, 8.0f, -2.5f);
	glVertex3f(-2.0f, 10.0f, -2.0f);
	glVertex3f(-2.0f, 10.0f, 2.0f);
	glEnd();


	glPopMatrix();

}

void drawCycleRoof(float a, float b, float c, float d, float e)
{
	glPushMatrix();
	glTranslatef(a, b, c);
	glScalef(e, 1.0f, 1.0f);
	glRotatef(d, 0.0f, 1.0f, 0.0f);
	glColor3f(0.7f, 0.7f, 0.0f);
	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 2.5f);
	glVertex3f(-2.5f, 0.0f, 2.5f);
	glVertex3f(-2.5f, 0.0f, -2.5f);
	glVertex3f(2.5f, 0.0f, -2.5f);
	glVertex3f(2.5f, 0.0f, 0.0f);
	glEnd();
	glPopMatrix();
}


void drawCycleWall(float a, float b, float c, float d, float e)
{
	glPushMatrix();
	glTranslatef(a, b, c);
	glScalef(e, 1.0f, 1.0f);
	glRotatef(d, 0.0f, 1.0f, 0.0f);
	glColor3f(0.7f, 0.7f, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -2.5f);
	glVertex3f(0.0f, 0.0f, 2.5f);
	glVertex3f(0.0f, 3.0f, 2.5f);
	glVertex3f(0.0f, 3.0f, -2.5f);
	glEnd();
	glPopMatrix();
}


void lecture()
{
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(5.0f, 0.0f, 2.5f);
	glVertex3f(5.0f, 0.0f, -2.5f);
	glVertex3f(2.5f, 0.0f, -5.0f);
	glVertex3f(-2.5f, 0.0f, -5.0f);
	glVertex3f(-5.0f, 0.0f, -2.5f);
	glVertex3f(-5.0f, 0.0f, 2.5f);
	glVertex3f(-2.5f, 0.0f, 5.0f);
	glVertex3f(2.5f, 0.0f, 5.0f);
	glEnd();

	glPopMatrix();
}

void stairs()
{
	glPushMatrix();
	for(float i=0.0f; i<=1.0f; i+=0.25)
	{
		//top
		glBegin(GL_QUADS);
		
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(5.0f, i+0.25, -2.5f+i);
		glVertex3f(15.0f, i+0.25, -2.5f+i);
		glVertex3f(15.0f, i+0.25, 2.5f);
		glVertex3f(5.0f, i+0.25, 2.5f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(5.0f, i+0.25, -2.5f+i);
		glVertex3f(15.0f, i+0.25, -2.5f+i);
		glVertex3f(15.0f, i, -2.5f+i);
		glVertex3f(5.0f, i, -2.5f+i);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glVertex3f(5.0f, i+0.25, 2.5f);
		glVertex3f(15.0f, i+0.25, 2.5f);
		glVertex3f(15.0f, i, 2.5f);
		glVertex3f(5.0f, i, 2.5f);

		glNormal3f(1.0f, 0.0f, 0.0f);
		glVertex3f(15.0f, i+0.25, -2.5f+i);
		glVertex3f(15.0f, i, -2.5f+i);
		glVertex3f(15.0f, i, 2.5f);
		glVertex3f(15.0f, i+0.25, 2.5f);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(5.0f, i+0.25, -2.5f+i);
		glVertex3f(5.0f, i, -2.5f+i);
		glVertex3f(5.0f, i, 2.5f);
		glVertex3f(5.0f, i+0.25, 2.5f);
		glEnd();


	}
		glBegin(GL_QUADS);
		
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(5.0f, 6.5f, -1.5f);
		glVertex3f(15.0f, 6.5f, -1.5f);
		glVertex3f(15.0f, 6.5f, 2.5f);
		glVertex3f(5.0f, 6.5f, 2.5f);

		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(5.0f, 6.0f, -1.5f);
		glVertex3f(15.0f, 6.0f, -1.5f);
		glVertex3f(15.0f, 6.0f, 2.5f);
		glVertex3f(5.0f, 6.0f, 2.5f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(5.0f, 6.5f, -1.5f);
		glVertex3f(15.0f, 6.5f, -1.5f);
		glVertex3f(15.0f, 6.0f, -1.5f);
		glVertex3f(5.0f, 6.0f, -1.5f);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glVertex3f(5.0f, 6.5f, 2.5f);
		glVertex3f(15.0f, 6.5f, 2.5f);
		glVertex3f(15.0f, 6.0f, 2.5f);
		glVertex3f(5.0f, 6.0f, 2.5f);

		glNormal3f(1.0f, 0.0f, 0.0f);
		glVertex3f(15.0f, 6.5f, -1.5f);
		glVertex3f(15.0f, 6.0f, -1.5f);
		glVertex3f(15.0f, 6.0f, 2.5f);
		glVertex3f(15.0f, 6.5f, 2.5f);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(5.0f, 6.5f, -1.5f);
		glVertex3f(5.0f, 6.0f, -1.5f);
		glVertex3f(5.0f, 6.0f, 2.5f);
		glVertex3f(5.0f, 6.5f, 2.5f);
		glEnd();

		GLUquadricObj *cylquad = gluNewQuadric();
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		glTranslatef(8.3f, 1.25f, 0.0f);
		gluCylinder(cylquad, 0.6, 0.6, 6, 10, 2 );
		glTranslatef(3.3f, 0.0f, 0.0f);
		gluCylinder(cylquad, 0.6, 0.6, 6, 10, 2 );

	glPopMatrix();
}

void drawHall(float a, float b, float c, float d)
{
	glPushMatrix();
	glTranslatef(a,b,c);
	glRotatef(d, 0.0f, 1.0f, 0.0f);
	lecture();
	stairs();
	drawCap();
	drawWall(5.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	drawWall(-5.0f, 0.0f, 0.0f, 180.0f, 1.0f);
	drawWall(0.0f, 0.0f, 5.0f, -90.0f, 1.0f);
	drawWall(0.0f, 0.0f, -5.0f, 90.0f, 1.0f);
	drawWall(-3.75f, 0.0f, -3.75f, 122.5f, 0.65f);
	drawWall(3.75f, 0.0f, -3.75f, 57.5f, 0.65f);
	drawWall(-3.75f, 0.0f, 3.75f, -122.5f, 0.65f);
	drawWall(3.75f, 0.0f, 3.75f, -57.5f, 0.65f);
	
	drawCycleWall(-7.5f, 0.0f, -5.0f, 180.0f, 1.0f);
	drawCycleWall(-6.25f, 0.0f, -2.5f, -90.0f, 0.5f);
	drawCycleWall(-2.5f, 0.0f, -5.0f, 0.0f, 0.5f);
	drawCycleWall(-5.0f, 0.0f, -7.5f, 90.0f, 1.0f);

	drawCycleRoof(-5.0f,3.0f,-5.0f,0.0f,1.0f);

	drawCycleWall(-7.5f, 0.0f, 5.0f, 180.0f, 1.0f);
	drawCycleWall(-6.25f, 0.0f, 2.5f, -90.0f, 0.5f);
	drawCycleWall(-2.5f, 0.0f, 5.0f, 0.0f, 0.5f);
	drawCycleWall(-5.0f, 0.0f, 7.5f, 90.0f, 1.0f);

	drawCycleRoof(-5.0f,3.0f,5.0f,90.0f,1.0f);
	glPopMatrix();
}
//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE); //Automatically normalize normals
	//glShadeModel(GL_SMOOTH); //Enable smooth shading
	glClearColor(0.7f, 0.9f, 1.0f, 1.0f);
}



//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = -70.0f;

//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glTranslatef(0.0f, -2.0f, -8.0f);
	glTranslatef (d[0], d[1], d[2]); 
    glRotatef (zAngle, 0,0,1);
    glRotatef (yAngle, 0,1,0);
    glRotatef (xAngle, 1,0,0);
	//glRotatef(_angle, 0.0f, 1.0f, 1.0f);
	//glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

	glPushMatrix();
	drawHall(0.0f, 0.0f, 0.0f, 0.0f);
	drawHall(20.0f, 0.0f, 0.0f, 90.0f);
	drawHall(0.0f, 0.0f, -20.0f, -90.0f);
	drawHall(20.0f, 0.0f, -20.0f, 180.0f);
	glPopMatrix();

    glutSwapBuffers();
}



void update(int value) {
	_angle += 1.5f;
	if (_angle > 360) {
		_angle -= 360;
	}
	
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	
	//Create the window
	glutCreateWindow("Lectuer Theatre");
	initRendering();
	
	//Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	
	glutTimerFunc(25, update, 0); //Add a timer
	
	glutMainLoop();
	return 0;
}









