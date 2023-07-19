// Design, develop and implement recursively subdivide a tetrahedron to form 3D
// sierpinski gasket. The number of recursive steps is to be specified by the user

#include<GL/glut.h>
typedef float point[3];

point V[]={
		0,0,1,
		0,1,-1,
		-1,-1,-1,
		1,-1,1
		};
void traingle(point a, point b,	 point c)
{
	glBegin(GL_POLYGON);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
	
	
}
void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2,2,-2,2,-10,10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutPostRedisplay();
	
	
}
void init()
{
	glClearColor(0,0,0,1);
	
}
void divi(point a,point b,point c,int n)
{
	if(n==0)
	{
		traingle(a,b,c);
		return;
	}
	point v1,v2,v3;
	int i=0;
	for(;i<3;i++)
	{
		v1[i]=(a[i]+b[i])/2;
		v2[i]=(b[i]+c[i])/2;
		v3[i]=(a[i]+c[i])/2;
	}
	divi(a,v1,v3,n-1);
	divi(b,v1,v2,n-1);
	divi(c,v2,v3,n-1);
	
}
		

void terrahedron()
{
	glColor3f(1,0,0);
	divi(V[0],V[1],V[2],2);
	
	glColor3f(0,1,0);
	divi(V[3],V[2],V[1],2);
	glColor3f(0,0,1);
	divi(V[0],V[3],V[1],2);
	glColor3f(1,0,1);
	divi(V[0],V[2],V[3],2);	
}
void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
terrahedron();
	glFlush();
}
int main(int argc,char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB| GLUT_DEPTH|GLUT_SINGLE);
	glutInitWindowSize(500,600);
	glutCreateWindow("Tetra hedron ");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	init();
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	
}
