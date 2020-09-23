//PROGRAM: To draw rectangle in a rectangle in a rectangle pattern using dda line algorithm
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

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
 float x1,y1,x2,y2;
 
 cout<<"\n Enter the coordinates of outer rectangle (x1,y1,x2,y2): "<<endl;
 cin>>x1>>y1>>x2>>y2;         
 
 float x=(x1+x2)/2;
 float y=(y1+y2)/2;
 float X1=(x1+x)/2;
 float X2=(x2+x)/2;
 float Y1=(y1+y)/2;
 float Y2=(y2+y)/2;
 
 int gd=DETECT,gm;
 initgraph(&gd,&gm, NULL);
 
 dda(x1,y1,x2,y1); 
 dda(x2,y1,x2,y2); 
 dda(x2,y2,x1,y2); 
 dda(x1,y2,x1,y1); 
 
 dda(x,y1,x2,y); 
 dda(x2,y,x,y2); 
 dda(x,y2,x1,y); 
 dda(x1,y,x,y1); 
 
 dda(X1,Y1,X2,Y1); 
 dda(X2,Y1,X2,Y2); 
 dda(X2,Y2,X1,Y2); 
 dda(X1,Y2,X1,Y1); 
 
 getch();
 closegraph();
 
 return(0);
}
