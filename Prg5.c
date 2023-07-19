//Clip a lines using Cohen-Sutherland algorithm

#include<GL/glut.h>
#include<stdbool.h>
#include<stdio.h>
int xmin=50, ymin=50,
    xmax=100,ymax=100;
 int x1=30,y1=20,
        x2=120,y2=150;
int LEFT=2,TOP=4,BOTTOM=1,RIGHT=8;
int opcode(double x,double y)
{
    int code=0;
    if(x>xmax)
        code|=RIGHT;
    else if(x<xmin)
         code|=LEFT;
    if(y>ymax)
        code|=TOP;
    else if(y<ymin)
         code|=BOTTOM;
    return code;
}
void drawRec(int xmin,int ymin,int xmax,int ymax)
{
     glBegin(GL_LINE_LOOP);
        glVertex2i(xmin,ymin);
        glVertex2i(xmin,ymax);
        glVertex2i(xmax,ymax);
        glVertex2i(xmax,ymin);
    glEnd();
}
void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}
void drawLine(double x1,double y1,double x2,double y2)
{
    glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glEnd();    
    
}
void clip(int x1,int y1,int x2,int y2)
{
    int op1=opcode(x1,y1);
    int op2=opcode(x2,y2);
    bool done=false;
    bool accept=false;
    do{
        if((op1|op2)==0)
        {
            accept=true;
            done=true;
        }
        else if(op1&op2)
        {
            accept=false;
            done=true;


        }
        else
        {
            
            int op=op1?op1:op2;
            double x,y;
                if(op&TOP)
                {

                     x=x1+(ymax-y1)*(x2-x1)/(y2-y1);
                     y=ymax;
                }
                else if(op&BOTTOM)

                {
                     x=x1+(ymin-y1)*(x2-x1)/(y2-y1);
                     y=ymin;
                }
                
                else if(op&LEFT)

                {
                     x=xmin;
                     y=y1+(y2-y1)/(x2-x1)*(xmin-x1);
                }
                else if(op&RIGHT)

                {
                     x=xmax;
                     y=y1+(y2-y1)/(x2-x1)*(xmax-x1);
                }
                if(op==op1)
                {   
                    x1=x;
                    y1=y;
                    op1=opcode(x,y);


                }
                else
                {
                    x2=x;
                    y2=y;
                    op2=opcode(x,y);


                }





        }

        }while(!done);
         int xwmin=200,
        ywmin=200,
        xwmax=300,
        ywmax=300;
        if(accept)
        {

            double sx=(xwmax-xwmin)/(xmax-xmin);
            double sy=(ywmax-ywmin)/(ymax-ymin);
             
    double  vx1=xwmin + sx*(x1-xmin);
    double  vy1=ywmin + sy*(y1-ymin);
    double  vx2=xwmin + sx*(x2-xmin);
    double  vy2=ywmin + sy*(y2-ymin);
        drawRec(xwmin,ywmin,xwmax,ywmax);
        drawLine(vx1,vy1,vx2,vy2);

        }


}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    drawRec(xmin,ymin,xmax,ymax);
    drawLine(x1,y1,x2,y2);   
    clip(x1,y1,x2,y2);
    glFlush();
}

int main(int argc,char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB| GLUT_SINGLE);
	glutInitWindowSize(500,600);
	glutCreateWindow("LINE Cliipping");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	
}