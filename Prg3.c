//Draw a color cube and spin it using OpenGL transformation matrices
#include<GL/glut.h>
GLfloat vertices[][3]={

                    -1,-1,-1,//0
                    1,-1,-1,//1
                    1,1,-1,//2
                    -1,1,-1,//3
                    -1,-1,1,//4
                    1,-1,1,//5
                    1,1,1,//6
                    -1,1,1//7


};
GLfloat color[][3]={
                1,0,0,
                0,1,0,
                0,0,1,
                1,1,0,
                0,1,1,
                1,0,1
};
int theta []={0,0,0};
int axis=0;
void spin()
{
        theta[axis]=(theta[axis]+1)%360;
        glutPostRedisplay();

}
void polygon(int a ,int b ,int c ,int d)
{
    
    glBegin(GL_POLYGON);
    glColor3fv(color[a]);
    glVertex3fv(vertices[a]);

    glColor3fv(color[b]);
    glVertex3fv(vertices[b]);

    glColor3fv(color[c]);
    glVertex3fv(vertices[c]);

    glColor3fv(color[d]);
    glVertex3fv(vertices[d]);
    glEnd();

}
void colorCube()
{
    polygon(0,3,2,1);
    polygon(0,4,7,3);
    polygon(5,4,0,1);

    polygon(6,2,3,7);
    polygon(6,2,1,5);
    polygon(6,7,4,5);

    

}
void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2,2,-2,2,-10,10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(theta[0],1,0,0);
    glRotatef(theta[1],0,1,0);
    glRotatef(theta[2],0,0,1);
    colorCube();

    glutSwapBuffers();
}
void mouse(int key,int,int, int)
{
    if(key==GLUT_RIGHT_BUTTON)
        axis=0;
    else if(key==GLUT_LEFT_BUTTON)
        axis=1;
    else if(key==GLUT_MIDDLE_BUTTON)
        axis=2;

}
int main(int argc,char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB| GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(500,600);
	glutCreateWindow("LINE DRAWING");
	glutDisplayFunc(display);
    glutIdleFunc(spin);
    glutMouseFunc(mouse);
	init();
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	
}