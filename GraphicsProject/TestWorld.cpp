#include "TestWorld.h"
#include "glm/ext.hpp"

void TestWorld::onStart()
{
	//Camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);

	//Light
	m_light = new Light();
	m_light->setDirection(glm::vec3(1.0f, 0.0f, -1.0f));
	m_light->setAmbient(glm::vec4(0.2f, 0.2f, 0.2f, 1.0f));
	m_light->setDiffuse(glm::vec4(0.6f, 0.6f, 1.0f, 1.0f));
	m_light->setSpecular(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	add(m_light);

	//Quad
	m_quad = new Quad();
	m_quad->setColor(glm::vec4(4.0f, 2.0f, 1.0f, 1.0f));
	m_quad->getTransform()->scale(glm::vec3(10.0f));
	add(m_quad);

	//OBJ
	m_obj = new OBJMesh();
	m_obj->load("Lucy.obj");
	m_obj->getTransform()->setScale(glm::vec3(0.5f));
	add(m_obj);
}

void TestWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_quad);
	destroy(m_obj);
}


