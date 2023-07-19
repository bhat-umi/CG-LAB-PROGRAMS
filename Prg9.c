//Develop a menu driven program to fill the polygon using scan line algorithm
#include<GL/glut.h>
int x1=200,y1=200,
        x2=100, y2=300,
        x3=200,y3=400,
        x4=300,y4=300;
int le[500],re[500];
int fill_color=0;
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
void edgedetect(float x1,float y1,float x2,float y2)
{
    float temp;
    if(y2-y1<0)
    {
        temp=x1;
        x1=x2;
        x2=temp;
        temp=y1;
        y1=y2;
        y2=temp;
    }
    float mx;
    if((y2-y1)!=0)
        mx=(x2-x1)/(y2-y1);
    else
        mx=(x2-x1);
    float x=x1;
    int i;
    for(i=y1;i<y2;i++)
    {
        if(x<le[i])
            le[i]=x;
        if(x>re[i])
            re[i]=x;
        x+=mx;
    }

}
void scanfill()
{
    
    int i=0;
    for(i=0;i<500;i++)
    {
        le[i]=500;
        re[i]=0;
    }
    edgedetect(x1,y1,x2,y2);
    edgedetect(x2,y2,x3,y3);
    edgedetect(x3,y3,x4,y4);
    edgedetect(x4,y4,x1,y1);
    int y,x;
    for(y=0;y<500;y++)
    {
        for(x=le[y];x<re[y];x++)
        {
            drawpixel(x,y);
            
        }
        
    }
}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_LINE_LOOP);
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);
        glVertex2i(x3,y3);
        glVertex2i(x4,y4);
         glEnd();
        if(fill_color)
            scanfill();
       

    glFlush();


}
void choice(int ch)
{
    fill_color=ch;
    if(ch==1){
    glColor3f(1,0,0);
    
    }
    if(ch==2){
    glColor3f(0,1,0);
    
    }
    glutPostRedisplay();
}
int main(int argc,char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB| GLUT_SINGLE);
	glutInitWindowSize(500,600);
	glutCreateWindow("scan fill");
	glutDisplayFunc(display);
    glutCreateMenu(choice);
    glutAddMenuEntry("red",1);
    glutAddMenuEntry("green",2);
    glutAddMenuEntry("No color",0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);


	init();

	glutMainLoop();
	
}