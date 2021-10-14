#pragma once
#include "Entity.h"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"

class Light : public Entity
{
public:
	Light() {}
	Light(glm::vec3 direction, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular);
	~Light() {}

	void onDraw() override;

	//Light Direction
	glm::vec3 getDirection();
	void setDirection(glm::vec3 direction);
	//Ambient Color
	glm::vec4 getAmbient() { return m_ambient; }
	void setAmbient(glm::vec4 ambient) { m_ambient = ambient; }
	//Diffuse Color
	glm::vec4 getDiffuse() { return m_diffuse; }
	void setDiffuse(glm::vec4 diffuse) { m_diffuse = diffuse; }
	//Specular Color
	glm::vec4 getSpecular() { return m_specular; }
	void setSpecular(glm::vec4 specular) { m_specular = specular; }

private:
	glm::vec4 m_ambient = glm::vec4(0.0f);
	glm::vec4 m_diffuse = glm::vec4(0.0f);
	glm::vec4 m_specular = glm::vec4(0.0f);
};

