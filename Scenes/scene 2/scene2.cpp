#include <iostream>
#include <stdlib.h>
#include "objects.h"
#include<math.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

GLfloat d[3] = {0.0, 0.0, 0.0};
GLfloat  xAngle = 0.0, yAngle = 0.0, zAngle = 0.0;
//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) { 
	switch (key) {

       case 'a' : d[0] += 0.2;  break;
       case 'd' : d[0] -= 0.2;  break;
       case 'w' : d[2] += 0.2;  break;
       case 's' : d[2] -= 0.2;  break;

     case 'g' : xAngle += 2;  break;
     case 'b' : xAngle -= 2;  break;
       
       case 'q' : yAngle += 1;  break;
       case 'e' : yAngle -= 1;  break;
       
    //   case 'j' : zAngle += 2;  break;
 
       //default: printf ("   Keyboard %c == %d\n", key, key);
    }
glutPostRedisplay();
}

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE); //Automatically normalize normals
	glShadeModel(GL_SMOOTH); //Enable smooth shading
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
	glClearColor(0.6f, 0.7f, 1.0f, 0.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glTranslatef(0.0f, 0.0f, -8.0f);
	glTranslatef (d[0], d[1], d[2]); 
    glRotatef (zAngle, 0,0,1);
    glRotatef (yAngle, 0,1,0);
    glRotatef (xAngle, 1,0,0);
		//Add ambient light
	GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	
	//Add positioned light
	GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	
	//Add directed light
	GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
	//Coming from the direction (-1, 0.5, 0.5)
	GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	
	//glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	
	float i;
	drawBase(0.0,-2.001,0.0);
	drawBoundry(1.8,-2.0,-3.5,0.0,1.0,18.0);
	drawBoundry(1.8,-2.0,-13.2,0.0,1.0,8.0);
	drawGate(1.8,-2.0,-5.2,1.0,1.0,1.5);
	
	glPushMatrix();
	glRotatef(180, 0.0f, 1.0f, 0.0f);
	drawGate(-1.8,-2.0,3.5,1.0,1.0,1.5);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	drawBoundry(13.2,-2.0,1.82,0.0,1.0,7.0);
	glPopMatrix();
	
	drawRoad(0.0,-2.01,0.0,1.6,1.0,1.0);
	drawDivider(0.0,-2.0,1.0,1.0,1.0,140.0);
	for(i=-12.0;i<=12.0;i+=3)
	lamp_post1(0.0,0.0f, i, 0.5f);
	
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	drawRoad(14.5,-2.01,7.5,1.0,1.0,0.61);
	drawDivider(14.5,-2.0,8.0,1.0,1.0,80.0);
   	for(i=0.0;i<=15.0;i+=3)
	lamp_post1(14.5,0.0f, i, 0.5f);	
	glPopMatrix();
	
	
	drawTennisCourt(5.0,-2.0,-12.0,0.4);
	drawTennisCourt(5.0,-2.0,-8.0,0.4);
	glPushMatrix();
	
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	drawRoad(4.5,-2.01,9.8,0.5,1.0,0.55);
	glPopMatrix();
	glPushMatrix();
	glRotatef(-90, 0.0f, 1.0f, 0.0f);
	for(i=-12.0;i<=-3.0;i+=3)
	lamp_post(-5.3,0.0f, i, 0.5f);
	glPopMatrix();
	
	drawSacBuilding(17.0,-1.0,-4.5,1.0,1.0,2.0);
	
	drawStair(13.0,-2.0,11.0,18.0,1.0,5.0);
	drawStair(13.0,-1.6,11.0,18.0,1.0,3.0);
	drawStair(13.0,-1.2,11.0,18.0,1.0,1.0);
	
	drawField(16.0,-2.0,4.0,1.0,1.0,1.0);
	drawGoal(21.0,-1.99,3.5,1.0,1.0,1.0);
	glPushMatrix();
	glRotatef(180,0.0f,1.0f,0.0f);
	drawGoal(-10.8,-1.99,-5.5,1.0,1.0,1.0);
	glPopMatrix();
	
	drawPath(7.5,-2.0,6.0,1.0,1.0,2.5);
	
	drawField(4.5,-2.0,3.0,0.4,1.0,1.0);
	glPushMatrix();
	glRotatef(90,0.0f,1.0f,0.0f);
	drawGoal(0.2,-1.99,4.0,1.0,1.0,0.4);
	glRotatef(180,0.0f,1.0f,0.0f);
	drawGoal(6.2,-1.99,-5.0,1.0,1.0,0.4);
	glPopMatrix();
	

    CreateTree(-1.8,-2.0,4.0,0.4,0.8,0.4,5);
    glCallList(Fract);
    
    CreateTree(-1.8,-2.0,-8.0,0.4,0.8,0.4,4);
    glCallList(Fract);
    
    CreateTree(-1.8,-2.0,0.0,0.4,0.8,0.4,5);
    glCallList(Fract);
    
	glutSwapBuffers();
	glFlush();
	
	//drawCase();
  
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
	glutCreateWindow("Scene No. 2");
	initRendering();
	
	//Set handler functions
	glutDisplayFunc(drawScene);
 	NewFractals();
     agvMakeAxesList(AXES);
     myGLInit(); 
    
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	
	glutTimerFunc(25, update, 0); //Add a timer
	
	glutMainLoop();
	return 0;
}









