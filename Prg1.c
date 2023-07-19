//Implement Brenham‟s line drawing algorithm for all types of slope
#include<GL/glut.h>
#include<stdio.h>
void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}
void drawpixel(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}
void breshmans(int x1,int y1,int x2,int y2)
{

    glColor3f(1,0,0);
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
    glEnd();
    glPointSize(2);
    glColor3f(1,1,1);
 





    int dx=x2-x1;
    int dy=y2-y1;
    float m= 1.0*dy/dx;
    if(m<1)
    {
        
        printf("hi");
        int x=x1,y=y1;
        if(dx<0)
        {
            
            x=x2;
            y=y2;
            x2=x1;

        }
        drawpixel(x,y);
        int p=2*dy-dx;
        while(x<x2)
        {
            x++;
            if(p<0)
            {
                p+=2*dy;

            }
            else
            {
                p+=2*dy -2*dx;
                y=y+1;

            }
            drawpixel(x,y);
        }
    }

    else if(m>1)
    {
        printf("hello");
        int x=x1,y=y1;
        if(dy<0)
        {
            
            y=y2;
            x=x2;
            y2=y1;
        }
        drawpixel(x,y);
        int p=2*dx-dy;
        while(y<y2)
        {
            y++;
            if(p<0)
            {
                p+=2*dx;

            }
            else
            {
                p+=2*dx -2*dy;
                x=x+1;

            }
            drawpixel(x,y);
        }
    
    }
    else
        {
            int x=x1,y=y1;
            drawpixel (x, y);
while (x < x2)
{
        x = x+1;
        y = y+1;
        drawpixel (x, y);
       }




}
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //x1,y1 x2,y2
    breshmans(10,10,460,450);
    glFlush();
}
int main(int argc,char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB| GLUT_SINGLE);
	glutInitWindowSize(500,600);
	glutCreateWindow("LINE DRAWING");
	glutDisplayFunc(display);
	init();
	
	glutMainLoop();
	
}