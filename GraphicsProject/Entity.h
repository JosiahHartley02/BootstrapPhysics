#pragma once
#include "Transform.h"
#include "Shader.h"
#include "glm\mat4x4.hpp"

class Entity
{
public:
	Entity();
	~Entity();

	void start();
	void update(float deltaTime);
	void draw();
	void end();

	virtual void onStart() {};
	virtual void onUpdate(float deltaTime) {};
	virtual void onDraw() {};
	virtual void onEnd() {};

	Transform* getTransform() { return m_transform; }

private:
	Transform* m_transform = nullptr;

	bool m_started = false;
};

