//PROGRAM: To draw inscribed and circumscribed circles in a triangle using dda line algorithm and bresenham circle algo.
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void display(int x, int y, int xc, int yc)
{
 putpixel(xc+x,yc+y,WHITE);
 putpixel(xc+x,yc-y,WHITE);
 putpixel(xc-x,yc+y,WHITE);
 putpixel(xc-x,yc-y,WHITE);
 putpixel(xc+y,yc+x,WHITE);
 putpixel(xc+y,yc-x,WHITE);
 putpixel(xc-y,yc+x,WHITE);
 putpixel(xc-y,yc-x,WHITE);
}

void bresencircle(int xc, int yc, int r)
{
 int x=0,y=r;
 float dp=3-(2*r);

 putpixel(x,y,WHITE);

 while(x<=y)
 {
  if(dp<=0)
   {
    dp=dp+(4*x)+6;
    x++;
   }
  else
   {
    dp=dp+(4*(x-y))+10;
    x++;
    y--;
   }
 
  display(x,y, xc, yc);
 };
}

void dda(float x1, float y1, float x2, float y2)  //DDA Algo
{
 float xnew, ynew;
 int steps, dx=(x2-x1), dy=(y2-y1);

 if(abs(dx)>abs(dy))
   steps=abs(dx);
 else
   steps=abs(dy);
 
 float xinc=(float)dx/steps, yinc=(float)dy/steps;
 float x=x1, y=y1;
 
 putpixel(x,y,WHITE); //putpixel(x,y,color) // Also we can write as putpixel(x1,y1, WHITE)
    
 int a,b;
   
 for(int i=1 ; i<=steps ; i++)
 {
  x = (x + xinc);
  y = (y + yinc);
  
    
  //FOR CONVERTING THE FLOATING VALUE TO ITS NEAREST INTEGER VALUE i.e. same as use of floor or ceil f(x)
  a=x + 0.5;
  b=y + 0.5;
 
  putpixel(a,b,WHITE);
 } 
}

int main()
{
 int xc,yc,r;
 
 cout<<"\n Enter the coordinates of centre and radius of outer circle (xc,yc,r): "<<endl;
 cin>>xc>>yc>>r;         
 
 int gd=DETECT,gm;
 initgraph(&gd,&gm, NULL);
 
 dda( xc , (yc-r) , (xc-(r*0.866)) , (yc+(r/2)) );    //cos(30) = 0.866
 dda( xc , (yc-r) , (xc+(r*0.866)) , (yc+(r/2)) );    //don't use cos(30) directly as it's giving inaccurate results
 dda( (xc-(r*0.866)) , (yc+(r/2)) , (xc+(r*0.866)) , (yc+(r/2)) );
 
 bresencircle(xc,yc,r/2);
 bresencircle(xc,yc,r); 
  
 getch();
 closegraph();
 
 return(0);
}

