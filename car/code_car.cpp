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



#include <iostream>
#include <stdlib.h>
#include<math.h>

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

float _angle = -70.0f;

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
	
	//glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	glPushMatrix();

	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-4.0f, 0.0f, 0.0f);
	glVertex3f(2.5f, 0.0f, 0.0f);
	glVertex3f(2.5f, 1.25f, 0.0f);
	glVertex3f(2.0f, 1.25f, 0.0f);
	glVertex3f(1.0f, 2.5f, 0.0f);
	glVertex3f(-1.5f, 2.5f, 0.0f);
	glVertex3f(-2.5f, 1.25f, 0.0f);
	glVertex3f(-4.0f, 1.0f, 0.0f);
	
	glEnd();

	glBegin(GL_POLYGON);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-4.0f, 0.0f, 2.0f);
	glVertex3f(2.5f, 0.0f, 2.0f);
	glVertex3f(2.5f, 1.25f, 2.0f);
	glVertex3f(2.0f, 1.25f, 2.0f);
	glVertex3f(1.0f, 2.5f, 2.0f);
	glVertex3f(-1.5f, 2.5f, 2.0f);
	glVertex3f(-2.5f, 1.25f, 2.0f);
	glVertex3f(-4.0f, 1.0f, 2.0f);
	
	glEnd();

	glBegin(GL_QUADS);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.5f, 0.0f, 0.0f);
	glVertex3f(2.5f, 1.25f, 0.0f);
	glVertex3f(2.5f, 1.25f, 2.0f);
	glVertex3f(2.5f, 0.0f, 2.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(2.5f, 1.25f, 0.0f);
	glVertex3f(2.5f, 1.25f, 2.0f);
	glVertex3f(2.0f, 1.25f, 2.0f);
	glVertex3f(2.0f, 1.25f, 0.0f);

	glNormal3f(5.0f, 4.0f, 0.0f);
	glVertex3f(2.0f, 1.25f, 0.0f);
	glVertex3f(2.0f, 1.25f, 2.0f);
	glVertex3f(1.0f, 2.5f, 2.0f);
	glVertex3f(1.0f, 2.5f, 0.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 2.5f, 0.0f);
	glVertex3f(1.0f, 2.5f, 2.0f);
	glVertex3f(-1.5f, 2.5f, 2.0f);
	glVertex3f(-1.5f, 2.5f, 0.0f);

	glNormal3f(-10.0f, 8.0f, 0.0f);
	glVertex3f(-1.5f, 2.5f, 2.0f);
	glVertex3f(-1.5f, 2.5f, 0.0f);
	glVertex3f(-2.5f, 1.25f, 0.0f);
	glVertex3f(-2.5f, 1.25f, 2.0f);

	glNormal3f(-1.0f, 6.0f, 0.0f);
	glVertex3f(-2.5f, 1.25f, 0.0f);
	glVertex3f(-2.5f, 1.25f, 2.0f);
	glVertex3f(-4.0f, 1.0f, 2.0f);
	glVertex3f(-4.0f, 1.0f, 0.0f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-4.0f, 1.0f, 2.0f);
	glVertex3f(-4.0f, 1.0f, 0.0f);
	glVertex3f(-4.0f, 0.0f, 0.0f);
	glVertex3f(-4.0f, 0.0f, 2.0f);
	
	glEnd();

	float i=0.0f, j=0.0f;

	//Front wheels

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_POLYGON);

	glNormal3f(0.0f, 0.0f, -1.0f);
	for(j=0.0; j<=180.0; j++)
	for(i=-0.001f; i<=0.2;i+=0.05)
		{
			glVertex3f(-2.5+0.5*cos(j), 0.5*sin(j), i);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 0.0f, 1.0f);
	for(j=0.0; j<=180.0; j++)
	for(i=0.001f; i>=-0.2;i-=0.05)
		{
			glVertex3f(-2.5+0.5*cos(j), 0.5*sin(j), i+2.0);
		}
	glEnd();


	//Rear Wheels

	glBegin(GL_POLYGON);

	glNormal3f(0.0f, 0.0f, -1.0f);
	for(j=0.0; j<=180.0; j++)
	for(i=-0.001f; i<=0.2;i+=0.05)	
		{
			glVertex3f(1.5+0.5*cos(j), 0.5*sin(j), i);
		}
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 0.0f, 1.0f);
	for(j=0.0; j<=180.0; j++)
	for(i=0.001f; i>=-0.2;i-=0.05)
		{
			glVertex3f(1.50+0.5*cos(j), 0.5*sin(j), i+2.0);
		}
	glEnd();

	//Front lights

	glBegin(GL_POLYGON);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	for(i=0.0; i<=180.0f; i++)
		glVertex3f(-4.001f, 0.5f+0.2*sin(i), 0.5f+0.2*cos(i));
	glEnd();

	glBegin(GL_POLYGON);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	for(i=0.0; i<=180.0f; i++)
		glVertex3f(-4.001f, 0.5f+0.2*sin(i), 1.5f+0.2*cos(i));
	glEnd();

	//Rear lights

	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_POLYGON);

	glNormal3f(1.0f, 0.0f, 0.0f);
	for(i=0.0; i<=180.0f; i++)
		glVertex3f(2.501f, 0.75f+0.15*sin(i), 0.5f+0.15*cos(i));
	glEnd();

	glBegin(GL_POLYGON);

	glNormal3f(1.0f, 0.0f, 0.0f);
	for(i=0.0; i<=180.0f; i++)
		glVertex3f(2.501f, 0.75f+0.15*sin(i), 1.5f+0.15*cos(i));
	glEnd();

	//Front doors

	glColor3f(0.6f, 0.6f, 0.6f);
	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-0.4f, 2.3f, -0.001f);
	glVertex3f(-1.5f, 2.3f, -0.001f);
	glVertex3f(-2.3f, 1.25f, -0.001f);
	glVertex3f(-0.4f, 1.25f, -0.001f);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.4f, 2.3f, 2.001f);
	glVertex3f(-1.5f, 2.3f, 2.001f);
	glVertex3f(-2.3f, 1.25f, 2.001f);
	glVertex3f(-0.4f, 1.25f, 2.001f);
	glEnd();

	//Back doors

	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, 2.3f, -0.001f);
	glVertex3f(1.0f, 2.3f, -0.001f);
	glVertex3f(1.8f, 1.25f, -0.001f);
	glVertex3f(0.0f, 1.25f, -0.001f);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 2.3f, 2.001f);
	glVertex3f(1.0f, 2.3f, 2.001f);
	glVertex3f(1.8f, 1.25f, 2.001f);
	glVertex3f(0.0f, 1.25f, 2.001f);
	glEnd();

	//Mirrors

	glBegin(GL_POLYGON);
	glNormal3f(-10.0f, 8.0f, 0.0f);
	glVertex3f(-1.501f, 2.5f, 2.0f);
	glVertex3f(-1.501f, 2.5f, 0.0f);
	glVertex3f(-2.501f, 1.25f, 0.0f);
	glVertex3f(-2.501f, 1.25f, 2.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(5.0f, 4.0f, 0.0f);
	glVertex3f(1.901f, 1.40f, 0.0f);
	glVertex3f(1.901f, 1.40f, 2.0f);
	glVertex3f(1.201f, 2.3f, 2.0f);
	glVertex3f(1.201f, 2.3f, 0.0f);
	glEnd();

	glPopMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);

	//door handles

	//bonnet
	
	
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
	glutCreateWindow("Vehicle");
	initRendering();
	
	//Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	
	glutTimerFunc(25, update, 0); //Add a timer
	
	glutMainLoop();
	return 0;
}









