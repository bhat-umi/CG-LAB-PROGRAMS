//Create and rotate a triangle about the origin and a fixed point
#include<GL/glut.h>
void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}
void drawTraingle()
{
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(80,0);
    glVertex2i(40,80);
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1,0,0);
    drawTraingle();
    glFlush();
    glColor3f(1,1,0);
    printf("Enter choice");
    int ch;
    scanf("%d",&ch);
    float angle ;
    switch(ch)
    {
        case 1:
            printf("Eneter angle in degree");
            
            scanf("%f",&angle);
            glRotatef(angle,0,0,1);
            drawTraingle();
            break;
        case 2:
            printf("Eneter angle in degree");
            
            scanf("%f",&angle);
            printf("Eneter x,y");
            int x,y;
            scanf("%d%d",&x,&y);
            glTranslatef(x,y,0);
            glRotatef(angle,0,0,1);
            drawTraingle();
            break;

    }

    glFlush();
}

int main(int argc,char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB| GLUT_SINGLE);
	glutInitWindowSize(500,600);
	glutCreateWindow("Rotation of traingle");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	
}