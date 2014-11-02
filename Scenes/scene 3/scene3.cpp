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
static GLint screenHeight = 700;
static GLint screenWidth = 700;
float camPosition[3] = {0, 0, 0};
float camLookAt[3] = {0, 0, -1};
#define pi (3.141592653589793)
GLfloat d[3] = {0.0, 0.0, 0.0};
GLfloat  xAngle = 0.0, yAngle = 0.0, zAngle = 0.0;

int screenx=0, screeny=0;

void normalize1(float array[])
{
	float mod = array[0] * array[0] + array[1] * array[1] + array[2] * array[2];
	mod = sqrt(mod);
	array[0]/=mod;
	array[1]/=mod;
	array[2]/=mod;
}
	
void moveLeft(int step)
{
	camPosition[0] += step * (camLookAt[2]);
	camPosition[2] += step * (-camLookAt[0]);
	camLookAt[0] += step * (camLookAt[2])/30000;
	camLookAt[2] += step * (-camLookAt[0])/30000;
	normalize1(camLookAt);
}

void moveForward(int step)
{
	camPosition[0] += step * camLookAt[0];
	camPosition[2] += step * camLookAt[2];
	camLookAt[0] += step * camLookAt[0]/30000;
	camLookAt[2] += step * camLookAt[2]/30000;
	normalize1(camLookAt);
}


void moveUp(int step)
{
	camPosition[1] += step ;
	camLookAt[1] += step/10000;
	normalize1(camLookAt);
}

//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) {
    int i=0;
	switch (key) {

       case 'a' : moveLeft(1);i++;  break;
       case 'd' : moveLeft(-1);i++; break;

       case 'w' : moveForward(1);i++; break;
       case 's' : moveForward(-1);i++;  break;
       
       case 'q' : yAngle += 1;  break;
       case 'e' : yAngle -= 1;  break;
       
       case 27: 	exit(0); break;
    }
glutPostRedisplay();
}

void Mouse(int button, int state, int x, int y)
{
	if(button == 1 && state == 2)
	{
		screenx = screenWidth - (GLint) x;
		screeny = screenHeight - (GLint) y;
	}
}

void mouseMotion(int x, int y)
{
	int spin=0,slant=0;
	x = screenWidth - (GLint) x;
	y = screenHeight - (GLint) y;

	float numerator, denominator,temp;

	if(x < screenx)
		spin = 1;
	else if(x > screenx)
		spin = -1;
		
	if(y < screeny)
		slant = -1;
	else if(y > screeny)
		slant = 1;
	
	screenx = x;
	screeny = y;

	float cosTheta = cos(2*pi/180);
	float sinTheta = sin(2*pi/180);

	if(spin)
	{
		numerator = camLookAt[1];
		temp = camLookAt[0] * cosTheta - spin * camLookAt[2] * sinTheta;
		camLookAt[2] = spin * camLookAt[0] * sinTheta + camLookAt[2] * cosTheta;
		camLookAt[0] = temp;
	}

	if(slant) 
	{
		float altitude = asin(camLookAt[1]);
		if(slant == 1 && altitude <= (80*pi/180))
			altitude += 1 * pi / 180;
		else if(slant == -1 && altitude >= -(80*pi/180))
			altitude -= 1 * pi / 180;

		denominator = 1.0 - camLookAt[1] * camLookAt[1];
		
		camLookAt[1] = sin(altitude);
		numerator = 1.0 - camLookAt[1] * camLookAt[1];
				
		float xzFactor;
		xzFactor = sqrt(numerator/denominator);
		
		camLookAt[0] *= xzFactor;
		camLookAt[2] *= xzFactor;

	}
	normalize(camLookAt);
	
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
	
	/*glTranslatef(0.0f, 0.0f, -8.0f);
	glTranslatef (d[0], d[1], d[2]); 
    glRotatef (zAngle, 0,0,1);
    glRotatef (yAngle, 0,1,0);
    glRotatef (xAngle, 1,0,0);*/
    
    gluLookAt(camPosition[0],camPosition[1],camPosition[2], 10000*camLookAt[0],10000*camLookAt[1],10000*camLookAt[2],  0, 1, 0);
    
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
	glScalef(0.5f,0.5f,0.5f);
	drawHall(6.0f, -4.0f, -4.0f, 0.0f);
	drawHall(26.0f, -4.0f, -4.0f, 90.0f);
	drawHall(6.0f, -4.0f, -24.0f, -90.0f);
	drawHall(26.0f, -4.0f, -24.0f, 180.0f);
	glPopMatrix();
	
	
	float i;
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	drawRoad(-3.0,-2.01,9.8,0.5,1.0,1.5);
	glPopMatrix();
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	for(i=-6.0;i<=18.0;i+=3)
	lamp_post2(-4.0,0.0f, i, 0.5f);
	glPopMatrix();
	
	drawCenter(8.5f,-2.0f,-7.0f,1.0,0.5,1.5);
	
	CreateTree(9.4f,-2.0,-8.0f,0.4,0.8,0.4,1);
    glCallList(Fract);
    
    CreateTree(9.4f,-2.0,-6.0f,0.4,0.8,0.4,3);
    glCallList(Fract);
    
    CreateTree(7.9f,-2.0,-8.3f,0.4,0.8,0.4,2);
    glCallList(Fract);
    
    CreateTree(7.9f,-2.0,-6.0f,0.4,0.8,0.4,4);
    glCallList(Fract);
    
    drawPool(7.0f, -2.0f, 15.0f);    

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
	glutCreateWindow("Lectuer Theatre-Scene 3");
	initRendering();
	glutFullScreen();
	
	//Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutMouseFunc(Mouse);
	glutMotionFunc(mouseMotion);
	
	//for tree
	NewFractals();
     agvMakeAxesList(AXES);
     myGLInit(); 
     //for tree ends
	
	glutTimerFunc(25, update, 0); //Add a timer
	
	glutMainLoop();
	return 0;
}









