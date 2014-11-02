void drawWindow(float,float,float,float);
void drawFloor(float, float, float, float);
void drawWing(float, float, float, float);
void joinWing();
void drawCube();
void drawCentre(float a, float b, float c, float d, float e);
void drawCircularRoad(float a, float b, float c, float d, float e);
void drawAudi(float, float, float, float);
void drawCC(float, float, float, float);
void drawAdmin(float, float, float, float, float, float, float);

void drawAdmin(float a, float b, float c, float d, float e, float f, float g)
{
    glPushMatrix();
    glTranslatef(a, b, c);
    glScalef(e, f, g);
    glRotatef(d, 0.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	
	//This is the middle cube

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
	glVertex3f(1.5f, -1.0f, -1.5f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	
	//Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	

	glEnd();


	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	
	//This is the right cube

	//Front
	glNormal3f(-2.0f, 0.0f, 4.0f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	glVertex3f(1.5f, -1.0f, 1.5f);
	glVertex3f(2.5f, -1.25f, 2.0f);
	glVertex3f(2.5f, 0.75f, 2.0f);

	//Back
	glNormal3f(2.0f, 0.0f, -4.0f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	glVertex3f(1.5f, -1.0f, -1.5f);
	glVertex3f(2.5f, -1.25f, -1.0f);
	glVertex3f(2.5f, 0.75f, -1.0f);
	
	//Right
	glNormal3f(2.0f, 0.0f, 0.0f);
	glVertex3f(2.5f, 0.75f, 2.0f);
	glVertex3f(2.5f, -1.25f, 2.0f);
	glVertex3f(2.5f, -1.25f, -1.0f);
	glVertex3f(2.5f, 0.75f, -1.0f);

	//Top

	glColor3f(1.0f,0.7f,0.8f);
	glNormal3f(2.0f, 0.0f, 0.0f);
	glVertex3f(2.4f, 0.75f, 2.0f);
	glVertex3f(1.4f, 1.0f, 1.5f);
	glVertex3f(1.4f, 1.0f, -1.5f);
	glVertex3f(2.4f, 0.75f, -1.0f);


	glColor3f(1.0f,1.0f,0.0f);
	glEnd();

glBegin(GL_QUADS);
	
	//This is the left cube

	//Front
	glNormal3f(2.0f, 0.0f, 4.0f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	glVertex3f(-2.5f, -1.25f, 2.0f);
	glVertex3f(-2.5f, 0.75f, 2.0f);

	//Back
	glNormal3f(-2.0f, 0.0f, -4.0f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	glVertex3f(-2.5f, -1.25f, -1.0f);
	glVertex3f(-2.5f, 0.75f, -1.0f);
	
	//Right
	glNormal3f(-2.0f, 0.0f, 0.0f);
	glVertex3f(-2.5f, 0.75f, 2.0f);
	glVertex3f(-2.5f, -1.25f, 2.0f);
	glVertex3f(-2.5f, -1.25f, -1.0f);
	glVertex3f(-2.5f, 0.75f, -1.0f);

	//Top
	glColor3f(1.0f,0.7f,0.8f);
	glNormal3f(-2.0f, 0.0f, 0.0f);
	glVertex3f(-2.4f, 0.75f, 2.0f);
	glVertex3f(-1.4f, 1.0f, 1.5f);
	glVertex3f(-1.4f, 1.0f, -1.5f);
	glVertex3f(-2.4f, 0.75f, -1.0f);


	glColor3f(1.0f,1.0f,0.0f);

	glEnd();
	

//	glPopMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
		//These are the stairs

	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_QUADS);
	
	//Front
	glNormal3f(0.0f,0.0f,1.0f);
	glVertex3f(-1.5f,-0.6f,1.6f);
	glVertex3f(1.5f,-0.6f,1.6f);
	glVertex3f(1.5f,-0.7f,1.6f);
	glVertex3f(-1.5f,-0.7f,1.6f);

	//Right
	glNormal3f(1.0f,0.0f,0.0f);
	glVertex3f(1.5f,-0.6f,1.5f);
	glVertex3f(1.5f,-0.7f,1.6f);
	glVertex3f(1.5f,-0.7f,1.5f);
	glVertex3f(1.5f,-0.6f,1.6f);

	//Left
	glNormal3f(-1.0f,0.0f,0.0f);
	glVertex3f(-1.5f,-0.6f,1.5f);
	glVertex3f(-1.5f,-0.7f,1.6f);
	glVertex3f(-1.5f,-0.7f,1.5f);
	glVertex3f(-1.5f,-0.6f,1.6f);

	//Top
	glNormal3f(0.0f,1.0f,0.0f);
	glVertex3f(-1.5f,-0.6f,1.5f);
	glVertex3f(1.5f,-0.6f,1.5f);
	glVertex3f(-1.5f,-0.6f,1.6f);
	glVertex3f(1.5f,-0.6f,1.6f);

	glEnd();

	//Second stair
	glBegin(GL_QUADS);
	
	//Front
	glNormal3f(0.0f,0.0f,1.0f);
	glVertex3f(-1.5f,-0.8f,1.7f);
	glVertex3f(1.5f,-0.8f,1.7f);
	glVertex3f(1.5f,-0.7f,1.7f);
	glVertex3f(-1.5f,-0.7f,1.7f);

	//Right
	glNormal3f(1.0f,0.0f,0.0f);
	glVertex3f(1.5f,-0.7f,1.5f);
	glVertex3f(1.5f,-0.8f,1.7f);
	glVertex3f(1.5f,-0.8f,1.5f);
	glVertex3f(1.5f,-0.7f,1.7f);

	//Left
	glNormal3f(-1.0f,0.0f,0.0f);
	glVertex3f(-1.5f,-0.7f,1.5f);
	glVertex3f(-1.5f,-0.8f,1.7f);
	glVertex3f(-1.5f,-0.8f,1.5f);
	glVertex3f(-1.5f,-0.7f,1.7f);

	//Top
	glNormal3f(0.0f,1.0f,0.0f);
	glVertex3f(-1.5f,-0.7f,1.5f);
	glVertex3f(1.5f,-0.7f,1.5f);
	glVertex3f(-1.5f,-0.7f,1.7f);
	glVertex3f(1.5f,-0.7f,1.7f);

	glEnd();

	//Third stair
	glBegin(GL_QUADS);
	
	//Front
	glNormal3f(0.0f,0.0f,1.0f);
	glVertex3f(-1.5f,-0.8f,1.8f);
	glVertex3f(1.5f,-0.8f,1.8f);
	glVertex3f(1.5f,-0.9f,1.8f);
	glVertex3f(-1.5f,-0.9f,1.8f);

	//Right
	glNormal3f(1.0f,0.0f,0.0f);
	glVertex3f(1.5f,-0.9f,1.5f);
	glVertex3f(1.5f,-0.8f,1.8f);
	glVertex3f(1.5f,-0.8f,1.5f);
	glVertex3f(1.5f,-0.9f,1.8f);

	//Left
	glNormal3f(-1.0f,0.0f,0.0f);
	glVertex3f(-1.5f,-0.9f,1.5f);
	glVertex3f(-1.5f,-0.8f,1.8f);
	glVertex3f(-1.5f,-0.8f,1.5f);
	glVertex3f(-1.5f,-0.9f,1.8f);

	//Top
	glNormal3f(0.0f,1.0f,0.0f);
	glVertex3f(-1.5f,-0.8f,1.5f);
	glVertex3f(1.5f,-0.8f,1.5f);
	glVertex3f(-1.5f,-0.8f,1.8f);
	glVertex3f(1.5f,-0.8f,1.8f);

	glEnd();

	//Third stair
	glBegin(GL_QUADS);
	
	//Front
	glNormal3f(0.0f,0.0f,1.0f);
	glVertex3f(-1.5f,-0.9f,1.9f);
	glVertex3f(1.5f,-0.9f,1.9f);
	glVertex3f(1.5f,-1.0f,1.9f);
	glVertex3f(-1.5f,-1.0f,1.9f);

	//Right
	glNormal3f(1.0f,0.0f,0.0f);
	glVertex3f(1.5f,-1.0f,1.5f);
	glVertex3f(1.5f,-0.9f,1.9f);
	glVertex3f(1.5f,-0.9f,1.5f);
	glVertex3f(1.5f,-1.0f,1.9f);

	//Left
	glNormal3f(-1.0f,0.0f,0.0f);
	glVertex3f(-1.5f,-1.0f,1.5f);
	glVertex3f(-1.5f,-0.9f,1.9f);
	glVertex3f(-1.5f,-0.9f,1.5f);
	glVertex3f(-1.5f,-1.0f,1.9f);

	//Top
	glNormal3f(0.0f,1.0f,0.0f);
	glVertex3f(-1.5f,-0.9f,1.5f);
	glVertex3f(1.5f,-0.9f,1.5f);
	glVertex3f(-1.5f,-0.9f,1.9f);
	glVertex3f(1.5f,-0.9f,1.9f);

	glEnd();
	
	glPopMatrix();
}



void drawCC(float a, float b, float c, float d)
{
    glPushMatrix();
    glTranslatef(a, b, c);
	glTranslatef(0.0f, -1.0f, 0.0f);
	glRotatef(d, 0.0f, 1.0f, 0.0f);
	//glScalef(0.15f, 0.2f, 0.2f);

	glBegin(GL_QUADS);
	
	//central-rectangular box
	          //base
	glColor3f(0.8f, 0.5f, 0.1f);
	glVertex3f(-10.0f, 0.0f, -5.0f);
	glVertex3f(10.0f, 0.0f, -5.0f);
	glVertex3f(10.0f, 0.0f, 5.0f);
	glVertex3f(-10.0f, 0.0f, 5.0f);
	          //top
	glVertex3f(-10.0f, 6.0f, -5.0f);
	glVertex3f(10.0f, 6.0f, -5.0f);
	glVertex3f(10.0f, 6.0f, 5.0f);
	glVertex3f(-10.0f, 6.0f, 5.0f);
	         //left
	glVertex3f(-10.0f, 0.0f, -5.0f);
	glVertex3f(-10.0f, 0.0f, 5.0f);
	glVertex3f(-10.0f, 6.0f, 5.0f);
	glVertex3f(-10.0f, 6.0f, -5.0f);

	glColor3f(0.7f, 0.2f, 0.0f);
	glVertex3f(-10.1f, 5.8f, -5.0f);
	glVertex3f(-10.1f, 5.8f, 5.0f);
	glVertex3f(-10.1f, 6.0f, 5.0f);
	glVertex3f(-10.1f, 6.0f, -5.0f);
	         //right
	glColor3f(0.8f, 0.5f, 0.1f);
	glVertex3f(10.0f, 0.0f, -5.0f);
	glVertex3f(10.0f, 0.0f, 5.0f);
	glVertex3f(10.0f, 6.0f, 5.0f);
	glVertex3f(10.0f, 6.0f, -5.0f);

	glColor3f(0.7f, 0.2f, 0.0f);
	glVertex3f(10.1f, 5.8f, -5.0f);
	glVertex3f(10.1f, 5.8f, 5.0f);
	glVertex3f(10.1f, 6.0f, 5.0f);
	glVertex3f(10.1f, 6.0f, -5.0f);

	         //front
    glColor3f(0.8f, 0.5f, 0.1f);
	glVertex3f(10.0f, 0.0f, 5.0f);
	glVertex3f(-10.0f, 0.0f, 5.0f);
	glVertex3f(-10.0f, 6.0f, 5.0f);
	glVertex3f(10.0f, 6.0f, 5.0f);


	//back
	glColor3f(0.8f, 0.5f, 0.1f);
	glVertex3f(10.0f, 0.0f, -5.0f);
	glVertex3f(-10.0f, 0.0f, -5.0f);
	glVertex3f(-10.0f, 6.0f, -5.0f);
	glVertex3f(10.0f, 6.0f, -5.0f);

	glColor3f(0.7f, 0.2f, 0.0f);
	glVertex3f(10.0f, 5.8f, -5.1f);
	glVertex3f(-10.0f, 5.8f, -5.1f);
	glVertex3f(-10.0f, 6.0f, -5.1f);
	glVertex3f(10.0f, 6.0f, -5.1f);


	   // porch
	glColor3f(0.8f, 0.6f, 0.1f);
	glVertex3f(2.0f, 5.0f, 5.0f);
	glVertex3f(2.0f, 5.0f, 7.0f);
	glVertex3f(-2.0f, 5.0f, 7.0f);
	glVertex3f(-2.0f, 5.0f, 5.0f);

	glColor3f(0.7f, 0.2f, 0.0f);
	glVertex3f(-2.0f, 5.0f, 7.0f);
	glVertex3f(2.0f, 5.0f, 7.0f);
	glVertex3f(2.0f, 4.8f, 7.0f);
	glVertex3f(-2.0f, 4.8f, 7.0f);

	glColor3f(0.7f, 0.2f, 0.0f);
	glVertex3f(-2.0f, 5.0f, 7.0f);
	glVertex3f(-2.0f, 4.8f, 7.0f);
	glVertex3f(-2.0f, 4.8f, 5.0f);
	glVertex3f(-2.0f, 5.0f, 5.0f);

	glColor3f(0.7f, 0.2f, 0.0f);
	glVertex3f(2.0f, 5.0f, 7.0f);
	glVertex3f(2.0f, 4.8f, 7.0f);
	glVertex3f(2.0f, 4.8f, 5.0f);
	glVertex3f(2.0f, 5.0f, 5.0f);


	      //poles
	glVertex3f(-2.0f, 5.0f, 7.0f);
	glVertex3f(-1.8f, 5.0f, 7.0f);
	glVertex3f(-1.8f, 0.0f, 7.0f);
	glVertex3f(-2.0f, 0.0f, 7.0f);

	glVertex3f(-2.0f, 5.0f, 7.0f);
	glVertex3f(-2.0f, 5.0f, 6.8f);
	glVertex3f(-2.0f, 0.0f, 6.8f);
	glVertex3f(-2.0f, 0.0f, 7.0f);

	glVertex3f(2.0f, 5.0f, 7.0f);
	glVertex3f(1.8f, 5.0f, 7.0f);
	glVertex3f(1.8f, 0.0f, 7.0f);
	glVertex3f(2.0f, 0.0f, 7.0f);

	glVertex3f(2.0f, 5.0f, 7.0f);
	glVertex3f(2.0f, 5.0f, 6.8f);
	glVertex3f(2.0f, 0.0f, 6.8f);
	glVertex3f(2.0f, 0.0f, 7.0f);


	//left-second-floor

	glColor3f(0.8f, 0.6f, 0.1f);
	glVertex3f(-10.0f, 0.0f, 5.0f);
	glVertex3f(-14.0f, 0.0f, 8.0f);
	glVertex3f(-14.0f, 4.5f, 8.0f);
	glVertex3f(-10.0f, 4.5f, 5.0f);

	glVertex3f(-14.0f, 0.0f, 8.0f);
	glVertex3f(-12.0f, 0.0f, 11.0f);
	glVertex3f(-12.0f, 4.5f, 11.0f);
	glVertex3f(-14.0f, 4.5f, 8.0f);

	glVertex3f(-12.0f, 0.0f, 11.0f);
	glVertex3f(-4.0f, 0.0f, 5.0f);
	glVertex3f(-4.0f, 4.5f, 5.0f);
	glVertex3f(-12.0f, 4.5f, 11.0f);

	glVertex3f(-12.0f, 4.5f, 11.0f);
	glVertex3f(-14.0f, 4.5f, 8.0f);
	glVertex3f(-10.0f, 4.5f, 5.0f);
	glVertex3f(-4.0f, 4.5f, 5.0f);

	//left-first-floor

	glColor3f(0.8f, 0.6f, 0.0f);
	glVertex3f(-12.0f, 0.0f, 11.0f);
	glVertex3f(-12.0f, 2.0f, 11.0f);
	glVertex3f(-10.5f, 2.0f, 13.0f);
	glVertex3f(-10.5f, 0.0f, 13.0f);

	glVertex3f(-10.5f, 0.0f, 13.0f);
	glVertex3f(-10.5f, 2.0f, 13.0f);
	glVertex3f(-3.0f, 2.0f, 7.0f);
	glVertex3f(-3.0f, 0.0f, 7.0f);

	glVertex3f(-4.0f, 2.0f, 5.0f);
	glVertex3f(-12.0f, 2.0f, 11.0f);
	glVertex3f(-10.5f, 2.0f, 13.0f);
	glVertex3f(-0.0f, 2.0f, 5.0f);

		//right-second-floor

	glColor3f(0.8f, 0.6f, 0.1f);
	glVertex3f(10.0f, 0.0f, 5.0f);
	glVertex3f(14.0f, 0.0f, 8.0f);
	glVertex3f(14.0f, 4.5f, 8.0f);
	glVertex3f(10.0f, 4.5f, 5.0f);

	glVertex3f(14.0f, 0.0f, 8.0f);
	glVertex3f(12.0f, 0.0f, 11.0f);
	glVertex3f(12.0f, 4.5f, 11.0f);
	glVertex3f(14.0f, 4.5f, 8.0f);

	glVertex3f(12.0f, 0.0f, 11.0f);
	glVertex3f(4.0f, 0.0f, 5.0f);
	glVertex3f(4.0f, 4.5f, 5.0f);
	glVertex3f(12.0f, 4.5f, 11.0f);

	glVertex3f(12.0f, 4.5f, 11.0f);
	glVertex3f(14.0f, 4.5f, 8.0f);
	glVertex3f(10.0f, 4.5f, 5.0f);
	glVertex3f(4.0f, 4.5f, 5.0f);

	//right-first-floor
	glColor3f(0.8f, 0.6f, 0.0f);

	glVertex3f(12.0f, 0.0f, 11.0f);
	glVertex3f(12.0f, 2.0f, 11.0f);
	glVertex3f(10.5f, 2.0f, 13.0f);
	glVertex3f(10.5f, 0.0f, 13.0f);

	glVertex3f(10.5f, 0.0f, 13.0f);
	glVertex3f(10.5f, 2.0f, 13.0f);
	glVertex3f(3.0f, 2.0f, 7.0f);
	glVertex3f(3.0f, 0.0f, 7.0f);

	glVertex3f(4.0f, 2.0f, 5.0f);
	glVertex3f(12.0f, 2.0f, 11.0f);
	glVertex3f(10.5f, 2.0f, 13.0f);
	glVertex3f(0.0f, 2.0f, 5.0f);


//porch base

    glColor3f(0.8f, 0.6f, 0.1f);
	glVertex3f(-3.0f, 0.0f, 7.1f);
	glVertex3f(-3.0f, 2.0f, 7.1f);
	glVertex3f(3.0f, 2.0f, 7.1f);
	glVertex3f(3.0f, 0.0f, 7.1f);

	glVertex3f(-1.0f, 2.0f, 5.1f);
	glVertex3f(-3.0f, 2.0f, 7.1f);
	glVertex3f(3.0f, 2.0f, 7.1f);
	glVertex3f(1.0f, 2.0f, 5.1f);

	glEnd();

	glPopMatrix();


}




void drawAudi(float a, float b, float c, float d)
{
    glPushMatrix();
    glTranslatef(a, b, c);
    glRotatef(d, 0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.6f, 0.1f);
	glVertex3f (-6.0f, 0.0f, 5.0f);
	glVertex3f (-10.0f, 0.0f, -4.0f);
	glVertex3f (-8.0f, 0.0f, -5.0f);
	glVertex3f (8.0f, 0.0f, -5.0f);
	glVertex3f (10.0f, 0.0f, -4.0f);
	glVertex3f (6.0f, 0.0f, 5.0f);
	glEnd();
	

	glBegin(GL_POLYGON);
	glColor3f(0.7f, 0.2f, 0.0f);
	glVertex3f (-6.0f, 10.0f, 5.0f);
	glVertex3f (-10.0f, 8.0f, -4.0f);
	glVertex3f (-8.0f, 7.6f, -5.0f);
	glVertex3f (8.0f, 7.6f, -5.0f);
	glVertex3f (10.0f, 8.0f, -4.0f);
	glVertex3f (6.0f, 10.0f, 5.0f);
	glEnd();

	//rear-walls
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-8.0f, 0.0f, -5.0f);
	glVertex3f(-8.0f, 7.6f, -5.0f);
	glVertex3f(8.0f, 7.6f, -5.0f);
	glVertex3f(8.0f, 0.0f, -5.0f);

	
	glVertex3f(8.0f, 0.0f, -5.0f);
	glVertex3f(8.0f, 7.6f, -5.0f);
	glVertex3f(10.0f, 8.0f, -4.0f);
	glVertex3f(10.0f, 0.0f, -4.0f);

	glVertex3f(-8.0f, 0.0f, -5.0f);
	glVertex3f(-8.0f, 7.6f, -5.0f);
	glVertex3f(-10.0f, 8.0f, -4.0f);
	glVertex3f(-10.0f, 0.0f, -4.0f);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-10.0f, 0.0f, -4.0f);
	glVertex3f(-10.0f, 8.0f, -4.0f);
	glVertex3f(-6.0f, 10.0f, 5.0f);
	glVertex3f(-6.0f, 0.0f, 5.0f);

	glVertex3f(-6.0f, 0.0f, 5.0f);
	glVertex3f(-6.0f, 10.0f, 5.0f);
	glVertex3f(6.0f, 10.0f, 5.0f);
	glVertex3f(6.0f, 0.0f, 5.0f);

	glVertex3f(10.0f, 0.0f, -4.0f);
	glVertex3f(10.0f, 8.0f, -4.0f);
	glVertex3f(6.0f, 10.0f, 5.0f);
	glVertex3f(6.0f, 0.0f, 5.0f);



	//side-extension

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-6.5f, 0.0f, 3.5f);
	glVertex3f(-6.5f, 9.5f, 3.5f);
	glVertex3f(-8.0f, 8.7f, 5.0f);
	glVertex3f(-8.0f, 0.0f, 5.0f);

	glVertex3f(-8.0f, 8.7f, 5.0f);
	glVertex3f(-8.0f, 0.0f, 5.0f);
	glVertex3f(-7.0f, 0.0f, 6.0f);
	glVertex3f(-7.0f, 8.8f, 6.0f);

	glVertex3f(-7.0f, 0.0f, 6.0f);
	glVertex3f(-7.0f, 8.8f, 6.0f);
	glVertex3f(-6.0f, 9.5f, 5.0f);
	glVertex3f(-6.0f, 0.0f, 5.0f);

	          //top
	glColor3f(0.9f, 0.4f, 0.0f);
	glVertex3f(-6.5f, 9.5f, 3.5f);
	glVertex3f(-6.0f, 9.5f, 5.0f);
	glVertex3f(-7.0f, 8.8f, 6.0f);
	glVertex3f(-8.0f, 8.7f, 5.0f);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(6.5f, 0.0f, 3.5f);
	glVertex3f(6.5f, 9.5f, 3.5f);
	glVertex3f(8.0f, 8.7f, 5.0f);
	glVertex3f(8.0f, 0.0f, 5.0f);

	glVertex3f(8.0f, 8.7f, 5.0f);
	glVertex3f(8.0f, 0.0f, 5.0f);
	glVertex3f(7.0f, 0.0f, 6.0f);
	glVertex3f(7.0f, 8.8f, 6.0f);

	glVertex3f(7.0f, 0.0f, 6.0f);
	glVertex3f(7.0f, 8.8f, 6.0f);
	glVertex3f(6.0f, 9.5f, 5.0f);
	glVertex3f(6.0f, 0.0f, 5.0f);

	glColor3f(0.7f, 0.4f, 0.0f);
	glVertex3f(6.5f, 9.5f, 3.5f);
	glVertex3f(6.0f, 9.5f, 5.0f);
	glVertex3f(7.0f, 8.8f, 6.0f);
	glVertex3f(8.0f, 8.7f, 5.0f);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-6.0f, 7.0f, 7.0f);
	glVertex3f(-7.0f, 7.0f, 6.0f);
	glVertex3f(-7.0f, 0.0f, 6.0f);
	glVertex3f(-6.0f, 0.0f, 7.0f);

	glVertex3f(6.0f, 7.0f, 7.0f);
	glVertex3f(7.0f, 7.0f, 6.0f);
	glVertex3f(7.0f, 0.0f, 6.0f);
	glVertex3f(6.0f, 0.0f, 7.0f);

	glColor3f(0.5f, 0.5f, 0.0f);
	glVertex3f(-4.0f, 3.0f, 7.0f);
	glVertex3f(-5.2f, 1.5f, 7.0f);
	glVertex3f(-5.2f, 1.5f, 8.0f);
	glVertex3f(-4.0f, 3.0f, 8.0f);

	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-5.2f, 1.5f, 7.0f);
	glVertex3f(-5.2f, 1.5f, 8.0f);
	glVertex3f(-6.0f, 1.5f, 8.0f);
	glVertex3f(-6.0f, 1.5f, 7.0f);


	glVertex3f(-6.0f, 1.5f, 7.0f);
	glVertex3f(-7.0f, 0.0f, 7.0f);
	glVertex3f(-7.0f, 0.0f, 8.0f);
	glVertex3f(-6.0f, 1.5f, 8.0f);

	glVertex3f(4.0f, 3.0f, 7.0f);
	glVertex3f(5.2f, 1.5f, 7.0f);
	glVertex3f(5.2f, 1.5f, 8.0f);
	glVertex3f(4.0f, 3.0f, 8.0f);

	glVertex3f(5.2f, 1.5f, 7.0f);
	glVertex3f(5.2f, 1.5f, 8.0f);
	glVertex3f(6.0f, 1.5f, 8.0f);
	glVertex3f(6.0f, 1.5f, 7.0f);


	glVertex3f(6.0f, 1.5f, 7.0f);
	glVertex3f(7.0f, 0.0f, 7.0f);
	glVertex3f(7.0f, 0.0f, 8.0f);
	glVertex3f(6.0f, 1.5f, 8.0f);


	glColor3f(0.8f, 0.8f, 0.0f);
	glVertex3f(-6.0f, 7.0f, 7.0f);
	glVertex3f(-6.0f, 0.0f, 7.0f);
	glVertex3f(6.0f, 0.0f, 7.0f);
	glVertex3f(6.0f, 7.0f, 7.0f);

			//front-top
	glColor3f(0.7f, 0.2f, 0.0f);
	glVertex3f(-6.0f, 7.5f, 5.0f);
	glVertex3f(-6.0f, 7.0f, 7.0f);
	glVertex3f(6.0f, 7.0f, 7.0f);
	glVertex3f(6.0f, 7.5f, 5.0f);

	glColor3f(0.7f, 0.2f, 0.0f);
	glVertex3f(-2.0f, 6.0f, 7.0f);
	glVertex3f(2.0f, 6.0f, 7.0f);
	glVertex3f(2.0f, 5.5f, 8.0f);
	glVertex3f(-2.0f, 5.5f, 8.0f);





	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f (-2.0f, 5.5f, 8.0f);
	glVertex3f (-4.0f, 5.0f, 8.0f);
	glVertex3f (-4.0f, 0.0f, 8.0f);
	glVertex3f (4.0f, 0.0f, 8.0f);
	glVertex3f (4.0f, 5.0f, 8.0f);
	glVertex3f (2.0f, 5.5f, 8.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.7f, 0.2f, 0.0f);
	glVertex3f(-6.0f, 7.0f, 7.0f);
	glVertex3f(-6.0f, 7.5f, 5.0f);
	glVertex3f(-7.0f, 7.0f, 6.0f);

	glColor3f(0.7f, 0.2f, 0.0f);
	glVertex3f(6.0f, 7.0f, 7.0f);
	glVertex3f(6.0f, 7.5f, 5.0f);
	glVertex3f(7.0f, 7.0f, 6.0f);




	glEnd();

	glPopMatrix();
}




