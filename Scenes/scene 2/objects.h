#include <GL/glut.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>           /* ULONG_MAX is defined here */
#include <float.h>            /* FLT_MAX is atleast defined here */

#include <time.h>  /* for random seed */

#include "fracviewer.h"

#ifdef WIN32
#define drand48() (((float) rand())/((float) RAND_MAX))
#define srand48(x) (srand((x)))
#endif

typedef enum { NOTALLOWED, MOUNTAIN, TREE, ISLAND, BIGMTN, STEM, LEAF, 
               MOUNTAIN_MAT, WATER_MAT, LEAF_MAT, TREE_MAT, STEMANDLEAVES,
               AXES,BUSSTOP } DisplayLists;

#define MAXLEVEL 8

int Rebuild = 1,        /* Rebuild display list in next display? */
    Fract   = TREE,     /* What fractal are we building */
    Level   = 5;        /* levels of recursion for fractals */     

int DrawAxes = 0; 

using namespace std;

void drawTennisCourt(float a, float b, float c,float d) {
    glPushMatrix();
    glTranslatef(a,b,c);
    glScalef(d,d,d);
	glColor3f(0.0f, 1.0f, 0.2f);
	
	glBegin(GL_QUADS);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(7.0f, 0.0f, 3.0f);
	glVertex3f(-7.0f, 0.0f, 3.0f);
	glVertex3f(-7.0f, 0.0f, -3.0f);
	glVertex3f(7.0f, 0.0f, -3.0f);

	glColor3f(0.2f, 0.0f,1.0f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(6.0f, 0.001f, 2.5f);
	glVertex3f(-6.0f, 0.001f, 2.5f);
	glVertex3f(-6.0f, 0.001f, -2.5f);
	glVertex3f(6.0f, 0.001f, -2.5f);

	glEnd();

	glColor3f(1.0f,1.0f,1.0f);
	glLineStipple(1, 0xAAAA);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.002f, 2.5f);
	glVertex3f(0.0f, 0.002f, -2.5f);
	
	glVertex3f(0.0f, 0.1f, 2.5f);
	glVertex3f(0.0f, 0.1f, -2.5f);
	
	glVertex3f(0.0f, 0.2f, 2.5f);
	glVertex3f(0.0f, 0.2f, -2.5f);
	
	glVertex3f(0.0f, 0.2f, 2.5f);
	glVertex3f(0.0f, 0.2f, -2.5f);
	
	glVertex3f(0.0f, 0.3f, 2.5f);
	glVertex3f(0.0f, 0.3f, -2.5f);

	glDisable(GL_LINE_STIPPLE);

	glVertex3f(-3.0f, 0.001f, 2.5f);
	glVertex3f(-3.0f, 0.001f, -2.5f);

	glVertex3f(3.0f, 0.001f, 2.5f);
	glVertex3f(3.0f, 0.001f, -2.5f);

	glVertex3f(3.0f, 0.001f, 0.0f);
	glVertex3f(-3.0f, 0.001f, 0.0f);
	
	glVertex3f(6.0f, 0.001f, 2.2f);
	glVertex3f(-6.0f, 0.001f, 2.2f);
	
	glVertex3f(6.0f, 0.001f, -2.2f);
	glVertex3f(-6.0f, 0.001f, -2.2f);
	
   /* glVertex3f(5.5f, 0.001f, 2.5f);
	glVertex3f(5.5f, 0.001f, -2.5f);
	
	glVertex3f(-5.5f, 0.001f, 2.5f);
	glVertex3f(-5.5f, 0.001f, -2.5f);*/

	glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(0.0f, 0.001f, 2.5f);
	glVertex3f(0.0f, 0.3f, 2.5f);

	glVertex3f(0.0f, 0.001f, -2.5f);
	glVertex3f(0.0f, 0.3f, -2.5f);

	glEnd();
	glPopMatrix();
	

}


void drawBase(float a,float b,float c){
    glPushMatrix();
    glTranslatef(a,b,c);
    glColor3f(0.83f, 0.7f,0.2f);  
    glBegin(GL_QUADS);
	
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(80.0f, -0.1f, 50.0f);
	glVertex3f(-80.0f, -0.1f, 50.0f);
	glVertex3f(-80.0f, -0.1f, -50.0f);
	glVertex3f(80.0f, -0.1f, -50.0f);

	glEnd();
	glPopMatrix();     
} 

