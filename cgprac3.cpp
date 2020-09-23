//Program: Bresenham's Line Drawing Algorithm
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

int sign(int arg)
{
 if(arg<0)
  return -1;
 if(arg==0)
  return 0;
 if(arg>0) 
  return 1;
}
	
void bresen(int x1, int y1, int x2, int y2)
{
 int x,y,xx=(x2-x1), yy=(y2-y1);
 int dx = abs(xx), dy = abs(yy);
 cout<<"\n\tdx: "<<dx<<"\tdy: "<<dy; 
 
 //interchange x & y depending on the slope of the line
 if(dy>dx)
 {
  cout<<"\n\t roles of y and x interchanged!";
  int temp = x, temp1=dx;
  x=y;
  dx=dy;
  y=temp;
  dy=temp1;    //steep slope
 }
 else// else gentle slope
  cout<<"\n\t|dx|>=|dy| HENCE gentle slope: ";
 
 int s1,s2,exchange;
 s1= sign(xx);
 s2= sign(yy);
 cout<<"\n\ts1: "<<s1<<"\ts2: "<<s2;
 
 int g = ((2*dy)-dx);
 cout<<"\n\tg: "<<g;
 
 x=x1; y=y1;
 int i=1;
 
 putpixel(x1,y1, WHITE);
 
 while(i<=dx)
 {
  if(g>=0)
  {   
   x = x + s1; cout<<"\n\t g>=0 x = x + s1="<<x;
   y = y + s2; cout<<"\n\t g>=0 y = y + s2="<<y;
   g = (g+2*dy-2*dx);  cout<<"\n\tg>=0 gnew: "<<g;
  }
  else
  {
   x = x + s1;  cout<<"\n\t g<0 x = x + s1="<<x;
   cout<<"\n\t g<0 y = y + s2="<<y;
   g = (g+2*dy);  cout<<"\n\tg<0 gnew: "<<g<<endl;
  }
  putpixel(x,y, WHITE);
  i++;
 };
}

int main()
{
 int x1,x2,y1,y2;
 
 cout<<"\n Enter the coordinates (x1,y1,x2,y2): "<<endl;
 cin>>x1>>y1>>x2>>y2;
 
 int gd=DETECT, gm;
 initgraph(&gd,&gm, NULL);
 
 bresen(x1,y1,x2,y2);
 
 getch();
 closegraph(); 
 return(0);
}
