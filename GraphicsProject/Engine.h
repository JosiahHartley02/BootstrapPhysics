#pragma once
#include "Shader.h"
#include "World.h"

struct GLFWwindow;

class Engine
{
public:
	Engine();
	Engine(int width, int height, const char* title);
	~Engine();

	int run();

	World* getActiveWorld() { return m_activeWorld; }
	void setActiveWorld(World* world) { m_activeWorld = world; }

private:
	int start();
	int update(float deltaTime);
	int draw();
	int end();

	bool getGameOver();

private:
	GLFWwindow* m_window = nullptr;
	int m_width, m_height;
	const char* m_title;

	glm::mat4 m_projectionMatrix = glm::mat4(1.0f);

	aie::ShaderProgram* m_shader = nullptr;

	World* m_activeWorld = nullptr;
};

