#include "Engine.h"

Engine::Engine()
{
}

Engine::~Engine()
{
}

int Engine::run()
{
	int exitCode = 0;

	exitCode = start();
	if (exitCode != 0)
		return exitCode;

	exitCode = update();
	if (exitCode != 0)
		return exitCode;

	return 0;
}

int Engine::start()
{
	return 0;
}

int Engine::update()
{
	return 0;
}

int Engine::end()
{
	return 0;
}

bool Engine::engineWindowShouldClose()
{
	bool condition = glfwWindowShouldClose(m_window);
	condition = condition || glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS;

	return condition;
}
