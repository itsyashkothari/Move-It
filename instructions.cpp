void clickb(int x, int y);
void instructions(){
    cleardevice();
    setbkcolor(bgl);
    settextstyle(8,0,5);
    outtextxy(500,40,"INSTRUCTIONS");

    setbkcolor(bgl);
    setcolor(btn);
    setfillstyle(SOLID_FILL,btn);
    circle(60,50,50);
    floodfill(60,50,btn);
    setbkcolor(btn);
    setcolor(bgl);
    settextstyle(8,0,4);
    outtextxy(20,30,"MENU");

    setcolor(hbd);
    setfillstyle(SOLID_FILL,hbd);
    rectangle(0,660,1370,800);
    floodfill(1,665,hbd);
    setbkcolor(bgl);

    setcolor(ntd);
    int l=120;
    outtextxy(50,l,"The player has to move the red box from the starting green region to");
    outtextxy(50,l+=40,"the end green region and collect all the yellow coloured coins in the");
    outtextxy(50,l+=40,"in the path. But beware of the blue obstacles, one circular and the");
    outtextxy(50,l+=40,"other linear which are continuously in motion. You have to avoid");
    outtextxy(50,l+=40,"them to minimize your number of deaths which will be counted during");
    outtextxy(50,l+=40,"the game.");
    outtextxy(50,l+=80,"                  CONTROLS  FOR  THE  OBJECT");
    outtextxy(50,l+=40,"````````````````````````````````````````````````````````````````");
    outtextxy(50,l+=40,"Use Arrow keys accordingly for motion in the indicated direction");
    registermousehandler(WM_LBUTTONDOWN, clickb);
}
