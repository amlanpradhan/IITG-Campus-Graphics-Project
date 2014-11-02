#include <iostream>
#include <stdlib.h>
#include<math.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

float _angle = -70.0f;

//Draws the 3D scene
void drawScene() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
//	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glTranslatef(0.0f, 0.0f, -8.0f);
	
	//Add ambient light
	//GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	
	//Add positioned light
	//GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
	//GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	//glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	
	//Add directed light
	//GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
	//Coming from the direction (-1, 0.5, 0.5)
	//GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
	//glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	//glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	
	glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	glPushMatrix();

	glColor3f(0.7f, 0.4f, 0.0f);
	
	//the base

	glBegin(GL_QUADS);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(2.5f, -1.25f, 0.0f);
	glVertex3f(2.5f, -1.50f, 0.0f);
	glVertex3f(-2.5f, -1.5f, 0.0f);
	glVertex3f(-2.5f, -1.25f, 0.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(2.5f, -1.25f, 2.0f);
	glVertex3f(2.5f, -1.50f, 2.0f);
	glVertex3f(-2.5f, -1.5f, 2.0f);
	glVertex3f(-2.5f, -1.25f, 2.0f);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.5f, -1.5f, 0.0f);
	glVertex3f(2.5f, -1.5f, 2.0f);
	glVertex3f(2.5f, -1.25f, 2.0f);
	glVertex3f(2.5f, -1.25f, 0.0f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.5f, -1.5f, 0.0f);
	glVertex3f(-2.5f, -1.5f, 2.0f);
	glVertex3f(-2.5f, -1.25f, 2.0f);
	glVertex3f(-2.5f, -1.25f, 0.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-2.5f, -1.25f, 0.0f);
	glVertex3f(2.5f, -1.25f, 0.0f);
	glVertex3f(2.5f, -1.25f, 2.0f);
	glVertex3f(-2.5f, -1.25f, 2.0f);


	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);

	glBegin(GL_QUADS);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-2.0f, -1.249f, 1.0f);
	glVertex3f(2.0f, -1.249f, 1.0f);
	glVertex3f(2.0f, -0.75f, 1.0f);
	glVertex3f(-2.0f, -0.75f, 1.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-2.0f, -1.249f, 1.99f);
	glVertex3f(2.0f, -1.249f, 1.99f);
	glVertex3f(2.0f, -0.75f, 1.99f);
	glVertex3f(-2.0f, -0.75f, 1.99f);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, -1.249f, 1.0f);
	glVertex3f(2.0f, -0.75f, 1.0f);
	glVertex3f(2.0f, -0.75f, 1.99f);
	glVertex3f(2.0f, -1.249f, 1.99f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, -1.249f, 1.0f);
	glVertex3f(-2.0f, -0.75f, 1.0f);
	glVertex3f(-2.0f, -0.75f, 1.99f);
	glVertex3f(-2.0f, -1.249f, 1.99f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(2.0f, -0.75f, 1.0f);
	glVertex3f(2.0f, -0.75f, 1.99f);
	glVertex3f(-2.0f, -0.75f, 1.99f);
	glVertex3f(-2.0f, -0.75f, 1.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(2.5f, -1.5f, 2.001f);
	glVertex3f(-2.5f, -1.50f, 2.001f);
	glVertex3f(-2.5f, 1.0f, 2.001f);
	glVertex3f(2.5f, 1.0f, 2.001f);

	glEnd();

	//The dome above

	float i=1.57f, j=0.0f;
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	for(j=-2.5f; j<=2.5; j+=0.1f)
	for(i=0.0f;i<=1.57f;i+=0.01f)
	{
		glVertex3f(j, 1.0+sin(i), 1.0+cos(i));
		glVertex3f(j, 1.0+sin(i), 1.0-cos(i));
	}
	glEnd();

	glPopMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);

	//rods

	glBegin(GL_LINES);

	glVertex3f(2.5f, -1.3f, 0.0f);
	glVertex3f(2.5f, 1.0f, 0.0f);

	glVertex3f(-2.5f, -1.3f, 0.0f);
	glVertex3f(-2.5f, 1.0f, 0.0f);

	glVertex3f(2.5f, -0.6f, 0.0f);
	glVertex3f(-2.5f, -0.6f, 0.0f);


	glEnd();
	
	
	glutSwapBuffers();
}
