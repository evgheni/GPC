
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "glut.h"

// dimensiunea ferestrei in pixeli
#define dim 300

unsigned char prevKey;

// concoida lui Nicomede (concoida dreptei)
// $x = a + b \cdot cos(t), y = a \cdot tg(t) + b \cdot sin(t)$. sau
// $x = a - b \cdot cos(t), y = a \cdot tg(t) - b \cdot sin(t)$. unde
// $t \in (-\pi / 2, \pi / 2)$
void Display1() {
   double xmax, ymax, xmin, ymin;
   double a = 1, b = 2;
   double pi = 4 * atan(1.0);
   double ratia = 0.05;
   double t;

   // calculul valorilor maxime/minime ptr. x si y
   // aceste valori vor fi folosite ulterior la scalare
   xmax = a - b - 1;
   xmin = a + b + 1;
   ymax = ymin = 0;
   for (t = - pi/2 + ratia; t < pi / 2; t += ratia) {
      double x1, y1, x2, y2;
      x1 = a + b * cos(t);
      xmax = (xmax < x1) ? x1 : xmax;
      xmin = (xmin > x1) ? x1 : xmin;

      x2 = a - b * cos(t);
      xmax = (xmax < x2) ? x2 : xmax;
      xmin = (xmin > x2) ? x2 : xmin;

      y1 = a * tan(t) + b * sin(t);
      ymax = (ymax < y1) ? y1 : ymax;
      ymin = (ymin > y1) ? y1 : ymin;

      y2 = a * tan(t) - b * sin(t);
      ymax = (ymax < y2) ? y2 : ymax;
      ymin = (ymin > y2) ? y2 : ymin;
   }

   xmax = (fabs(xmax) > fabs(xmin)) ? fabs(xmax) : fabs(xmin);
   ymax = (fabs(ymax) > fabs(ymin)) ? fabs(ymax) : fabs(ymin);

   // afisarea punctelor propriu-zise precedata de scalare
   glColor3f(1,0.1,0.1); // rosu
   glBegin(GL_LINE_STRIP); 
   for (t = - pi/2 + ratia; t < pi / 2; t += ratia) {
      double x1, y1, x2, y2;
      x1 = (a + b * cos(t)) / xmax;
      x2 = (a - b * cos(t)) / xmax;
      y1 = (a * tan(t) + b * sin(t)) / ymax;
      y2 = (a * tan(t) - b * sin(t)) / ymax;

      glVertex2f(x1,y1);
   }
   glEnd();

   glBegin(GL_LINE_STRIP); 
   for (t = - pi/2 + ratia; t < pi / 2; t += ratia) {
      double x1, y1, x2, y2;
      x1 = (a + b * cos(t)) / xmax;
      x2 = (a - b * cos(t)) / xmax;
      y1 = (a * tan(t) + b * sin(t)) / ymax;
      y2 = (a * tan(t) - b * sin(t)) / ymax;

      glVertex2f(x2,y2);
   }
   glEnd();
}

// graficul functiei 
// $f(x) = \bar sin(x) \bar \cdot e^{-sin(x)}, x \in \langle 0, 8 \cdot \pi \rangle$, 
void Display2() {
   double pi = 4 * atan(1.0);
   double xmax = 8 * pi;
   double ymax = exp(1.1);
   double ratia = 0.05;

   // afisarea punctelor propriu-zise precedata de scalare
   glColor3f(1,0.1,0.1); // rosu
   glBegin(GL_LINE_STRIP); 
   for (double x = 0; x < xmax; x += ratia) {
      double x1, y1;
      x1 = x / xmax;
      y1 = (fabs(sin(x)) * exp(-sin(x))) / ymax;

      glVertex2f(x1,y1);
   }
   glEnd();
}

