# include "iGraphics.h"
#include"ninja.h"

int ccf=1;

struct Coin
{
int xl,xr,yb,yt;
bool isAlive;

Coin()
{
	isAlive = true;
	;}
Coin(int xl,int xr,int yb,int yt)
{
this->xl = xl;
this->xr = xr;
this->yb = yb;
this->yt = yt;
isAlive = true;
}

};

Coin coins[5];

void iDraw()
{
	//place your drawing codes here
	iClear();
	if(p==1){

		iShowImage(0, 0, 400, 400, image1);
		

    iSetColor(255,0,0);
	iLine(cursorMX,cursorMY,cursorMX,cursorMY+10);
	iLine(cursorMX,cursorMY,cursorMX,cursorMY-10);
	iLine(cursorMX,cursorMY,cursorMX+10,cursorMY);
	iLine(cursorMX,cursorMY,cursorMX-10,cursorMY);}
	
	if(p==2){
		
		iShowImage(bx1, by1,400 ,400, image2);
		iShowImage(bx2, by2,400 ,400, image2);    //Background
		iSetColor(255,0,0);
		if(lflag<130){
			iShowImage(nx, ny, nx1,ny1, ninja);
		
		if((nx+50)==bulletx1) {
		lflag++;
		//printf("%d\n",lflag);
	    }
	    for(int i=0;i<5;i++){
		if((nx<coins[i].xl && nx+nx1>coins[i].xl) && (ny<coins[i].yb && ny+ny1>coins[i].yb)){  //coins collission
			//printf("collided\n");
			coins[i].isAlive = false;
			printf("%d\n",ll);
			
			if(coins[i].isAlive==false && i==0)
				ll=1;
			if(coins[i].isAlive==false && i==2)
				ll=2;
			if(coins[i].isAlive==false && i==3)
				ll=3;
			if(coins[i].isAlive==false && i==4)
				ll=5;

		}
		}
		for(int i=0;i<5;i++){
			if(coins[i].isAlive==true)iShowImage(coins[i].xl, coins[i].yb, 20,15, coin);}
		
				iShowImage(346, ny-10, 45,80, enemy);
				iFilledCircle(bulletx1,bullety1,5);
				}
		else 
			iShowImage(0,0,400,400,image6);
		if(ll>=5){
			p=6;
		for(int i=0;i<5;i++){
			coins[i].isAlive = true;}
		}
		iText(10,10,"press backspace for back");

		
	}
	
	
		
	if(p==4){                                //Credit
		iShowImage(0, 0, 400, 400, image3);
		iText(10,10,"press backspace for back");
		
		
	}
	if(p==3){                                //Instruction
		iShowImage(0, 0, 400, 400, image5);
		iText(10,10,"press backspace for back");

	}
	if(p==5){                                //HighScore
		iShowImage(0,0,400,400,image4);	
		iText(10,10,"press backspace for back");
		iSetColor(0,0,0);
		iFilledRectangle(150,300,80,35);
		iSetColor(255,255,255);
		iText(150,310,"HighScore");


	}
	 if(p==6){
		iShowImage(bx1, by1,400 ,400, image7);
		iShowImage(bx2, by2,400 ,400, image7);    //Background 2
		iSetColor(255,0,0);
		if(lflag<130){
			iShowImage(nx, ny, nx1,ny1, ninja);
		
		if((nx+50)==bulletx2) {
		lflag++;
		printf("%d\n",lflag);
	    }
	    for(int i=0;i<5;i++){
		if((nx<coins[i].xl && nx+nx1>coins[i].xl) && (ny<coins[i].yb && ny+ny1>coins[i].yb)){
			//printf("collided\n");
			coins[i].isAlive = false;
		
			

		}}
		for(int i=0;i<5;i++){
			if(coins[i].isAlive==true)
				iShowImage(coins[i].xl, coins[i].yb, 20,15, coin);}
		
				iShowImage(346, ny-10, 45,80, enemy);
				iFilledCircle(bulletx2,bullety2,5);}
		else 
			iShowImage(0,0,400,400,image6);

		
	}
	 iText(10,10,"press backspace for back");


	}


/*
	function iDraw() is called again and again by the system.
*/
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
	dragMX = mx;
	dragMY = my;
}


/*
	function iPassiveMouse() is called when the user moves the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int mx, int my)
{
    cursorMX = mx;
    cursorMY = my;
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{    
	//printf("x-- %d   y--%d\n",mx,my);
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if((mx>37 && mx<37+50 ) && (my >237 && my<237+20))
		p=2;
	}

	
		if((mx>37 && mx<37+50) && (my>117 && my<117+20))
		{ p=4; }
		if((mx>37 && mx<37+50) && (my>197 && my<197+20))
		{ p=3; }
		if((mx>37 && mx<37+50) && (my>157 && my<157+20))
		{ p=5; }			
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'x')
	{
		//do something with 'x'
		exit(0);
	}

	if(key == '\b')
	{
		//do something with 'x'
		p=1;
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
void iSpecialKeyboard(unsigned char key)  //movement of ninja
{

	if(key == GLUT_KEY_UP)
	{
		ny+=10;
	}
	if(key == GLUT_KEY_DOWN)
	{
		ny-=10;
	}
	if(key == GLUT_KEY_RIGHT)
	{
		nx+=10;
	}
	if(key == GLUT_KEY_LEFT)
	{
		nx-=12;
	}


	//place your codes for other keys here
}
void bulletChange(){
	bulletx1 -= dx;
	
	if(bulletx1 < 50){
		bulletx1=346;
		bullety1=ny+50;}
	}
void bulletChange2(){
	bulletx2 -= dx;
	
	if(bulletx2 < 50){
		bulletx2=346;
		bullety2=ny+50;}
	}

void background()
{bx1=bx1-2;
bx2=bx2-2;
if(bx2==0)
{bx1=0;
bx2=300;}
}

int main()
{
	//place your own initialization codes here.

	cflag=0;
	dx=5;
	dy=7;
	
	bulletx1=390;
	bullety1=ny;
	bulletx2=390;
	bullety2=ey;
	coins[0] = Coin(112,132,134,152);
	coins[1] = Coin(164,156,184,184);
	coins[2] = Coin(226,133,246,153);
	coins[3] = Coin(296,165,316,135);
	coins[4] = Coin(340,180,360,150);
	bullettimer= iSetTimer(50, bulletChange);
	bullettimer2= iSetTimer(40, bulletChange2);
	iInitialize(400, 400, "Slaying Ninja.");
	image1 = iLoadImage("images\\menu.jpg");
	image2 = iLoadImage("images\\backgr.jpg");
	image3 = iLoadImage("images\\credits.jpg");
	image5 = iLoadImage("images\\instructions.jpg");
	image4 = iLoadImage("images\\highscore.jpg");
	image6 = iLoadImage("images\\gameover.png");
	image7 = iLoadImage("images\\level2.gif");
	ninja= iLoadImage("images\\ninja1.png");
	coin=iLoadImage("images\\download.png");
	enemy=iLoadImage("images\\enemy (2).png");
	iSetTimer(10,background);
	iStart();
	
	return 0;
}