void drawCentre(float a, float b, float c, float d, float e)
{
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.8f);
    glTranslatef(a, b, c);
    glTranslatef(0.0f, -2.0f, 0.0f);
    GLUquadricObj *cylquad = gluNewQuadric();
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0,0.0,-1.0);
	gluCylinder(cylquad, d, d, e, 10, 2 );
	glPopMatrix();
}



void drawCircleTop(float a, float b, float c, float d, float e)
{
    glPushMatrix();
    glTranslatef(a, b, c);
    glTranslatef(0.0f, -2.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    GLUquadricObj *cylquad = gluNewQuadric();
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    gluDisk(cylquad, d, e, 10, 2);
    glPopMatrix();
}



void drawCircularRoad(float a, float b, float c, float d, float e)
{
    glPushMatrix();
    glTranslatef(a, b, c);
    glTranslatef(0.0f, -2.0f, 0.0f);
    glColor3f(0.0f, 0.1f,0.1f); 
    GLUquadricObj *cylquad = gluNewQuadric();
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    gluDisk(cylquad, d, e, 10, 2);
    glPopMatrix();
}



void drawWindow(float a, float b, float c, float d)
{
	glPushMatrix();

	glTranslatef(a,b,c);
	glScalef(d, 1.0, 1.0);
	glBegin(GL_QUADS);

	//window
	glColor3f(0.0f, 0.0f, 0.0f);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0.75f, 0.9f, -1.0f);
	glVertex3f(-1.75f, 0.9f, -1.0f);
	glVertex3f(-1.75f, 1.75f, -1.0f);
	glVertex3f(0.75f, 1.75f, -1.0f);

	glEnd();

	glPopMatrix();
}



