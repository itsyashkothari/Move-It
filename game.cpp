#include<math.h>
#include<fstream>
#include<graphics.h>

using namespace std;
void menu(int lvlnum);
void game(int,int);
void startgame(int);
void changesep(int,int);
void load_level(int);
void boxg(int,int,int);
void ccheck(int,int,int);
int menu();
void clickb(int x, int y);

int boxx,boxy,tc=0,ts=0;
int sp=2,cn=0,death=-1;
int gm=0;

class objs{
int x,y,a,b;
public:
    int xs,ys,xe,ye;
    void s()
    {
        if(xs<xe)
          {a=sp;x=xs+sp;y=ys-sp;}
        else if(xs>xe)
            {a=-sp;x=xs-sp;y=ys+sp;}
        else
        { a=0;b=-sp;x=xs;y=(ys>ye)? ys-sp : ys+sp ;}
    }
    void movement()
    {
        setcolor(bgl);
        setfillstyle(SOLID_FILL,bgl);
        circle(x,y,8);
        floodfill(x,y,bgl);
        if(a==0)
         {
            if(y==ye || y==ys )
                b=-b;
        }
        else if(x==xe || x==xs )
            a=-a;
        x=x+a;
        if (a!=0)
            y=ys+(x-xs)*(ye-ys)/(xe-xs);
        else
            y=y+b;
        setcolor(obs);
        setfillstyle(SOLID_FILL,obs);
        circle(x,y,8);
        floodfill(x,y,obs);
    }
};
class objc{
int x,y;
double t=0;
public:
    int xs,ys,xe,ye;
    float r;
    void c()
    {
        r = sqrt(pow((xs-xe),2)+pow((ys-ye),2));
    }
    void movement()
    {
        setcolor(bgl);
        setfillstyle(SOLID_FILL,bgl);
        circle(x,y,8);
        floodfill(x,y,bgl);
        if(t>=8*atan(1))
            t=0;
        else
            t=t+0.05;
        x=xs+r*cos(t);
        y=ys+r*sin(t);
        setcolor(obs);
        setfillstyle(SOLID_FILL,obs);
        circle(x,y,8);
        floodfill(x,y,obs);
    }
};

objs so[20];
objc co[20];

