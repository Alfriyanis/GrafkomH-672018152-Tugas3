#include <iostream>
#include <GL/freeglut.h>

void Display() {
	float A1x = 50, A1y = 50, B1x = 150, B1y = 200, A2x = 50, A2y = 200, B2x = 150, B2y = 50,
	A3x = 100, A3y = 50, B3x = 200, B3y = 200, A4x = 100, A4y = 200, B4x = 200, B4y = 50,
	MA1B1, MA2B2, MA3B3, MA4B4, cA1B1, cA2B2, cA3B3, cA4B4, px1, px, py1, py, pz1, pz, pi1, pi;
	
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);//kuning
	glColor3f(1.0, 1.0, 0.0);
		glVertex2f(A1x, A1y);
		glVertex2f(B1x, B1y);
	glEnd();

	glBegin(GL_LINES);//biru
	glColor3f(0.0, 0.0, 1.0);
		glVertex2f(A2x, A2y);
		glVertex2f(B2x, B2y);
	glEnd();

	glBegin(GL_LINES);// hijau
	glColor3f(0.0, 1.0, 0.0);
		glVertex2f(A3x, A3y);
		glVertex2f(B3x, B3y);
	glEnd();

	glBegin(GL_LINES);// hitam
	glColor3f(0.0, 0.0, 0.0);
		glVertex2f(A4x, A4y);
		glVertex2f(B4x, B4y);
	glEnd();


	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(A2x, A2y, 0);
		glVertex3f(B3x, B3y, 0);
		glVertex3f(B4x, B4y, 0);
		glVertex3f(A1x, A1y, 0);
		glVertex3f(A2x, A2y, 0);
	glEnd();

	//perpotongan
	MA1B1 = (B1y - A1y) / (B1x - A1x);
	MA2B2 = (B2y - A2y) / (B2x - A2x);
	MA3B3 = (B3y - A3y) / (B3x - A3x);
	MA4B4 = (B4y - A4y) / (B4x - A4x);
	cA1B1 = A1y - (A1x * MA1B1);
	cA2B2 = A2y - (A2x * MA2B2);
	cA3B3 = A3y - (A3x * MA3B3);
	cA4B4 = A4y - (A4x * MA4B4);

	//titik-potong
	px1 = (cA2B2 - cA1B1) / (MA1B1 - MA2B2);
	px  = (MA1B1 * px1) + cA1B1;
	py1 = (cA3B3 - cA2B2) / (MA2B2 - MA3B3);
	py	= (MA2B2 * py1) + cA2B2;
	pz1 = (cA4B4 - cA3B3) / (MA3B3 - MA4B4);
	pz	= (MA3B3 * pz1) + cA3B3;
	pi1 = (cA1B1 - cA4B4) / (MA4B4 - MA1B1);
	pi	= (MA4B4 * pi1) + cA4B4;

	//hasil
	glBegin(GL_POINTS);
	glPointSize(2);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(px1, px);
	glEnd();

	glBegin(GL_POINTS);
	glPointSize(2);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(py1, py);
	glEnd();

	glBegin(GL_POINTS);
	glPointSize(2);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(pz1, pz);
	glEnd();

	glBegin(GL_POINTS);
	glPointSize(2);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(pi1, pi);
	glEnd();

	glFlush();
}

void myinit(void) {

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(10.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glLineWidth(4.0f);
	gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 50);
	glutCreateWindow("TITIK PERPOTONGAN");

	glutDisplayFunc(Display);

	myinit();

	glutMainLoop();

}