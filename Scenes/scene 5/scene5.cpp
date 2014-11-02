#include <iostream>
#include <stdlib.h>
#include "objects.h"
#include "com_hall.h"
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

       case 'a' : d[0] += 0.3;  break;
       case 'd' : d[0] -= 0.3;  break;
       case 'w' : d[2] += 0.3;  break;
       case 's' : d[2] -= 0.3;  break;

      case 'g' : xAngle += 2;  break;
      case 'b' : xAngle -= 2;  break;
       
       case 'q' : yAngle += 1;  break;
       case 'e' : yAngle -= 1;  break;
       
     //  case 'j' : zAngle += 2;  break;
 
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
	//glRotatef(_angle, 0.0f, 1.0f, 1.0f);
	//glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

    
	glPushMatrix();
	
	drawBase(0.0,-2.001,0.0);
	drawWing(5.0f, -2.0f, 0.0f, 1.0f);
	drawWing(5.0f, -2.0f, -8.0f, 1.0f);
	joinWing(10.0f,-2.0f,-6.0f,0.2f,12.0f,10.0f);
	
	drawWing(5.0f, -2.0f, 18.0f, 1.0f);
	drawWing(5.0f, -2.0f, 10.0f, 1.0f);
	joinWing(10.0f,-2.0f,12.0f,0.2f,12.0f,10.0f);
	
	drawRoad(-5.0f,-2.0f,0.0f,1.0f,1.0f,2.0f);
	float i;
	for(i=-20.0;i<=15.0;i+=5.0)
	lamp_post(-2.85,0.0,i,1.0);
	
	for(i=-11.0;i<=-2.0;i+=3.0)
	lamp_post2(-0.7,0.0,i,0.6);
	
	for(i=7.0;i<=16.0;i+=3.0)
	lamp_post2(-0.7,0.0,i,0.6);
	 
	drawComHall(-10.0f,0.0f,-4.0f,1.0,1.0f,1.0f, 90.0);    
	
	drawBoundry(-8.0f,-2.0f,-22.0f,0.0f,26.0f);
	
	drawBoundry(-8.0f,-2.0f,4.0f,-60.0f,10.0f);
	drawGate(-8.5f,-2.0f,4.3f,-60.0);
	drawGate(-9.4f,-2.0f,4.83f,120.0);
	
	drawGate(-13.5f,-2.0f,7.2f,-60.0);
	drawGate(-14.4f,-2.0f,7.7f,120.0);
	
	drawBoundry(-16.65f,-2.0f,9.05f,0.0f,6.0f);
	drawFootPath(-3.65,-3.0,-4.0f,1.5f,4.0f,90.0f);
	
	
	CreateTree(-2.8f,-2.0,-8.0f,0.4,0.8,0.4,4);
    glCallList(Fract);
    
    CreateTree(-2.8f,-2.5,-6.2f,0.4,0.8,0.4,4);
    glCallList(Fract);
    
    CreateTree(-2.8f,-2.0,-3.0f,0.4,0.8,0.4,3);
    glCallList(Fract);
    
    CreateTree(-2.8f,-2.3,1.0f,0.4,0.8,0.4,2);
    glCallList(Fract);
    
    CreateTree(-2.8f,-2.0,-10.0f,0.4,0.8,0.4,2);
    glCallList(Fract);
    
    CreateTree(-6.5f,-2.0,0.4f,0.4,0.8,0.4,2);
    glCallList(Fract);
    
    CreateTree(-6.2f,-2.0,-2.4f,0.4,0.8,0.4,3);
    glCallList(Fract);
    
    CreateTree(-6.3f,-2.0,-5.0f,0.4,0.8,0.4,2);
    glCallList(Fract);
    
    CreateTree(-6.25f,-2.0,-8.0f,0.4,0.8,0.4,4);
    glCallList(Fract);
    
    
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
	glutCreateWindow("Hostels-Scene 5");
	initRendering();
	
	//Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	//for tree
	NewFractals();
     agvMakeAxesList(AXES);
     myGLInit(); 
     //for tree ends
	
	glutTimerFunc(25, update, 0); //Add a timer
	
	glutMainLoop();
	return 0;
}









