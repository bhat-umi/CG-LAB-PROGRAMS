//Develop a menu driven program to animate a flag using Bezier Curve algorithm

///to run
//cc beizer.c -lGL -lGLU -lglut -lm 

#include<GL/glut.h>
#include<math.h>
void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

}
float ya=30;
int d=1;
int ANIMATE=0;
void animate()
{
    if(!ANIMATE)
        return;
    if(d==0)
    {
        if(ya<30)
        ya+=0.05;
        else
        d=1;
    }
    if(d==1)
    {
        if(ya>-30)
            ya-=0.05;
        else
        d=0;
    }
    
    glutPostRedisplay();
}
void display()
{
    
    glClear(GL_COLOR_BUFFER_BIT);
     glLoadIdentity();
    GLfloat x[4]={100,200,200,300-ya};
    GLfloat y[4]={450,450+ya,450-ya,450};
    GLfloat xt[200];
    GLfloat yt[200];
    float t=0;
    int i=0;
    
    for(t=0;t<=1;t+=0.005)
    {
        xt[i]=(pow((1-t),3)*x[0]) + (3*t*pow((1-t),2)*x[1]) +  (3*t*t*(1-t)*x[2]) + (t*t*t*x[3]);
        yt[i]=(pow((1-t),3)*y[0]) + (3*t*pow((1-t),2)*y[1]) +  (3*t*t*(1-t)*y[2]) + (t*t*t*y[3]);
        i++;
    }
    
    glBegin(GL_POLYGON);
    int j=0;
    glColor3f(1,0,0);
    for(j=1;j<i;j++)
        glVertex2f(xt[j],yt[j]);
    for(j=i-1;j>=1;j--)
        glVertex2f(xt[j],yt[j]-50);
    glEnd();
    

    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    for(j=1;j<i;j++)
        glVertex2f(xt[j],yt[j]-50);
    for(j=i-1;j>=1;j--)
        glVertex2f(xt[j],yt[j]-100);
    glEnd();
    
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    for(j=1;j<i;j++)
        glVertex2f(xt[j],yt[j]-100);
    for(j=i-1;j>=1;j--)
        glVertex2f(xt[j],yt[j]-150);
    glEnd();
    




    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex2i(100,450);
    glVertex2i(100,100);
    glEnd();
    glFlush();

}

void menu(int ch)
{
    if(ch==2)
        exit(0);
    ANIMATE=ch;
    
}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutCreateWindow("Flag");
    init();
    glutCreateMenu(menu);
    glutAddMenuEntry("Strat",1);
    glutAddMenuEntry("Stop",0);
    glutAddMenuEntry("Exit",2);
    glutAttachMenu(GLUT_LEFT_BUTTON);

    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();



}