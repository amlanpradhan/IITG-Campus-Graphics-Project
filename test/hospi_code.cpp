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

void drawBalcony(float,float,float,float);
void drawFloor(float, float, float, float);
void drawWing(float, float, float, float);
void joinWing();

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
void drawCuboid(float a, float b, float c, float d, float e, float f)
{
	glPushMatrix();
	glTranslatef(a, b, c);
	glScalef(d, e, f);
	glutSolidCube(1);
	glPopMatrix();
}
void drawRamp(float r, float a, float b, float c)
{
	glPushMatrix();
	glTranslatef(a, b, c);
	glRotatef(r, 0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);

	glColor3f(0.4f, 0.4f, 0.4f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-5.0f, 0.0f, -3.0f);
	glVertex3f(5.0f, 0.0f, -3.0f);
	glVertex3f(5.0f, 0.0f, -5.0f);
	glVertex3f(-5.0f, 0.0f, -5.0f);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(5.0f, 1.0f, -5.0f);
	glVertex3f(-5.0f, 1.0f, -5.0f);

	glVertex3f(5.0f, 1.0f, -3.0f);
	glVertex3f(-5.0f, 1.0f, -3.0f);

	for(float i=0.0f; i<=10.0f; i++)
	{
		glVertex3f(-5.0f+i, 1.0f, -3.0f);
		glVertex3f(-5.0f+i, 0.0f, -3.0f);

		glVertex3f(-5.0f+i, 1.0f, -5.0f);
		glVertex3f(-5.0f+i, 0.0f, -5.0f);
	}
	glEnd();
	glPopMatrix();
}

void drawBuilding1(float a, float b, float c)
{
	glPushMatrix();
	glTranslatef(a, b, c);
	glColor3f(1.0f, 1.0f, 1.0f);
	drawCuboid(0.0f, 0.0f, 0.0f, 6.0f, 3.0f, 10.0f);
	glColor3f(0.4f, 0.4f, 0.4f);
	for(float i=0.0f; i<=2.0f;i++)
	{
		glBegin(GL_QUADS);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-2.5f+(2*i)+1.0f,-1.0f, 5.01f);
		glVertex3f(-2.5f+(2*i),-1.0f, 5.01f);
		glVertex3f(-2.5f+(2*i),1.0f, 5.01f);
		glVertex3f(-2.5f+(2*i)+1.0f,1.0f, 5.01f);
		glEnd();
	}
	for(float i=0.0f; i<=4.0f;i++)
	{
		glBegin(GL_QUADS);
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(-3.01f,-1.0f,4.0f-(2*i));
		glVertex3f(-3.01f,-1.0f, 4.0f-(2*i)-1.0f);
		glVertex3f(-3.01f,1.0f, 4.0f-(2*i)-1.0f);
		glVertex3f(-3.01f,1.0f, 4.0f-(2*i));
		glEnd();
	}
	glPopMatrix();
}
void drawBuilding2(float a, float b, float c)
{
	glPushMatrix();
	glTranslatef(a, b, c);
	glColor3f(1.0f, 1.0f, 1.0f);
	drawCuboid(0.0f, 0.0f, 0.0f, 16.0f, 3.0f, 4.0f);
	glColor3f(0.4f, 0.4f, 0.4f);
	for(float i=0.0f; i<=5.0f;i++)
	{
		glBegin(GL_QUADS);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-6.0f+(2*i)+1.0f,-1.0f, 2.01f);
		glVertex3f(-6.0f+(2*i),-1.0f, 2.01f);
		glVertex3f(-6.0f+(2*i),1.0f, 2.01f);
		glVertex3f(-6.0f+(2*i)+1.0f,1.0f, 2.01f);
		glEnd();
	}
	for(float i=0.0f; i<=5.0f;i++)
	{
		glBegin(GL_QUADS);
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(-6.0f+(2*i)+1.0f,-1.0f, -2.01f);
		glVertex3f(-6.0f+(2*i),-1.0f, -2.01f);
		glVertex3f(-6.0f+(2*i),1.0f, -2.01f);
		glVertex3f(-6.0f+(2*i)+1.0f,1.0f, -2.01f);
		glEnd();
	}
	for(float i=0.0f; i<=1.0f;i++)
	{
		glBegin(GL_QUADS);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(7.01f,-1.0f,1.0f-(2*i));
		glVertex3f(7.01f,-1.0f, 1.0f-(2*i)-1.0f);
		glVertex3f(7.01f,1.0f, 1.0f-(2*i)-1.0f);
		glVertex3f(7.01f,1.0f, 1.0f-(2*i));
		glEnd();
	}
	glPopMatrix();
}
void drawEntrance1(float a, float b, float c)
{
	glPushMatrix();
	glColor3f(0.8f, 0.8f, 0.8f);
	glBegin(GL_QUADS);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.0f,0.0f,0.0f);
	glVertex3f(2.0f,0.0f, -10.0f);
	glVertex3f(2.0f,3.0f, -10.0f);
	glVertex3f(2.0f,3.0f, 0.0f);
	glEnd();	
	glBegin(GL_QUADS);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f,0.0f,0.0f);
	glVertex3f(-2.0f,0.0f, -10.0f);
	glVertex3f(-2.0f,3.0f, -10.0f);
	glVertex3f(-2.0f,3.0f, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(6.0f,0.0f,-3.0f);
	glVertex3f(6.0f,0.0f, -6.0f);
	glVertex3f(6.0f,3.0f, -6.0f);
	glVertex3f(6.0f,3.0f, -3.0f);
	glEnd();
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(6.0f,3.0f,-3.0f);
	glVertex3f(6.0f,3.0f, -6.0f);
	glVertex3f(2.0f,3.0f, -6.0f);
	glVertex3f(2.0f,3.0f, -3.0f);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(13.0f,0.0f,-10.0f);
	glVertex3f(13.0f,0.0f, -14.0f);
	glVertex3f(13.0f,6.0f, -14.0f);
	glVertex3f(13.0f,6.0f, -10.0f);
	glEnd();
	glBegin(GL_QUADS);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(13.0f,6.0f,-10.0f);
	glVertex3f(13.0f,6.0f, -14.0f);
	glVertex3f(0.0f,6.0f, -14.0f);
	glVertex3f(0.0f,6.0f, -10.0f);
	glEnd();
	glPopMatrix();
}

