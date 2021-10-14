#include "World.h"

void World::start()
{
	onStart();
	m_started = true;
}

void World::update(float deltaTime)
{
	if (!m_started) {
		start();
	}

	onUpdate(deltaTime);

	//Update the list of entities
	for (Entity* entity : addList) {
		entities.push_back(entity);
	}
	addList.clear();
	entities.unique();
	for (Entity* entity : removeList) {
		entities.remove(entity);
	}
	removeList.clear();
	for (Entity* entity : destroyList) {
		entities.remove(entity);
		delete entity;
	}
	destroyList.clear();

	//Update the entities
	for (Entity* entity : entities) {
		entity->update(deltaTime);
	}
}

void World::draw()
{
	onDraw();

	for (Entity* entity : entities) {
		entity->draw();
	}
}

void World::end()
{
	onEnd();
}

void World::add(Entity* entity)
{
	removeList.remove(entity);
	addList.push_back(entity);
}

void World::remove(Entity* entity)
{
	addList.remove(entity);
	removeList.push_back(entity);
}

void World::destroy(Entity* entity)
{
	addList.remove(entity);
	removeList.remove(entity);
	destroyList.push_back(entity);
}
