#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

double rx1 = 0.0;
double ry1 = 0.0;

float l1[] = { -250.0,  0.0, 0.0 }; // Coordinates of the light source
float n1[] = { 1.0,  0.0, 0.0 }; // Normal vector for the plane
float e1[] = { -15.26, 0.0,15.0 }; // Point of the plane


// This function is called whenever the object needs to be drawn
// (For the shadow and itself; for each frame twice)
void draw1()
{

    // glDisable(GL_LIGHTING);
	drawNacBuilding(-26.2,-1.0,-0.5,0.0,0.3);
	drawNacBuilding(-27.2,-1.0,-1.7,-30.0,0.1);
    glEnable(GL_LIGHTING); 
	//glTranslatef(8.0,4.6,0.0);
	//glScalef(10.0,10.0,10.0);
	//drawRoad();
}

/*
 * This is where the "magic" is done:
 *
 * Multiply the current ModelView-Matrix with a shadow-projetion
 * matrix.
 *
 * l is the position of the light source
 * e is a point on within the plane on which the shadow is to be
 *   projected.  
 * n is the normal vector of the plane.
 *
 * Everything that is drawn after this call is "squashed" down
 * to the plane. Hint: Gray or black color and no lighting 
 * looks good for shadows *g*
 */
void glShadowProjection1(float * l, float * e, float * n)
{
  float d, c;
  float mat[16];

  // These are c and d (corresponding to the tutorial)
  
  d = n1[0]*l1[0] + n1[1]*l1[1] + n1[2]*l1[2];
  c = e1[0]*n1[0] + e1[1]*n1[1] + e1[2]*n1[2] - d;

  // Create the matrix. OpenGL uses column by column
  // ordering

  mat[0]  = l1[0]*n1[0]+c; 
  mat[4]  = n1[1]*l1[0]; 
  mat[8]  = n1[2]*l1[0]; 
  mat[12] = -l1[0]*c-l1[0]*d;
  
  mat[1]  = n1[0]*l1[1];        
  mat[5]  = l1[1]*n1[1]+c;
  mat[9]  = n1[2]*l1[1]; 
  mat[13] = -l1[1]*c-l1[1]*d;
  
  mat[2]  = n1[0]*l1[2];        
  mat[6]  = n1[1]*l1[2]; 
  mat[10] = l1[2]*n1[2]+c; 
  mat[14] = -l1[2]*c-l1[2]*d;
  
  mat[3]  = n1[0];        
  mat[7]  = n1[1]; 
  mat[11] = n1[2]; 
  mat[15] = -d;

  // Finally multiply the matrices together *plonk*
  glMultMatrixf(mat);
}

/** 
 * render - gets called whenever we want to redraw the scene
 */
void render1()
{
  glPushMatrix();
  //glTranslatef(a,b,c);
  glColor3f(0.0,0.0,0.0);
  glBegin(GL_POINTS);
  glVertex3f(l1[0],l1[1],l1[2]);
  glEnd();

  // First, we draw the plane onto which the shadow should fall
  // The Y-Coordinate of the plane is reduced by 0.1 so the plane is
  // a little bit under the shadow. We reduce the risk of Z-Buffer
  // flittering this way.
  /*glColor3f(0.8,0.8,0.8);
  glBegin(GL_QUADS);
  glNormal3f(0.0,1.0,0.0);

  glVertex3f(-1300.0,-2.0, 1300.0);
  glVertex3f( 1300.0,-2.0, 1300.0);
  glVertex3f( 1300.0,-2.0,-1300.0);
  glVertex3f(-1300.0,-2.0,-1300.0);
  
  glEnd();
*/

  // Draw the object that casts the shadow
  glPushMatrix();
 // glRotatef(ry,0,1,0);
 // glTranslatef(0.0,-65.0,0.0);
 //glRotatef(rx,1,0,0);
  glEnable(GL_LIGHTING);
  glColor3f(0.0,1.0,0.5);
  draw1();
  glPopMatrix();
glDisable(GL_LIGHTING);
  // Now we draw the shadow
  glPushMatrix();
  glShadowProjection(l1,e1,n1);  
 // glRotatef(ry,0,1,0);
  //glRotatef(rx,1,0,0);
 // glDisable(GL_LIGHTING);
  glColor3f(0.4,0.4,0.4);
  draw1();
  glPopMatrix();
  
  glPopMatrix();

}

