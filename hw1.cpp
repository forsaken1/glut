#include <GL/freeglut.h>

void init()
{
	glClearColor(0, 0, 0, 0);
	gluOrtho2D(-5, 5, -5, 5);
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);//Change the object color to red

	glBegin(GL_TRIANGLES);//Start drawing a triangle
	glVertex2f(3,-4);//draw our first coordinate
	glVertex2f(3.5,-3);//Our second coordinate
	glVertex2f(4,-4);//Our last coordinate
	glEnd();//Stop drawing triangles

	glColor3f(0,1,0);//Change the object colors to green

	glBegin(GL_QUADS);//Start drawing quads
	glVertex2f(-4,-4);//first coordinate
	glVertex2f(-4,-2);//second coordinate

	glColor3f(0,0,1);//Change the color to blue halfway through to create a neat color effect

	glVertex2f(-2,-2);//third coordinate (now blue)
	glVertex2f(-2,-4);//last coordinate
	glEnd();//Stop drawing quads

	glColor3f(1,0,0);//Change color to red
	glBegin(GL_POLYGON);//Start drawing a polygon
	glVertex2f(-2,2);//first vertex
	glColor3f(0,1,0);//Change color to green
	glVertex2f(-1,3);//second vertex
	glColor3f(0,0,1);//Change color to blue
	glVertex2f(0,2);//third vertex
	glColor3f(1,0,1);//Change color to purple
	glVertex2f(-0.5,0);//fourth vertex
	glColor3f(1,1,0);//Change color to yellow
	glVertex2f(-1.5,0);//last vertex
	glEnd();//Stop drawing our polygon
	
	glFlush();
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Homework #1");

	init();
	glutDisplayFunc(draw);
	glutMainLoop();

	return 0;
}