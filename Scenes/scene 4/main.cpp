#include <iostream>
#include <stdlib.h>
#include "objects.h"
#include "objects2.h"
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
       //case 'k' : d[1] += 0.1;  break;
       case 'w' : d[2] += 0.3;  break;
       case 's' : d[2] -= 0.3;  break;

       case 'g' : xAngle += 2;  break;
       case 'b' : xAngle -= 2;  break;
       
       case 'q' : yAngle += 1;  break;
       case 'e' : yAngle -= 1;  break;
       
       case 'j' : zAngle += 2;  break;
 
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
	
	//glTranslatef(0.0f, 0.0f, -8.0f);
	//glRotatef(90, 1.0f, 0.0f, 0.0f);
	glTranslatef (d[0], d[1], d[2]); 
    glRotatef (zAngle, 0,0,1);
    glRotatef (yAngle, 0,1,0);
    glRotatef (xAngle, 1,0,0);
	//glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	//glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);


   	//Add ambient light
	GLfloat ambientColor[] = {0.1f, 0.1f, 0.1f, 1.0f}; //Color (0.2, 0.2, 0.2)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	
	//Add positioned light
	GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = {0.0f, 8.0f, 0.0f, 1.0f}; //Positioned at (4, 0, 8)
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

	drawBase(0.0f, -2.1f, 0.0f);
	drawGreen(2.0f, -2.01f, -3.0f, 30.0f, 40.0f);
	drawRoad(-7.0f, -2.0f, 6.0f, 60.0f, 3.0f, -40.0f);
	drawRoad(10.0f, -2.0f, 4.0f, 9.0f, 3.0f, 50.0f);
	drawRoad(27.0f, -2.0f, 16.0f, 15.0f, 3.0f, 50.0f);
	drawRoad(9.0f, -2.0f, -13.0f, 9.0f, 3.0f, 140.0f);
	drawRoad(-20.0f, -2.0f, 8.0f, 30.0f, 3.0f, -90.0f);
	drawRoad(-20.0f, -2.0f, -22.0f, 25.0f, 2.0f, -90.0f);
	drawRoad(-9.0f, -2.0f, 20.0f, 20.0f, 3.0f, 0.0f);
	drawRoad(18.0f, -2.0f, 30.0f, 40.0f, 3.0f, 0.0f);
	drawRoad(8.0f, -2.0f, 35.0f, 10.0f, 5.0f, 0.0f);
	drawLake(50.0f, -2.001f, -10.0f, 40.0f, 40.0f);
	
	drawCentre(2.0f, 0.0f, -3.0f, 4.0f, 1.0f);
	drawCircularRoad(2.0f, 0.0f, -3.0f, 4.0f, 6.0f);
	drawCircleTop(2.0f, 1.0f, -3.0f, 0.0f, 4.0f);
	
	drawCentre(-8.0f, -0.5f, 8.0f, 2.0f, 0.5f);
	drawCircularRoad(-8.0f, 0.0f, 8.0f, 2.0f, 4.0f);
	drawCircleTop(-8.0f, 0.5f, 8.0f, 0.0f, 2.0f);
	
	drawCentre(-10.0f, -0.5f, -4.0f, 2.0f, 0.5f);
	drawCircularRoad(-10.0f, -0.0f, -4.0f, 2.0f, 4.0f);
	drawCircleTop(-10.0f, 0.5f, -4.0f, 0.0f, 2.0f);
	
	drawCentre(18.0f, -0.5f, 8.0f, 2.0f, 0.5f);
	drawCircularRoad(18.0f, 0.0f, 8.0f, 2.0f, 4.0f);
	drawCircleTop(18.0f, 0.5f, 8.0f, 0.0f, 2.0f);
	
	drawAudi(-2.0f, -3.0f, -30.0f, 0.0f);
	drawCC(7.0f, -1.0f, 25.0f, 180.0f);
	drawAdmin(-24.0f , 2.0f, -5.0f, 90.0f, 4.0f, 4.0f, 6.0f);

	glPopMatrix();
	
	CreateTree(-4.0f,-2.5f,4.0f,0.4,0.4,0.4,3);
    glCallList(Fract);
    
    CreateTree(-2.0f,-2.5f,2.0f,0.4,0.4,0.4,3);
    glCallList(Fract);
    
    CreateTree(-4.0f,-2.50f,4.0f,0.4,0.4,0.4,3);
    glCallList(Fract);
    
    CreateTree(-5.0f,-2.5f, 1.0f,0.4,0.4,0.4,3);
    glCallList(Fract);
    
    CreateTree(-6.0f,-2.5f,2.0f,0.4,0.4,0.4,3);
    glCallList(Fract);
    
    CreateTree(-7.0f,-2.5f,3.0f,0.4,0.4,0.4,3);
    glCallList(Fract);
    float k;
    for(k=0.0; k <=20.0; k+=2.0)
    {
        CreateTree(-4.0f+k,-2.5f,7.0f,0.4,0.4,0.4,3);
        glCallList(Fract);
        glFlush();
    }
    
    for(k=0.0; k <=16.0; k+=2.0)
    {
        CreateTree(-7.0,-2.5f,3.0f-k,0.4,0.4,0.4,3);
        glCallList(Fract);
        glFlush();
    }
  /*  
    for(k=0.0; k <=26.0; k+=2.0)
    {
        CreateTree(20.0f,-2.5f,7.0f-k,0.4,0.4,0.4,3);
        glCallList(Fract);
        CreateTree(17.0f,-2.5f,7.0f-k,0.4,0.4,0.4,3);
        glCallList(Fract);
        glFlush();
    }
    
    for(k=0.0; k <=16.0; k+=2.0)
    {
        CreateTree(2.0f+(k/1.3),-2.5f,0.0f-k,0.4,0.4,0.4,3);
        glCallList(Fract);
        
        CreateTree(-2.5f+(k/1.2),-2.5f,-0.5f-k,0.4,0.4,0.4,3);
        glCallList(Fract);
        glFlush();
    }*/
	
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
	
		//for tree
	NewFractals();
     agvMakeAxesList(AXES);
     myGLInit(); 
     //for tree ends
	
	
	glutTimerFunc(25, update, 0); //Add a timer
	
	glutMainLoop();
	return 0;
}









