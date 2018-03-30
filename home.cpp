#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "MENU.CPP"

using namespace std;
void clickh()
{
    clearmouseclick(WM_LBUTTONDOWN);
    while(1)
    {
        delay(1);
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN,x,y);
            if(x>1220 && y>580)
                menu();
            else if(x<130 && y>580)
                exit(0);
        }
    }
}

int main(){
    int gd = DETECT,gm;
	initgraph(&gd,&gm,"C:\\Program Files (x86)\\CodeBlocks\\MinGW");

    setrgbpalette(0,0,0,0);
    setrgbpalette(1,205,220,57);
    setrgbpalette(2,0,188,212);
    setrgbpalette(4,211,47,47);
    setrgbpalette(5,255,235,59);
    setrgbpalette(6,76,175,80);
    setrgbpalette(7,178,178,178);
    setrgbpalette(8,255,255,255);
    setrgbpalette(9,3,169,244);
    setrgbpalette(10,255,215,64);
    setrgbpalette(11,158,158,158);
    setrgbpalette(12,255,143,0);
    setrgbpalette(13,255,87,34);
    setrgbpalette(14,63,81,181);
    setrgbpalette(15,255,255,255);

    cleardevice();
    setcolor(bgl);
    setfillstyle(SOLID_FILL,bgl);
    floodfill(1,1,bgl);
    rectangle(0,0,1360,700);

    setcolor(hbd);
    rectangle(0,0,1370,110);
    setfillstyle(SOLID_FILL,hbd);
    floodfill(1,1,hbd);
    setcolor(htd);
    setbkcolor(hbd);
    settextstyle(8,0,8);
    outtextxy(500,20,"MOVE IT !");

    setcolor(hbd);
    setfillstyle(SOLID_FILL,hbd);
    rectangle(0,660,1370,800);
    floodfill(1,661,hbd);

    setbkcolor(btn);
    setcolor(btn);
    circle(1280,640,60);
    setfillstyle(SOLID_FILL,btn);
    floodfill(1280,640,btn);
    setcolor(bgl);
    settextstyle(8,0,5);
    outtextxy(1230,620,"NEXT");
    setbkcolor(btn);
    setcolor(btn);
    circle(70,640,60);
    setfillstyle(SOLID_FILL,btn);
    floodfill(70,640,btn);
    setcolor(bgl);
    settextstyle(8,0,5);
    outtextxy(20,620,"EXIT");

    setcolor(htl);
    settextstyle(8,0,5);
    setbkcolor(bgl);


    clickh();
    getch();
    closegraph();
}