void lamp_post(float a, float b, float c, float d)
{
    glPushMatrix();
    glTranslatef(a, b, c);
    glScalef(d, d, d);
    glColor3f(1.0f, 1.0f, 0.0f);
    //glRotatef(-90, 0.0f, 1.0f, 0.0f);

    GLUquadricObj *cylquad = gluNewQuadric();
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	gluCylinder(cylquad, 0.1, 0.1, 5, 10, 2 );
	glRotatef(120, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 0.0f);
	gluCylinder(cylquad, 0.1, 0.1, 1, 10, 2 );
	glTranslatef(-0.1f, 0.0f, 0.9f);
	glColor3f(1.0f, 0.6f, 0.0f);
	gluSphere(cylquad,0.25,10,2);
	glPopMatrix();
} 

void lamp_post1(float a, float b, float c, float d)
{
    glPushMatrix();
    glTranslatef(a, b, c);
    glScalef(d, d, d);
    glColor3f(1.0f, 1.0f, 0.0f);
    //glRotatef(-90, 0.0f, 1.0f, 0.0f);

    GLUquadricObj *cylquad = gluNewQuadric();
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	gluCylinder(cylquad, 0.1, 0.1, 5, 10, 2 );
	glRotatef(120, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 0.0f);
	gluCylinder(cylquad, 0.1, 0.1, 1, 10, 2 );
	glTranslatef(-0.1f, 0.0f, 0.9f);
	glColor3f(1.0f, 0.6f, 0.0f);
	gluSphere(cylquad,0.25,10,2);
	
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glTranslatef(1.0f, 0.0f, 0.0f);
	gluCylinder(cylquad, 0.1, 0.1, 1, 10, 2 );	
    glTranslatef(0.1f, 0.0f, 0.9f);
	glColor3f(1.0f, 0.6f, 0.0f);
	gluSphere(cylquad,0.25,10,2);
	glPopMatrix();
} 

void drawRoad(float a,float b,float c,float d,float e,float f)
{
    glPushMatrix();
    glTranslatef(a,b,c);
    glScalef(d,e,f);
    
    glColor3f(0.0f, 0.1f,0.1f); 
    glBegin(GL_QUADS);
	
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 15.0f);
	glVertex3f(-1.0f, 0.0f, 15.0f);
	glVertex3f(-1.0f, 0.0f, -15.0f);
	glVertex3f(1.0f, 0.0f, -15.0f);
	glEnd();
	glPopMatrix();     
} 
void drawDivider(float a,float b,float c,float d,float e,float f)
{
    glPushMatrix();
    glTranslatef(a,b,c);
    glScalef(d,e,f);
	glColor3f(0.8f, 0.6f,0.0f); 
	glutSolidCube(0.2);
	glPopMatrix();     
}   
   

