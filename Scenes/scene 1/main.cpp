#include <iostream>
#include <stdlib.h>
#include "objects.h"
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;
GLfloat d[3] = {0.1, 0.1, 0.1};
//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27: //Escape key
			exit(0);
	}
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
	
	glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	//glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

	drawBusStop(5.0f, -1.49f, 3.0, 0.4f);
	drawPool(0.50f, -1.0f, -10.0f, 0.9f);
	drawBuilding(-5.0f, -2.0f, -11.0f, 1.0f);
	glColor3f(0.8f, 0.6f, 0.0f);
	drawBase(0.0f, -2.001f, 0.0f, 0.0f);
	drawRoad(0.0f, -2.0f, 2.0f, 20.0f, 0.0f);	
	drawRoad(1.0f, -2.0f, 3.0f, 8.0f, -90.0f);
	drawRoad(9.0f, -2.0f, 2.0f, 10.0f, 90.0f);
	drawRoad(-9.0f, -2.0f, 2.0f, 10.0f, -90.0f);
	drawRoad(-9.0f, -2.0f, -8.0f, 10.0f, -90.0f);
	drawRoad(-19.0f, -2.0f, -2.0f, 20.0f, 0.0f);
	drawRoad(-19.0f, -2.0f, -4.0f, 20.0f, 180.0f);
	
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









