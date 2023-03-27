#include<GL/glut.h>
#include <stdio.h>
int x,y;
int where_to_rotate = 0;
float t_x = 0, t_y = 0;
float rotate_angle = 0;

void draw_pixel(float x1, float x2){
	glPointSize(6.0);
	glBegin(GL_POINTS);
	glvertex2f(x1,y1);
	glEnd();
}

void tiangle(int x, int y){
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glvertex2f(x,y);
	glvertex2f(x+300, y+400);
	glvertex2f(x+300,y);
	glEnd();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0,1,0);

	draw_pixel(0,0);
	if(where_to_rotate==1){
		t_x = 0;
		t_y = 0;
		rotate_angle +=1;
	}

	if(where_to_rotate == 2){
		t_x = x;
		t_y = y;
		rotate_angle +=1;
		glColor3f(0,0,1);
		draw_pixel(x,y);
	}
	glTranslatef(t_x, t_y, 0);
	glRotatef(rotate_angle,0,0,1);
	glTranslatef(-t_x, -t_y, 0);

	triangle(t_x, t_y);

	glutPostRedisplay();
	glutSwapBuffers();
}

void rotateMenu(int option){
	if(option==1)
		where_to_rotate = 1;
	if(option==2)
		where_to_rotate = 2;
	if(option = 3)
		where_to_rotate = 3;
}

void init()
{
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-800,800,-800,800);
	glMatrixMode(GL_MODELVIEW);	
}

int main(int argc, char** argv){

	printf("enter the point\n");
	scanf("%d%d",&x,&y);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Rotate triangle");
	inti();
	glutDisplayFunc(display);
	glutCreateMenu(rotateMenu);
	glutAddMenuEntry("Rotate Around Origin",1);
	glutAddMenuEntry("Rotate Fixed Point",2);
	glutAddMenuEntry("Rotate Stop",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
}