void drawSacBuilding(float a,float b,float c,float d,float e,float f)
{
     	glPushMatrix();
     	glTranslatef(a,b,c);
    glScalef(d,e,f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	
	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	glVertex3f(1.5f, -1.0f, 1.5f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	
	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.5f, -1.0f, -1.5f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	glVertex3f(1.5f, -1.0f, 1.5f);
	
	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	glVertex3f(1.5f, -1.0f, -1.5f);
	
	//Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	
	glEnd();

	

	//door
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.52f,-1.0f,0.5f);
    glVertex3f(-1.52f,-1.0f,-0.5f);
    glVertex3f(-1.52f,0.0f,-0.5f);
    glVertex3f(-1.52f,0.0f,0.5f);
	glEnd();

	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	//front
	glNormal3f(0.0f, 1.0f, 0.66f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	glVertex3f(0.0f, 2.0f, 0.0f);

	//right
	glNormal3f(0.66f, 1.0f, 0.0f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	glVertex3f(0.0f, 2.0f, 0.0f);

	//back
	glNormal3f(0.0f, 1.0f, -0.66f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	glVertex3f(0.0f, 2.0f, 0.0f);

	//left
	glNormal3f(-0.66f, 1.0f, 0.0f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	glVertex3f(0.0f, 2.0f, 0.0f);

	glEnd();

	glPopMatrix();

} 

void drawStair(float a,float b,float c,float d,float e,float f)
{
     glPushMatrix();
    glTranslatef(a,b,c);
    glScalef(d,e,f);
    
    glColor3f(0.8f, 0.8f,0.8f);
    glutSolidCube(0.4f);
    
    glPopMatrix();
}

void drawField(float a,float b,float c,float d,float e,float f)
{
    glPushMatrix();
    glTranslatef(a,b,c);
    glScalef(d,e,f);
    
    glColor3f(0.0f, 1.0f,0.0f);  
    glBegin(GL_QUADS);
	
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(6.0f, 0.0f, 4.0f);
	glVertex3f(-6.0f, 0.0f, 4.0f);
	glVertex3f(-6.0f, 0.0f, -4.0f);
	glVertex3f(6.0f, 0.0f, -4.0f);
	glEnd();
	
	glPopMatrix();
}

void drawPath(float a,float b,float c,float d,float e,float f)
{
    glPushMatrix();
    glTranslatef(a,b,c);
    glScalef(d,e,f);
    
    glColor3f(0.8f, 0.8f,0.8f);  
    glBegin(GL_QUADS);
	
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.5f, 0.0f, 4.0f);
	glVertex3f(-0.5f, 0.0f, 4.0f);
	glVertex3f(-0.5f, 0.0f, -4.0f);
	glVertex3f(0.5f, 0.0f, -4.0f);

	glEnd();
	glPopMatrix();
}

void drawBoundry(float a,float b,float c,float d,float e,float f)
{
    glPushMatrix();
    glTranslatef(a,b,c);
    //glScalef(d,e,f);
    glColor3f(0.0f,0.0f,0.0f);
    
    glBegin(GL_LINES);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,1.0f,0.0f);
    
    glVertex3f(0.0f,0.0f,f);
    glVertex3f(0.0f,1.0f,f);
    
    glVertex3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f,1.0f,f);
    float i;
    for(i=0.0;i<=f;i+=0.3)
    {
    glVertex3f(0.0f,0.0f,i);
    glVertex3f(0.0f,1.0f,i);
    }   
    for(i=0.0;i<=1.0;i+=0.2)
    {
    glVertex3f(0.0f,i,0.0f);
    glVertex3f(0.0f,i,f);
    }                         
    glDisable(GL_LINE_STIPPLE);
    glEnd(); 
    
    GLUquadricObj *cylquad = gluNewQuadric();
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0,0.0,-1.0);
	gluCylinder(cylquad, 0.01, 0.01, 2.0, 10, 2 );
    glPopMatrix(); 
} 

void drawGate(float a,float b,float c,float d,float e,float f)
{
    glPushMatrix();
    glTranslatef(a,b,c);
    glScalef(d,e,f);
    glColor3f(1.0f,1.0f,0.4f);
 
    glBegin(GL_LINES);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,1.0f,0.0f);
    
    glVertex3f(0.0f,0.0f,0.5f);
    glVertex3f(0.0f,1.5f,0.5f);
    
    glVertex3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f,1.5f,0.5f);
    float i;
    for(i=0.0;i<=0.5;i+=0.01)
    {
    glVertex3f(0.0f,0.0f,i);
    glVertex3f(0.0f,1.0f,i);
    }   
    for(i=0.0;i<=1.0;i+=0.02)
    {
    glVertex3f(0.0f,i,0.0f);
    glVertex3f(0.0f,i,0.5f);
    }                         
    glDisable(GL_LINE_STIPPLE);
    glEnd(); 
    
    GLUquadricObj *cylquad = gluNewQuadric();
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0,0.0,-1.0);
	gluCylinder(cylquad, 0.01, 0.01, 2.0, 10, 2 );
    glPopMatrix(); 
}  

void drawGoal(float a,float b,float c,float d,float e,float f)
{
    glPushMatrix();	
	glTranslatef(a,b,c);
    glScalef(d,e,f);
    glColor3f(0.0f,0.0f,0.0f);
    
    glBegin(GL_LINES);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,1.0f,0.0f);
    
    glVertex3f(0.5f,0.0f,0.0f);
    glVertex3f(0.5f,1.0f,0.0f);
    
    glVertex3f(0.5f,1.0f,0.0f);
    glVertex3f(0.0f,1.0f,0.0f);    
    
    glVertex3f(0.0f,0.0f,2.0f);
    glVertex3f(0.0f,1.0f,2.0f);
    
    glVertex3f(0.5f,0.0f,2.0f);
    glVertex3f(0.5f,1.0f,2.0f);
    
    glVertex3f(0.5f,1.0f,2.0f);
    glVertex3f(0.0f,1.0f,2.0f);
    
    glVertex3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f,1.0f,2.0f);
    
    glVertex3f(0.5f,1.0f,0.0f);
    glVertex3f(0.5f,1.0f,2.0f);
    float i;
    for(i=0.0;i<=1.0;i+=0.1)
    {
     glVertex3f(0.5f,i,0.0f);
     glVertex3f(0.5f,i,2.0f);                       
     }
     
     for(i=0.0;i<=2.0;i+=0.1)
    {
     glVertex3f(0.5f,0.0f,i);
     glVertex3f(0.5f,1.0f,i);                       
     }                                                                                       

    glEnd();
	glPopMatrix();
	
}	

      

