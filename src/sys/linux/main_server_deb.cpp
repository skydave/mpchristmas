//============================================================================
//
//
//
//============================================================================
#include <stdio.h>
#include <cstdlib>

#define XRES 640
#define YRES 480



#include <GL/gl.h>
#include <GL/glut.h>
/*

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// GLUT application code
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void glutPrint(float x, float y, void* font, const char* text, float r, float g, float b, float a)
{

	if(!text || !strlen(text)) return;

	glColor4f(r,g,b,a);

	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glRasterPos2f(x,y);
	while (*text)
	{
		glutBitmapCharacter(font, *text);
		text++;
	}
}
*/


void initGL()
{
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

	glShadeModel(GL_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glHint(GL_LINE_SMOOTH_HINT,GL_NICEST);
}

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//gluPerspective(45, (float)width/height, camera->m_near, camera->m_far);
	gluPerspective(45, (float)width/height, 0.01f, 10000.0f);
}

void display()
{
	glClearColor(.8,0.8,0.8,1);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

//    camera->setProjection();
//    consoleInterface->updateVars();


	glPopMatrix();


	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho (0, XRES, 0, YRES, 0, 1);


//    glutPrint(10, 10, GLUT_BITMAP_HELVETICA_12, frame.getStatus().c_str(), 1, 1, 1, 0.75);
	glPopMatrix();

	glutPostRedisplay();
	glutSwapBuffers();
}


void keydown(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: //ESC
		exit(0);
		break;
	default:
		break;
	}

	glutPostRedisplay();
}


void idle()
{
	glutPostRedisplay();
}

void processMouse(int button, int state, int x, int y)
{
	specialKey = glutGetModifiers();
	lastx = x;
	lasty = y;

	switch(button)
	{
	case GLUT_LEFT_BUTTON:      Buttons[0] = ((GLUT_DOWN==state)?1:0); break;
	case GLUT_MIDDLE_BUTTON:    Buttons[1] = ((GLUT_DOWN==state)?1:0); break;
	case GLUT_RIGHT_BUTTON:     Buttons[2] = ((GLUT_DOWN==state)?1:0); break;
	default: break;
	}

	glutPostRedisplay();
}

void processMouseEntry(int state)
{
	glutPostRedisplay();
}

void processMousePassiveMotion(int x, int y)
{
	glutPostRedisplay();
}

void processMouseActiveMotion(int x, int y)
{
	// update camera
	glutPostRedisplay();
}


int main(int argc, char ** argv)
{

	// Initialize GLUT
	glutInit(&argc, argv);

	//glutInitDisplayString("rgba alpha double samples>=4");
	glutInitWindowSize(XRES, YRES);
	glutCreateWindow("mpchristmas");


	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keydown);
	glutMouseFunc(processMouse);
	glutSpecialFunc(specialKeydown);
	glutMotionFunc(processMouseActiveMotion);
	glutPassiveMotionFunc(processMousePassiveMotion);
	glutEntryFunc(processMouseEntry);
	glutIdleFunc(idle);



	initGL();

	glutMainLoop();
	return 0;
}