void drawFloor(float a, float b, float c, float d)
{
	glColor3f(1.0f, 0.9f, 0.0f);
	glPushMatrix();
	glTranslatef(a,b,c);
	glScalef(d, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(10.0f, 0.0f, -1.01f);
	glVertex3f(-10.0f, 0.0f, -1.01f);
	glVertex3f(-10.0f, 2.0f, -1.01f);
	glVertex3f(10.0f, 2.0f, -1.01f);
	
	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(10.0f, 0.0f, -1.01f);
	glVertex3f(10.0f, 0.0f, -3.0f);
	glVertex3f(10.0f, 2.0f, -3.0f);
	glVertex3f(10.0f, 2.0f, -1.01f);
	
	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(10.0f, 0.0f, -3.0f);
	glVertex3f(-10.0f, 0.0f, -3.0f);
	glVertex3f(-10.0f, 2.0f, -3.0f);
	glVertex3f(10.0f, 2.0f, -3.0f);
	
	//Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-10.0f, 0.0f, -1.01f);
	glVertex3f(-10.0f, 0.0f, -3.0f);
	glVertex3f(-10.0f, 2.0f, -3.0f);
	glVertex3f(-10.0f, 2.0f, -1.01f);

	//Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(10.0f, 2.0f, -1.01f);
	glVertex3f(10.0f, 2.0f, -3.0f);
	glVertex3f(-10.0f, 2.0f, -3.0f);
	glVertex3f(-10.0f, 2.0f, -1.01f);

	//Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(10.0f, 0.0f, -1.01f);
	glVertex3f(10.0f, 0.0f, -3.0f);
	glVertex3f(-10.0f, 0.0f, -3.0f);
	glVertex3f(-10.0f, 0.0f, -1.01f);

	glEnd();

	//include the balconies
	for(float j= -9.0f; j<= 9.5f; j+=2.5f)
		drawWindow(j, 0.0f, 0.0f, 0.5f);
	glPopMatrix();
}

void drawWing(float a, float b, float c, float d)
{
	glTranslatef(a, b, c);
	drawFloor(0.0f, 0.0f, 0.0f, 1.0f);
	drawFloor(0.0f, 2.0f, 0.0f, 1.0f);
	drawFloor(0.0f, 4.0f, 0.0f, 1.0f);

}

void joinWing()
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
glBegin(GL_QUADS);
	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-5.0f, 0.0f, 7.0f);
	glVertex3f(-5.0f, 2.0f, 7.0f);
	glVertex3f(-6.0f, 2.0f, 7.01f);
	glVertex3f(-6.0f, 0.0f, 7.01f);
	
	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-5.01f, 0.0f, -3.01f);
	glVertex3f(-5.01f, 0.0f, 7.0f);
	glVertex3f(-5.01f, 2.0f, 7.0f);
	glVertex3f(-5.01f, 2.0f, -3.0f);
	
	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-5.0f, 0.0f, -3.0f);
	glVertex3f(-5.0f, 2.0f, -3.0f);
	glVertex3f(-6.0f, 2.0f, -3.0f);
	glVertex3f(-6.0f, 0.0f, -3.0f);
	
	//Left
glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-6.01f, 0.0f, -3.01f);
	glVertex3f(-6.01f, 0.0f, 7.0f);
	glVertex3f(-6.01f, 2.0f, 7.0f);
	glVertex3f(-6.01f, 2.0f, -3.0f);

 //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-5.0f, 2.0f, 7.0f);
	glVertex3f(-6.0f, 2.0f, 7.0f);
	glVertex3f(-6.0f, 2.0f, -3.0f);
	glVertex3f(-5.0f, 2.0f, -3.0f);

	glEnd();
	glPopMatrix();

}

void drawCube()
{
	glColor3f(1.0f, 0.9f, 0.0f);
	glPushMatrix();
	//glTranslatef(a,b,c);
	//glScalef(d, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(10.0f, -2.0f, 1.01f);
	glVertex3f(-10.0f, -2.0f, 1.01f);
	glVertex3f(-10.0f, 0.0f, 1.01f);
	glVertex3f(10.0f, 0.0f, 1.01f);
	
	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(10.0f, -2.0f, 1.01f);
	glVertex3f(10.0f, -2.0f, -3.0f);
	glVertex3f(10.0f, 0.0f, -3.0f);
	glVertex3f(10.0f, 0.0f, 1.01f);
	
	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(10.0f, -2.0f, -3.0f);
	glVertex3f(-10.0f, -2.0f, -3.0f);
	glVertex3f(-10.0f, 0.0f, -3.0f);
	glVertex3f(10.0f, 0.0f, -3.0f);
	
	//Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-10.0f, -2.0f, 1.01f);
	glVertex3f(-10.0f, -2.0f, -3.0f);
	glVertex3f(-10.0f, 0.0f, -3.0f);
	glVertex3f(-10.0f, 0.0f, 1.01f);

	//Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(10.0f, 0.0f, 1.01f);
	glVertex3f(10.0f, 0.0f, -3.0f);
	glVertex3f(-10.0f, 0.0f, -3.0f);
	glVertex3f(-10.0f, 0.0f, 1.01f);

	//Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(10.0f, -2.0f, 1.01f);
	glVertex3f(10.0f, -2.0f, -3.0f);
	glVertex3f(-10.0f, -2.0f, -3.0f);
	glVertex3f(-10.0f, -2.0f, 1.01f);

	glEnd();
}