/***************************************************************/
/************************* VECTOR JUNK *************************/
/***************************************************************/

  /* print vertex to stderr */
void printvert(float v[3])
{
  fprintf(stderr, "(%f, %f, %f)\n", v[0], v[1], v[2]);
}

  /* normalizes v */
void normalize(GLfloat v[3])
{
  GLfloat d = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);

  if (d == 0)
    fprintf(stderr, "Zero length vector in normalize\n");
  else
    v[0] /= d; v[1] /= d; v[2] /= d;
}

  /* calculates a normalized crossproduct to v1, v2 */
void ncrossprod(float v1[3], float v2[3], float cp[3])
{
  cp[0] = v1[1]*v2[2] - v1[2]*v2[1];
  cp[1] = v1[2]*v2[0] - v1[0]*v2[2];
  cp[2] = v1[0]*v2[1] - v1[1]*v2[0];
  normalize(cp);
}

  /* calculates normal to the triangle designated by v1, v2, v3 */
void triagnormal(float v1[3], float v2[3], float v3[3], float norm[3])
{
  float vec1[3], vec2[3];

  vec1[0] = v3[0] - v1[0];  vec2[0] = v2[0] - v1[0];
  vec1[1] = v3[1] - v1[1];  vec2[1] = v2[1] - v1[1];
  vec1[2] = v3[2] - v1[2];  vec2[2] = v2[2] - v1[2];

  ncrossprod(vec2, vec1, norm);
}

float xzlength(float v1[3], float v2[3])
{
  return sqrt((v1[0] - v2[0])*(v1[0] - v2[0]) +
              (v1[2] - v2[2])*(v1[2] - v2[2]));
}

float xzslope(float v1[3], float v2[3])
{
  return ((v1[0] != v2[0]) ? ((v1[2] - v2[2]) / (v1[0] - v2[0]))
	                   : FLT_MAX);
}


/***************************************************************/
/***************************** TREE ****************************/
/***************************************************************/

long TreeSeed;   /* for srand48 - remember so we can build "same tree"
                     at a different level */

 /*
  * recursive tree drawing thing, fleshed out from class notes pseudocode 
  */
void FractalTree(int level)
{
  long savedseed;  /* need to save seeds while building tree too */

  if (level == Level) {
      glPushMatrix();
        glRotatef(drand48()*180, 0, 1, 0);
        glCallList(STEMANDLEAVES);
      glPopMatrix();
  } else {
    glCallList(STEM);
    glPushMatrix();
    glRotatef(drand48()*180, 0, 1, 0);
    glTranslatef(0, 1, 0);
    glScalef(0.7, 0.7, 0.7);

      savedseed = (long) drand48()*ULONG_MAX;    /* recurse on a 3-way branching */
      glPushMatrix();    
        glRotatef(110 + drand48()*40, 0, 1, 0);
        glRotatef(30 + drand48()*20, 0, 0, 1);
        FractalTree(level + 1);

      glPopMatrix();

      srand48(savedseed);
      savedseed = (long) drand48()*ULONG_MAX;
      glPushMatrix();
        glRotatef(-130 + drand48()*40, 0, 1, 0);
        glRotatef(30 + drand48()*20, 0, 0, 1);
        FractalTree(level + 1);
      glPopMatrix();

      srand48(savedseed);
      glPushMatrix();
        glRotatef(-20 + drand48()*40, 0, 1, 0);
        glRotatef(30 + drand48()*20, 0, 0, 1);
        FractalTree(level + 1);
      glPopMatrix();

    glPopMatrix();
  }
}

  /*
   * Create display lists for a leaf, a set of leaves, and a stem
   */
