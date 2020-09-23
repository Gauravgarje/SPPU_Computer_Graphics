//Program: Drawing Solid, Dotted, Dashed, Dashdot and thick lines using DDA Algorithm
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void dda(float x1, float y1, float x2, float y2)
{
 int steps, dx=(x2-x1), dy=(y2-y1);
 
 if(abs(dx)>abs(dy))
   steps=abs(dx);
 else
   steps=abs(dy);
 
 float xinc=(float)dx/steps, yinc=(float)dy/steps;
 float x=x1, y=y1;
 
 putpixel(x,y,15);
 outtextxy(x2+100,y2, "NORMAL LINE");
 int a,b;
 
 for(int i=1 ; i<=steps ; i++)
 {
  x = (x + xinc);
  y = (y + yinc);
  
  a=x + 0.5;
  b=y + 0.5;
  
  putpixel(a,b,15);
 } 
}

void solidline(float x1, float y1, float x2, float y2)
{
 int steps, dx=(x2-x1), dy=(y2-y1);
 
 if(abs(dx)>abs(dy))
   steps=abs(dx);
 else
   steps=abs(dy);
 
 float xinc=(float)dx/steps, yinc=(float)dy/steps;
 float x=x1, y=y1;
 
 putpixel(x,y,15);
 outtextxy(x2+100,y2, "SOLID LINE");
 int a,b;
 
 for(int i=1 ; i<=steps ; i++)
 {
  x = (x + xinc);
  y = (y + yinc);
  
  a=x + 0.5;
  b=y + 0.5;

  putpixel(a,b,15);
  putpixel(a,b-1,15);
  putpixel(a,b+1,15);
 } 
}

void dottedline(float x1, float y1, float x2, float y2)
{
 int steps, dx=(x2-x1), dy=(y2-y1);
 
 if(abs(dx)>abs(dy))
   steps=abs(dx);
 else
   steps=abs(dy);
 
 float xinc=(float)dx/steps, yinc=(float)dy/steps; 
 float x=x1, y=y1;
 
 putpixel(x,y,15);
 outtextxy(x2+100,y2, "DOTTED LINE");
 int a,b;
 
 for(int i=1 ; i<=steps ; i++)
 {
  x = (x + xinc);
  y = (y + yinc);
  
  a=x + 0.5;
  b=y + 0.5;

  if(i%4 == 0)
  {
   putpixel(a,b,15);
  }
 } 
}

void dashedline(float x1, float y1, float x2, float y2)
{
 int steps, dx=(x2-x1), dy=(y2-y1);
 
 if(abs(dx)>abs(dy))
   steps=abs(dx);
 else
   steps=abs(dy);
 
 float xinc=(float)dx/steps, yinc=(float)dy/steps; 
 float x=x1, y=y1;
 
 putpixel(x,y,15);
 outtextxy(x2+100,y2, "DASHED LINE");
 int a,b;
 
 for(int i=1, flag=0 ; i<=steps ; i++)
 {
  x = (x + xinc);
  y = (y + yinc);
  
  a=x + 0.5;
  b=y + 0.5;

  if(flag==0)
  {
   putpixel(a,b,15);
  }
  
  if(i%4 == 0)
  {
   if(flag==1)
     flag=0;
   else
     flag=1;
  }
  
 } 
}

void dashdotline(float x1, float y1, float x2, float y2)
{
 int steps, dx=(x2-x1), dy=(y2-y1);
 
 if(abs(dx)>abs(dy))
   steps=abs(dx);
 else
   steps=abs(dy);
 
 float xinc=(float)dx/steps, yinc=(float)dy/steps; 
 float x=x1, y=y1;
 
 putpixel(x,y,15);
 outtextxy(x2+100,y2, "DASH-DOTTED LINE");
 
 for(int i=1, a,b,flag=0 ; i<=steps ; i++)
 {
  x = (x + xinc);
  y = (y + yinc);
  
  a=x + 0.5;
  b=y + 0.5;
   
  if(flag==0)
  {
   putpixel(a,b,15);
  }
  
  if(i%5 == 0)
  {
   if(flag==1)
     flag=0;
   else
     flag=1;
  }
  
  if(i%3 == 0)
  {
   putpixel(a,b,15);
  } 
 } 
}

void thickline(float x1, float y1, float x2, float y2, float w)
{
 int steps, dx=(x2-x1), dy=(y2-y1);
 
 float l = sqrt( pow( dx, 2) + pow( dy, 2) );
 int wy = (int)( (w-1)*l )/( 2*abs(dx) );
 
 if(abs(dx)>abs(dy))
   steps=abs(dx);
 else
   steps=abs(dy);
 
 float xinc=(float)dx/steps, yinc=(float)dy/steps; 
 float x=x1, y=y1;
 
 putpixel(x,y,15);
 outtextxy(x2+100,y2, "THICK LINE");
 int a,b;
 
 for(int i=1 ; i<=steps ; i++)
 {
  x = (x + xinc);
  y = (y + yinc);
  
  a=x + 0.5;
  b=y + 0.5;
  
  putpixel(a,b,15); //normal line
  
  for(int j=0; j<=wy ; j++)
  { 
   putpixel(a,b+j,15);
   putpixel(a,b-j,15);
  }
 } 
}

int main()
{
 int x1,y1,x2,y2;
 float w;
 
 cout<<"\n Enter the coordinates (x1,y1,x2,y2) and line thickness(only for thick line of width w) : ";
 cin>>x1>>y1>>x2>>y2>>w;
 
 int gd=DETECT, gm;
 initgraph(&gd, &gm, NULL);

 dda(x1,y1,x2,y2);
 solidline(x1,y1+30,x2,y2+30);
 dottedline(x1,y1+60,x2,y2+60);
 dashedline(x1,y1+90,x2,y2+90);
 dashdotline(x1,y1+120,x2,y2+120);
 thickline(x1,y1+150,x2,y2+150, w);
 
 getch();
 closegraph();

 return(0);
}