void drawCylinder(float a, float b, float c)
{
	glPushMatrix();
	GLUquadricObj *cylquad = gluNewQuadric();
	glTranslatef(a, b, c);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(cylquad, 0.2, 0.2, 3, 10, 2 );
	glPopMatrix();
}
void drawEntrance2(float a, float b, float c)
{
	glPushMatrix();
	glColor3f(0.7f, 0.4f, 0.4f);
	drawCuboid(0.0f, 3.0f, 2.0f, 4.0f, 0.6f, 4.0f);
	drawCylinder(2.0f, 0.0f, 0.0f);
	drawCylinder(-2.0f, 0.0f, 0.0f);
	drawCylinder(2.0f, 0.0f, 4.0f);
	drawCylinder(-2.0f, 0.0f, 4.0f);
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
	
	//glTranslatef(0.0f, 0.0f, -8.0f);
	glTranslatef (d[0], d[1], d[2]); 
    glRotatef (zAngle, 0,0,1);
    glRotatef (yAngle, 0,1,0);
    glRotatef (xAngle, 1,0,0);
	//glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	//glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

	glPushMatrix();


	drawRamp(10.0f, 8.0f, -2.0f+3.0f, -9.0f);
	drawRamp(-10.0f, 8.0f, 1.5f+1.0f, -7.0f);
	drawBuilding1(0.0f, 4.5f, -5.0f);
	drawBuilding1(-7.0f, 1.5f, -5.0f);
	drawBuilding1(-7.0f, 4.5f, -5.0f);
	drawBuilding2(5.0f, 1.5f, -16.0f);
	drawBuilding2(5.0f, 4.5f, -16.0f);
	drawCuboid(-3.0f, 2.5f, -5.5f, 2.0f, 5.0f, 9.0f);
	drawEntrance1(0.0f, 0.0f, 0.0f);

	drawEntrance2(0.0f, 0.0f, 0.0f);

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
	glutCreateWindow("Scene");
	initRendering();
	
	//Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	
	glutTimerFunc(25, update, 0); //Add a timer
	
	glutMainLoop();
	return 0;
}









