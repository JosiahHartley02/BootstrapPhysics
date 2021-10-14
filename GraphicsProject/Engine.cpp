#include "Engine.h"
#include "gl_core_4_4.h"
#include "GLFW/glfw3.h"
#include "glm/ext.hpp"
#include <iostream>

Engine::Engine() : Engine(1280, 720, "Window")
{
}

Engine::Engine(int width, int height, const char* title)
{
	m_width = width;
	m_height = height;
	m_title = title;

	m_shader = new aie::ShaderProgram();
}

Engine::~Engine()
{
}

int Engine::run()
{
	int exitCode = 0;

	//Check for active world
	if (!m_activeWorld) {
		return exitCode = 1;
	}

	//Start
	exitCode = start();
	if (exitCode) {
		return exitCode;
	}

	double deltaTime = 0.0f;
	double timeOfPreviousUpdate = 0.0;

	//Update and draw
	while (!getGameOver()) {
		//Get the current time
		double timeOfCurrentUpdate = glfwGetTime();
		//Find the change in time
		deltaTime = timeOfCurrentUpdate - timeOfPreviousUpdate;
		//Store the current time for the next loop
		timeOfPreviousUpdate = timeOfCurrentUpdate;

		exitCode = update(deltaTime);
		if (exitCode) {
			return exitCode;
		}

		exitCode = draw();
		if (exitCode) {
			return exitCode;
		}
	}

	//End
	exitCode = end();
	if (exitCode) {
		return exitCode;
	}

	return 0;
}

int Engine::start()
{
	//Initialize GLFW
	if (glfwInit() == GLFW_FALSE) {
		return -1;
	}

	//Create a window
	m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
	if (!m_window) {
		glfwTerminate();
		return -2;
	}
	glfwMakeContextCurrent(m_window);

	//Load OpenGL
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) {
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return -3;
	}
	int majorVersion = ogl_GetMajorVersion();
	int minorVersion = ogl_GetMinorVersion();
	printf("OpenGL version %i.%i\n", majorVersion, minorVersion);

	//Initialize the screen
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glEnable(GL_DEPTH_TEST);

	//Initialize the shader
	m_shader->loadShader(
		aie::eShaderStage::VERTEX,
		"vertex.shader"
	);
	m_shader->loadShader(
		aie::eShaderStage::FRAGMENT,
		"fragment.shader"
	);
	if (!m_shader->link()) {
		printf("Shader Error: %s\n", m_shader->getLastError());
		return -10;
	}

	return 0;
}

int Engine::update(float deltaTime)
{
	if (!m_window) return -4;

	glfwPollEvents();

	m_activeWorld->update(deltaTime);

	return 0;
}

int Engine::draw()
{
	if (!m_window) return -5;

	//Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_shader->bind();

	Camera* camera = m_activeWorld->getCamera();

	m_projectionMatrix = glm::perspective(
		camera->getFieldOfView() * glm::pi<float>() / 180.0f,
		(float)m_width / (float)m_height,
		camera->getNearClip(),
		camera->getFarClip()
	);
	glm::mat4 projectionViewMatrix = m_projectionMatrix * camera->getTransform()->getGlobalMatrix();
	m_shader->bindUniform("projectionViewMatrix", projectionViewMatrix);
	m_shader->bindUniform("cameraPosition", camera->getTransform()->getPosition());

	m_activeWorld->draw();

	glfwSwapBuffers(m_window);

	return 0;
}

int Engine::end()
{
	if (!m_window) return -6;

	m_activeWorld->end();

	glfwDestroyWindow(m_window);
	glfwTerminate();
	return 0;
}

bool Engine::getGameOver()
{
	if (!m_window) return true;

	bool gameIsOver = glfwWindowShouldClose(m_window);
	gameIsOver = gameIsOver || glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS;

	return gameIsOver;
}
