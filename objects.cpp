#include<graphics.h>

int blk=BLACK;
int btn=1;
int hbd=2;
int hbl=3;
int box=4;
int con=5;
int sep=6;
int bgd=7;
int bgl=8;
int obs=9;
int htd=10;
int htl=11;
int ntd=12;
int ntl=13;
int obc=14;
int wht=0;

void boxf(int x,int y){
    setcolor(box);
    setfillstyle(SOLID_FILL,box);
    rectangle(x-10,y-10,x+10,y+10);
    floodfill(x,y,box);
}
void clrf(int x,int y){
    setcolor(blk);
    rectangle(x-15,y-15,x+15,y+15);
}
void bglg(int x,int y){
    setcolor(bgl);
    setfillstyle(SOLID_FILL,bgl);
    rectangle(x-15,y-15,x+15,y+15);
    floodfill(x,y,bgl);
}
void bglf(int x,int y){
    setcolor(bgl);
    setfillstyle(SOLID_FILL,bgl);
    floodfill(x,y,blk);
}
void coin(int x,int y){
    setcolor(con);
    setfillstyle(SOLID_FILL,con);
    circle(x,y,6);
    floodfill(x,y,con);
}
void bgdf(int x,int y){
    setcolor(bgd);
    setfillstyle(SOLID_FILL,bgd);
    rectangle(x-15,y-15,x+15,y+15);
    floodfill(x,y,bgd);
}
void sepf(int x,int y){
    setcolor(sep);
    setfillstyle(SOLID_FILL,sep);
    rectangle(x-15,y-15,x+15,y+15);
    floodfill(x,y,sep);
}
void obsf(int x,int y){
    setcolor(obs);
    setfillstyle(SOLID_FILL,obs);
    circle(x,y,8);
    floodfill(x,y,obs);
}
void obcf(int x,int y){
    setcolor(obc);
    setfillstyle(SOLID_FILL,obc);
    circle(x,y,8);
    floodfill(x,y,obc);
}
void grid(){
    setcolor(blk);
    for(int i=0;i<=1241-100;i+=30)
        line(100+i,100,100+i,550);
    for(int i=0;i<=550-100;i+=30)
        line(100,100+i,1241,100+i);
}
