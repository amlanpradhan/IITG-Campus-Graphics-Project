#include <iostream>
#include <stdlib.h>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

void drawWall(float a, float b, float c, float d, float e)
{

	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(a, b, c);
	glScalef(e, 1.0f, 1.0f);
	glRotatef(d, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(4.0f, 4.0f, 0.0f);
	glVertex3f(-4.0f, 4.0f, 0.0f);
	glVertex3f(-4.0f, 6.0f, 0.0f);
	glVertex3f(4.0f, 6.0f, 0.0f);
	glEnd();

	glPopMatrix();
}

void drawRoof()
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex3f(4.2f, 3.8f, 0.3f);
	glVertex3f(-4.2f, 3.8f, 0.3f);
	glVertex3f(0.0f, 7.0f, -2.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(4.2f, 3.8f, 0.3f);
	glVertex3f(0.0f, 7.0f, -2.0f);
	glVertex3f(0.0f, 9.0f, -11.6f);
	glVertex3f(7.7f, 3.8f, -9.6f);	
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-4.2f, 3.8f, 0.3f);
	glVertex3f(0.0f, 7.0f, -2.0f);
	glVertex3f(0.0f, 9.0f, -11.6f);
	glVertex3f(-7.7f, 3.8f, -9.6f);	
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(4.2f, 3.8f, -16.0f);
	glVertex3f(0.0f, 7.0f, -16.0f);
	glVertex3f(0.0f, 9.0f, -11.6f);
	glVertex3f(7.7f, 3.8f, -9.6f);	
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-4.2f, 3.8f, -16.0f);
	glVertex3f(0.0f, 7.0f, -16.0f);
	glVertex3f(0.0f, 9.0f, -11.6f);
	glVertex3f(-7.7f, 3.8f, -9.6f);	
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(4.2f, 3.8f, -16.0f);
	glVertex3f(4.2f, 3.8f, -22.0f);
	glVertex3f(0.0f, 7.0f, -22.0f);
	glVertex3f(0.0f, 7.0f, -16.0f);	
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-4.2f, 3.8f, -16.0f);
	glVertex3f(-4.2f, 3.8f, -22.0f);
	glVertex3f(0.0f, 7.0f, -22.0f);
	glVertex3f(0.0f, 7.0f, -16.0f);	
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 7.0f, -22.0f);
	glVertex3f(4.2f, 3.8f, -22.0f);
	glVertex3f(-4.2f, 3.8f, -22.0f);	
	glEnd();

	glPopMatrix();
}

void drawCylinder(float a, float b, float c)
{
	glPushMatrix();
	GLUquadricObj *cylquad = gluNewQuadric();
	glTranslatef(a, b, c);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(cylquad, 0.3, 0.3, 6, 10, 2 );
	glPopMatrix();
}
void drawCube(float a, float b, float c, float d, float e, float f)
{
	glPushMatrix();
	glTranslatef(a, b, c);
	glScalef(d, e, f);
	glutSolidCube(4.0f);
	glPopMatrix();
}

void drawBoundary()
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(6.0f, -2.0f, -22.0f);
	glVertex3f(-6.0f, -2.0f, -22.0f);
	glVertex3f(-6.0f, 4.0f, -22.0f);
	glVertex3f(6.0f, 4.0f, -22.0f);
	glEnd();
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 1.0f, 0.0f);
	//glVertex3f(4.0f, -2.0f, 0.0f);
	glVertex3f(-4.0f, -2.0f, 0.0f);
	glVertex3f(-8.0f, -2.0f, -6.0f);
	glVertex3f(-9.0f, -2.0f, -11.6f);
	glVertex3f(-5.5f, -2.0f, -16.0f);
	glVertex3f(-5.5f, -2.0f, -20.0f);
	glVertex3f(5.5f, -2.0f, -20.0f);
	glVertex3f(5.5f, -2.0f, -16.0f);
	glVertex3f(9.0f, -2.0f, -11.6f);
	glVertex3f(8.0f, -2.0f, -6.0f);
	glVertex3f(4.0f, -2.0f, 0.0f);
	glEnd();
	glPopMatrix();

}

void drawComHall(float a,float b,float c,float d,float e,float f,float g)
{

	glPushMatrix();
	glTranslatef(a,b,c);
    glScalef(d,e,f);
    glRotatef(g,0.0,1.0,0.0);
    
    drawWall(0.0f, -2.0f, 0.0f, 0.0f, 1.0f);
	drawWall(6.0f, -2.0f, -3.5f, 60.0f, 1.0f);
	drawWall(-6.0f, -2.0f, -3.50f, -60.0f, 1.0f);
	drawWall(6.5f, -2.0f, -11.0f, 100.0f, 2.5f);
	drawWall(-6.5f, -2.0f, -11.0f, -100.0f, 2.5f);
	drawWall(0.0f, -2.0f, -13.99f, 0.0f, 1.5f);
	drawCylinder(4.5f, -2.0f, -1.0f);
	drawCylinder(-4.5f, -2.0f, -1.0f);
	drawCylinder(7.5, -2.0f, -5.9f);
	drawCylinder(-7.5f, -2.0f, -5.9f);
	drawCylinder(5.2f, -2.0f, -14.0f);
	drawCylinder(-5.2f, -2.0f, -14.0f);
	drawCylinder(6.0f, -2.0f, -12.0f);
	drawCylinder(-6.0f, -2.0f, -12.0f);
	drawCylinder(7.0f, -2.0f, -10.0f);
	drawCylinder(-7.0f, -2.0f, -10.0f);
	drawBoundary();
	drawRoof();
	drawCube(6.0f, 1.0f, -18.0f, 1.0f, 1.5f, 2.0f);
	drawCube(-6.0f, 1.0f, -18.0f, 1.0f, 1.5f, 2.0f);
	drawCube(0.0f, -1.5f, -18.0f, 2.0f, 0.3f, 2.0f);
	glPopMatrix();
}











