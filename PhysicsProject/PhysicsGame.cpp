#include "PhysicsGame.h"
#include "Input.h"
#include "Font.h"
#include "Gizmos.h"
#include <glm/ext.hpp>

bool PhysicsGame::startup()
{



	m_renderer = new aie::Renderer2D();
	setBackgroundColour(0.55f, 0.13f, 0.42f, 1.0f);

	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void PhysicsGame::shutdown()
{
	delete m_font;
	delete m_renderer;
}

void PhysicsGame::update(float deltaTime)
{
	//Get the input instance
	aie::Input* input = aie::Input::getInstance();

	//Exit on Esc
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{			    	quit();					}
}

void PhysicsGame::draw()
{
	clearScreen();

	m_renderer->begin();
	m_renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

	//Draw FPS
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_renderer->drawText(m_font, fps, 0.0f, 720.0f - 32.0f);

	m_renderer->end();
}
