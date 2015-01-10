#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<glut.h>
#include<Windows.h>
#include<math.h>
#include<string.h>
using namespace std;
using std::string;

void PlayerScreen(void);
void cross(GLint,GLint);
void DrawCircle(float, float, float, int);

int screenwidth = 900; int screenheight = 600;
int i = 0;
int tic = 0;
int player2 = 0;
int comp = 0;
//static int numVerts = 2;
//static int i = 2;

class GLintPoint{ public: GLint x, y; };

//#define NUM 100
//static GLintPoint List[NUM];
//static int last = -1;
 
//void drawDot(GLint x, GLint y)
//{ // draw dot at integer point (x, y) 
//	glBegin(GL_POINTS);
//	glVertex2i(x, y);
//	glEnd();
//}
GLintPoint CP;

void moveto(GLint x, GLint y)
{
	CP.x = x;
	CP.y = y;

}
void bitmap_output(int x, int y, string s, void *font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = s.length();
	for (i = 0; i<len; i++)
	{
		glutBitmapCharacter(font, s[i]);
	}
	glFlush();
}
void screen1()
{

	glColor3f(0.0, 1.0, 2.0);
	glBegin(GL_QUADS); //For new game button
	glVertex2f(280, 200);
	glVertex2f(280, 250);
	glVertex2f(360, 250);
	glVertex2f(360, 200);
	
	glEnd();


	glColor3f(0.0, 1.0, 2.0);
	glBegin(GL_QUADS); //For computer new game button
	glVertex2f(240, 200);
	glVertex2f(240, 250);
	glVertex2f(390, 250);
	glVertex2f(390, 200);

	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	bitmap_output(245, 235,"Click To PLay", GLUT_BITMAP_TIMES_ROMAN_24);
	//	glFlush();
	glColor3f(0.0, 1.0, 2.0);
	glBegin(GL_LINE_LOOP); //For computer selection
	glVertex2f(240, 270);
	glVertex2f(240, 300);
	glVertex2f(290, 300);
	glVertex2f(290, 270);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	bitmap_output(170, 290, "Computer", GLUT_BITMAP_HELVETICA_12);

	glColor3f(0.0, 1.0, 2.0);
	glBegin(GL_LINE_LOOP); //For second player selection
	glVertex2f(350, 270);
	glVertex2f(350, 300);
	glVertex2f(400, 300);
	glVertex2f(400, 270);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	bitmap_output(294, 290, "Player2", GLUT_BITMAP_HELVETICA_12);

}
void screen2()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	PlayerScreen();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP); //For game boundry
	glVertex2f(200, 200);
	glVertex2f(200, 500);
	glVertex2f(700, 500);
	glVertex2f(700, 200);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP); //For horizontal game boundry
	glVertex2f(200, 290);
	glVertex2f(700, 290);
	glEnd();
	glBegin(GL_LINE_STRIP); //For horizontal game boundry
	glVertex2f(200, 390);
	glVertex2f(700, 390);
	glEnd();
	
	glBegin(GL_LINE_STRIP); //For vertical game boundry
	glVertex2f(350, 200);
	glVertex2f(350, 500);
	glEnd();

	glBegin(GL_LINE_STRIP); //For vertical game boundry
	glVertex2f(530, 200);
	glVertex2f(530, 500);
	glEnd();

	glFlush();


}

void PlayerScreen()
{

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP); //For Player1
	glVertex2f(120, 80);
	glVertex2f(120, 130);
	glVertex2f(170, 130);
	glVertex2f(170, 80);
	glEnd();
	bitmap_output(100, 70, "PLAYER 1", GLUT_BITMAP_TIMES_ROMAN_24);
	cross(125,85);
	
	
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP); //For Player/Computer
	glVertex2f(300, 80);
	glVertex2f(300, 130);
	glVertex2f(350, 130);
	glVertex2f(350, 80);
	glEnd();
	DrawCircle(325, 105, 20, 30);
	if (player2 == 1)
	{
		bitmap_output(300, 70, "PLAYER 2", GLUT_BITMAP_TIMES_ROMAN_24);
	
	}
	if (comp == 1){ 
		bitmap_output(300, 70, "COMPUTER", GLUT_BITMAP_TIMES_ROMAN_24);
	
	}

}

void tick(GLint x,GLint y)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(x, y);
	glVertex2f(x, y+20);
	glVertex2f(x+20, y-20);
	glEnd();
	glFlush();
//	screen2();
	i = 1;
	tic = 1;
	
}
void DrawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
}
void cross(GLint x, GLint y)
{
	glColor3f(0.0, 0.0, 0.0);
	
	glBegin(GL_LINE_STRIP); //For cross
	glVertex2f(x+40 ,y);
	glVertex2f(x , y+40);
	glEnd();

	glBegin(GL_LINE_STRIP); //For cross
	glVertex2f(x, y);
	glVertex2f(x+40, y+40);
	glEnd();
	
	glFlush();
	

}

void myMouse(int button, int state, int x, int y)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
		if (i == 1)
		{
			if ((x >= 280 && x <= 360) && (y >= 200 && y <= 250))
			screen2();
		}
		else
		{
			if (tic == 0)
			{

				if ((x >= 240 && x <= 290) && (y >= 270 && y <= 300))
				{
					tick(x, y); comp = 1;

				}
				else if ((x >= 350 && x <= 400) && (y >= 270 && y <= 300))
				{
					tick(x, y); player2 = 1;
				}
			}
		}
	}
}

void myMovedMouse(int mouseX, int mouseY)
{
	
}
void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{

}

void reshape(int w, int h)
{
	screenheight = h;
	screenwidth = w;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, h, 0, -1, 1);  /* flip y-axis around */
}




void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenwidth, 0.0, (GLdouble)screenheight);


}


void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	screen1();

	glFlush();
}
int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenwidth, screenheight);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("TIC TAC TOE Game.");
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(myKeyboard);
	glutReshapeFunc(reshape);
	myInit();
	glutMainLoop();
	return 0;
}

