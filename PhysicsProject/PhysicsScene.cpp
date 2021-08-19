#include "PhysicsScene.h"
#include "PhysicsObject.h"
#include "Sphere.h"

PhysicsScene::PhysicsScene() : m_timeStep(0.01f), m_gravity(glm::vec2(0,0))
{

}

PhysicsScene::~PhysicsScene()
{

}

void PhysicsScene::addActor(PhysicsObject* actor)
{
	m_actors.insert(actor);
}

void PhysicsScene::removeActor(PhysicsObject* actor)
{
	m_actors.erase(actor);
}

void PhysicsScene::update(float deltaTime)
{
	static float accumulatedTime = 0.0f;
	accumulatedTime += deltaTime;

	//As long as there is enough accumulated time for a fixedUpdate...
	while (accumulatedTime >= m_timeStep)
	{
		//...call each actor's fixedUpdate
		for (PhysicsObject* actor : m_actors)
		{
			actor->fixedUpdate(m_gravity, m_timeStep);
		}
		accumulatedTime -= m_timeStep;

		auto outerEnd = m_actors.end();
		outerEnd--;
		for (auto outer = m_actors.begin(); outer != outerEnd; outer++) {
			auto innerBegin = outer;
			innerBegin++;
			for (auto inner = innerBegin; inner != m_actors.end(); inner++) {
				PhysicsObject* object1 = *outer;
				PhysicsObject* object2 = *inner;

				//Collision Check
				sphereToSphere(dynamic_cast<Sphere*>(object1), dynamic_cast<Sphere*>(object2));
			}
		}
	}
}

void PhysicsScene::draw()
{
	for (PhysicsObject* actor : m_actors)
	{
		actor->draw();
	}
}

bool PhysicsScene::sphereToSphere(Sphere* sphere1, Sphere* sphere2)
{
	//check to make sure both spheres exist
	if (sphere1 != nullptr && sphere2 != nullptr)
	{
		//check to see the length of the two radii if they were touching
		float maxDistanceToCollide = sphere1->getRadius() + sphere2->getRadius();
		//check to see the distance between the two spheres
		glm::vec2 Displacement = { sphere2->getPosition().x - sphere1->getPosition().x, sphere2->getPosition().y - sphere1->getPosition().y};
		//convert vec2 displacement to float
		float distance = (Displacement.x * Displacement.x) + (Displacement.y * Displacement.y);
		distance /= distance;
		//if the distance between the two spheres is shorter than the maxDistanceToCollide, then it is safe to assume collision
		if (distance < maxDistanceToCollide)
		{
			return true;
		}
	}
	return false;
}
