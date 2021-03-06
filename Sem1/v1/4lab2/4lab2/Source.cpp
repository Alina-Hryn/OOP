#include <time.h>
#include <stdlib.h>
#include  <GL/glut.h>

int N = 30, M = 20;
int Scale = 25;
int k = 0;
int w = Scale*N;
int h = Scale*M;

int dir, num = 1;
int apples = 0;

struct
{
	int x;
	int y;
}  s[1];

class Fructs
{
public:
	int x, y;

	void New()
	{
		x = rand() % N;
		y = rand() % M;
	}

	void DrawApple()
	{
		glColor3f(1.0, 0.0, 0.0);
		glRectf(x*Scale, y*Scale, (x + 1)*Scale, (y + 1)*Scale);
	}
	
		
	
	void deleteApple()
	{
		x = 30000;
		y = 30000;

		glColor3f(0.0, 1.0, 0.0);
		glRectf(0, 0, 0, 0);
	}
} m[10];



void DrawSnake()
{
	glColor3f(0.5,0.3,0.2);
	glRectf(s[0].x*Scale, s[0].y*Scale, (s[0].x + 0.9)*Scale, (s[0].y + 0.9)*Scale);
}

void Tick()
{/*
 for (int i = num; i>0; --i)
 {
 s[i].x = s[i - 1].x;
 s[i].y = s[i - 1].y;
 }*/

	if (dir == 0) {
		s[0].y += 1;
		k++;
	}
	if (dir == 1)
	{
		s[0].x -= 1;
		k++;
	}
	if (dir == 2)
	{
		s[0].x += 1;
		k++;
	}
	if (dir == 3) {
		s[0].y -= 1;
		k++;
	}
	for (int i = 0; i < 10; i++)
		if ((s[0].x == m[i].x) && (s[0].y == m[i].y))
		{
			num++; m[i].deleteApple();
			k++;
		}

	if (s[0].x > N) dir = 1;  if (s[0].x < 0) dir = 2;
	if (s[0].y > M) dir = 3;  if (s[0].y < 0) dir = 0;

	for (int i = 1; i < num; i++)
		if (s[0].x == s[i].x && s[0].y == s[i].y)  num = i;
	glutPostRedisplay();
}



void DrawField()
{
	glColor3f(0.0, 0.7, 0.0);
	glBegin(GL_LINES);
	for (int i = 0; i < w; i += Scale)
	{
		glVertex2f(i, 0); glVertex2f(i, h);
	}
	for (int j = 0; j < h; j += Scale)
	{
		glVertex2f(0, j); glVertex2f(w, j);
	}
	glEnd();
}




void display() {

	glClear(GL_COLOR_BUFFER_BIT);

	DrawField();

	DrawSnake();

	for (int i = 0; i < 10; i++) {

		m[i].DrawApple();
	}
	glFlush();
	glutSwapBuffers();

}

void display1() {

	glClear(GL_COLOR_BUFFER_BIT);

	DrawField();

	DrawSnake();

	

}


void KeyboardEvent(int key, int a, int b)
{
	switch (key)
	{
	case 101:   dir = 0; break;
	case 102:   dir = 2; break;
	case 100:  dir = 1; break;
	case 103:  dir = 3; break;
	}

}

void timer(int = 0)
{
	display();

	Tick();

	glutTimerFunc(50, timer, k);
	k--;
}

int main(int argc, char **argv) {

	srand(time(0));
	int i;
	for (i = 0; i < 10; i++)
		m[i].New();


	s[i].x = 10;
	s[i].y = 10;
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(w, h);
	glutCreateWindow("Test");
	glClearColor(1.0, 1.0, 0.6, 1.0);  //���� ����
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);

	glutDisplayFunc(display);
	glutSpecialFunc(KeyboardEvent);
	glutTimerFunc(50, timer, k);

	if (k == 10)
		glutDisplayFunc(display1);
	glutMainLoop();
}