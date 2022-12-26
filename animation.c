#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<stdlib.h>

#define ScreenWidth getmaxx()
#define ScreenHeight getmaxy()
#define GroundY ScreenHeight*0.74

void drawline(int x1,int y1,int x2,int y2,int c)
{
 int dx=x2-x1, dy=y2-y1,l;
 
if(abs(dx)>abs(dy))
l=abs(dx);
else
l=abs(dy);
float dx1=dx/float(l), dy1=dy/float(l);
float xn=x1, yn=y1;
putpixel((int)x1,(int)y1,c);
int i=0;
while(i<l)
{
xn=xn+dx1;
yn=yn+dy1;
putpixel((int)xn,(int)yn,c);
i++;
}
}
void Rain(int x)
{
int i,rx,ry;
for(i=0;i<400;i++)
{
rx=rand() % ScreenWidth;
ry=rand() % ScreenHeight;
if(ry<GroundY-4)
{
if(ry<GroundY-120 || (ry>GroundY-120 && (rx<x-20 || rx>x+60)))
drawline(rx,ry,rx+0.5,ry+4,15);
drawline(rx,ry,rx+0.5,ry+4,15);
}
}
}
void rainbow()
{
    int x, y, i;
  
    x = 350;
    y = 225;
  
    for (i=30; i<150; i++)
    {
        delay(100);
  
        setcolor(i/10);
  
        arc(x, y, 0, 180, i-10);
    }
}
void drawcircle(int x,int y,int r,int c)
{
int xk=0,yk=r;
float pk=(5/4)-r;
while(xk<yk)
{
putpixel(xk+x,yk+y,c);
putpixel(-xk+x,yk+y,c);
putpixel(xk+x,-yk+y,c);
putpixel(-xk+x,-yk+y,c);
putpixel(yk+x,xk+y,c);
putpixel(-yk+x,xk+y,c);
putpixel(yk+x,-xk+y,c);
putpixel(-yk+x,-xk+y,c);
if(pk<0)
{
xk=xk+1;
yk=yk;
pk=pk+(2*xk)+1;
}
else
{
xk=xk+1;
yk=yk-1;
pk=pk+(2*xk)-(2*yk)+1;
}
}
}

void main()
{
int gd=DETECT,gm;
int i,j,c1,c2,c,x=0;

     initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
int c3=9;
int a=400;
while(a!=500)
{
drawline(0,a,800,a,c3);
a++;
}
     for(i=0;i<120 ;i++)
     {
     
 clrscr();
	Rain(x);
	x=(x+4)%ScreenWidth;
      for( j=0;j<35;j++)
       {
       if(190-i>130)
 c1=4,c2=1,c=2;
 else
 c1=14,c2=11,c=10;
       
       drawcircle(320,190-i,j-10,c1);
       setcolor(c2);
       arc(100+i,200,0,180,j-25);
       arc(115+i,200,0,180,j-20);
       arc(140+i,200,0,180,j-15);
       arc(165+i,200,0,180,j-25);

       arc(405+i,150,0,180,j-25);
       arc(430+i,150,0,180,j-15);
       arc(455+i,150,0,180,j-25);
       }
  int b=0;

  while(b+250!=400)
  {
   b++;
   
   drawline(0,400,175,250+b,c);
   drawline(175,250+b,350,400,c);
   drawline(350,400,525,250+b,c);
   drawline(525,250+b,700,400,c);
   }     
	delay(150);
     }
     
     rainbow();
     getch();
     }