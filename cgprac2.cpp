//Program: DDA Algorithm
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void dda(float x1, float y1, float x2, float y2)
{
 int steps, dx=(x2-x1), dy=(y2-y1);
 cout<<"\n  dx: "<<dx<<"  dy: "<<dy;
 
 if(abs(dx)>abs(dy))
   steps=abs(dx);
 else
   steps=abs(dy);
 
 float xinc=(float)dx/steps, yinc=(float)dy/steps;
 cout<<"\n  xinc: "<<xinc<<"  yinc: "<<yinc<<"  steps: "<<steps;
 
 float x=x1, y=y1;
 
 putpixel(x,y,15); //putpixel(x,y,color) // Also we can write as putpixel(x1,y1, WHITE)
 cout<<"\n step 1"<<"  x1: "<<x1<<"  y1: "<<y1<<endl;
 
 int a,b;
 
 for(int i=1 ; i<=steps ; i++)
 {
  x = (x + xinc);
  y = (y + yinc);
  
  
  //FOR CONVERTING THE FLOATING VALUE TO ITS NEAREST INTEGER VALUE i.e. same as use of floor or ceil f(x)
  a=x + 0.5;
  b=y + 0.5;

  /*
  //FOR ROUNDING OFF
  if((xnew-(int)xnew)>=0.5)
    a=ceil(xnew);
  else
    a=floor(xnew);
  
  if((ynew-(int)ynew)>=0.5)
    b=ceil(ynew);
  else
    b=floor(ynew);
  //END FOR ROUNDING OFF
  */
  
  cout<<" step "<<i+1<<"\t x="<<x<<" y="<<y<<" a="<<a<<" b="<<b;
  putpixel(a,b,15);
  
  cout<<"\t\t xnew="<<x<<" ynew="<<y<<"\n";
 } 
}

int main()
{
 int x1,y1,x2,y2;
 
 cout<<"\n Enter the coordinates (x1,y1,x2,y2): ";
 cin>>x1>>y1>>x2>>y2;
 
 int gd=DETECT, gm;
 initgraph(&gd, &gm, NULL);

 dda(x1,y1,x2,y1);
 
 /*
 //SQUARE
 dda(30,30,230,30);
 dda(230,30,230,230);
 dda(230,230,30,230);
 dda(30,230,30,30);
 */
 
 getch();
 closegraph();

 return(0);
}
