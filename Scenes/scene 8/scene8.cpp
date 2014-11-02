#include <iostream>
#include <stdlib.h>      
#include<math.h>  
#include "shadow.h"
#include "shadow1.h"
   
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
      // case 'k' : d[1] += 0.1;  break;  
       case 'w' : d[2] += 0.3;  break; 
       case 's' : d[2] -= 0.3;  break;

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
	//glShadeModel(GL_SMOOTH); //Enable smooth shading
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
//	glDisable(GL_LIGHTING);
	float i;
	drawBase(0.0,-2.001,0.0);
	
	drawFront(-0.1,-2.0,0.0,0.4,1.2,1.0);
	drawFront(-2.5,-2.0,0.0,1.5,2.3,1.0);
	
	for(i=1;i<=5;i++)
	drawFront1(-11.3+(1.5*i),1.2+0.25*i,0.0,0.3,1.2,1.0); 
	
	for(i=1;i<=5;i++)
	drawFront2(12.8-(1.5*i),1.2+0.25*i,0.0,0.3,1.2,1.0);
	
    drawSet1(-2.4,-2.4,0.0,1.0,1.7,1.0);
    drawSet2(4.4,-2.4,0.0,1.0,1.7,1.0);    
    drawSet3(-12.4,-2.0,-0.1,5.5,10.0,4.0);
    drawSet3(12.4,-2.0,-0.1,5.5,10.0,4.0);  
    
    drawGate(-14.5,0.0,2.01,1.5,1.0,1.0); 
    drawGate(-12.8,0.0,2.01,1.5,1.0,1.0);
    drawGate(14.0,0.0,2.01,1.2,1.0,1.0);
    drawGate(12.5,0.0,2.01,1.2,1.0,1.0);  
    
    drawStairs(-13.8,-1.0,1.8,0.8,1.0,1.0,0.0); 
    drawStairs(-13.8,-3.0,3.8,0.8,1.75,1.0,0.0);
    
    drawStairs(-12.0,-1.0,1.8,0.8,1.0,1.0,0.0);
    drawStairs(-12.0,-2.0,3.8,0.8,1.0,1.0,0.0);
    
    drawStairs(-9.4,-1.0,1.8,0.8,1.0,1.0,90.0); 
    drawStairs(-8.0,-2.0,1.8,1.5,1.0,1.0,90.0); 
    
    drawStairs(14.6,-1.0,1.8,0.6,1.0,1.0,0.0); 
    drawStairs(14.6,-3.0,3.8,0.6,1.75,1.0,0.0);
    
    drawStairs(13.3,-1.0,1.8,0.4,1.0,1.0,0.0); 
    drawStairs(13.3,-2.0,3.8,0.4,1.0,1.0,0.0);
    
    drawStairs(11.4,-1.0,1.8,0.7,1.0,1.0,-90.0); 
    drawStairs(10.0,-2.0,1.8,1.4,1.0,1.0,-90.0); 
    
    drawSet4(1.0,0.4,-0.1,3.3,3.4,1.0);     
          
	drawNacBuilding(-15.0,-1.0,-3.0,0.0,1.0); 
    
    drawDivider(-16.2,-2.0,-5.0,4.0,1.0,27.5);
    drawDivider(16.2,-2.0,-5.0,4.0,1.0,27.5);
    
    drawDivider(-16.2,0.0,-5.0,4.0,1.0,27.5);
    drawDivider(16.2,0.0,-5.0,4.0,1.0,27.5); 
    
    for(i=0;i<=12;i+=2)   
    {
    drawCircle(-15.4,0.0,1.6-i,0.2,3.0);
    drawCircle(-17.0,0.0,1.6-i,0.2,3.0);
     }
    for(i=0;i<=12;i+=2)
    {
    drawCircle(15.4,0.0,1.6-i,0.2,3.0);
    drawCircle(17.0,0.0,1.6-i,0.2,3.0);
     }      
  
	
	drawNacBuilding(17.2,-1.0,-0.5,0.0,0.3);
	drawNacBuilding(25.2,-1.0,-0.6,30.0,0.1);
	
	drawPath(0.0,-2.0,10.0,70,1.0,0.4);
	drawPath(0.8,-2.0,15.0,2.0,1.0,1.0); 
	
	drawPath(-35.0,-2.0,-10.0,2.0,1.0,10.0);  
	drawPath(35.0,-2.0,-10.0,2.0,1.0,10.0);
	
	drawCar(-29.0,-1.92,5.0,0.4,0.4,0.4,0.0);
	drawCar(-26.0,-1.92,5.0,0.4,0.4,0.4,-90.0);
	drawCar(-23.0,-1.92,5.0,0.4,0.4,0.4,90.0);
	drawCar(-20.0,-1.92,5.0,0.4,0.4,0.4,-90.0);
	
	for(i=0;i<=3;i++) 
	{
	glPushMatrix();    
    render(-16-4*i,0,6.2);   
    glPopMatrix();
    }
    glPushMatrix();    
    render1();   
    glPopMatrix();
    
    
   	for(i=0;i<=3;i++)
	{
	lamp_post(-4.4-8*i,1.0,12.0,0.6,90.0); 
    lamp_post(4.4+8*i,1.0,12.0,0.6,90.0);     
    }
    
    for(i=0;i<=7;i++)
	{
	lamp_post(-36.0,0.0,23.0-8*i,0.6,0.0); 
    lamp_post(36.0,0.0,23.0-8*i,0.6,180.0);      
    }

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
	glutCreateWindow("Scene No. 8-NAC Front");
	initRendering();
	
	//Set handler functions
	glutDisplayFunc(drawScene);
	
	
	//for tree
 	NewFractals();
     agvMakeAxesList(AXES);
     myGLInit(); 
     //for tree ends
    
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	
	glutTimerFunc(25, update, 0); //Add a timer
	
	glutMainLoop();
	return 0;
}









