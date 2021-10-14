#include "Entity.h"

Entity::Entity()
{
	m_transform = new Transform();
}

Entity::~Entity()
{
	delete m_transform;
}

void Entity::start()
{
	onStart();
	m_started = true;
}

void Entity::update(float deltaTime)
{
	if (!m_started)
		start();

	onUpdate(deltaTime);
}

void Entity::draw()
{
	onDraw();
}

void Entity::end()
{
	onEnd();
	m_started = false;
}
