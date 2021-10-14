#pragma once
#include "glm/mat4x4.hpp"
#include "glm/vec3.hpp"

class Transform
{
public:
	Transform() {}
	~Transform() {}

	void translate(glm::vec3 translation);
	void translate(float x, float y, float z);
	void rotate(glm::vec3 rotation);
	void rotate(float pitch, float yaw, float roll);
	void scale(glm::vec3 scale);
	void scale(float x, float y, float z);

	Transform* getParent() { return m_parent; }
	void setParent(Transform* parent) { m_parent = parent; }

	glm::vec3 getPosition() { return m_position; }
	void setPosition(glm::vec3 position);
	void setPosition(float x, float y, float z);
	glm::vec3 getRotation() { return m_rotation; }
	void setRotation(glm::vec3 rotation);
	void setRotation(float pitch, float yaw, float roll);
	glm::vec3 getScale() { return m_scale; }
	void setScale(glm::vec3 scale);
	void setScale(float x, float y, float z);

	glm::vec3 getRight();
	glm::vec3 getUp();
	glm::vec3 getForward();
	void setForward(glm::vec3 direction);

	glm::mat4 getLocalMatrix();
	glm::mat4 getGlobalMatrix();

private:
	Transform* m_parent = nullptr;
	glm::vec3 m_position = glm::vec3(0.0f);
	glm::vec3 m_rotation = glm::vec3(0.0f);
	glm::vec3 m_scale = glm::vec3(1.0f);
	glm::mat4 m_localMatrix = glm::mat4(1.0f);
	bool m_shouldUpdateLocalMatrix = true;
	glm::mat4 m_globalMatrix = glm::mat4(1.0f);
	bool m_shouldUpdateGlobalMatrix = true;
};

