#include<iostream>
#include "OBJECTS.CPP"
#include "GAME.CPP"
#include "EDITOR.CPP"
#include "CREDITS.CPP"
#include "INSTRUCTIONS.CPP"
void clickb(int x,int y) {
    if(y<200 && x<200)
        menu();
}
void clickl(){

    clearmouseclick(WM_LBUTTONDOWN);
    while(1)
    {
        delay(1);
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN,x,y);
            if (x>250 && x<600 && y>300 && y<380)
                game(1,1);
            else if (x>800 && x<1150 && y>300 && y<380)
                game(1,2);
        }
    }
}
void select()
{
    cleardevice();
    setcolor(bgl);
    setfillstyle(SOLID_FILL,bgl);
    floodfill(1,1,bgl);
    rectangle(0,0,1360,700);
    setcolor(btn);
    setfillstyle(SOLID_FILL,btn);
    circle(60,50,50);
    floodfill(60,50,btn);
    setbkcolor(btn);
    setcolor(bgl);
    settextstyle(8,0,4);
    outtextxy(20,30,"MENU");

    setbkcolor(bgl);
        setcolor(LIGHTBLUE);
        settextstyle(8,0,6);
        outtextxy(250,300,"Ready-made");
        outtextxy(800,300,"Custom-made");
    registermousehandler(WM_LBUTTONDOWN,clickb);
    death=-1;
    clickl();
}
void clickm(){

    clearmouseclick(WM_LBUTTONDOWN);
    while(1)
    {
        delay(1);
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN,x,y);
            if (x>109 && x<484 && y>200 && y<260)
                select();
            else if (x>109 && x<484 && y>300 && y<360)
                edit();
                else if (x>109 && x<484 && y>400 && y<460)
                        instructions();
                        else if (x>109 && x<484 && y>500 && y<560)
                                credits();
                                else if (x>109 && x<484 && y>600 && y<660)
                                        exit(0);
        }
    }
}
int menu() {

        setrgbpalette(0,0,0,0);
        setrgbpalette(1,205,220,57);
        setrgbpalette(2,0,188,212);
        setrgbpalette(4,211,47,47);
        setrgbpalette(5,255,235,59);
        setrgbpalette(6,76,175,80);
        setrgbpalette(7,224,224,224);
        setrgbpalette(8,255,255,255);
        setrgbpalette(9,3,169,244);
        setrgbpalette(10,255,215,64);
        setrgbpalette(11,255,215,64);
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

        setbkcolor(bgl);
        setcolor(LIGHTBLUE);
        settextstyle(8,0,6);
        outtextxy(110,200,"PLAY GAME");
        outtextxy(110,300,"LEVEL EDITOR");
        outtextxy(110,400,"INSTRUCTIONS");
        outtextxy(110,500,"CREDITS");
        outtextxy(110,600,"EXIT");

        clickm();
        registermousehandler(WM_LBUTTONDOWN,clickb);
    getch();
}
