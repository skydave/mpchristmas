#include "Game.h"

#include <iostream>

#include <GL/gl.h>
#include <GL/glut.h>

//
// renders the game world
//
void Game::render()
{
	int xres = glutGet(GLUT_SCREEN_WIDTH);
	int yres = glutGet(GLUT_SCREEN_HEIGHT);

	// render background
	glClearColor(.8,0.8,0.8,1);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

//    camera->setProjection();
//    consoleInterface->updateVars();



	// render environment

	// render players
	for( std::map<int, Player *>::iterator it = m_state.m_players.begin(); it != m_state.m_players.end(); ++it )
	{
		renderPlayer( it->second );
	}




	glPopMatrix();


	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho (0, xres, 0, yres, 0, 1);


//    glutPrint(10, 10, GLUT_BITMAP_HELVETICA_12, frame.getStatus().c_str(), 1, 1, 1, 0.75);
	glPopMatrix();






}



void Game::renderPlayer( Player* )
{
	glColor3f(1.0f,0.0f,0.0f);
	glutSolidSphere(2.5, 50, 40);
}
