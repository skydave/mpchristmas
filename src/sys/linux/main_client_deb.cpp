//============================================================================
//
//
//
//============================================================================
#include <stdio.h>
#include <cstdlib>

#include "../../Client.h"


#define XRES 640
#define YRES 480



#include <GL/gl.h>
#include <GL/glut.h>








Client g_client;






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
	g_client.m_game.render();
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

void specialKeydown(int key, int, int )
{
	/*
	if( consoleInterface->getConsole().IsOpen() )
	{
		consoleInterface->getConsole().SpecialFunc( key );
	}
	*/
}


void idle()
{
	g_client.update();
	glutPostRedisplay();
}

void processMouse(int button, int state, int x, int y)
{

	/*
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
*/
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



	g_client.init();

	glutMainLoop();

	g_client.shutdown();
	return 0;
}

