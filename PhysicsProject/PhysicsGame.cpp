#include "PhysicsGame.h"
#include "Sphere.h"
#include "Plane.h"
#include "Input.h"
#include "Font.h"
#include "Gizmos.h"
#include <glm/ext.hpp>

bool PhysicsGame::startup()
{
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	m_renderer = new aie::Renderer2D();
	setBackgroundColour(0.2f, 0.5f, 0.42f, 1.0f);

	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_scene = new PhysicsScene();
	m_scene->setTimeStep(0.001f);
	m_scene->setGravity({0.0f,0.0f});

	Plane* bottomSurface = new Plane(glm::vec2(0.0f, 1.0f), -50.0f, glm::vec4(0.2f, 0.8f, 0.2f, 1.0f));
	m_scene->addActor(bottomSurface);

	Plane* topSurface = new Plane(glm::vec2(0.0f, -1.0f), -50.0f, glm::vec4(0.2f, 0.8f, 0.2f, 1.0f));
	m_scene->addActor(topSurface);

	Plane* leftSurface = new Plane(glm::vec2(1.0f, 0.0f), -90, glm::vec4(0.2f, 0.8f, 0.2f, 1.0f));
	m_scene->addActor(leftSurface);

	Plane* rightSurface = new Plane(glm::vec2(-1.0f, 0.0f), -90, glm::vec4(0.2f, 0.8f, 0.2f, 1.0f));
	m_scene->addActor(rightSurface);



	Sphere* cueBall = new Sphere(glm::vec2(0, -40), glm::vec2(), 5, 1, glm::vec4(0.8f, 0.8f, 0.8f, 1.0f));
	m_scene->addActor(cueBall);
	cueBall->applyForce(glm::vec2(0.0f, 100.0f));

	Sphere* billiardBall = new Sphere(glm::vec2(0.0f, -1.5f), glm::vec2(), 1, 1, glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	m_scene->addActor(billiardBall);

	Sphere* billiardBall1 = new Sphere(glm::vec2(1.25f, 0.25f), glm::vec2(), 1, 1, glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	m_scene->addActor(billiardBall1);
	Sphere* billiardBall2 = new Sphere(glm::vec2(-1.25f, 0.25f), glm::vec2(), 1, 1, glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	m_scene->addActor(billiardBall2);

	Sphere* billiardBall3 = new Sphere(glm::vec2(2.60f, 2.0f), glm::vec2(), 1, 1, glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	m_scene->addActor(billiardBall3);
	Sphere* billiardBall4 = new Sphere(glm::vec2(0.0f, 2.0f), glm::vec2(), 1, 1, glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	m_scene->addActor(billiardBall4);
	Sphere* billiardBall5 = new Sphere(glm::vec2(-2.60f, 2.0f), glm::vec2(), 1, 1, glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	m_scene->addActor(billiardBall5);

	Sphere* billiardBall6 = new Sphere(glm::vec2(-4.75f, 4.25f), glm::vec2(), 1, 1, glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	m_scene->addActor(billiardBall6);
	Sphere* billiardBall7 = new Sphere(glm::vec2(2.60f, 4.25f), glm::vec2(), 1, 1, glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	m_scene->addActor(billiardBall7);
	Sphere* billiardBall8 = new Sphere(glm::vec2(0.0f, 4.25f), glm::vec2(), 1, 1, glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	m_scene->addActor(billiardBall8);
	Sphere* billiardBall9 = new Sphere(glm::vec2(-2.60f, 4.25f), glm::vec2(), 1, 1, glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	m_scene->addActor(billiardBall9);

	return true;
}

void PhysicsGame::shutdown()
{
	delete m_font;
	delete m_renderer;
	delete m_scene;
}

void PhysicsGame::update(float deltaTime)
{
	//Get the input instance
	aie::Input* input = aie::Input::getInstance();

	aie::Gizmos::clear();

	m_scene->update(deltaTime);

	//Exit on Esc
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{			    	quit();					}
	//CHAOS

	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		m_scene->setGravity(glm::vec2(0, 100));
	}
	else if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		m_scene->setGravity(glm::vec2(0, -100));
	}
	else if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		m_scene->setGravity(glm::vec2(-100, 0));
	}
	else if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		m_scene->setGravity(glm::vec2(100, 0));
	}
	else
		m_scene->setGravity(glm::vec2(0, 0));
}

void PhysicsGame::draw()
{
	clearScreen();

	m_renderer->begin();

	//Draw the scene first
	m_scene->draw();

	//Draw the Gizmos
	static float aspectRatio = 16.0f / 9.0f;
	aie::Gizmos::draw2D(glm::ortho<float>(
		-100,				//left
		100,				//right
		-100 / aspectRatio, //Bottom 
		100 / aspectRatio,  //Top
		-1.0f,				//zNear
		1.0f)				//zFar
	);

	//Draw FPS last to act as an overlay
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
	m_renderer->drawText(m_font, fps, 0.0f, 720.0f - 32.0f);

	m_renderer->end();
}
