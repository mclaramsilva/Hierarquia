#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

GLfloat tx = 0;
GLfloat ang1 = 0, ang2 = -90;
GLfloat win = 50;

void Desenha(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f,0.0f,0.0f);
	glLineWidth(4);
	glBegin(GL_LINE_LOOP);
		glVertex2f(-win,-3.9);
		glVertex2f(win,-3.9);
	glEnd();
	glPushMatrix();                           
	glTranslatef(tx,0.0f,0.0f);
    
	glPushMatrix();
	glScalef(2.5f,2.5f,1.0f);
	glColor3f(0.6f,0.2f,0.8f);
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
		glVertex2f(1.8,1);
		glVertex2f(1.8,-1.5);
		glVertex2f(-1.8,-1.5);
		glVertex2f(-1.8,1);
	glEnd();
    
	glPopMatrix();
	glTranslatef(0.0f,2.0f,0.0f);
	glRotatef(ang1,0.0f,0.0f,1.0f);    
	glScalef(1.4f,1.4f,1.0f);
	glColor3f(1.0f,0.41f,0.71f);
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
		glVertex2f(0.5,4.6);
		glVertex2f(1.0,-0.8);
		glVertex2f(-1.0,-0.8);
		glVertex2f(-0.5,4.6);
	glEnd();
	glPointSize(2);
	glBegin(GL_POINTS);
	glVertex2i(0,0);              
	glEnd();
                                    
	glTranslatef(0.4f,2.6f,0.0f);
	glRotatef(ang2,0.0f,0.0f,1.0f);
	glColor3f(0.5f,1.0f,0.0f); 
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
		glVertex2f(0.0,4.0);
		glVertex2f(1.0,-0.0);
		glVertex2f(-1.0,-0.0);
		glVertex2f(-0.0,4.0);
	glEnd();
	glPointSize(2);
	glBegin(GL_POINTS);
		glVertex2i(0,0);              
	glEnd();
                    
	glPopMatrix();    
	glFlush();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	GLsizei largura, altura;
	if(h == 0) h = 1;

	largura = w;
	altura = h;
	glViewport(0, 0, largura, altura);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (largura <= altura) 
	{ 
		gluOrtho2D (-25.0f, 25.0f, -25.0f*altura/largura, 25.0f*altura/largura);
		win = 25.0f;
	}              
	else 
	{ 
		gluOrtho2D (-25.0f*largura/altura, 25.0f*largura/altura, -25.0f, 25.0f);
		win = 25.0f*largura/altura;           
	}             
}

void TeclasEspeciais(int key, int x, int y)
{
	if(key == GLUT_KEY_LEFT)
	{
		tx-=2;
		if ( tx < -win )
			tx = -win; 
	}
	if(key == GLUT_KEY_RIGHT)
	{
		tx+=2;
		if ( tx > win )
			tx = win; 
	}     
	if(key == GLUT_KEY_UP)
		ang1-=5;
	if(key == GLUT_KEY_DOWN)
		ang1+=5;
	if(key == GLUT_KEY_F1)
		ang2-=5;
	if(key == GLUT_KEY_F2)
		ang2+=5;              
                                                
	glutPostRedisplay();
}

void Teclado (unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}
void Inicializa (void)
{   
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
	glutInitWindowPosition(5,5);     
	glutInitWindowSize(500,500);  
	glutCreateWindow("HIERARQUIA - atividade 2 computação gráfica"); 
	glutDisplayFunc(Desenha);  
	glutReshapeFunc(AlteraTamanhoJanela);    
	glutSpecialFunc(TeclasEspeciais);
	glutKeyboardFunc (Teclado);

	Inicializa(); 
	glutMainLoop();

	return 0;
}