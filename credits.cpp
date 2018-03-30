int menu();
void clickb(int x, int y);
void credits() {
    cleardevice();
    setbkcolor(bgl);
    settextstyle(8,0,5);
    outtextxy(500,40,"CREDITS");

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
    settextstyle(8,0,4);
    outtextxy(50,160,"Made By : CHINMAY GARG AND YASH KOTHARI");
    outtextxy(50,240,"Guided by : MS. JASPAL VISHWAKARMA");

    registermousehandler(WM_LBUTTONDOWN,clickb);
}