void CreateTreeLists(void)
{
  GLUquadricObj *cylquad = gluNewQuadric();
  int i;

  glNewList(STEM, GL_COMPILE);
  glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    gluCylinder(cylquad, 0.1, 0.08, 1, 10, 2 );
  glPopMatrix();
  glEndList();

  glNewList(LEAF, GL_COMPILE);  /* I think this was jeff allen's leaf idea */
    glBegin(GL_TRIANGLES);
      glNormal3f(-0.1, 0, 0.25);  /* not normalized */
      glVertex3f(0, 0, 0);
      glVertex3f(0.25, 0.25, 0.1);
      glVertex3f(0, 0.5, 0);

      glNormal3f(0.1, 0, 0.25);
      glVertex3f(0, 0, 0);
      glVertex3f(0, 0.5, 0);
      glVertex3f(-0.25, 0.25, 0.1);
    glEnd();
  glEndList();

  glNewList(STEMANDLEAVES, GL_COMPILE);
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
    glCallList(STEM);
    glCallList(LEAF_MAT);
    for(i = 0; i < 3; i++) {
      glTranslatef(0, 0.333, 0);
      glRotatef(90, 0, 1, 0);
      glPushMatrix();
        glRotatef(0, 0, 1, 0);
        glRotatef(50, 1, 0, 0);
        glCallList(LEAF);
      glPopMatrix();
      glPushMatrix();
        glRotatef(180, 0, 1, 0);
        glRotatef(60, 1, 0, 0);
        glCallList(LEAF);
      glPopMatrix();
    }
  glPopAttrib();
  glPopMatrix();
  glEndList();
}

 /*
  * draw and build display list for tree
  */
  
void TreeSetLevel(int a)
{
 Level=a;
 FractalTree(0);    
}

void CreateTree(float a ,float b,float c,float d,float e,float f,int g)
{
  srand48(TreeSeed);

    glNewList(TREE, GL_COMPILE);
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
    glCallList(TREE_MAT);
    glTranslatef(a,b,c);
    glScalef(d,e,f);
    TreeSetLevel(g);
    glPopAttrib();
    glPopMatrix();
  glEndList();  
}

 /*
  * new seed for a new tree (groan)
  */
void NewTree(void)
{
  TreeSeed = time(NULL);
}

void NewFractals(void)
{
  NewTree();
}


/***************************************************************/
/**************************** OPENGL ***************************/
/***************************************************************/



void SetupMaterials(void)
{
 /* GLfloat mtn_ambuse[] =   { 0.426, 0.256, 0.108, 1.0 };
  GLfloat mtn_specular[] = { 0.394, 0.272, 0.167, 1.0 };
  GLfloat mtn_shininess[] = { 10 };

  GLfloat water_ambuse[] =   { 0.0, 0.1, 0.5, 1.0 };
  GLfloat water_specular[] = { 0.0, 0.1, 0.5, 1.0 };
  GLfloat water_shininess[] = { 10 };*/

  GLfloat tree_ambuse[] =   { 0.4, 0.25, 0.1, 1.0 };
  GLfloat tree_specular[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat tree_shininess[] = { 0 };

  GLfloat leaf_ambuse[] =   { 0.0, 0.8, 0.0, 1.0 };
  GLfloat leaf_specular[] = { 0.0, 0.8, 0.0, 1.0 };
  GLfloat leaf_shininess[] = { 10 };

 /* glNewList(MOUNTAIN_MAT, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mtn_ambuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mtn_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mtn_shininess);
  glEndList();

  glNewList(WATER_MAT, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, water_ambuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, water_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, water_shininess);
  glEndList();
*/
  glNewList(TREE_MAT, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, tree_ambuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, tree_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, tree_shininess);
  glEndList();

  glNewList(LEAF_MAT, GL_COMPILE);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, leaf_ambuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, leaf_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, leaf_shininess);
  glEndList();
}

void myGLInit(void)
{
  GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_position[] = { 0.0, 0.3, 0.3, 0.0 };

  GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };

  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  glDepthFunc(GL_LEQUAL);
  glEnable(GL_DEPTH_TEST);

  glEnable(GL_NORMALIZE);
#if 0
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
#endif

  glShadeModel(GL_SMOOTH);
#if 0
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
#endif

  SetupMaterials();
  CreateTreeLists();

  glFlush();
} 

/***************************************************************/
/************************ GLUT STUFF ***************************/
/***************************************************************/

void reshape(GLsizei w, GLsizei h)
{
  glViewport(0,0,w,h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, (GLdouble)w/h, 0.01, 100);
  glPushMatrix();
  glMatrixMode(GL_MODELVIEW);
  glFlush();
}

//tree ends
