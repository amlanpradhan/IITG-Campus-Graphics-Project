/* Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/* File for "Lighting" lesson of the OpenGL tutorial on
 * www.videotutorialsrock.com
 */



#include <iostream>
#include <stdlib.h>
#include <math.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

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
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 45.0f;

//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
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
	//glPushMatrix();

	glScalef(0.7f,0.7f, 0.7f);
	glColor3f(0.5f, 0.75f, 0.5f);
	glBegin(GL_QUADS);
	
	//This is the core

	//Front
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-4.0f, 1.25f, -2.0f);
	glVertex3f(4.0f, 1.25f, -2.0f);
	glVertex3f(4.0f, -1.25f, -2.0f);
	glVertex3f(-4.0f, -1.25f, -2.0f);
	
	//Back
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-4.0f, 1.25f, 2.0f);
	glVertex3f(4.0f, 1.25f, 2.0f);
	glVertex3f(4.0f, -1.25f, 2.0f);
	glVertex3f(-4.0f, -1.25f, 2.0f);
	
	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(4.0f, 1.25f, 2.0f);
	glVertex3f(4.0f, -1.25f, 2.0f);
	glVertex3f(4.0f, -1.25f, -2.0f);
	glVertex3f(4.0f, 1.25f, -2.0f);
	
	//Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-4.0f, 1.25f, 2.0f);
	glVertex3f(-4.0f, 1.25f, -2.0f);
	glVertex3f(-4.0f, -1.25f, -2.0f);
	glVertex3f(-4.0f, -1.25f, 2.0f);

	glEnd();

	glColor3f(1.0f, 0.9f, 0.1f);

	glBegin(GL_QUADS);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(3.0f, 0.6f, -2.01f);
	glVertex3f(3.0f, -0.6f, -2.01f);
	glVertex3f(2.50f, -0.6f, -2.01f);
	glVertex3f(2.5f, 0.6f, -2.01f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(2.0f, 0.6f, -2.01f);
	glVertex3f(2.0f, -0.6f, -2.01f);
	glVertex3f(1.50f, -0.6f, -2.01f);
	glVertex3f(1.5f, 0.6f, -2.01f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(1.0f, 0.6f, -2.01f);
	glVertex3f(1.0f, -0.6f, -2.01f);
	glVertex3f(0.50f, -0.6f, -2.01f);
	glVertex3f(0.5f, 0.6f, -2.01f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, 0.6f, -2.01f);
	glVertex3f(-1.0f, -0.6f, -2.01f);
	glVertex3f(-0.50f, -0.6f, -2.01f);
	glVertex3f(-0.5f, 0.6f, -2.01f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-3.0f, 0.6f, -2.01f);
	glVertex3f(-3.0f, -0.6f, -2.01f);
	glVertex3f(-2.50f, -0.6f, -2.01f);
	glVertex3f(-2.5f, 0.6f, -2.01f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-2.0f, 0.6f, -2.01f);
	glVertex3f(-2.0f, -0.6f, -2.01f);
	glVertex3f(-1.50f, -0.6f, -2.01f);
	glVertex3f(-1.5f, 0.6f, -2.01f);

	//rear windows

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(3.0f, 0.6f, 2.01f);
	glVertex3f(3.0f, -0.6f, 2.01f);
	glVertex3f(2.50f, -0.6f, 2.01f);
	glVertex3f(2.5f, 0.6f, 2.01f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(2.0f, 0.6f, 2.01f);
	glVertex3f(2.0f, -0.6f, 2.01f);
	glVertex3f(1.50f, -0.6f, 2.01f);
	glVertex3f(1.5f, 0.6f, 2.01f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 0.6f, 2.01f);
	glVertex3f(1.0f, -0.6f, 2.01f);
	glVertex3f(0.50f, -0.6f, 2.01f);
	glVertex3f(0.5f, 0.6f, 2.01f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, 0.6f, 2.01f);
	glVertex3f(-1.0f, -0.6f, 2.01f);
	glVertex3f(-0.50f, -0.6f, 2.01f);
	glVertex3f(-0.5f, 0.6f, 2.01f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-3.0f, 0.6f, 2.01f);
	glVertex3f(-3.0f, -0.6f, 2.01f);
	glVertex3f(-2.50f, -0.6f, 2.01f);
	glVertex3f(-2.5f, 0.6f, 2.01f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-2.0f, 0.6f, 2.01f);
	glVertex3f(-2.0f, -0.6f, 2.01f);
	glVertex3f(-1.50f, -0.6f, 2.01f);
	glVertex3f(-1.5f, 0.6f, 2.01f);

	glEnd();

	//Here are the doors

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_QUADS);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(4.001f, 1.0f, 1.0f);
	glVertex3f(4.001f, -1.25f, 1.0f);
	glVertex3f(4.001f, -1.25f, -1.0f);
	glVertex3f(4.001f, 1.0f, -1.0f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-4.001f, 1.0f, 1.0f);
	glVertex3f(-4.001f, -1.25f, 1.0f);
	glVertex3f(-4.001f, -1.25f, -1.0f);
	glVertex3f(-4.001f, 1.0f, -1.0f);

	glEnd();

	//And now the domes

	float i= 0.0f;
	float j= 0.0f;

	glColor3f(0.0f, 0.0f, 1.0f);

	glBegin(GL_POLYGON);

		for(i=0.0f; i<=180.0f; i+=0.5)
	for(j= 0.0f; j<=1.75f; j+=0.2)
		glVertex3f(3.99f-j, (1.25+2.0*cos(i)), 2.0*sin(i));


	glColor3f(1.0f, 0.0f, 0.0f);

	for(i=0.0f; i<=180.0f; i+=0.5)
	for(j= 0.0f; j<=0.75f; j+=0.2)
		glVertex3f(2.24f-j, (1.25+2.75*cos(i)), 2.0*sin(i));


	glColor3f(0.0f, 0.0f, 1.0f);

	for(i=0.0f; i<=180.0f; i+=0.5)
	for(j= 0.0f; j<=1.75f; j+=0.2)
		glVertex3f(1.49f-j, (1.25+2.0*cos(i)), 2.0*sin(i));


	glColor3f(1.0f, 0.0f, 0.0f);

	for(i=0.0f; i<=180.0f; i+=0.5)
	for(j= 0.0f; j<=0.75f; j+=0.2)
		glVertex3f(-0.24f-j, (1.25+2.75*cos(i)), 2.0*sin(i));


	glColor3f(0.0f, 0.0f, 1.0f);

	for(i=0.0f; i<=180.0f; i+=0.5)
	for(j= 0.0f; j<=3.01f; j+=0.2)
		glVertex3f(-0.99f-j, (1.25+2.0*cos(i)), 2.0*sin(i));



	glEnd();


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
	glutInitWindowSize(400, 400);
	
	//Create the window
	glutCreateWindow("Workshop");
	initRendering();
	
	//Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	
	glutTimerFunc(25, update, 0); //Add a timer
	
	glutMainLoop();
	return 0;
}









