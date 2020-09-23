//Program: Demo program using circle, line, arc function
#include<iostream>
#include<graphics>

using namespace std;

int main()
{
  int gd=DETECT, gm;
  initgraph(&gd, &gm, NULL);

  cleardevice();
  rectangle(100,100,150,150);       //rectangle(x1, y1, x2, y2) where (x1,y1) are starting corner points
                                                      //and (x2, y2) are ending corner points.
  outtextxy(10,10, char *MADE BY GAURAV GARJE);
  ellipse(150, 150, 0, 360, 100, 40);  //ellipse(x, y, start angle, end angle, x radius, y radius)
  bar(200,200,250,250);               //same as rectangle but with white color fill inside
  delay(5000);
  cleardevice();
  circle(250, 150, 140);          //circle(x, y, radius)
  circle(200, 100, 40);
  circle(300, 100, 40);
  line(250, 120, 250, 185);            //line(x1, y1, x2, y2)
  arc(250, 170, 30, 150, 70);           //arc(x, y, starting angle in degree, ending angle in degree, radius)
                                                        //angle always measured from right x axis in clockwise direction
  getch();
  closegraph();
  return(0);
}
