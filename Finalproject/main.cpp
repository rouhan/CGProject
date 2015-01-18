#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<glut.h>
#include<Windows.h>
#include<math.h>
#include<string.h>
#include <time.h>

using namespace std;
using std::string;

void PlayerScreen(void);
void screen3(string);
void cross(GLint,GLint);
void DrawCircle(float, float, float, int);
void gamemark(int, int);
void gamecheck(int , int , int );
int computerplay();

int screenwidth = 900; int screenheight = 600;
int i,a,b,c,d,e,f,g,h,t,k = 0;
int tic = 0;
int player2 = 0;
int comp = 0;
int play[10];
int board[3][3] ;
int turn1 = 1, turn2;
int pos1 = 1, pos2 = 2, pos3 = 3, pos4 = 4, pos5 = 5, pos6 = 6, pos7 = 7, pos8 = 8, pos9 = 9;
int con=0;

//static int numVerts = 2;
//static int i = 2;

class GLintPoint{ public: GLint x, y; };
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
	i = 2;

	glFlush();


}
void screen3(string naam)
{
	
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP); //For Score boundry
	glVertex2f(200, 200);
	glVertex2f(200, 500);
	glVertex2f(700, 500);
	glVertex2f(700, 200);
	glEnd();

	glColor3f(1.0, 0.0, 0.0); 
	bitmap_output(370, 180, naam, GLUT_BITMAP_TIMES_ROMAN_24);
	k = 11;
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
	glColor3f(0.0, 0.0, 0.0);
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
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
	glFlush();
}
void gameplay(int x,int y)
{

	if ((x >= 200 && x <= 350) && (y >= 390 && y <= 500) && g == 0)//3rd row
	{

		g = 1; gamemark(240, 420);
	}
	if ((x >= 350 && x <= 530) && (y >= 390 && y <= 500) && h == 0)
	{
		h = 1; gamemark(390, 420);
	}
	if ((x >= 530 && x <= 700) && (y >= 390 && y <= 500) && t == 0)
	{
		t = 1; gamemark(570, 420);
	}

	if ((x >= 200 && x <= 350) && (y >= 290 && y <= 390) && d == 0) // 2nd Row
	{
		d = 1; gamemark(240, 310);
	}
	if ((x >= 350 && x <= 530) && (y >= 290 && y <= 390) && e == 0)
	{
		e = 1; gamemark(390, 310);
	}
	if ((x >= 530 && x <= 700) && (y >= 290 && y <= 390) && f == 0)
	{
		f = 1; gamemark(570, 310);
	}

	if ((x >= 200 && x <= 350) && (y >= 200 && y <= 290) && a == 0)  //1st row
	{
		a = 1; gamemark(240, 230);
	}
	if ((x >= 350 && x <= 530) && (y >= 200 && y <= 290) && b == 0)
	{
		b = 1; gamemark(390, 230); 
	}
	if ((x >= 530 && x <= 700) && (y >= 200 && y <= 290) && c == 0)
	{
		c = 1; gamemark(570, 230);
	}
}
void gameplay2(int x,int y)
{
	if (turn1 == 1 )
	{

		if ((x >= 200 && x <= 350) && (y >= 390 && y <= 500) && g == 0)//3rd row
		{
			g = 1; gamemark(240, 420);
		}
		if ((x >= 350 && x <= 530) && (y >= 390 && y <= 500) && h == 0)
		{
			h = 1; gamemark(390, 420);
		}
		if ((x >= 530 && x <= 700) && (y >= 390 && y <= 500) && t == 0)
		{
			t = 1; gamemark(570, 420);
		}

		if ((x >= 200 && x <= 350) && (y >= 290 && y <= 390) && d == 0) // 2nd Row
		{
			d = 1; gamemark(240, 310);
		}
		if ((x >= 350 && x <= 530) && (y >= 290 && y <= 390) && e == 0)
		{
			e = 1; gamemark(390, 310);
		}
		if ((x >= 530 && x <= 700) && (y >= 290 && y <= 390) && f == 0)
		{
			f = 1; gamemark(570, 310);
		}

		if ((x >= 200 && x <= 350) && (y >= 200 && y <= 290) && a == 0)  //1st row
		{
			a = 1; gamemark(240, 230);
		}
		if ((x >= 350 && x <= 530) && (y >= 200 && y <= 290) && b == 0)
		{
			b = 1; gamemark(390, 230);
		}
		if ((x >= 530 && x <= 700) && (y >= 200 && y <= 290) && c == 0)
		{
			c = 1; gamemark(570, 230);
		}
	}
	
	
	
	if (a != 1 || b != 1 || c != 1 || d != 1 || e != 1 || f != 1 || g != 1 || h != 1 || t != 1)
	{
		con = computerplay();

		if (con == pos1&& a != 1)
		{
			gamemark(240, 230);
			a = 1;
		}
		else if (con == pos2 && b != 1)
		{
			gamemark(390, 230);
			b = 1;
		}
		else if (con == pos3&& c != 1)
		{
			gamemark(570, 230);
			c = 1;
		}
		else if (con == pos4&& d != 1)
		{
			d = 1; gamemark(240, 310);
		}
		else if (con == pos5 && e != 1)
		{
			e = 1; gamemark(390, 310);
		}
		else if (con == pos6&& f != 1)
		{
			f = 1; gamemark(570, 310);
		}
		else if (con == pos7 && g != 1)
		{
			g = 1; gamemark(240, 420);
		}
		else if (con == pos8&& h != 1)
		{
			h = 1; gamemark(390, 420);
		}
		else if (con == pos9 && t != 1)
		{
			t = 1; gamemark(570, 420);
		}
		else
		{
			gameplay2(x, y);
		}

	}
	

}
void gamemark(int x,int y)
{
	int value;
	if (turn1 == 1)
	{
		cross(x,y);
		value = 1;
		gamecheck(x,y,value);
		turn1 = 0;
		turn2 = 1;
		
	}
	else if (turn2 == 1)
	{
		turn1 = 1;
		turn2 = 0;
		value = 2;
		gamecheck(x,y,value);
		DrawCircle(x+30, y+20, 20, 30);
	}
}
void gamecheck(int x, int y,int val)
{
	string konjeeta;
	if (comp == 1)
	{
		konjeeta = "Computer Win";
	}
	else if (player2 == 1)
	{
		konjeeta = "Player 2 Win";
	}

	if ((x >= 200 && x <= 350) && (y >= 390 && y <= 500))//3rd row
	{
		board[2][0] = val;
	}
	if ((x >= 350 && x <= 530) && (y >= 390 && y <= 500))
	{
		board[2][1] = val;
	}
	if ((x >= 530 && x <= 700) && (y >= 390 && y <= 500))
	{	
		board[2][2] = val;
	}

	
	if ((x >= 200 && x <= 350) && (y >= 290 && y <= 390)) // 2nd Row
	{
		board[1][0] = val;
	}
	if ((x >= 350 && x <= 530) && (y >= 290 && y <= 390))
	{	
		board[1][1] = val;
	}
	if ((x >= 530 && x <= 700) && (y >= 290 && y <= 390))
	{	
		board[1][2] = val;
	}

	
	if ((x >= 200 && x <= 350) && (y >= 200 && y <= 290))  //1st row
	{
		board[0][0] = val;
	}
	if ((x >= 350 && x <= 530) && (y >= 200 && y <= 290))
	{
		board[0][1] = val;
	}
	if ((x >= 530 && x <= 700) && (y >= 200 && y <= 290))
	{
		board[0][2] = val;
	}

	for (int i = 0; i < 3; i++)//Check for a win
	{
		if (board[i][0] != 0)
		{
			if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]))
			{
				if (val == 1)
				{
					screen3("Player1 Wins");
					a = b = c = d = e = f = g = h = t = 1;
				}
				else if (val == 2)
				{
					screen3(konjeeta);//Player 2 Wins
					a = b = c = d = e = f = g = h = t = 1;
				}
			}
		}
		
		if  (board[0][i] != 0)
		{
			if ((board[0][i] == board[1][i] && board[1][i] == board[2][i]))
			{
				if (val == 1)
				{
					screen3("Player1 Wins");
					a = b = c = d = e = f = g = h = t = 1;
				}
				else if (val == 2)
				{
					screen3(konjeeta);//Player 2 Wins
					a = b = c = d = e = f = g = h = t = 1;
				}
			}
		}
		if (board[1][1] != 0)
		{
			if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]))
			{
				if (val == 1)
				{
					screen3("Player1 Wins");
					a = b = c = d = e = f = g = h = t = 1;
				}
				else if (val==2)
				{
					screen3(konjeeta);//Player 2 Wins
					a = b = c = d = e = f = g = h = t = 1;
				}
			}
		}
		if (board[1][1] != 0)
		{
			if ((board[0][2] == board[1][1] && board[1][1] == board[2][0]))
			{
				if (val == 1)
				{
					screen3("Player1 Wins");
					a = b = c = d = e = f = g = h = t = 1;
				}
				else if (val == 2)
				{
					screen3(konjeeta);//Player 2 Wins
					a = b = c = d = e = f = g = h = t = 1;
				}
			}
		}
		
	}

}

int computerplay()
{
	int v1;
	
	
	v1 = rand() % 9+1;
	return v1;

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
		if (k != 10 && i == 2 && player2 == 1 )
		{
			gameplay(x, y);
			k++;
		}
		if (k != 9 && i == 2 && comp == 1)
		{
			gameplay2(x,y);
			k++;
		}
		if (k==10)
		{
			screen3("DRAW");
		}

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