double min(double a,double b){
if (a<b) return a; else return b;

}
//2.1 Afisarea functiei ...
void Display3(){
   glColor3f(1,0.1,0.1); // rosu
   glBegin(GL_LINE_STRIP); 
   double xmax=30;
   double ratia=0.1;
   double x1,y1;
   for (double x = 0; x < xmax; x += ratia) {
	  

		if (x!=0) 
		{	
			x1=x/30;
			
		
			y1=min((x-floor(x)),1.0-(x-floor(x)));
			y1=y1/x;
		}
		else {
		x1=0;
		y1=1;
		}

		glVertex2f(x1,y1);
   }
   glEnd();


}
//2.2.1 Melcul lui Pascal
void Display4(){
	glColor3f(1,0.1,0.1); // rosu
	double x,y,a,b,t;
	a=0.3;
	b=0.2;
	glBegin(GL_LINE_STRIP); 
   for (t=-3.14;t<=3.14;t+=0.01){
   x=2*(a*cos(t)+b)*cos(t);
   y=2*(a*cos(t)+b)*sin(t);
   glVertex2f(x,y);
   }
   glEnd();

}
// 2.2.2 Trisectoarea lui Longchamps
void Display5(){
	glColor3f(1,0.1,0.1); // rosu
	double x,y,a,b,t;
	a=0.2;
	
	glBegin(GL_LINE_STRIP);
	for(t=-1.56;t<1.56;t+=0.01){	
	x=a/(4*cos(t)*cos(t)-3);
	y=(a*(sin(t)/cos(t)))/(4*cos(t)*cos(t)-3);
	glVertex2d(x,y);
		
	}
	glEnd();
}
//2.2.3 Cicloida
void Display6(){
	glColor3f(1,0.1,0.1); // rosu
	double x,y,a,b,t;
	a=0.1;
	b=0.2;
	glBegin(GL_LINE_STRIP);
	for(t=-10;t<=10;t+=0.01){
	x=a*t-b*sin(t);
	y=a-b*cos(t);
		glVertex2d(x,y);
		
	}
	glEnd();
}
//2.2.4 Epicicoida
void Display7(){
	glColor3f(1,0.1,0.1); // rosu
	double x,y,a,b,t,r,R;
	R=0.1;
	r=0.3;
	glBegin(GL_LINE_STRIP);
	for(t=0;t<=6.24;t+=0.01){
	x=(R+r)*cos((r/R)*t)-r*cos(t+(r/R)*t);
	y=(R+r)*sin((r/R)*t)-r*sin(t+(r/R)*t);
		glVertex2d(x,y);
		
	}
	glEnd();
}
//2.2.5 Hipocicloida
void Display8(){
	glColor3f(1,0.1,0.1); // rosu
	double x,y,a,b,t,r,R;
	R=0.1;
	r=0.3;
	glBegin(GL_LINE_STRIP);
	for(t=0;t<=6.24;t+=0.01){
	x=(R-r)*cos((r/R)*t)-r*cos(t-(r/R)*t);
	y=(R-r)*sin((r/R)*t)-r*sin(t-(r/R)*t);
	glVertex2d(x,y);
		
	}
	glEnd();
}

void Init(void) {

   glClearColor(1.0,1.0,1.0,1.0);

   glLineWidth(1);

//   glPointSize(4);

   glPolygonMode(GL_FRONT, GL_LINE);
}

void Display(void) {
   glClear(GL_COLOR_BUFFER_BIT);

   switch(prevKey) {
   case '1':
      Display1();
      break;
   case '2':
      Display2();
      break;
	  case '3':
      Display3();
      break;
	  case '4':
      Display4();
      break;
	  case '5':
      Display5();
      break;
	  case '6':
      Display6();
      break;
	  case '7':
      Display7();
      break;
	  case '8':
      Display8();
      break;
   default:
      break;
   }

   glFlush();
}

void Reshape(int w, int h) {
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}

void KeyboardFunc(unsigned char key, int x, int y) {
   prevKey = key;
   if (key == 27) // escape
      exit(0);
   glutPostRedisplay();
}

void MouseFunc(int button, int state, int x, int y) {
}

int main(int argc, char** argv) {

   glutInit(&argc, argv);
   
   glutInitWindowSize(dim, dim);

   glutInitWindowPosition(100, 100);

   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

   glutCreateWindow (argv[0]);

   Init();

   glutReshapeFunc(Reshape);
   
   glutKeyboardFunc(KeyboardFunc);
   
   glutMouseFunc(MouseFunc);

   glutDisplayFunc(Display);
   
   glutMainLoop();

   return 0;
}