void changesep(int x,int y){
    setcolor(bgl);
    setfillstyle(SOLID_FILL,bgl);
    rectangle(x-15,y-15,x+15,y+15);
    floodfill(x,y,bgl);
    if(getpixel(x-30,y)==sep)
        changesep(x-30,y);
    if(getpixel(x,y-30)==sep)
        changesep(x,y-30);
    if(getpixel(x+30,y)==sep)
        changesep(x+30,y);
    if(getpixel(x,y+30)==sep)
        changesep(x,y+30);
}
void load_level(int lvlnum,int m) {
    char ch,lvlname[20],temp[20],filename[20];
    if(m==1)
        strcpy(filename,"leveldata_rm.txt");
    else
        strcpy(filename,"leveldata_cm.txt");
    ifstream ld(filename);
    for(int i=1;i<=20;i++)
        if(i==lvlnum)
            {
                ld>>lvlname;break;
            }
        else
            ld>>temp;
    ld.close();

    ifstream f(lvlname);
    for(int y=115;y<=535;y+=30)
        for(int x=115;x<=1225;x+=30)
           {
               f>>ch;
                switch(ch)
                {
                    case ')' : bglg(x,y);break;
                    case '\'': bglg(x,y);coin(x,y);cn++;break;
                    case '&' : boxx=x;boxy=y;break;
                    case '(' : sepf(x,y);break;
                    case '+' : bglg(x,y);break;
                    case '0' : bglg(x,y);break;
                }
            }

    int ob;
    f>>ob;
    while(f)
    {
        if(ob==1)
        {
            f>>ob;so[ts].xs=ob;f>>ob;so[ts].ys=ob;
            f>>ob;so[ts].xe=ob;f>>ob;so[ts].ye=ob;
            so[ts++].s();
            f>>ob;
        }
        if(ob==2)
        {
            f>>ob;co[tc].xs=ob;f>>ob;co[tc].ys=ob;
            f>>ob;co[tc].xe=ob;f>>ob;co[tc].ye=ob;
            co[tc++].c();
            f>>ob;
        }
    }
    changesep(boxx,boxy);
    boxf(boxx,boxy);
    f.close();

}
void boxg(int x,int y,int cb){
	setcolor(cb);
	setfillstyle(SOLID_FILL,cb);
	rectangle(x-10,y-10,x+10,y+10);
	floodfill(x,y,cb);
}
void ccheck(int x,int y,int lvlnum){
    for(int i=x-12;i<x+12;i++)
    {
        if(getpixel(i,y+12)==obc || getpixel(i,y-12)==obc || getpixel(i,y+12)==obs || getpixel(i,y-12)==obs)
            game(lvlnum,gm);
        if(getpixel(i,y+12)==con)
        {
            --cn;
            setfillstyle(SOLID_FILL,bgl);
            floodfill(i,y+12,bgl);
            boxf(x,y);
        }
        if(getpixel(i,y-12)==con)
        {
            --cn;
            setfillstyle(SOLID_FILL,bgl);
            floodfill(i,y-12,bgl);
            boxf(x,y);
        }
        if((getpixel(i,y+12)==sep || getpixel(i,y-12)==sep) && cn==0)
        {--death;game(++lvlnum,gm);}
    }
    for(int i=y-12;i<y+12;i++)
    {
        if(getpixel(x-12,i)==obc || getpixel(x+12,i)==obc || getpixel(x-12,i)==obs || getpixel(x+12,i)==obs )
            game(lvlnum,gm);
        if(getpixel(x+12,i)==con)
        {
            --cn;
            setfillstyle(SOLID_FILL,bgl);
            floodfill(x+12,i,bgl);
            boxf(x,y);
        }
        if(getpixel(x-12,i)==con)
        {
            --cn;
            setfillstyle(SOLID_FILL,bgl);
            floodfill(x-12,i,bgl);
            boxf(x,y);
        }
        if((getpixel(i,y+12)==sep || getpixel(i,y-12)==sep) && cn==0)
        {--death;game(++lvlnum,gm);}
    }
}
void startgame(int lvlnum){

    setbkcolor(bgd);
    setcolor(wht);
    char deaths[10];
    sprintf(deaths,"Deaths : %d",death);
    outtextxy(500,20,deaths);

    setbkcolor(bgl);
    setcolor(btn);
    setfillstyle(SOLID_FILL,btn);
    circle(60,50,50);
    floodfill(60,50,btn);
    setbkcolor(btn);
    setcolor(bgl);
    settextstyle(8,0,4);
    outtextxy(20,30,"BACK");
    setbkcolor(bgl);

    int x=boxx,y=boxy;
    char m;
    while(1)
    {
        delay (5);
        for(int i=0;i<tc;i++)
            co[i].movement();
        for(int i=0;i<ts;i++)
            so[i].movement();
        ccheck(x,y,lvlnum);
        if(kbhit())
        {
            ccheck(x,y,lvlnum);
            m = getch();
            if (m==0 || m==0xE0) m=getch();
            switch(m)
            {
                case 72 :  if (getpixel(x+12,y-12)!=bgd && getpixel(x-12,y-12)!=bgd)
                            {
                                if(getpixel(x+12,y-12)==sep || getpixel(x-12,y-12)==sep)
                                    if(cn!=0)
                                        break;
                                int c=getpixel(x,y+11);
                                if(c==bgd)c=bgl;
                                boxg(x,y,c);
                                y=y-4;boxg(x,y,box);
                            }
                            break;
                case 75 :  if (getpixel(x-12,y-12)!=bgd && getpixel(x-12,y+12)!=bgd)
                            {
                                if(getpixel(x-12,y-12)==sep || getpixel(x-12,y+12)==sep)
                                    if(cn!=0)
                                        break;
                                int c=getpixel(x+11,y);
                                if(c==bgd)c=bgl;
                                boxg(x,y,c);
                                x=x-4;boxg(x,y,box);
                            }
                            break;
                case 80 :  if (getpixel(x+12,y+12)!=bgd && getpixel(x-12,y+12)!=bgd)
                            {
                                if(getpixel(x+12,y+12)==sep || getpixel(x-12,y+12)==sep)
                                    if(cn!=0)
                                        break;
                                int c=getpixel(x-11,y);
                                if(c==bgd)c=bgl;
                                boxg(x,y,c);
                                y=y+4;boxg(x,y,box);
                            }
                            break;
                case 77 :  if (getpixel(x+12,y-12)!=bgd && getpixel(x+12,y+12)!=bgd)
                            {
                                if(getpixel(x+17,y-12)==sep || getpixel(x+17,y+12)==sep)
                                    if(cn!=0)
                                        break;
                                int c=getpixel(x,y-11);
                                if(c==bgd)c=bgl;
                                boxg(x,y,c);
                                x=x+4;boxg(x,y,box);
                            }
                            break;
            }
        }
    }
}

void game(int lvlnum,int mode){
    setrgbpalette(7,0,96,100);
    cleardevice();
    setcolor(wht);
    setbkcolor(bgl);
    setcolor(btn);
    setfillstyle(SOLID_FILL,btn);
    circle(60,50,50);
    floodfill(60,50,btn);
    setbkcolor(btn);
    setcolor(bgl);
    settextstyle(8,0,4);
    outtextxy(20,30,"MENU");
    setrgbpalette(7,0,96,100);
    setcolor(bgd);
    rectangle(0,0,1360,700);
    setfillstyle(SOLID_FILL,bgd);
    floodfill(1,1,bgd);

    tc=0;ts=0;cn=0;gm=mode;
    death++;
    load_level(lvlnum,gm);
    startgame(lvlnum);
    closegraph();
}
