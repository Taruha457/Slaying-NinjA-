 #include "iGraphics.h"
#include "bitmap_loader.h"
#include<string.h>

//Screen
int screenWidth =900;
int screenHeight =600;
//variable for loading images in menu bar
int Background;
int PlayBackground;
int CreditBackground;
int HighScoreBackground;
int InstructionBackground;
int EnterNameBackground;
//variable for choosing option in menu bar
int ChoiceOption=0;
int Mode=0;
int r=255;
int g=255;
int b=255;
//input name variable
char InputName[20];
char OutputName[20];
int IndexNumber=0;
//file function

void setname(char name);

//function for showing image in menu bar
void background();
void playbackground();
void creditbackground();
void highscorebackground();
void instructionbackground();
void enternamebackground();

//mouse varibale for menu
int MouseX;
int MouseY;
//function for mouse in menu
void menumousecollision();

void iDraw()
{
	iClear();
	
	if(Mode==0){
	enternamebackground();
	if(ChoiceOption==1)
		{
			r=255;
			g=0;
			b=0;
			iSetColor(0,0,0);
			iText(505,206, InputName, GLUT_BITMAP_TIMES_ROMAN_24);
		}
	iSetColor(r,g,b);
	iRectangle(492,185,336,56);
		
	}

	if(ChoiceOption==2)
	{	
		playbackground();
		//iSetColor(255,255,255);
		//iRectangle(485,260,70,40);//2
		//iRectangle(485,210,160,40);//3
		//iRectangle(485,160,170,40);//4
		//iRectangle(485,110,90,40);//5
		//iRectangle(485,60,60,40);//6
	}
	if(ChoiceOption==3)
	{
			background();
	}
	else if(ChoiceOption==4)
	{
		highscorebackground();
		iSetColor(255,255,255);
		iText(345,276, OutputName, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(ChoiceOption==5)
	{
		instructionbackground();
	}
	else if(ChoiceOption==6)
	{
		creditbackground();
	}
	}




void iPassiveMouse(int mx, int my)
{
	MouseX=mx;
	MouseY=my;
	
}



/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my)
{
	printf("%d %d\n", mx, my);

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
		
		if((MouseX>492 && MouseX<492+334)&&(MouseY>185 && MouseY<185+56)&& Mode!=2)
		{
			ChoiceOption=1;//enter name box
		}
		else if(ChoiceOption==2)
		{

			if((MouseX>485 && MouseX<485+70)&&(MouseY>260 && MouseY<260+40))
			{
				ChoiceOption=3;//play
			}
			else if((MouseX>485 && MouseX<485+160)&&(MouseY>210 && MouseY<210+40))
			{
				ChoiceOption=4;//highscore
			}
			else if((MouseX>485 && MouseX<485+170)&&(MouseY>160 && MouseY<160+40))
			{
				ChoiceOption=5;//Instruction
			}
			else if((MouseX>485 && MouseX<485+90)&&(MouseY>110 && MouseY<110+40))
			{
				ChoiceOption=6;//Credit
			}
			else if((MouseX>485 && MouseX<485+60)&&(MouseY>60 && MouseY<60+40))
			{
				exit(0);
			}
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here

	}
}

/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
	if(ChoiceOption==1)
	{
		if(key!='\b'&& key!='\r')
		{
			InputName[IndexNumber] = key;
			IndexNumber++;
			InputName[IndexNumber] = '\0';
		}
		else if(key=='\b')
		{
			if(IndexNumber<=0)
				IndexNumber=0;
			else
				IndexNumber--;

			InputName[IndexNumber] = '\0';
		}
		else if(key =='\r')
		{   Mode=2;
			ChoiceOption=2;
			printf("%s", &InputName);
		}
	}

		
	FILE *fp = fopen("Name.bin","wb");

	fwrite(&InputName, sizeof(InputName), 1, fp);
	fclose(fp);

	fp=fopen("Name.bin","rb");
	fread(&OutputName, sizeof(OutputName),1,fp);
	fclose(fp);

	if(key=='b'&& Mode!=0)
	{
		ChoiceOption=2;
		
	}

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

	
}

int main()
{
	iInitialize(screenWidth, screenHeight, "Arquero The Game");
	Background= iLoadImage("Background.jpg");
	InstructionBackground= iLoadImage("InstructionBackground.jpg");
	CreditBackground= iLoadImage("CreditBackground.jpg");
	PlayBackground= iLoadImage("PlayBackground.jpg");
	HighScoreBackground= iLoadImage("HighScoreBackground.jpg");
	EnterNameBackground=iLoadImage("EnterNameBackground.jpg");

	iStart();
	
	return 0;
}
void background()
{
	iShowImage(0,0,screenWidth, screenHeight,Background);
}
void playbackground()
{
	iShowImage(0,0,screenWidth, screenHeight,PlayBackground);
}
void creditbackground()
{
	iShowImage(0,0,screenWidth, screenHeight,CreditBackground);
}
void highscorebackground()
{
	iShowImage(0,0,screenWidth, screenHeight,HighScoreBackground);
}
void instructionbackground()
{
	iShowImage(0,0,screenWidth, screenHeight,InstructionBackground);
}
void enternamebackground()
{
	iShowImage(0,0,screenWidth, screenHeight,EnterNameBackground);
}
