#include<iostream>
#include<fstream>
using namespace std;

void edit();
void first(int ,int );
int menu();
void clickb(int x, int y);
int cx(int x){
    return x-((x-100)%30)+15;}
int cy(int y){
    return y-((y-100)%30)+15;}
struct obj{
    int xo,yo;}c[20][2],s[20][2];

int x=0,y=0,z=0,lc=0,ls=0,p=0,hx=0,hy=0;

void clear_obj(int x,int y)
{
    if(getpixel(cx(x),cy(y))==obc)
    for (int i=0;i<=lc;i++)
                if(c[i][0].xo==x && c[i][0].yo==y || c[i][1].xo==x && c[i][1].yo==y)
                    {
                        bglf(c[i][1].xo,c[i][1].yo);
                        bglf(c[i][0].xo,c[i][0].yo);
                        c[i][0].xo=-1;c[i][0].yo=-1;c[i][1].xo=-1;c[i][1].yo=-1;

                    }
    if(getpixel(cx(x),cy(y))==obs)
    for (int i=0;i<=ls;i++)
                if(s[i][0].xo==x && s[i][0].yo==y || s[i][1].xo==x && s[i][1].yo==y)
                    {
                        bglf(s[i][1].xo,s[i][1].yo);
                        bglf(s[i][0].xo,s[i][0].yo);
                        s[i][0].xo=-1;s[i][0].yo=-1;s[i][1].xo=-1;s[i][1].yo=-1;
                    }
}
void click()
{
    int t=1;
    clearmouseclick(WM_LBUTTONDOWN);
    while(t)
    {
        delay(1);
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN,x,y);
            cout<<"\nClick x = "<<x<<" y = "<<y;
            hy=y;
            hx=x;
            t=0;
        }
    }
}
int checkxyright(int x,int y)
{
    if(x>100&&y>100&&x<1241&&y<550)
        return 1;
    else
        return 0;
}
void box_act()
{
    click();
    if(checkxyright(x,y))
    {
        x=cx(x);y=cy(y);
        clear_obj(x,y);
        setfillstyle(SOLID_FILL,sep);
        floodfill(x,y,blk);
        boxf(x,y);
        z++;
        click();
        first(x,y);
    }
    else
        first(x,y);
}
void sep_act()
{
    click();
    if(checkxyright(x,y))
    {
        if(getpixel(cx(x),cy(y))==box)
           z=0;
        clear_obj(x,y);
        setfillstyle(SOLID_FILL,sep);
        floodfill(x,y,blk);
        p++;
        sep_act();
    }
    else
        first(x,y);
}
void bgd_act ()
{
    click();
    if(checkxyright(x,y))
    {
        if(getpixel(cx(x),cy(y))==box)
           z=0;
        clear_obj(x,y);
        setfillstyle(SOLID_FILL,bgd);
        floodfill(x,y,blk);
        bgd_act();
    }
    else
        first(x,y);
}
void con_act ()
{
    click();
    if(checkxyright(x,y))
    {
        if(getpixel(cx(x),cy(y))==box)
           z=0;
        clear_obj(x,y);
        setfillstyle(SOLID_FILL,bgd);
        floodfill(x,y,blk);
        coin(cx(x),cy(y));
        cn++;
        con_act();
    }
    else
        first(x,y);
}
void obc_act()
{
    int i=0;
    while(i!=2)
    {
        again :
        click();
        if(checkxyright(x,y))
        {
            if(getpixel(cx(x),cy(y))==box)
                z=0;
            clear_obj(x,y);
            setfillstyle(SOLID_FILL,bgd);
            floodfill(x,y,blk);
            obcf(cx(x),cy(y));
            c[lc][i].xo=cx(x);
            c[lc][i].yo=cy(y);
            cout<<c[lc][i].xo<<"  "<<c[lc][i].yo<<"\n";
            i++;
        }
        else if(i==0)
            first(x,y);
        else if(i==1)
            goto again;
        if(i==1)
            goto again;
    }
    lc++;
    obc_act();

}
void obs_act()
{
    int i=0;
    while(i!=2)
    {
        again :
        click();
        if(checkxyright(x,y))
        {
            if(getpixel(cx(x),cy(y))==box)
                z=0;
            clear_obj(x,y);
            setfillstyle(SOLID_FILL,bgd);
            floodfill(x,y,blk);
            obsf(cx(x),cy(y));
            s[ls][i].xo=cx(x);
            s[ls][i].yo=cy(y);
            i++;
        }
        else if(i==0)
            first(x,y);
        else if(i==1)
            goto again;
        if(i==1)
            goto again;

    }
   // line(s[ls][1].xo,s[ls][1].yo,s[ls][2].xo,s[ls][2].yo);
    ls++;
    obs_act();

}
void clear_act()
{
    int i;
    cout<<"clear";
    click();
    x=cx(x);y=cy(y);
    if(checkxyright(x,y))
    {
        if(getpixel(x,y)==sep || getpixel(x,y)==bgd)
            bglf(x,y);
        else if(getpixel(x,y)==con)
            bglf(x,y);
        else if(getpixel(x,y)==obc)
        {
            for (i=0;i<=lc;i++)
                if(c[i][0].xo==x && c[i][0].yo==y || c[i][1].xo==x && c[i][1].yo==y)
                    {
                        bglf(c[i][1].xo,c[i][1].yo);
                        bglf(c[i][0].xo,c[i][0].yo);
                        cout<<c[i][1].xo<<"  "<<c[i][1].yo<<"\n";
                        cout<<c[i][0].xo<<"  "<<c[i][0].yo<<"\n";
                        c[i][0].xo=-1;c[i][0].yo=-1;c[i][1].xo=-1;c[i][1].yo=-1;
                    }
        }
        else if(getpixel(x,y)==obs)
        {
            for (i=0;i<=ls;i++)
                if(s[i][0].xo==x && s[i][0].yo==y || s[i][1].xo==x && s[i][1].yo==y)
                    {
                        bglf(s[i][1].xo,s[i][1].yo);
                        bglf(s[i][0].xo,s[i][0].yo);
                        s[i][0].xo=-1;s[i][0].yo=-1;s[i][1].xo=-1;s[i][1].yo=-1;
                    }
        }
        else if(getpixel(x,y)==box)
        {
            z=0;
            bglf(x,y);
        }
        else if(getpixel(x,y)==bgl);
        clear_act();
    }
    else
        first(x,y);
}
void save()
{
    if(z==1 && p>=2)
    {
        char lvlname[20]={" "},temp[20]={" "},g;

        setbkcolor(bgl);
        setcolor(bgl);
        setfillstyle(SOLID_FILL,bgl);
        floodfill(1,552,bgl);
        rectangle(20,600,1360,700);
        setcolor(ntd);
        settextstyle(8,0,5);
        outtextxy(200,600,"Enter Level Name : ");
        for(int i=0;i<20;i++)
        {
            lvlname[i] = getch();
            if(lvlname[i]==13)
            {
                lvlname[i]='\0';
                goto saving;
            }
            outtextxy(710,600,lvlname);
        }
        saving:
        strcat(lvlname,".txt");

        ofstream t ("temp.txt");
        t<<lvlname;
        ifstream ld ("leveldata_cm.txt");
        ld>>temp;
        while(ld)
        {
            t<<"\n"<<temp;
            ld>>temp;
        }
        t.close();
        ld.close();
        remove("leveldata_cm.txt");
        rename("temp.txt","leveldata_cm.txt");
        ofstream f (lvlname);
        for(y=115;y<=535;y+=30)
            for(x=115;x<=1225;x+=30)                 // 37 * 14 = 518
            {
                g = getpixel(x,y)+34;
                f<<g<<" ";
            }
        for(int i=0;i<lc;i++)
            if(c[i][0].xo!=-1)
                f<<"2 "<<c[i][0].xo<<" "<<c[i][0].yo<<" "<<c[i][1].xo<<" "<<c[i][1].yo<<" ";
        for(int i=0;i<ls;i++)
            if(s[i][0].xo!=-1)
                f<<"1 "<<s[i][0].xo<<" "<<s[i][0].yo<<" "<<s[i][1].xo<<" "<<s[i][1].yo<<" ";
        f.close();
        menu();
    }
    else
    {
        click();
        first(x,y);
    }
}
void first(int x,int y)
{
    if (x>1259 && y<101)
        save();
    else if(y>585 && y<615 && x>115 && x<145)
        clear_act();
    else if(y>585 && y<615 && x>215 && x<245)
        sep_act();
    else if(y>585 && y<615 && x>415 && x<445)
        bgd_act();
    else if(y>585 && y<615 && x>615 && x<645)
        con_act();
    else if(y>585 && y<615 && x>815 && x<845)
        obs_act();
    else if(y>585 && y<615 && x>1015 && x<1045)
        obc_act();
    else if(y>590 && y<610 && x>1215 && x<1245 && z==0)
        box_act();
    else if(y<101 && x<111)
        menu();
    else
    {
        click();
        first(hx,hy);
    }
}
void edit()
{
    cleardevice();
    setrgbpalette(7,224,224,224);
    setcolor(bgl);
    rectangle(0,0,1360,700);
    setfillstyle(SOLID_FILL,bgl);
    floodfill(1,1,bgl);

    setbkcolor(bgl);
    setcolor(btn);
    setfillstyle(SOLID_FILL,btn);
    circle(60,50,50);
    floodfill(60,50,btn);
    setbkcolor(btn);
    setcolor(bgl);
    settextstyle(8,0,4);
    outtextxy(20,30,"MENU");

    setbkcolor(bgl);
    setcolor(btn);
    setfillstyle(SOLID_FILL,btn);
    circle(1300,50,50);
    floodfill(1300,50,btn);
    setbkcolor(btn);
    setcolor(bgl);
    settextstyle(8,0,4);
    outtextxy(1260,30,"SAVE");

    setcolor(hbd);
    setfillstyle(SOLID_FILL,hbd);
    rectangle(0,660,1370,800);
    floodfill(1,665,hbd);

    setcolor(blk);
    settextstyle(8,0,1);
    setbkcolor(bgl);
    grid();
    clrf(130,600);outtextxy(100,620,"Clear");
    sepf(230,600);outtextxy(190,620,"Terminals");
    bgdf(430,600);outtextxy(370,620,"Background");
    coin(630,600);outtextxy(610,620,"Coin");
    obsf(830,600);outtextxy(790,620,"Straight");
    obcf(1030,600);outtextxy(990,620,"Circular");
    boxf(1230,600);outtextxy(1215,620,"Box");
    setbkcolor(bgl);
    setcolor(hbd);
    settextstyle(8,0,5);
    outtextxy(500,30,"LEVEL EDITOR");
    z=0;
    for(int i=0;i<20;i++)
    {
        c[i][0].xo=-1;
        c[i][1].xo=-1;
        s[i][0].xo=-1;
        s[i][1].xo=-1;
    }
    click();
    first(x,y);

    ending:
	closegraph();
}
