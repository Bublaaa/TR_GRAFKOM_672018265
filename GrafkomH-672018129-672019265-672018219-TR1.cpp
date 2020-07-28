#include <iostream>
#include <vector>
#include <GL/freeglut.h>
#include <math.h>
#define M_PI 3.14
using namespace std;
class point {
public: point(int xx, int yy) { x = xx; y = yy; }
	  int x, y;
};
class triangle {
public: triangle(point p1, point p2, point p3) {
	tri.push_back(p1);
	tri.push_back(p2);
	tri.push_back(p3);
}
	  vector<point> tri;
	  int get_triangle_size(void);
};
int triangle::get_triangle_size() {
	return tri.size();
}
void init(void);
void display(void);
void ukuran(int, int);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);
void arrow_key(int, int, int);
void moncong(void);
void air_laut(void);
void lambung(void);
void buritan(double, int);
void bangunan(double, int);
void penyangga(void);
void curved_belakang(double, int);
void depan_unik(double, int);
void atas_depan_unik(double, int);
void kolam(void);
void bangunan_batas(double, int);
void bangunan_atas(double, int);
void atas_depan(void);
void atas_samping(void);
void atas_belakang(void);
void atas_p_belakang(void);
void samping(void);
void moncong_atas(double, int);
void moncong_bawah(double, int);
void dermaga(void);
void pulau(void);
void bintang(void);
void jendela(void);
void pelampung(double, int);
void timer(int);
void hujan(void);
void set_triangle(void);
void tween(triangle, triangle);
int is_depth;
float y =90.0;
float ypos = 5.0;
float delta = 5.0;

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1920, 1080);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("TR 1");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(arrow_key);
	glutMouseFunc(mouse);
	glutReshapeFunc(ukuran);
	glutMainLoop();
	return 0;
}
void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	is_depth = 1;
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glPointSize(5.0);
	glLineWidth(6.0f);
	GLfloat mat_specular[] = { 0.3, 0.3, 0.3, 0.3 };
	GLfloat mat_shininess[] = { 0.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glViewport(-80,80,-200,200);
}
void ukuran(int lebar, int tinggi) {
	if (tinggi == 0) tinggi = 1;
	glLoadIdentity();
	gluPerspective(100.0, lebar / tinggi, 80.0, 500.0);
	glTranslatef(0.0, -35.0, -250.0);

}
void display(void) {
	if (is_depth) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_COLOR_MATERIAL);
	}
	else
	{glClear(GL_COLOR_BUFFER_BIT);
	}
	lambung();
	moncong();
	buritan(25.0, 40);
	bangunan(20.0, 40);
	depan_unik(20.0, 40);
	bangunan_batas(20, 40);
	bangunan_atas(15, 40);
	atas_depan_unik(20, 40);
	air_laut();
	dermaga();
	pulau();
	bintang();
	jendela();
	pelampung(5.0,40);
	hujan();
	glPushMatrix();
	glPopMatrix();
	glDisable(GL_COLOR_MATERIAL);
	glutSwapBuffers();
}
void pulau(void)
{
	//kanan & kiri
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.6);
	glVertex3f(-70.0, -14.0, 175.0);
	glVertex3f(-50.0, -18.0, 180.0);
	glVertex3f(-50.0, -25.0, 25.0);
	glVertex3f(-70.0, -14.0, 30.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-79.8, -25.0, 25.0);
	glVertex3f(-79.8, -25.0, 185.0);
	glVertex3f(-79.8, -14.0, 175.0);
	glVertex3f(-79.8, -14.0, 30.0);
	glEnd();

	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-80.0, -14.0, 175.0);
	glVertex3f(-70.0, -14.0, 175.0);
	glVertex3f(-70.0, -14.0, 30.0);
	glVertex3f(-80.0, -14.0, 30.0);
	glEnd();

	//depan
	glBegin(GL_POLYGON);
	glVertex3f(-79.9, -20.0, 180.0);
	glVertex3f(-50.0, -18.0, 180.0);
	glVertex3f(-70.0, -14.0, 175.0);
	glVertex3f(-79.9, -14.0, 175.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-80.0, -25.0, 25.0);
	glVertex3f(-50.0, -25.0, 25.0);
	glVertex3f(-70.0, -14.0, 30.0);
	glVertex3f(-80.0, -14.0, 30.0);
	glEnd();


}
void bintang(void) {
	float ax = 50,
		az = 50,
		bx = 200,
		bz = 350,
		cx = 125,
		cz = 100,
		dx = 25,
		dz = 300,
		ex = 90,
		ez = 250,
		fx = 400,
		fz = 300,
		Mab, Mcd, Mef,
		Cab, Ccd, Cef,
		px, py, pz, pi;

	Mab = (bz - az) / (bx - ax);
	Mcd = (dz - cz) / (dx - cx);
	Mef = (fz - ez) / (fx - ex);
	Cab = az - (ax * Mab);
	Ccd = cz - (cx * Mcd);
	Cef = ez - (ex * Mef);

	px = (Ccd - Cab) / (Mab - Mcd);
	py = (Mab * px) + Cab;
	pz = (Cef - Cab) / (Mab - Mef);
	pi = (Mef * pz) + Cef;

	glBegin(GL_POINTS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(px - 200, 125, py - 23);
	glVertex3f(pz - 255, 125, pi - pi);
	glVertex3f(py - 11, 150, pi - 243);
	glVertex3f(pi - 34, 111, py - 23);
	glVertex3f(pz - 23, 125, pz - 354);
	glEnd();
}
void dermaga(void)
{
	//atas
	glBegin(GL_POLYGON);
	glColor3f(0.4, 0.2, 0.0);
	glVertex3f(-80.0, -17.0, 220.0);
	glVertex3f(40.0, -17.0, 220.0);
	glVertex3f(40.0, -17.0, 180.0);
	glVertex3f(-80.0, -17.0, 180.0);
	glEnd();
	//depan & belakang
	for (int z = 180;z <= 220;z = z + 40)
	{
		glBegin(GL_QUADS);
		glVertex3f(-80.0, -25.0, z);
		glVertex3f(40.0, -25.0, z);
		glVertex3f(40.0, -17.0, z);
		glVertex3f(-80.0, -17.0, z);
		glEnd();
	}
	//kanan & kiri
	for (int x= -80;x <= 40;x = x + 120)
	{
		glBegin(GL_QUADS);
		glVertex3f(x, -25.0, 180.0);
		glVertex3f(x, -25.0, 220.0);
		glVertex3f(x, -17.0, 220.0);
		glVertex3f(x, -17.0, 180.0);
		glEnd();
	}
	//samping kapal
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-50.0, -17.0, 180.0);
	glVertex3f(-30.0, -17.0, 180.0);
	glVertex3f(-30.0, -17.0, 10.0);
	glVertex3f(-50.0, -17.0, 10.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-50.0, -25.0, 10.0);
	glVertex3f(-30.0, -25.0, 10.0);
	glVertex3f(-30.0, -17.0, 10.0);
	glVertex3f(-50.0, -17.0, 10.0);
	glEnd();
	//kanan & kiri
	for (int x = -50;x <= -30;x = x + 20)
	{
		glBegin(GL_QUADS);
		glVertex3f(x, -25.0, 10.0);
		glVertex3f(x, -25.0, 180.0);
		glVertex3f(x, -17.0, 180.0);
		glVertex3f(x, -17.0, 10.0);
		glEnd();
	}
}
void air_laut(void)
{
	//atas
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.5);
	glVertex3f(-80.0, -25.0, 220.0);
	glVertex3f(75.0, -25.0, 220.0);
	glVertex3f(75.0, -25.0, -230.0);
	glVertex3f(-80.0, -25.0, -230.0);
	glEnd();
	//side
	for (int x = -80;x <= 75;x = x + 155)
	{
		glBegin(GL_QUADS);
		glVertex3f(x, -35.0, -230.0);
		glVertex3f(x, -35.0, 220.0);
		glVertex3f(x, -25.0, 220.0);
		glVertex3f(x, -25.0, -230.0);
		glEnd();
	}
	//depan & belakang
	for (int z = -230;z <= 220;z = z + 450)
	{
		glBegin(GL_QUADS);
		glVertex3f(-80.0, -35.0, z);
		glVertex3f(75.0, -35.0, z);
		glVertex3f(75.0, -25.0, z);
		glVertex3f(-80.0, -25.0, z);
		glEnd();
	}
}
void lambung(void) {

	float x = 25.0;
	glColor3f(0.8, 0.8, 0.8);
	//atas
	//belakang
	glBegin(GL_QUADS);
	glVertex3f(-25.0, -5.0, -140.0);
	glVertex3f(25.0, -5.0, -140.0);
	glVertex3f(25.0, -5.0, -159.5);
	glVertex3f(-25.0, -5.0, -159.5);
	glEnd();

	//depan
	glBegin(GL_QUADS);
	glVertex3f(-25.0, -5.0, 130.0);
	glVertex3f(25.0, -5.0, 130.0);
	glVertex3f(25.0, -5.0, 120.0);
	glVertex3f(-25.0, -5.0, 120.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-25.0, -10.0, 120.0);
	glVertex3f(25.0, -10.0, 120.0);
	glVertex3f(25.0, -10.0, 100.0);
	glVertex3f(-25.0, -10.0, 100.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-25.0, -16.0, -135.0);
	glVertex3f(25.0, -16.0, -135.0);
	glVertex3f(25.0, -16.0, 100.0);
	glVertex3f(-25.0, -16.0, 100.0);
	glEnd();

	//vertikal
	glBegin(GL_QUADS);
	glVertex3f(25.0, -5.0, 120.0);
	glVertex3f(-25.0, -5.0, 120.0);
	glVertex3f(-25.0, -10.0, 120.0);
	glVertex3f(25.0, -10.0, 120.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(25.0, -10.0, 100.0);
	glVertex3f(-25.0, -10.0, 100.0);
	glVertex3f(-25.0, -16.0, 100.0);
	glVertex3f(25.0, -16.0, 100.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-25.0, -5.0, -140.0);
	glVertex3f(25.0, -5.0, -140.0);
	glVertex3f(25.0, -16.0, -135.0);
	glVertex3f(-25.0, -16.0, -135.0);
	glEnd();

	//bawah
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-x, -5.0, 130);
	glVertex3f(-x, -5.0, 120);
	glVertex3f(-x, -10.0, 120);
	glVertex3f(0, -40.0, 120);
	glVertex3f(0, -40.0, 150);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-x, -10.0, 120);
	glVertex3f(-x, -10.0, 100);
	glVertex3f(-x, -16.0, 100);
	glVertex3f(0, -40.0, 100);
	glVertex3f(0, -40.0, 120);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-x, -16.0, 100);
	glVertex3f(-x, -16.0, -135);
	glVertex3f(0, -40.0, -135);
	glVertex3f(0, -40.0, 120);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-x, -16.0, -135);
	glVertex3f(-x, -5.0, -140);
	glVertex3f(0, -40.0, -140);
	glVertex3f(0, -40.0, -135);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-x, -5.0, -140);
	glVertex3f(-x, -5.0, -158);
	glVertex3f(0, -40.0, -165);
	glVertex3f(0, -40.0, -140);
	glEnd();

	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(x, -5.0, 130);
	glVertex3f(x, -5.0, 120);
	glVertex3f(x, -10.0, 120);
	glVertex3f(0, -40.0, 120);
	glVertex3f(0, -40.0, 150);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(x, -10.0, 120);
	glVertex3f(x, -10.0, 100);
	glVertex3f(x, -16.0, 100);
	glVertex3f(0, -40.0, 100);
	glVertex3f(0, -40.0, 120);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(x, -16.0, 100);
	glVertex3f(x, -16.0, -135);
	glVertex3f(0, -40.0, -135);
	glVertex3f(0, -40.0, 120);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(x, -16.0, -135);
	glVertex3f(x, -5.0, -140);
	glVertex3f(0, -40.0, -140);
	glVertex3f(0, -40.0, -135);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(x, -5.0, -140);
	glVertex3f(x, -5.0, -158);
	glVertex3f(0, -40.0, -165);
	glVertex3f(0, -40.0, -140);
	glEnd();
}
void buritan(double r, int vertex)
{
	//atas
	glColor3f(0.8, 0.8, 0.8);
	double ngon = (double)vertex;
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	for (int y = -5;y >= -16;y--) {
		for (int i = 0; i < vertex; i++) {
			double x = r * cos(2 * M_PI * i / ngon);
			double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) - 155;
			if (z <= -155.0) {
				glVertex3f(x, y, z + (y * 0.3));
			}
		}
	}

	glEnd();
	//belakang
		//kanan
		//kiri

	//tengah
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.0001)) * sin(2 * M_PI * i / ngon)) - 150;
		if (z <= -155) {
			if (x > -1) {
				glVertex3d(x, -16.0, z);
			}
		}

	}glVertex3d(-25 + 25, -40, -165);
	glEnd();

	//kanan
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.0001)) * sin(2 * M_PI * i / ngon)) - 150;
		if (z <= -155) {
			if (x < 0) {
				glVertex3d(x, -16.0, z);
			}
		}

	}glVertex3d(-25 + 25, -40, -165);
	glEnd();

}
void moncong(void) {
	glColor3f(0.8, 0.8, 0.8);
	moncong_bawah(25.0, 40);
	moncong_atas(25.0, 40);
}
void penyangga(void) 
{
	for (int z = 70; z >= -10; z = z - 5)
	{
		glBegin(GL_TRIANGLES);
		glColor3f(0.7, 0.8, 0.9);
		glVertex3f(15.0, 30.0, z);
		glVertex3f(15.0, 35.0, z);
		glVertex3f(20.0, 35.0, z);
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex3f(-15.0, 30.0, z);
		glVertex3f(-15.0, 35.0, z);
		glVertex3f(-20.0, 35.0, z);
		glEnd();

	}

	for (int z = -65; z >= -115; z = z - 5)
	{
		glBegin(GL_TRIANGLES);
		glVertex3f(15.0, 30.0, z);
		glVertex3f(15.0, 35.0, z);
		glVertex3f(22.0, 35.0, z);
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex3f(-15.0, 30.0, z);
		glVertex3f(-15.0, 35.0, z);
		glVertex3f(-22.0, 35.0, z);
		glEnd();
	}
}
void bangunan(double r, int vertex)
{

	//kanan
	//lurus
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(20.0, -5.0, 110.0);
	glVertex3f(20.0, 30.0, 110.0);
	glVertex3f(20.0, -5.0, 130.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.0, -5.0, 110.0);
	glVertex3f(20.0, -5.0, 120.0);
	glVertex3f(20.0, -10.0, 120.0);
	glVertex3f(20.0, -10.0, 100.0);
	glVertex3f(20.0, -16.0, 100.0);
	glVertex3f(20.0, -16.0, 70.0);
	glVertex3f(20.0, 35.0, 70.0);
	glVertex3f(20.0, 35.0, 110.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.0, -16.0, -120.0);
	glVertex3f(20.0, -5.0, -135.0);
	glVertex3f(20.0, -16.0, -135.0);
	glVertex3f(20.0, -5.0, -140.0);
	glVertex3f(20.0, -5.0, -160.0);
	glVertex3f(20.0, 35.0, -150.0);
	glVertex3f(20.0, 35.0, -120.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.0, -16.0, 65.0);
	glVertex3f(15.0, 35.0, 65.0);
	glVertex3f(15.0, 35.0, -10.0);
	glVertex3f(15.0, -16.0, -10.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.0, -16.0, -65.0);
	glVertex3f(15.0, 35.0, -65.0);
	glVertex3f(15.0, 35.0, -115.0);
	glVertex3f(15.0, -16.0, -115.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.0, -16.0, -15.0);
	glVertex3f(20.0, 35.0, -15.0);
	glVertex3f(20.0, 35.0, -60.0);
	glVertex3f(20.0, -16.0, -60.0);
	glEnd();

	//serong
	//kedalam
	glColor3f(0.4, 0.4, 0.4);
	glBegin(GL_POLYGON);
	glVertex3f(20.0, -16.0, 70.0);
	glVertex3f(20.0, 35.0, 70.0);
	glVertex3f(15.0, 35.0, 65.0);
	glVertex3f(15.0, -16.0, 65.0);
	glEnd();
	//keluar
	glBegin(GL_POLYGON);
	glVertex3f(15.0, -16.0, -10);
	glVertex3f(20.0, -16.0, -15);
	glVertex3f(20.0, 35.0, -15);
	glVertex3f(15.0, 35.0, -10);
	glEnd();
	//kedalam
	glBegin(GL_POLYGON);
	glVertex3f(20.0, -16.0, -60);
	glVertex3f(15.0, -16.0, -65);
	glVertex3f(15.0, 35.0, -65);
	glVertex3f(20.0, 35.0, -60);
	glEnd();
	//keluar
	glBegin(GL_POLYGON);
	glVertex3f(15.0, -16.0, -115);
	glVertex3f(20.0, -16.0, -120);
	glVertex3f(20.0, 35.0, -120);
	glVertex3f(15.0, 35.0, -115);
	glEnd();

	//kiri
	//lurus
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, -5.0, 110.0);
	glVertex3f(-20.0, 30.0, 110.0);
	glVertex3f(-20.0, -5.0, 130.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.0, -5.0, 110.0);
	glVertex3f(-20.0, -5.0, 120.0);
	glVertex3f(-20.0, -10.0, 120.0);
	glVertex3f(-20.0, -10.0, 100.0);
	glVertex3f(-20.0, -16.0, 100.0);
	glVertex3f(-20.0, -16.0, 70.0);
	glVertex3f(-20.0, 35.0, 70.0);
	glVertex3f(-20.0, 35.0, 110.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.0, -16.0, -120.0);
	glVertex3f(-20.0, -5.0, -135.0);
	glVertex3f(-20.0, -16.0, -135.0);
	glVertex3f(-20.0, -5.0, -140.0);
	glVertex3f(-20.0, -5.0, -160.0);
	glVertex3f(-20.0, 35.0, -150.0);
	glVertex3f(-20.0, 35.0, -120.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.0, -16.0, 65.0);
	glVertex3f(-15.0, 35.0, 65.0);
	glVertex3f(-15.0, 35.0, -10.0);
	glVertex3f(-15.0, -16.0, -10.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.0, -16.0, -65.0);
	glVertex3f(-15.0, 35.0, -65.0);
	glVertex3f(-15.0, 35.0, -115.0);
	glVertex3f(-15.0, -16.0, -115.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.0, -16.0, -15.0);
	glVertex3f(-20.0, 35.0, -15.0);
	glVertex3f(-20.0, 35.0, -60.0);
	glVertex3f(-20.0, -16.0, -60.0);
	glEnd();

	//serong
	//kedalam
	glColor3f(0.4, 0.4, 0.4);
	glBegin(GL_POLYGON);
	glVertex3f(-20.0, -16.0, 70.0);
	glVertex3f(-20.0, 35.0, 70.0);
	glVertex3f(-15.0, 35.0, 65.0);
	glVertex3f(-15.0, -16.0, 65.0);
	glEnd();
	//keluar
	glBegin(GL_POLYGON);
	glVertex3f(-15.0, -16.0, -10);
	glVertex3f(-20.0, -16.0, -15);
	glVertex3f(-20.0, 35.0, -15);
	glVertex3f(-15.0, 35.0, -10);
	glEnd();
	//kedalam
	glBegin(GL_POLYGON);
	glVertex3f(-20.0, -16.0, -60);
	glVertex3f(-15.0, -16.0, -65);
	glVertex3f(-15.0, 35.0, -65);
	glVertex3f(-20.0, 35.0, -60);
	glEnd();
	//keluar
	glBegin(GL_POLYGON);
	glVertex3f(-15.0, -16.0, -115);
	glVertex3f(-20.0, -16.0, -120);
	glVertex3f(-20.0, 35.0, -120);
	glVertex3f(-15.0, 35.0, -115);
	glEnd();

	//depan
	double ngon = (double)vertex;
	//kanan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 110;
		if (z >= 115) {
			if (x >= 0) {
				glVertex3d(x, 30.0, z);
			}
		}
	}
	glVertex3d(0, -5, 150);
	for (int i = 0; i < vertex; i++) {
		double x = (r)*cos(2 * M_PI * i / ngon);
		double z = ((r - (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 120;
		if (z >= 110) {
			if (x >= 0) {
				glVertex3d(x, -5.0, z + 10);
			}
		}
	}
	glVertex3d(20, 30, 110);
	glEnd();

	//kiri
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = (-r) * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 110;
		if (z >= 115) {
			if (x <= 0) {
				glVertex3d(x, 30.0, z);
			}
		}

	}
	glVertex3d(0, -5, 150);
	for (int i = 0; i < vertex; i++) {
		double x = (-r) * cos(2 * M_PI * i / ngon);
		double z = ((r - (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 120;
		if (z >= 110) {
			if (x <= 0) {
				glVertex3d(x, -5.0, z + 10);
			}
		}

	}
	glVertex3d(-20, 30, 110);
	glEnd();

	//belakang
	glBegin(GL_QUADS);
	glVertex3f(-20.0, -5.0, -160.0);
	glVertex3f(20.0, -5.0, -160.0);
	glVertex3f(20.0, 35.0, -150.0);
	glVertex3f(-20.0, 35.0, -150.0);
	glEnd();
	curved_belakang(25.0, 80);
	
	penyangga();
}
void curved_belakang(double r, int vertex) {
	double ngon = (double)vertex;
	glBegin(GL_POLYGON);
	for (int i = 0; i <= vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon) - 135);
		if (z < -149) {
			glVertex3f(x, 40, z);
		}
	}glVertex3f(0.0, -5, -170);
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i <= vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon) - 135);
		if (x < 1) {
			if (z < -149) {
				glVertex3f(x, 40, z);
			}
		}
	}glVertex3f(0.0, -4.7, -170);
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i <= vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon) - 135);
		if (x > -1) {
			if (z < -149) {
				glVertex3f(x, 40, z);
			}
		}
	}glVertex3f(0.0, -4.7, -170);
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i <= vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon) - 145);
		if (x > -1) {
			if (z < -159) {
				glVertex3f(x, -4.7, z);
			}
		}
	}glVertex3f(20.0, 40, -150);
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i <= vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon) - 145);
		if (x < 1) {
			if (z < -159) {
				glVertex3f(x, -4.7, z);
			}
		}
	}glVertex3f(-20.0, 40, -150);
	glEnd();

}
void depan_unik(double r, int vertex)
{
	double ngon = (double)vertex;
	//atas
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.7);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 110;
		if (z >= 115.0) {
			glVertex3f(x, 35.0, z);
		}
	}
	glEnd();

	//depan
	//kanan
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 110;
		if (z >= 115) {
			if (x >= 0) {
				glVertex3d(x, 34.9, z);
			}
		}
	}
	glVertex3d(0, 30, 130);

	for (int i = 0; i < vertex; i++) {
		double x = (r)*cos(2 * M_PI * i / ngon);
		double z = ((r - (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 110;
		if (z >= 115) {
			if (x >= 0) {
				glVertex3d(x, 30.1, z);
			}
		}
	}
	glVertex3d(15 + 4, 34.9, 115);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = (-r) * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 110;
		if (z >= 115) {
			if (x <= 0) {
				glVertex3d(x, 34.9, z);
			}
		}
	}
	glVertex3d(0, 30, 130);
	for (int i = 0; i < vertex; i++) {
		double x = (-r) * cos(2 * M_PI * i / ngon);
		double z = ((r - (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 110;
		if (z >= 115) {
			if (x <= 0) {
				glVertex3d(x, 30.1, z);
			}
		}
	}
	glVertex3d(-15 - 4, 34.9, 115);
	glEnd();

	//bangunan panjang
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-25.0, 34.9, 109.0);
	glVertex3f(25.0, 34.9, 109.0);
	glVertex3f(22.0, 34.9, 116.0);
	glVertex3f(-22.0, 34.9, 116.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glVertex3f(-25.0, 30.0, 110.0);
	glVertex3f(25.0, 30.0, 110.0);
	glVertex3f(22.0, 30.0, 116.0);
	glVertex3f(-22.0, 30.0, 116.0);
	glEnd();
	//depan
	glBegin(GL_POLYGON);
	glVertex3f(-22.0, 30.0, 116.0);
	glVertex3f(-22.0, 34.9, 116.0);
	glVertex3f(22.0, 34.9, 116.0);
	glVertex3f(22.0, 30.0, 116.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-25.0, 30.0, 109.0);
	glVertex3f(-25.0, 34.9, 109.0);
	glVertex3f(25.0, 34.9, 109.0);
	glVertex3f(25.0, 30.0, 109.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-25.0, 30.0, 109.0);
	glVertex3f(-25.0, 34.9, 109.0);
	glVertex3f(-22.0, 34.9, 116.0);
	glVertex3f(-22.0, 30.0, 116.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(25.0, 30.0, 109.0);
	glVertex3f(25.0, 34.9, 109.0);
	glVertex3f(22.0, 34.9, 116.0);
	glVertex3f(22.0, 30.0, 116.0);
	glEnd();
}
void atas_depan_unik(double r, int vertex) {
	double ngon = (double)vertex;
	//mejorok
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.7, 0.8);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 108;
		if (z >= 113.0) {
			if (x < 1) {
				glVertex3f(x, 35.1, z);
			}
		}
	}glVertex3f(-20.0, 37, 114);
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 108;
		if (z >= 113.0) {
			if (x > -1) {
				glVertex3f(x, 35.1, z);
			}
		}
	}glVertex3f(20.0, 37.5, 114);
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 111;
		if (z >= 113.0) {
			if (x < 1) {
				glVertex3f(x, 37, z);
			}
		}
	}glVertex3f(0.0, 35.1, 128);
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 112;
		if (z >= 113.0) {
			if (x > -1) {
				glVertex3f(x, 37, z);
			}
		}
	}glVertex3f(0.0, 35, 128);
	glEnd();
	//atasnya menjorok
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 112;
		if (z >= 113.0) {
			if (x < 1) {
				glVertex3f(x, 37.1, z);
			}
		}
	}glVertex3f(-17.0, 48, 98);
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 112;
		if (z >= 113.0) {
			if (x > -1) {
				glVertex3f(x, 37.1, z);
			}
		}
	}glVertex3f(17.0, 48, 98);
	glEnd();

	//atasnya atasan
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 88;
		if (z >= 98.0) {
			glVertex3f(x, 48, z);
		}
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 88;
		if (z >= 98.0) {
			if (x < 1) {
				glVertex3f(x, 48, z);
			}
		}
	}glVertex3f(0.0, 37.1, 133);
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 88;
		if (z >= 98.0) {
			if (x > -1) {
				glVertex3f(x, 48, z);
			}
		}
	}glVertex3f(0.0, 37.1, 133);
	glEnd();

	//atasnya atasnya atasan
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 75;
		if (z >= 85.0) {
			glVertex3f(x, 57, z);
		}
	}
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(16.0, 57.0, 87.0);
	glVertex3f(-16.0, 57.0, 87.0);
	glVertex3f(-16.0, 57.0, 78.0);
	glVertex3f(16.0, 57.0, 78.0);
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 90;
		if (z <= 80.0) {
			glVertex3f(x, 57, z);
		}
	}
	glEnd();
	//bawahnya kebelakang
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 90;
		if (z <= 80.0) {
			if (x > -1) {
				glVertex3f(x, 57, z);
			}
		}
	}glVertex3f(16, 40, 70);
	glEnd(); glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 90;
		if (z <= 80.0) {
			if (x < 1) {
				glVertex3f(x, 57, z);
			}
		}
	}glVertex3f(-16, 40, 70);
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 82;
		if (z <= 72.0) {
			if (x < 1) {
				glVertex3f(x, 40, z);
			}
		}
	}glVertex3f(0, 57, 70);
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 82;
		if (z <= 72.0) {
			if (x > -1) {
				glVertex3f(x, 40, z);
			}
		}
	}glVertex3f(0, 57, 70);
	glEnd();
	//bawahnya kedepan
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 75;
		if (z >= 85.0) {
			if (x < 1) {
				glVertex3f(x, 57, z);
			}
		}
	}glVertex3f(-16, 40, 108);
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 75;
		if (z >= 85.0) {
			if (x > -1) {
				glVertex3f(x, 57, z);
			}
		}
	}glVertex3f(16, 40, 108);
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 95;
		if (z >= 105.0) {
			if (x < 1) {
				glVertex3f(x, 40, z);
			}
		}
	}glVertex3f(0, 57, 95);
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 0.00001)) * sin(2 * M_PI * i / ngon)) + 95;
		if (z >= 105.0) {
			if (x > -1) {
				glVertex3f(x, 40, z);
			}
		}
	}glVertex3f(0, 57, 95);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(16, 40, 70);
	glVertex3f(16, 40, 110);
	glVertex3f(16, 57, 87);
	glVertex3f(16, 57, 78);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(17, 46.5, 100);
	glVertex3f(20, 38, 115);
	glVertex3f(17, 40, 100);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-16, 40, 70);
	glVertex3f(-16, 40, 110);
	glVertex3f(-16, 57, 87);
	glVertex3f(-16, 57, 78);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-17, 46.5, 100);
	glVertex3f(-20, 38, 115);
	glVertex3f(-17, 40, 100);
	glEnd();
}
void kolam(void)
{
	//pagar
	//kiri
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, 35.0, 30.0);
	glVertex3f(-20.0, 40.0, 30.0);
	glVertex3f(-20.0, 40.0, -10.0);
	glVertex3f(-20.0, 35.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(13.0, 35.0, 30.0);
	glVertex3f(15.0, 40.0, 30.0);
	glVertex3f(15.0, 40.0, -10.0);
	glVertex3f(13.0, 35.0, -10.0);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(20.0, 35.0, 30.0);
	glVertex3f(20.0, 40.0, 30.0);
	glVertex3f(20.0, 40.0, -10.0);
	glVertex3f(20.0, 35.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-13.0, 35.0, 30.0);
	glVertex3f(-15.0, 40.0, 30.0);
	glVertex3f(-15.0, 40.0, -10.0);
	glVertex3f(-13.0, 35.0, -10.0);
	glEnd();
	//atas
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, 40.0, 30.0);
	glVertex3f(-20.0, 40.0, -10.0);
	glVertex3f(-15.0, 40.0, -10.0);
	glVertex3f(-15.0, 40.0, 30.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(20.0, 40.0, 30.0);
	glVertex3f(20.0, 40.0, -10.0);
	glVertex3f(15.0, 40.0, -10.0);
	glVertex3f(15.0, 40.0, 30.0);
	glEnd();
	//bawah
	glBegin(GL_QUADS);
	glVertex3f(-20.0, 35.0, 30.0);
	glVertex3f(-20.0, 35.0, -10.0);
	glVertex3f(-15.0, 35.0, -10.0);
	glVertex3f(-15.0, 35.0, 30.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(20.0, 35.0, 30.0);
	glVertex3f(20.0, 35.0, -10.0);
	glVertex3f(15.0, 35.0, -10.0);
	glVertex3f(15.0, 35.0, 30.0);
	glEnd();

	//pinggir kolam
	//sisi kanan dan kiri
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-13.0, 35.0, 25.0);
	glVertex3f(-8.0, 35.0, 25.0);
	glVertex3f(-8.0, 35.0, 0.0);
	glVertex3f(-13.0, 35.0, 0.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(13.0, 35.0, 25.0);
	glVertex3f(8.0, 35.0, 25.0);
	glVertex3f(8.0, 35.0, 0.0);
	glVertex3f(13.0, 35.0, 0.0);
	glEnd();
	//sisi depan dan belakang
	glBegin(GL_QUADS);
	glVertex3f(-13.0, 35.0, 30.0);
	glVertex3f(13.0, 35.0, 30.0);
	glVertex3f(13.0, 35.0, 25.0);
	glVertex3f(-13.0, 35.0, 25.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-13.0, 35.0, 0.0);
	glVertex3f(13.0, 35.0, 0.0);
	glVertex3f(13.0, 35.0, -10.0);
	glVertex3f(-13.0, 35.0, -10.0);
	glEnd();

	//kolam
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.8, 0.8);
	glVertex3f(-8.0, 35.0, 25.0);
	glVertex3f(8.0, 35.0, 25.0);
	glVertex3f(8.0, 35.0, 0.0);
	glVertex3f(-8.0, 35.0, 0.0);
	glEnd();
}
void bangunan_batas(double r, int vertex)
{
	//bangunan belakang
	//atas
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, 40.0, 109.0);
	glVertex3f(-20.0, 40.0, 30.0);
	glVertex3f(20.0, 40.0, 30.0);
	glVertex3f(20.0, 40.0, 109.0);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, 35.0, 116.0);
	glVertex3f(-20.0, 40.0, 111.0);
	glVertex3f(-20.0, 40.0, 30.0);
	glVertex3f(-20.0, 35.0, 30.0);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(20.0, 35.0, 116.0);
	glVertex3f(20.0, 40.0, 111.0);
	glVertex3f(20.0, 40.0, 30.0);
	glVertex3f(20.0, 35.0, 30.0);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, 35.0, 30.0);
	glVertex3f(-20.0, 40.0, 30.0);
	glVertex3f(20.0, 40.0, 30.0);
	glVertex3f(20.0, 35.0, 30.0);
	glEnd();

	kolam();

	//serong
	//belakang
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, 35.0, -10.0);
	glVertex3f(-20.0, 40.0, -10.0);
	glVertex3f(20.0, 40.0, -10.0);
	glVertex3f(20.0, 35.0, -10.0);
	glEnd();
	//atas
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, 40.0, -10.0);
	glVertex3f(20.0, 40.0, -10.0);
	glVertex3f(22.0, 40.0, -15.0);
	glVertex3f(-22.0, 40.0, -15.0);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glVertex3f(22.0, 35.0, -15.0);
	glVertex3f(20.0, 35.0, -10.0);
	glVertex3f(20.0, 40.0, -10.0);
	glVertex3f(22.0, 40.0, -15.0);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glVertex3f(-22.0, 35.0, -15.0);
	glVertex3f(-20.0, 35.0, -10.0);
	glVertex3f(-20.0, 40.0, -10.0);
	glVertex3f(-22.0, 40.0, -15.0);
	glEnd();


	//atas
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-22.0, 40.0, -15.0);
	glVertex3f(-22.0, 40.0, -150.0);
	glVertex3f(22.0, 40.0, -150.0);
	glVertex3f(22.0, 40.0, -15.0);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(22.0, 35.0, -15.0);
	glVertex3f(22.0, 35.0, -150.0);
	glVertex3f(22.0, 40.0, -150.0);
	glVertex3f(22.0, 40.0, -15.0);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-22.0, 35.0, -15.0);
	glVertex3f(-22.0, 35.0, -150.0);
	glVertex3f(-22.0, 40.0, -150.0);
	glVertex3f(-22.0, 40.0, -15.0);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-22.0, 35.0, -150.0);
	glVertex3f(22.0, 35.0, -150.0);
	glVertex3f(22.0, 40.0, -150.0);
	glVertex3f(-22.0, 40.0, -150.0);
	glEnd();


}
void atas_depan(void)
{

	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.9);
	glVertex3f(-1.5, 50.0, 70.0);
	glVertex3f(1.5, 50.0, 70.0);
	glVertex3f(2.5, 48.0, 35.0);
	glVertex3f(-2.5, 48.0, 35.0);
	glEnd();
	//atas
	glBegin(GL_QUADS);
	glVertex3f(-1.5, 52.0, 70.0);
	glVertex3f(1.5, 52.0, 70.0);
	glVertex3f(2.5, 49.0, 35.0);
	glVertex3f(-2.5, 49.0, 35.0);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glVertex3f(-1.5, 50.0, 70.0);
	glVertex3f(1.5, 50.0, 70.0);
	glVertex3f(1.5, 52.0, 70.0);
	glVertex3f(-1.5, 52.0, 70.0);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glVertex3f(-2.5, 48.0, 35.0);
	glVertex3f(2.5, 48.0, 35.0);
	glVertex3f(2.5, 49.0, 35.0);
	glVertex3f(-2.5, 49.0, 35.0);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glVertex3f(1.5, 50.0, 70.0);
	glVertex3f(2.5, 48.0, 35.0);
	glVertex3f(2.5, 49.0, 35.0);
	glVertex3f(1.5, 52.0, 70.0);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glVertex3f(-1.5, 50.0, 70.0);
	glVertex3f(-2.5, 48.0, 35.0);
	glVertex3f(-2.5, 49.0, 35.0);
	glVertex3f(-1.5, 52.0, 70.0);
	glEnd();

	//paling atas
	//atas
	glBegin(GL_QUADS);
	glVertex3f(-0.5, 55.0, 38.0);
	glVertex3f(0.5, 55.0, 38.0);
	glVertex3f(1.0, 55.0, 35.0);
	glVertex3f(-1.0, 55.0, 35.0);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glVertex3f(-0.5, 49.0, 40.0);
	glVertex3f(0.5, 49.0, 40.0);
	glVertex3f(0.5, 55.0, 38.0);
	glVertex3f(-0.5, 55.0, 38.0);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glVertex3f(-1.0, 49.0, 35.0);
	glVertex3f(1.0, 49.0, 35.0);
	glVertex3f(1.0, 55.0, 35.0);
	glVertex3f(-1.0, 55.0, 35.0);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glVertex3f(-1.0, 49.0, 35.0);
	glVertex3f(-0.5, 49.0, 40.0);
	glVertex3f(-0.5, 55.0, 38.0);
	glVertex3f(-1.0, 55.0, 35.0);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glVertex3f(1.0, 49.0, 35.0);
	glVertex3f(0.5, 49.0, 40.0);
	glVertex3f(0.5, 55.0, 38.0);
	glVertex3f(1.0, 55.0, 35.0);
	glEnd();
}
void atas_samping(void)
{
	//depan
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-13.2, 47.0, -50.0);
	glVertex3f(-10.0, 47.0, -50.0);
	glVertex3f(-10.0, 53.0, -50.0);
	glVertex3f(-13.2, 49.0, -50.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(13.2, 47.0, -50.0);
	glVertex3f(10.0, 47.0, -50.0);
	glVertex3f(10.0, 53.0, -50.0);
	glVertex3f(13.2, 49.0, -50.0);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glVertex3f(-14.0, 40.0, -120.0);
	glVertex3f(-14.0, 40.0, -60.0);
	glVertex3f(-13.0, 49.0, -60.0);
	glVertex3f(-13.0, 49.0, -120.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-13.2, 47.0, -60.0);
	glVertex3f(-13.2, 47.0, -50.0);
	glVertex3f(-13.0, 49.0, -50.0);
	glVertex3f(-13.0, 49.0, -60.0);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glVertex3f(14.0, 40.0, -120.0);
	glVertex3f(14.0, 40.0, -60.0);
	glVertex3f(13.0, 49.0, -60.0);
	glVertex3f(13.0, 49.0, -120.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(13.2, 47.0, -60.0);
	glVertex3f(13.2, 47.0, -50.0);
	glVertex3f(13.0, 49.0, -50.0);
	glVertex3f(13.0, 49.0, -60.0);
	glEnd();
	//atas
	glBegin(GL_QUADS);
	glVertex3f(-13.0, 49.0, -120.0);
	glVertex3f(-13.0, 49.0, -50.0);
	glVertex3f(-10.0, 50.0, -50.0);
	glVertex3f(-10.0, 50.0, -120.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(13.0, 49.0, -120.0);
	glVertex3f(13.0, 49.0, -50.0);
	glVertex3f(10.0, 50.0, -50.0);
	glVertex3f(10.0, 50.0, -120.0);
	glEnd();
	//belakang
	for (int z = -60;z >= -120;z = z - 10)
	{
		glBegin(GL_QUADS);
		glVertex3f(-14.0, 40.0, z);
		glVertex3f(-10.0, 40.0, z);
		glVertex3f(-10.0, 53.0, z);
		glVertex3f(-13.0, 49.0, z);
		glEnd();
		glBegin(GL_QUADS);
		glVertex3f(14.0, 40.0, z);
		glVertex3f(10.0, 40.0, z);
		glVertex3f(10.0, 53.0, z);
		glVertex3f(13.0, 49.0, z);
		glEnd();
	}
	samping();

}
void samping(void)
{
	//depan & belakang
	for (int z = -65;z >=-95;z = z - 10) {
		glBegin(GL_QUADS);
		glColor3f(0.6, 0.6, 0.6);
		glVertex3f(-13.5, 43.0, z);
		glVertex3f(-18.0, 43.0, z);
		glVertex3f(-20.0, 49.0, z);
		glVertex3f(-13.0, 49.0, z);
		glEnd();
		glBegin(GL_QUADS);
		glVertex3f(13.5, 43.0, z);
		glVertex3f(18.0, 43.0, z);
		glVertex3f(20.0, 49.0, z);
		glVertex3f(13.0, 49.0, z);
		glEnd();
	}
	//atas depan
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-13.0, 49.0, -65.0);
	glVertex3f(-20.0, 49.0, -65.0);
	glVertex3f(-20.0, 49.0, -75.0);
	glVertex3f(-13.0, 49.0, -75.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(13.0, 49.0, -65.0);
	glVertex3f(20.0, 49.0, -65.0);
	glVertex3f(20.0, 49.0, -75.0);
	glVertex3f(13.0, 49.0, -75.0);
	glEnd();
	//atas belakang
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-13.0, 49.0, -85.0);
	glVertex3f(-20.0, 49.0, -85.0);
	glVertex3f(-20.0, 49.0, -95.0);
	glVertex3f(-13.0, 49.0, -95.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(13.0, 49.0, -85.0);
	glVertex3f(20.0, 49.0, -85.0);
	glVertex3f(20.0, 49.0, -95.0);
	glVertex3f(13.0, 49.0, -95.0);
	glEnd();

	//bawah depan
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-13.5, 43.0, -65.0);
	glVertex3f(-18.0, 43.0, -65.0);
	glVertex3f(-18.0, 43.0, -75.0);
	glVertex3f(-13.5, 43.0, -75.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(13.5, 43.0, -65.0);
	glVertex3f(18.0, 43.0, -65.0);
	glVertex3f(18.0, 43.0, -75.0);
	glVertex3f(13.5, 43.0, -75.0);
	glEnd();
	//bawah belakang
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-13.5, 43.0, -85.0);
	glVertex3f(-18.0, 43.0, -85.0);
	glVertex3f(-18.0, 43.0, -95.0);
	glVertex3f(-13.5, 43.0, -95.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(13.5, 43.0, -85.0);
	glVertex3f(18.0, 43.0, -85.0);
	glVertex3f(18.0, 43.0, -95.0);
	glVertex3f(13.5, 43.0, -95.0);
	glEnd();

	//kaca depan
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.8);
	glVertex3f(-17.0, 43.0, -65.0);
	glVertex3f(-17.0, 43.0, -75.0);
	glVertex3f(-19.0, 49.0, -75.0);
	glVertex3f(-19.5, 49.0, -65.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.8);
	glVertex3f(17.0, 43.0, -65.0);
	glVertex3f(17.0, 43.0, -75.0);
	glVertex3f(19.0, 49.0, -75.0);
	glVertex3f(19.5, 49.0, -65.0);
	glEnd();
	//kaca belakang
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.8);
	glVertex3f(-17.0, 43.0, -85.0);
	glVertex3f(-17.0, 43.0, -95.0);
	glVertex3f(-19.0, 49.0, -95.0);
	glVertex3f(-19.5, 49.0, -85.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.8);
	glVertex3f(17.0, 43.0, -85.0);
	glVertex3f(17.0, 43.0, -95.0);
	glVertex3f(19.0, 49.0, -95.0);
	glVertex3f(19.5, 49.0, -85.0);
	glEnd();

}
void atas_belakang(void)
{
	//paling atas depan
	//atas
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-2.5, 60.0, -40.0);
	glVertex3f(2.5, 60.0, -40.0);
	glVertex3f(2.5, 60.0, -45.0);
	glVertex3f(-2.5, 60.0, -45.0);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-4.0, 53.1, -25.0);
	glVertex3f(4.0, 53.1, -25.0);
	glVertex3f(4.0, 53.1, -45.0);
	glVertex3f(-4.0, 53.1, -45.0);
	glEnd();
	//depan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-4.0, 53.0, -25.0);
	glVertex3f(4.0, 53.0, -25.0);
	glVertex3f(2.5, 60.0, -40.0);
	glVertex3f(-2.5, 60.0, -40.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-4.0, 53.0, -45.0);
	glVertex3f(4.0, 53.0, -45.0);
	glVertex3f(2.5, 60.0, -45.0);
	glVertex3f(-2.5, 60.0, -45.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-4.0, 53.0, -45.0);
	glVertex3f(-4.0, 53.0, -25.0);
	glVertex3f(-2.5, 60.0, -40.0);
	glVertex3f(-2.5, 60.0, -45.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(4.0, 53.0, -45.0);
	glVertex3f(4.0, 53.0, -25.0);
	glVertex3f(2.5, 60.0, -40.0);
	glVertex3f(2.5, 60.0, -45.0);
	glEnd();

	//paling atas belakang
	//atas
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(8.0, 60.0, -120.0);
	glVertex3f(5.0, 60.0, -120.0);
	glVertex3f(5.0, 60.0, -125.0);
	glVertex3f(8.0, 60.0, -125.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-8.0, 60.0, -120.0);
	glVertex3f(-5.0, 60.0, -120.0);
	glVertex3f(-5.0, 60.0, -125.0);
	glVertex3f(-8.0, 60.0, -125.0);
	glEnd();
	//depan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(9.0, 53.0, -115.0);
	glVertex3f(4.0, 53.0, -115.0);
	glVertex3f(5.0, 60.0, -120.0);
	glVertex3f(8.0, 60.0, -120.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-9.0, 53.0, -115.0);
	glVertex3f(-4.0, 53.0, -115.0);
	glVertex3f(-5.0, 60.0, -120.0);
	glVertex3f(-8.0, 60.0, -120.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(9.0, 53.0, -125.0);
	glVertex3f(4.0, 53.0, -125.0);
	glVertex3f(5.0, 60.0, -125.0);
	glVertex3f(8.0, 60.0, -125.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-9.0, 53.0, -125.0);
	glVertex3f(-4.0, 53.0, -125.0);
	glVertex3f(-5.0, 60.0, -125.0);
	glVertex3f(-8.0, 60.0, -125.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(4.0, 53.0, -125.0);
	glVertex3f(4.0, 53.0, -115.0);
	glVertex3f(5.0, 60.0, -120.0);
	glVertex3f(5.0, 60.0, -125.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-4.0, 53.0, -125.0);
	glVertex3f(-4.0, 53.0, -115.0);
	glVertex3f(-5.0, 60.0, -120.0);
	glVertex3f(-5.0, 60.0, -125.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(9.0, 53.0, -125.0);
	glVertex3f(9.0, 53.0, -115.0);
	glVertex3f(8.0, 60.0, -120.0);
	glVertex3f(8.0, 60.0, -125.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-9.0, 53.0, -125.0);
	glVertex3f(-9.0, 53.0, -115.0);
	glVertex3f(-8.0, 60.0, -120.0);
	glVertex3f(-8.0, 60.0, -125.0);
	glEnd();

	//atas
	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-10.0, 53.0, -20.0);
	glVertex3f(10.0, 53.0, -20.0);
	glVertex3f(10.0, 53.0, -125.0);
	glVertex3f(-10.0, 53.0, -125.0);
	glEnd();
	//depan
	glBegin(GL_POLYGON);
	glVertex3f(-10.0, 47.0, -20.0);
	glVertex3f(10.0, 47.0, -20.0);
	glVertex3f(10.0, 53.0, -20.0);
	glVertex3f(-10.0, 53.0, -20.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-10.0, 40.0, -125.0);
	glVertex3f(10.0, 40.0, -125.0);
	glVertex3f(10.0, 53.0, -125.0);
	glVertex3f(-10.0, 53.0, -125.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(10.0, 47.0, -20.0);
	glVertex3f(10.0, 47.0, -120.0);
	glVertex3f(10.0, 53.0, -120.0);
	glVertex3f(10.0, 53.0, -20.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(10.0, 40.0, -120.0);
	glVertex3f(10.0, 40.0, -125.0);
	glVertex3f(10.0, 53.0, -125.0);
	glVertex3f(10.0, 53.0, -120.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-10.0, 47.0, -20.0);
	glVertex3f(-10.0, 47.0, -120.0);
	glVertex3f(-10.0, 53.0, -120.0);
	glVertex3f(-10.0, 53.0, -20.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-10.0, 40.0, -120.0);
	glVertex3f(-10.0, 40.0, -125.0);
	glVertex3f(-10.0, 53.0, -125.0);
	glVertex3f(-10.0, 53.0, -120.0);
	glEnd();

	//batas 
	//bawah
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-16.0, 45.1, -18.0);
	glVertex3f(16.0, 45.1, -18.0);
	glVertex3f(16.0, 45.1, -60.0);
	glVertex3f(-16.0, 45.1, -60.0);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-16.0, 47.0, -18.0);
	glVertex3f(16.0, 47.0, -18.0);
	glVertex3f(16.0, 47.0, -60.0);
	glVertex3f(-16.0, 47.0, -60.0);
	glEnd();
	//depan
	glBegin(GL_POLYGON);
	glVertex3f(-16.0, 45.0, -18.0);
	glVertex3f(16.0, 45.0, -18.0);
	glVertex3f(16.0, 47.0, -18.0);
	glVertex3f(-16.0, 47.0, -18.0);
	glEnd();
	//depan
	glBegin(GL_POLYGON);
	glVertex3f(-16.0, 45.0, -60.0);
	glVertex3f(16.0, 45.0, -60.0);
	glVertex3f(16.0, 47.0, -60.0);
	glVertex3f(-16.0, 47.0, -60.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(16.0, 45.0, -18.0);
	glVertex3f(16.0, 45.0, -60.0);
	glVertex3f(16.0, 47.0, -60.0);
	glVertex3f(16.0, 47.0, -18.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-16.0, 45.0, -18.0);
	glVertex3f(-16.0, 45.0, -60.0);
	glVertex3f(-16.0, 47.0, -60.0);
	glVertex3f(-16.0, 47.0, -18.0);
	glEnd();

	//bagian bawah
	//atas
	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-15.0, 45.0, -20.0);
	glVertex3f(15.0, 45.0, -20.0);
	glVertex3f(15.0, 45.0, -60.0);
	glVertex3f(-15.0, 45.0, -60.0);
	glEnd();
	//depan
	glBegin(GL_POLYGON);
	glVertex3f(-15.0, 45.0, -20.0);
	glVertex3f(15.0, 45.0, -20.0);
	glVertex3f(15.0, 40.0, -20.0);
	glVertex3f(-15.0, 40.0, -20.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-15.0, 45.0, -60.0);
	glVertex3f(15.0, 45.0, -60.0);
	glVertex3f(15.0, 40.0, -60.0);
	glVertex3f(-15.0, 40.0, -60.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(15.0, 40.0, -20.0);
	glVertex3f(15.0, 40.0, -60.0);
	glVertex3f(15.0, 45.0, -60.0);
	glVertex3f(15.0, 45.0, -20.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-15.0, 40.0, -20.0);
	glVertex3f(-15.0, 40.0, -60.0);
	glVertex3f(-15.0, 45.0, -60.0);
	glVertex3f(-15.0, 45.0, -20.0);
	glEnd();

	atas_p_belakang();
}
void atas_p_belakang(void)
{
	//kotak kiri
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-12.0, 40.0, -120.5);
	glVertex3f(-12.0, 40.0, -125.5);
	glVertex3f(-12.0, 55.0, -125.5);
	glVertex3f(-12.0, 55.0, -120.5);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(-11.9, 40.0, -120.5);
	glVertex3f(-11.9, 40.0, -125.5);
	glVertex3f(-11.9, 55.0, -125.5);
	glVertex3f(-11.9, 55.0, -120.5);
	glEnd();
	//depan
	glBegin(GL_POLYGON);
	glVertex3f(-12.0, 40.0, -120.5);
	glVertex3f(-10.0, 40.0, -120.5);
	glVertex3f(-10.0, 55.0, -120.5);
	glVertex3f(-12.0, 55.0, -120.5);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-12.0, 40.0, -125.5);
	glVertex3f(-10.0, 40.0, -125.5);
	glVertex3f(-10.0, 55.0, -125.5);
	glVertex3f(-12.0, 55.0, -125.5);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-12.0, 5.0, -125.5);
	glVertex3f(-10.0, 55.0, -125.5);
	glVertex3f(-10.0, 55.0, -120.5);
	glVertex3f(-12.0, 55.0, -120.5);
	glEnd();


	//bagian bawah
	//depan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-11.0, 40.0, -126.0);
	glVertex3f(11.0, 40.0, -126.0);
	glVertex3f(11.0, 45.0, -126.0);
	glVertex3f(-11.0, 45.0, -126.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(-11.0, 40.0, -138.0);
	glVertex3f(11.0, 40.0, -138.0);
	glVertex3f(11.0, 45.0, -138.0);
	glVertex3f(-11.0, 45.0, -138.0);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(-11.0, 45.0, -126.0);
	glVertex3f(11.0, 45.0, -126.0);
	glVertex3f(11.0, 45.0, -138.0);
	glVertex3f(-11.0, 45.0, -138.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(11.0, 40.0, -126.0);
	glVertex3f(11.0, 40.0, -138.0);
	glVertex3f(11.0, 45.0, -138.0);
	glVertex3f(11.0, 45.0, -126.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(-11.0, 40.0, -126.0);
	glVertex3f(-11.0, 40.0, -138.0);
	glVertex3f(-11.0, 45.0, -138.0);
	glVertex3f(-11.0, 45.0, -126.0);
	glEnd();

	//bagian tengah
	//atas
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(8.0, 53.0, -130.0);
	glVertex3f(5.0, 53.0, -130.0);
	glVertex3f(5.0, 53.0, -126.0);
	glVertex3f(8.0, 53.0, -126.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-8.0, 53.0, -130.0);
	glVertex3f(-5.0, 53.0, -130.0);
	glVertex3f(-5.0, 53.0, -126.0);
	glVertex3f(-8.0, 53.0, -126.0);
	glEnd();
	//depan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(9.0, 45.0, -126.0);
	glVertex3f(4.0, 45.0, -126.0);
	glVertex3f(5.0, 53.0, -126.0);
	glVertex3f(8.0, 53.0, -126.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-9.0, 45.0, -126.0);
	glVertex3f(-4.0, 45.0, -126.0);
	glVertex3f(-5.0, 53.0, -126.0);
	glVertex3f(-8.0, 53.0, -126.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(9.0, 45.0, -131.0);
	glVertex3f(4.0, 45.0, -131.0);
	glVertex3f(5.0, 53.0, -130.0);
	glVertex3f(8.0, 53.0, -130.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-9.0, 45.0, -131.0);
	glVertex3f(-4.0, 45.0, -131.0);
	glVertex3f(-5.0, 53.0, -130.0);
	glVertex3f(-8.0, 53.0, -130.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(4.0, 45.0, -126.0);
	glVertex3f(4.0, 45.0, -131.0);
	glVertex3f(5.0, 53.0, -130.0);
	glVertex3f(5.0, 53.0, -126.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-4.0, 45.0, -126.0);
	glVertex3f(-4.0, 45.0, -131.0);
	glVertex3f(-5.0, 53.0, -130.0);
	glVertex3f(-5.0, 53.0, -126.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(9.0, 45.0, -126.0);
	glVertex3f(9.0, 45.0, -131.0);
	glVertex3f(8.0, 53.0, -130.0);
	glVertex3f(8.0, 53.0, -126.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-9.0, 45.0, -126.0);
	glVertex3f(-9.0, 45.0, -131.0);
	glVertex3f(-8.0, 53.0, -130.0);
	glVertex3f(-8.0, 53.0, -126.0);
	glEnd();

	//bagian penyambung
	//atas
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-4.0, 61.0, -126);
	glVertex3f(4.0, 61.0, -126);
	glVertex3f(4.0, 61.0, -131);
	glVertex3f(-4.0, 61.0, -131);
	glEnd();
	//bawah
	glBegin(GL_QUADS);
	glVertex3f(-4.5, 57.0, -126);
	glVertex3f(4.5, 57.0, -126);
	glVertex3f(4.5, 57.0, -131);
	glVertex3f(-4.5, 57.0, -131);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glVertex3f(-4.5, 57.0, -126);
	glVertex3f(4.5, 57.0, -126);
	glVertex3f(4.0, 61.0, -126);
	glVertex3f(-4.0, 61.0, -126);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glVertex3f(-4.5, 57.0, -130.5);
	glVertex3f(4.5, 57.0, -130.5);
	glVertex3f(4.0, 61.0, -131);
	glVertex3f(-4.0, 61.0, -131);
	glEnd();



	//bagian atas
	//atas
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(9.0, 61.0, -131.0);
	glVertex3f(4.0, 61.0, -131.0);
	glVertex3f(4.0, 61.0, -126.0);
	glVertex3f(9.0, 61.0, -126.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-9.0, 61.0, -131.0);
	glVertex3f(-4.0, 61.0, -131.0);
	glVertex3f(-4.0, 61.0, -126.0);
	glVertex3f(-9.0, 61.0, -126.0);
	glEnd();
	//depan
	glBegin(GL_POLYGON);
	glVertex3f(9.0, 61.0, -126.0);
	glVertex3f(4.0, 61.0, -126.0);
	glVertex3f(5.0, 53.0, -126.0);
	glVertex3f(8.0, 53.0, -126.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-9.0, 61.0, -126.0);
	glVertex3f(-4.0, 61.0, -126.0);
	glVertex3f(-5.0, 53.0, -126.0);
	glVertex3f(-8.0, 53.0, -126.0);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(9.0, 61.0, -131.0);
	glVertex3f(4.0, 61.0, -131.0);
	glVertex3f(5.0, 53.0, -130.0);
	glVertex3f(8.0, 53.0, -130.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-9.0, 61.0, -131.0);
	glVertex3f(-4.0, 61.0, -131.0);
	glVertex3f(-5.0, 53.0, -130.0);
	glVertex3f(-8.0, 53.0, -130.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(4.0, 61.0, -126.0);
	glVertex3f(4.0, 61.0, -131.0);
	glVertex3f(5.0, 53.0, -130.0);
	glVertex3f(5.0, 53.0, -126.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-4.0, 61.0, -126.0);
	glVertex3f(-4.0, 61.0, -131.0);
	glVertex3f(-5.0, 53.0, -130.0);
	glVertex3f(-5.0, 53.0, -126.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(9.0, 61.0, -126.0);
	glVertex3f(9.0, 61.0, -131.0);
	glVertex3f(8.0, 53.0, -130.0);
	glVertex3f(8.0, 53.0, -126.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-9.0, 61.0, -126.0);
	glVertex3f(-9.0, 61.0, -131.0);
	glVertex3f(-8.0, 53.0, -130.0);
	glVertex3f(-8.0, 53.0, -126.0);
	glEnd();
}
void bangunan_atas(double r, int vertex)
{
	//bangunan depan
	//bagian belakang
	//bawah
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.7, 0.8);
	glVertex3f(-15.0, 40.1, 70.0);
	glVertex3f(15.0, 40.1, 70.0);
	glVertex3f(15.0, 40.1, 35.0);
	glVertex3f(-15.0, 40.1, 35.0);
	glEnd();
	//atas
	glBegin(GL_QUADS);
	glVertex3f(-15.0, 48.0, 70.0);
	glVertex3f(-1.5, 50.0, 70.0);
	glVertex3f(-2.5, 48.0, 35.0);
	glVertex3f(-15.0, 45.0, 35.0);
	glEnd();

	atas_depan();

	glColor3f(0.6, 0.7, 0.8);
	glBegin(GL_QUADS);
	glVertex3f(15.0, 48.0, 70.0);
	glVertex3f(1.5, 50.0, 70.0);
	glVertex3f(2.5, 48.0, 35.0);
	glVertex3f(15.0, 45.0, 35.0);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glVertex3f(-15.0, 40.1, 70.0);
	glVertex3f(0.0, 40.1, 70.0);
	glVertex3f(0.0, 50.0, 70.0);
	glVertex3f(-15.0, 48.0, 70.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(15.0, 40.1, 70.0);
	glVertex3f(0.0, 40.1, 70.0);
	glVertex3f(0.0, 50.0, 70.0);
	glVertex3f(15.0, 48.0, 70.0);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glVertex3f(-15.0, 40.1, 35.0);
	glVertex3f(0.0, 40.1, 35.0);
	glVertex3f(0.0, 48.0, 35.0);
	glVertex3f(-15.0, 45.0, 35.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(15.0, 40.1, 35.0);
	glVertex3f(0.0, 40.1, 35.0);
	glVertex3f(0.0, 48.0, 35.0);
	glVertex3f(15.0, 45.0, 35.0);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glVertex3f(-15.0, 40.1, 35.0);
	glVertex3f(-15.0, 40.1, 70.0);
	glVertex3f(-15.0, 48.0, 70.0);
	glVertex3f(-15.0, 45.0, 35.0);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glVertex3f(15.0, 40.1, 35.0);
	glVertex3f(15.0, 40.1, 70.0);
	glVertex3f(15.0, 48.0, 70.0);
	glVertex3f(15.0, 45.0, 35.0);
	glEnd();

	// bangunan belakang
	atas_belakang();
	//bangunan samping
	atas_samping();
}
void moncong_bawah(double r, int vertex) {
	double ngon = (double)vertex;
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 2)) * sin(2 * M_PI * i / ngon)) + 130;
		if (z >= 130) {
			if (x >= 0) {
				glVertex3d(x, -5.0, z);
			}
		}

	}glVertex3d(-25 + 25, -40, 150);
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = (-r) * cos(2 * M_PI * i / ngon);
		double z = ((r)+(i * 2)) * sin(2 * M_PI * i / ngon) + 130;
		if (z >= 130) {
			if (x < 0) {
				glVertex3d(x, -5.0, z);
			}
		}

	}glVertex3d(-25 + 25, -40, 150);
	glEnd();
}
void moncong_atas(double r, int vertex) {
	double ngon = (double)vertex;
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = r * cos(2 * M_PI * i / ngon);
		double z = ((r + (i * 2)) * sin(2 * M_PI * i / ngon)) + 130;
		if (z >= 130) {
			if (x >= 0) {
				glVertex3d(x, -4.9, z);
			}
		}

	}glVertex3d(0, -5.0, 130);
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = (-r) * cos(2 * M_PI * i / ngon);
		double z = ((r)+(i * 2)) * sin(2 * M_PI * i / ngon) + 130;
		if (z >= 130) {
			if (x < 0) {
				glVertex3d(x, -4.9, z);
			}
		}

	}glVertex3d(0, -5.0, 130);
	glEnd();
}
void keyboard(unsigned char key, int x, int y) {
	
	switch (key) {
	case 'w':
	case 'W':
		glRotatef(-2.0, 1.0, 0.0, 0.0);
		break;
	case 's':
	case 'S':
		glRotatef(2.0, 1.0, 0.0, 0.0);
		break;
	case 'a':
	case 'A':
		glRotatef(-2.0, 0.0, 1.0, 0.0);
		break;
	case 'd':
	case 'D':
		glRotatef(2.0, 0.0, 1.0, 0.0);
		break;
	case 'q':
	case 'Q':
		glScalef(1.2, 1.2, 1.2);
		break;
	case 'e':
	case 'E':
		glScalef(0.8, 0.8, 0.8);
		break;
	case 'z':
	case 'Z':
		glRotatef(1.0, 0.0, 0.0, 2.0);
		break;
	case 'x':
	case 'X':
		glRotatef(1.0, 0.0, 0.0, -2.0);
		break;
	case ' ':
		glutTimerFunc(0, timer, 0);
		break;
	}

	display();
}
void arrow_key(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		glTranslatef(-2.0, 0.0, 0.0);
		break;
	case GLUT_KEY_RIGHT:
		glTranslatef(2.0, 0.0, 0.0);
		break;
	case GLUT_KEY_UP:
		glTranslatef(0.0, 2.0, 0.0);
		break;
	case GLUT_KEY_DOWN:
		glTranslatef(0.0, -2.0, 0.0);
		break;
	}
	display();
}
void mouse(int button, int a, int x, int y)
{
	switch (button)
	{
		if (a == GLUT_DOWN || a == GLUT_UP)
		{
	case GLUT_LEFT_BUTTON:
		glRotatef(-2.0, 0.0, 1.0, 0.0);
		break;
	case GLUT_RIGHT_BUTTON:
		glRotatef(2.0, 0.0, 1.0, 0.0);
		break;
	case 3:
		glRotatef(-2.0, 1.0, 0.0, 0.0);
		break;
	case 4:
		glRotatef(2.0, 1.0, 0.0, 0.0);
		break;
		}
	}
	display();
}
void jendela(void) {
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-15.1, 20.0, 60.0);
	glVertex3f(-15.1, 30.0, 60.0);
	glVertex3f(-15.1, 30.0, 50.0);
	glVertex3f(-15.1, 20.0, 50.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, 20.0, 45.0);
	glVertex3f(-15.1, 30.0, 45.0);
	glVertex3f(-15.1, 30.0, 35.0);
	glVertex3f(-15.1, 20.0, 35.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, 20.0, 30.0);
	glVertex3f(-15.1, 30.0, 30.0);
	glVertex3f(-15.1, 30.0, 20.0);
	glVertex3f(-15.1, 20.0, 20.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, 20.0, 15.0);
	glVertex3f(-15.1, 30.0, 15.0);
	glVertex3f(-15.1, 30.0, 5.0);
	glVertex3f(-15.1, 20.0, 5.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, 20.0, 0.0);
	glVertex3f(-15.1, 30.0, 0.0);
	glVertex3f(-15.1, 30.0, -8.0);
	glVertex3f(-15.1, 20.0, -8.0);
	glEnd();
	//2
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, 5.0, 60.0);
	glVertex3f(-15.1, 15.0, 60.0);
	glVertex3f(-15.1, 15.0, 50.0);
	glVertex3f(-15.1, 5.0, 50.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, 5.0, 45.0);
	glVertex3f(-15.1, 15.0, 45.0);
	glVertex3f(-15.1, 15.0, 35.0);
	glVertex3f(-15.1, 5.0, 35.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, 5.0, 30.0);
	glVertex3f(-15.1, 15.0, 30.0);
	glVertex3f(-15.1, 15.0, 20.0);
	glVertex3f(-15.1, 5.0, 20.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, 5.0, 15.0);
	glVertex3f(-15.1, 15.0, 15.0);
	glVertex3f(-15.1, 15.0, 5.0);
	glVertex3f(-15.1, 5.0, 5.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, 5.0, 0.0);
	glVertex3f(-15.1, 15.0, 0.0);
	glVertex3f(-15.1, 15.0, -8.0);
	glVertex3f(-15.1, 5.0, -8.0);
	glEnd();
	//3
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, -10.0, 60.0);
	glVertex3f(-15.1, 0.0, 60.0);
	glVertex3f(-15.1, 0.0, 50.0);
	glVertex3f(-15.1, -10.0, 50.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, -10, 45.0);
	glVertex3f(-15.1, 0.0, 45.0);
	glVertex3f(-15.1, 0.0, 35.0);
	glVertex3f(-15.1, -10.0, 35.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, -10.0, 30.0);
	glVertex3f(-15.1, 0.0, 30.0);
	glVertex3f(-15.1, 0.0, 20.0);
	glVertex3f(-15.1, -10.0, 20.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, -10.0, 15.0);
	glVertex3f(-15.1, 0.0, 15.0);
	glVertex3f(-15.1, 0.0, 5.0);
	glVertex3f(-15.1, -10.0, 5.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, -10.0, 0.0);
	glVertex3f(-15.1, 0.0, 0.0);
	glVertex3f(-15.1, 0.0, -8.0);
	glVertex3f(-15.1, -10.0, -8.0);
	glEnd();

	//3
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, -10.0, -80.0);
	glVertex3f(-15.1, 0.0, -80.0);
	glVertex3f(-15.1, 0.0, -70.0);
	glVertex3f(-15.1, -10.0, -70.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, -10.0, -95.0);
	glVertex3f(-15.1, 0.0, -95.0);
	glVertex3f(-15.1, 0.0, -85.0);
	glVertex3f(-15.1, -10.0, -85.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, -10.0, -110.0);
	glVertex3f(-15.1, 0.0, -110.0);
	glVertex3f(-15.1, 0.0, -100.0);
	glVertex3f(-15.1, -10.0, -100.0);
	glEnd();
	//2
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, 15.0, -80.0);
	glVertex3f(-15.1, 5.0, -80.0);
	glVertex3f(-15.1, 5.0, -70.0);
	glVertex3f(-15.1, 15.0, -70.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, 15.0, -95.0);
	glVertex3f(-15.1, 5.0, -95.0);
	glVertex3f(-15.1, 5.0, -85.0);
	glVertex3f(-15.1, 15.0, -85.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, 15.0, -110.0);
	glVertex3f(-15.1, 5.0, -110.0);
	glVertex3f(-15.1, 5.0, -100.0);
	glVertex3f(-15.1, 15.0, -100.0);
	glEnd();
	//1
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, 30.0, -80.0);
	glVertex3f(-15.1, 20.0, -80.0);
	glVertex3f(-15.1, 20.0, -70.0);
	glVertex3f(-15.1, 30.0, -70.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, 30.0, -95.0);
	glVertex3f(-15.1, 20.0, -95.0);
	glVertex3f(-15.1, 20.0, -85.0);
	glVertex3f(-15.1, 30.0, -85.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-15.1, 30.0, -110.0);
	glVertex3f(-15.1, 20.0, -110.0);
	glVertex3f(-15.1, 20.0, -100.0);
	glVertex3f(-15.1, 30.0, -100.0);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3f(-20.1, 30.0, -18.0);
	glVertex3f(-20.1, 20.0, -18.0);
	glVertex3f(-20.1, 20.0, -25.0);
	glVertex3f(-20.1, 30.0, -25.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.1, 15.0, -18.0);
	glVertex3f(-20.1, 5.0, -18.0);
	glVertex3f(-20.1, 5.0, -25.0);
	glVertex3f(-20.1, 15.0, -25.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.1, -10.0, -18.0);
	glVertex3f(-20.1, 0.0, -18.0);
	glVertex3f(-20.1, 0.0, -25.0);
	glVertex3f(-20.1, -10.0, -25.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.1, 30.0, -30.0);
	glVertex3f(-20.1, 20.0, -30.0);
	glVertex3f(-20.1, 20.0, -40.0);
	glVertex3f(-20.1, 30.0, -40.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.1, 15.0, -30.0);
	glVertex3f(-20.1, 5.0, -30.0);
	glVertex3f(-20.1, 5.0, -40.0);
	glVertex3f(-20.1, 15.0, -40.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.1, -10.0, -30.0);
	glVertex3f(-20.1, 0.0, -30.0);
	glVertex3f(-20.1, 0.0, -40.0);
	glVertex3f(-20.1, -10.0, -40.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.1, 30.0, -45.0);
	glVertex3f(-20.1, 20.0, -45.0);
	glVertex3f(-20.1, 20.0, -55.0);
	glVertex3f(-20.1, 30.0, -55.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.1, 15.0, -45.0);
	glVertex3f(-20.1, 5.0, -45.0);
	glVertex3f(-20.1, 5.0, -55.0);
	glVertex3f(-20.1, 15.0, -55.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.1, -10.0, -45.0);
	glVertex3f(-20.1, 0.0, -45.0);
	glVertex3f(-20.1, 0.0, -55.0);
	glVertex3f(-20.1, -10.0, -55.0);
	glEnd();
	//belakang sendiri kn
	glBegin(GL_POLYGON);
	glVertex3f(-20.1, -10.0, -125.0);
	glVertex3f(-20.1, 0.0, -125.0);
	glVertex3f(-20.1, 0.0, -135.0);
	glVertex3f(-20.1, -10.0, -135.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.1, 5.0, -125.0);
	glVertex3f(-20.1, 15.0, -125.0);
	glVertex3f(-20.1, 15.0, -135.0);
	glVertex3f(-20.1, 5.0, -135.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.1, 20.0, -125.0);
	glVertex3f(-20.1, 30.0, -125.0);
	glVertex3f(-20.1, 30.0, -135.0);
	glVertex3f(-20.1, 20.0, -135.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-20.1, 5.0, -140.0);
	glVertex3f(-20.1, 15.0, -140.0);
	glVertex3f(-20.1, 15.0, -150.0);
	glVertex3f(-20.1, 5.0, -150.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.1, 20.0, -140.0);
	glVertex3f(-20.1, 30.0, -140.0);
	glVertex3f(-20.1, 30.0, -150.0);
	glVertex3f(-20.1, 20.0, -150.0);
	glEnd();

	//depan sendiri
	glBegin(GL_POLYGON);
	glVertex3f(-20.1, 20.0, 110.0);
	glVertex3f(-20.1, 30.0, 105.0);
	glVertex3f(-20.1, 30.0, 95.0);
	glVertex3f(-20.1, 20.0, 95.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.1, 5.0, 120.0);
	glVertex3f(-20.1, 15.0, 115.0);
	glVertex3f(-20.1, 15.0, 95.0);
	glVertex3f(-20.1, 5.0, 95.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.1, -5.0, 120.0);
	glVertex3f(-20.1, 0.0, 120.0);
	glVertex3f(-20.1, 0.0, 95.0);
	glVertex3f(-20.1, -5.0, 95.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-20.1, 20.0, 90.0);
	glVertex3f(-20.1, 30.0, 90.0);
	glVertex3f(-20.1, 30.0, 80.0);
	glVertex3f(-20.1, 20.0, 80.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.1, 5.0, 90.0);
	glVertex3f(-20.1, 15.0, 90.0);
	glVertex3f(-20.1, 15.0, 80.0);
	glVertex3f(-20.1, 5.0, 80.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.1, -10.0, 90.0);
	glVertex3f(-20.1, 0.0, 90.0);
	glVertex3f(-20.1, 0.0, 80.0);
	glVertex3f(-20.1, -10.0, 80.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-20.1, 20.0, 77.0);
	glVertex3f(-20.1, 30.0, 77.0);
	glVertex3f(-20.1, 30.0, 70.0);
	glVertex3f(-20.1, 20.0, 70.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.1, 5.0, 77.0);
	glVertex3f(-20.1, 15.0, 77.0);
	glVertex3f(-20.1, 15.0, 70.0);
	glVertex3f(-20.1, 5.0, 70.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-20.1, -10.0, 77.0);
	glVertex3f(-20.1, 0.0, 77.0);
	glVertex3f(-20.1, 0.0, 70.0);
	glVertex3f(-20.1, -10.0, 70.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(15.1, 20.0, 60.0);
	glVertex3f(15.1, 30.0, 60.0);
	glVertex3f(15.1, 30.0, 50.0);
	glVertex3f(15.1, 20.0, 50.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.1, 20.0, 45.0);
	glVertex3f(15.1, 30.0, 45.0);
	glVertex3f(15.1, 30.0, 35.0);
	glVertex3f(15.1, 20.0, 35.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.1, 20.0, 30.0);
	glVertex3f(15.1, 30.0, 30.0);
	glVertex3f(15.1, 30.0, 20.0);
	glVertex3f(15.1, 20.0, 20.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.1, 20.0, 15.0);
	glVertex3f(15.1, 30.0, 15.0);
	glVertex3f(15.1, 30.0, 5.0);
	glVertex3f(15.1, 20.0, 5.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.1, 20.0, 0.0);
	glVertex3f(15.1, 30.0, 0.0);
	glVertex3f(15.1, 30.0, -8.0);
	glVertex3f(15.1, 20.0, -8.0);
	glEnd();
	//2
	glBegin(GL_POLYGON);
	glVertex3f(15.1, 5.0, 60.0);
	glVertex3f(15.1, 15.0, 60.0);
	glVertex3f(15.1, 15.0, 50.0);
	glVertex3f(15.1, 5.0, 50.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.1, 5.0, 45.0);
	glVertex3f(15.1, 15.0, 45.0);
	glVertex3f(15.1, 15.0, 35.0);
	glVertex3f(15.1, 5.0, 35.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.1, 5.0, 30.0);
	glVertex3f(15.1, 15.0, 30.0);
	glVertex3f(15.1, 15.0, 20.0);
	glVertex3f(15.1, 5.0, 20.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.1, 5.0, 15.0);
	glVertex3f(15.1, 15.0, 15.0);
	glVertex3f(15.1, 15.0, 5.0);
	glVertex3f(15.1, 5.0, 5.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.1, 5.0, 0.0);
	glVertex3f(15.1, 15.0, 0.0);
	glVertex3f(15.1, 15.0, -8.0);
	glVertex3f(15.1, 5.0, -8.0);
	glEnd();
	//3
	glBegin(GL_POLYGON);
	glVertex3f(15.1, -10.0, 60.0);
	glVertex3f(15.1, 0.0, 60.0);
	glVertex3f(15.1, 0.0, 50.0);
	glVertex3f(15.1, -10.0, 50.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.1, -10, 45.0);
	glVertex3f(15.1, 0.0, 45.0);
	glVertex3f(15.1, 0.0, 35.0);
	glVertex3f(15.1, -10.0, 35.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.1, -10.0, 30.0);
	glVertex3f(15.1, 0.0, 30.0);
	glVertex3f(15.1, 0.0, 20.0);
	glVertex3f(15.1, -10.0, 20.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.1, -10.0, 15.0);
	glVertex3f(15.1, 0.0, 15.0);
	glVertex3f(15.1, 0.0, 5.0);
	glVertex3f(15.1, -10.0, 5.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.1, -10.0, 0.0);
	glVertex3f(15.1, 0.0, 0.0);
	glVertex3f(15.1, 0.0, -8.0);
	glVertex3f(15.1, -10.0, -8.0);
	glEnd();

	//3
	glBegin(GL_POLYGON);
	glVertex3f(15.1, -10.0, -80.0);
	glVertex3f(15.1, 0.0, -80.0);
	glVertex3f(15.1, 0.0, -70.0);
	glVertex3f(15.1, -10.0, -70.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.1, -10.0, -95.0);
	glVertex3f(15.1, 0.0, -95.0);
	glVertex3f(15.1, 0.0, -85.0);
	glVertex3f(15.1, -10.0, -85.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.1, -10.0, -110.0);
	glVertex3f(15.1, 0.0, -110.0);
	glVertex3f(15.1, 0.0, -100.0);
	glVertex3f(15.1, -10.0, -100.0);
	glEnd();
	//2
	glBegin(GL_POLYGON);
	glVertex3f(15.1, 15.0, -80.0);
	glVertex3f(15.1, 5.0, -80.0);
	glVertex3f(15.1, 5.0, -70.0);
	glVertex3f(15.1, 15.0, -70.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.1, 15.0, -95.0);
	glVertex3f(15.1, 5.0, -95.0);
	glVertex3f(15.1, 5.0, -85.0);
	glVertex3f(15.1, 15.0, -85.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.1, 15.0, -110.0);
	glVertex3f(15.1, 5.0, -110.0);
	glVertex3f(15.1, 5.0, -100.0);
	glVertex3f(15.1, 15.0, -100.0);
	glEnd();
	//1
	glBegin(GL_POLYGON);
	glVertex3f(15.1, 30.0, -80.0);
	glVertex3f(15.1, 20.0, -80.0);
	glVertex3f(15.1, 20.0, -70.0);
	glVertex3f(15.1, 30.0, -70.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.1, 30.0, -95.0);
	glVertex3f(15.1, 20.0, -95.0);
	glVertex3f(15.1, 20.0, -85.0);
	glVertex3f(15.1, 30.0, -85.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(15.1, 30.0, -110.0);
	glVertex3f(15.1, 20.0, -110.0);
	glVertex3f(15.1, 20.0, -100.0);
	glVertex3f(15.1, 30.0, -100.0);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3f(20.1, 30.0, -18.0);
	glVertex3f(20.1, 20.0, -18.0);
	glVertex3f(20.1, 20.0, -25.0);
	glVertex3f(20.1, 30.0, -25.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.1, 15.0, -18.0);
	glVertex3f(20.1, 5.0, -18.0);
	glVertex3f(20.1, 5.0, -25.0);
	glVertex3f(20.1, 15.0, -25.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.1, -10.0, -18.0);
	glVertex3f(20.1, 0.0, -18.0);
	glVertex3f(20.1, 0.0, -25.0);
	glVertex3f(20.1, -10.0, -25.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.1, 30.0, -30.0);
	glVertex3f(20.1, 20.0, -30.0);
	glVertex3f(20.1, 20.0, -40.0);
	glVertex3f(20.1, 30.0, -40.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.1, 15.0, -30.0);
	glVertex3f(20.1, 5.0, -30.0);
	glVertex3f(20.1, 5.0, -40.0);
	glVertex3f(20.1, 15.0, -40.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.1, -10.0, -30.0);
	glVertex3f(20.1, 0.0, -30.0);
	glVertex3f(20.1, 0.0, -40.0);
	glVertex3f(20.1, -10.0, -40.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.1, 30.0, -45.0);
	glVertex3f(20.1, 20.0, -45.0);
	glVertex3f(20.1, 20.0, -55.0);
	glVertex3f(20.1, 30.0, -55.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.1, 15.0, -45.0);
	glVertex3f(20.1, 5.0, -45.0);
	glVertex3f(20.1, 5.0, -55.0);
	glVertex3f(20.1, 15.0, -55.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.1, -10.0, -45.0);
	glVertex3f(20.1, 0.0, -45.0);
	glVertex3f(20.1, 0.0, -55.0);
	glVertex3f(20.1, -10.0, -55.0);
	glEnd();
	//belakang sendiri kn
	glBegin(GL_POLYGON);
	glVertex3f(20.1, -10.0, -125.0);
	glVertex3f(20.1, 0.0, -125.0);
	glVertex3f(20.1, 0.0, -135.0);
	glVertex3f(20.1, -10.0, -135.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.1, 5.0, -125.0);
	glVertex3f(20.1, 15.0, -125.0);
	glVertex3f(20.1, 15.0, -135.0);
	glVertex3f(20.1, 5.0, -135.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.1, 20.0, -125.0);
	glVertex3f(20.1, 30.0, -125.0);
	glVertex3f(20.1, 30.0, -135.0);
	glVertex3f(20.1, 20.0, -135.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(20.1, 5.0, -140.0);
	glVertex3f(20.1, 15.0, -140.0);
	glVertex3f(20.1, 15.0, -150.0);
	glVertex3f(20.1, 5.0, -150.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.1, 20.0, -140.0);
	glVertex3f(20.1, 30.0, -140.0);
	glVertex3f(20.1, 30.0, -150.0);
	glVertex3f(20.1, 20.0, -150.0);
	glEnd();

	//depan sendiri
	glBegin(GL_POLYGON);
	glVertex3f(20.1, 20.0, 110.0);
	glVertex3f(20.1, 30.0, 105.0);
	glVertex3f(20.1, 30.0, 95.0);
	glVertex3f(20.1, 20.0, 95.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.1, 5.0, 120.0);
	glVertex3f(20.1, 15.0, 115.0);
	glVertex3f(20.1, 15.0, 95.0);
	glVertex3f(20.1, 5.0, 95.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.1, -5.0, 120.0);
	glVertex3f(20.1, 0.0, 120.0);
	glVertex3f(20.1, 0.0, 95.0);
	glVertex3f(20.1, -5.0, 95.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(20.1, 20.0, 90.0);
	glVertex3f(20.1, 30.0, 90.0);
	glVertex3f(20.1, 30.0, 80.0);
	glVertex3f(20.1, 20.0, 80.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.1, 5.0, 90.0);
	glVertex3f(20.1, 15.0, 90.0);
	glVertex3f(20.1, 15.0, 80.0);
	glVertex3f(20.1, 5.0, 80.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.1, -10.0, 90.0);
	glVertex3f(20.1, 0.0, 90.0);
	glVertex3f(20.1, 0.0, 80.0);
	glVertex3f(20.1, -10.0, 80.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(20.1, 20.0, 77.0);
	glVertex3f(20.1, 30.0, 77.0);
	glVertex3f(20.1, 30.0, 70.0);
	glVertex3f(20.1, 20.0, 70.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.1, 5.0, 77.0);
	glVertex3f(20.1, 15.0, 77.0);
	glVertex3f(20.1, 15.0, 70.0);
	glVertex3f(20.1, 5.0, 70.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(20.1, -10.0, 77.0);
	glVertex3f(20.1, 0.0, 77.0);
	glVertex3f(20.1, 0.0, 70.0);
	glVertex3f(20.1, -10.0, 70.0);
	glEnd();

	//belakang
	glBegin(GL_QUADS);
	glVertex3f(-18.0, 20.0, -154.0);
	glVertex3f(-13.0, 20.0, -154.0);
	glVertex3f(-13.0, 34.0, -150.0);
	glVertex3f(-18.0, 34.0, -150.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-8.0, 20.0, -154.0);
	glVertex3f(-3.0, 20.0, -154.0);
	glVertex3f(-3.0, 34.0, -150.0);
	glVertex3f(-8.0, 34.0, -150.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(2.0, 20.0, -154.0);
	glVertex3f(7.0, 20.0, -154.0);
	glVertex3f(7.0, 34.0, -150.0);
	glVertex3f(2.0, 34.0, -150.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(12.0, 20.0, -154.0);
	glVertex3f(17.0, 20.0, -154.0);
	glVertex3f(17.0, 34.0, -150.0);
	glVertex3f(12.0, 34.0, -150.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-18.0, 8.0, -157.0);
	glVertex3f(-13.0, 8.0, -157.0);
	glVertex3f(-13.0, 15.0, -155.0);
	glVertex3f(-18.0, 15.0, -155.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-8.0, 8.0, -157.0);
	glVertex3f(-3.0, 8.0, -157.0);
	glVertex3f(-3.0, 15.0, -155.0);
	glVertex3f(-8.0, 15.0, -155.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(2.0, 8.0, -157.0);
	glVertex3f(7.0, 8.0, -157.0);
	glVertex3f(7.0, 15.0, -155.0);
	glVertex3f(2.0, 15.0, -155.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(12.0, 8.0, -157.0);
	glVertex3f(17.0, 8.0, -157.0);
	glVertex3f(17.0, 15.0, -155.0);
	glVertex3f(12.0, 15.0, -155.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-18.0, -1.0, -159.5);
	glVertex3f(-13.0, -1.0, -159.5);
	glVertex3f(-13.0, 6.0, -157.0);
	glVertex3f(-18.0, 6.0, -157.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-8.0, -1.0, -159.5);
	glVertex3f(-3.0, -1.0, -159.5);
	glVertex3f(-3.0, 6.0, -157.0);
	glVertex3f(-8.0, 6.0, -157.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(2.0, -1.0, -159.5);
	glVertex3f(7.0, -1.0, -159.5);
	glVertex3f(7.0, 6.0, -157.0);
	glVertex3f(2.0, 6.0, -157.0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(12.0, -1.0, -159.5);
	glVertex3f(17.0, -1.0, -159.5);
	glVertex3f(17.0, 6.0, -157.0);
	glVertex3f(12.0, 6.0, -157.0);
	glEnd();

}
void pelampung(double r, int vertex) {
	double ngon = (double)vertex;
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.0);
	for (int y = -2; y >= -4.5; y--) {
		for (int i = 0; i < vertex; i++) {
			double x = r * cos(2 * M_PI * i / ngon);
			double z = ((r + (i * 0.05)) * sin(2 * M_PI * i / ngon)) + 160;
			glVertex3d(x, y, z);
		}

	}
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	for (int y = -1.9; y >= -4.5; y--) {
		for (int i = 0; i < vertex; i++) {
			double x = (r - 2) * cos(2 * M_PI * i / ngon);
			double z = (((r - 2) + (i * 0.05)) * sin(2 * M_PI * i / ngon)) + 160;
			glVertex3d(x, y, z);
		}

	}
	glEnd();
}
void hujan(void) 
{
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.9);
	glVertex3f(-30.0, 80 - ypos, -20);
	glVertex3f(-32.0, 80 - ypos, -20);
	glVertex3f(-32.0, 80 -4 - ypos, -20);
	glVertex3f(-30.0, 80 -4 - ypos, -20);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.9);
	glVertex3f(-30.0 - 10, y - ypos, -10);
	glVertex3f(-32.0 - 10, y - ypos, -10);
	glVertex3f(-32.0 - 10, y - 4 - ypos, -10);
	glVertex3f(-30.0 - 10, y - 4 - ypos, -10);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.9);
	glVertex3f(-30.0 - 10, 75 - ypos, +20);
	glVertex3f(-32.0 - 10, 75 - ypos, +20);
	glVertex3f(-32.0 - 10, 75 - 4 - ypos, +20);
	glVertex3f(-30.0 - 10, 75 - 4 - ypos, +20);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.9);
	glVertex3f(-30.0 + 20, y - ypos, 5);
	glVertex3f(-32.0 + 20, y - ypos, 5);
	glVertex3f(-32.0 + 20, y - 4 - ypos, 5);
	glVertex3f(-30.0 + 20, y - 4 - ypos, 5);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.9);
	glVertex3f(-30.0+25, 100 - ypos, 30);
	glVertex3f(-32.0 + 25, 100 - ypos, 30);
	glVertex3f(-32.0 + 25, 100 - 4 - ypos, 30);
	glVertex3f(-30.0 + 25, 100 - 4 - ypos, 30);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.9);
	glVertex3f(-30.0+34, y - ypos, 34);
	glVertex3f(-32.0 + 34, y - ypos, 34);
	glVertex3f(-32.0 + 34, y - 4 - ypos, 34);
	glVertex3f(-30.0 + 34, y - 4 - ypos, 34);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.9);
	glVertex3f(-30.0 + 34, 110 - ypos, 45);
	glVertex3f(-32.0 + 34, 110 - ypos, 45);
	glVertex3f(-32.0 + 34, 110 - 4 - ypos, 45);
	glVertex3f(-30.0 + 34, 110 - 4 - ypos, 45);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.9);
	glVertex3f(-30.0, y - ypos, -30);
	glVertex3f(-32.0, y - ypos, -30);
	glVertex3f(-32.0, y - 4 - ypos, -30);
	glVertex3f(-30.0, y - 4 - ypos, -30);
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.9);
	glVertex3f(-30.0, y - ypos, -40);
	glVertex3f(-32.0, y - ypos, -40);
	glVertex3f(-32.0, y - 4 - ypos, -40);
	glVertex3f(-30.0, y - 4 - ypos, -40);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.9);
	glVertex3f(-30.0, y - ypos, 14);
	glVertex3f(-32.0, y - ypos, 14);
	glVertex3f(-32.0, y - 4 - ypos, 14);
	glVertex3f(-30.0, y - 4 - ypos, 14);
	glEnd();
	
}
void set_triangle() {
	point p1(-10, -15);
	point p2(-10, -20);
	point p3(-10, -15);
	triangle t1(p1, p2, p3);
	point p4(15, 15);
	point p5(10, -10);
	point p6(15, 15);
	triangle t2(p4, p5, p6);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < t1.get_triangle_size(); i++) {
		glVertex2f(t1.tri[i].x, t1.tri[i].y);
	}
	glEnd();
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < t1.get_triangle_size(); i++) {
		glVertex2f(t2.tri[i].x, t2.tri[i].y);
	}
	glEnd();
	tween(t1, t2);
}
void tween(triangle t1, triangle t2) {
	glBegin(GL_TRIANGLES);
	for (float i = 0; i <= 1; i = i + 0.4) {
		for (float j = 0; j < t1.get_triangle_size(); j++) {
			float x = t1.tri[j].x + (t2.tri[j].x - t1.tri[j].x) * i;
			float y = t1.tri[j].y + (t2.tri[j].y - t1.tri[j].y) * i;
			glVertex2f(x, y);
		}
	}
	glEnd();
}
void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 20, timer, 0);
	ypos += delta;
	
}
