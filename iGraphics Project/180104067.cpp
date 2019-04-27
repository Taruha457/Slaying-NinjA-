#include "iGraphics.h"
#include "bitmap_loader.h"

int x = 300, y = 300, r = 20;
int win_b = 400, win_l = 400;
float delay = 0;
int speed = 0;
int counter =0;
/*
 function iDraw() is called again and again by the system.

 */
void drawRoadLines(int offset)
{
	int len = 10;
	int width = 5;
	int gap = 10;
	int midx = 0, midy = win_l / 2;
	for (int i = 0; i < win_b / (len + gap); i++)
		iFilledRectangle((i * (len + gap) + offset) % win_b, midy, len, width);
}
int k = 0;

void drawCOLflag(double n)
{
		iSetColor(252,209,22);
	iFilledRectangle(200,140,n,40);

	iSetColor(0,56,147);
	iFilledRectangle(200,120,n,20);

	iSetColor(206,17,38);
	iFilledRectangle(200,100,n,20);
	iSetColor(0,250,0);

	iText(220,70,"The Flag of Colombia",GLUT_BITMAP_TIMES_ROMAN_10);
	
}
void drawLogo()
{
	iSetColor(250,0,0);
	iCircle(500,200,50,100);
	iCircle(500,200,49,100);
	iCircle(500,200,48,100);
	iCircle(500,200,47,100);
	iCircle(500,200,46,100);
	iCircle(500,200,45,100);
	iCircle(500,200,44,100);
	iCircle(500,200,43,100);
	iCircle(500,200,42,100);
	iCircle(500,200,41,100);
	iCircle(500,200,40,100);
	iSetColor(255,255,255);
	iCircle(500,200,39,100);
	iCircle(500,200,38,100);
	iCircle(500,200,37,100);
	iCircle(500,200,36,100);
	iCircle(500,200,35,100);
	iCircle(500,200,34,100);
	iCircle(500,200,33,100);
	iCircle(500,200,32,100);
	iCircle(500,200,31,100);
	iCircle(500,200,30,100);
	iCircle(500,200,29,100);
	iSetColor(250,0,0);
	iCircle(500,200,28,100);
	iCircle(500,200,27,100);
	iCircle(500,200,26,100);
	iCircle(500,200,25,100);
	iCircle(500,200,24,100);
	iCircle(500,200,23,100);
	iCircle(500,200,22,100);
	iCircle(500,200,21,100);
	iCircle(500,200,20,100);
	iCircle(500,200,19,100);
	iCircle(500,200,18,100);
	iSetColor(0,0,250);
	iCircle(500,200,17,100);
	iCircle(500,200,16,100);
	iCircle(500,200,15,100);
	iCircle(500,200,14,100);
	iCircle(500,200,13,100);
	iCircle(500,200,12,100);
	iCircle(500,200,11,100);
	iCircle(500,200,10,100);
	iCircle(500,200,9,100);
	iCircle(500,200,8,100);
	iCircle(500,200,7,100);
	iCircle(500,200,6,100);
	iCircle(500,200,5,100);
	iCircle(500,200,4,100);
	iCircle(500,200,3,100);
	iCircle(500,200,2,100);
	iCircle(500,200,1,100);
	iSetColor(255,255,255);
	iText(470,140,"Captain America",GLUT_BITMAP_TIMES_ROMAN_10);
}

void drawShape()
{
	iSetColor(123,101,164);
	iFilledRectangle(700,100,100,20);
	iSetColor(141,89,77);
	iFilledRectangle(700,120,50,30);
	iSetColor(57,67,64);
	iFilledRectangle(750,120,50,100);
	iSetColor(200,0,0);
	iText(750,80,"SHAPE",GLUT_BITMAP_TIMES_ROMAN_10);
}
void iDraw()
{
	//place your drawing codes here
	iClear();

	double n=120;
	 drawCOLflag(n);
	 drawLogo();
	 drawShape();
}

void iPassiveMouse(int x, int y)
{
	;
}


/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
	//place your codes here
}

/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		x += 10;
		y += 10;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		x -= 10;
		y -= 10;
	}
}

/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}
	else if (key == 'a' && speed < 5)
		speed += 1;
	else if (key == 's' && speed > 0)
		speed -= 1;
	//place your codes for other keys here
}

/*
 function iSpecialKeyboard() is called whenver user hits special keys like-
 function keys, home, end, pg up, pg down, arraows etc. you have to use
 appropriate constants to detect them. A list is:
 GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
 GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
 GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
 GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
 */
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.


	iInitialize(1000, 400, "Demo");

	iStart(); // it will start drawing

	return 0;
}