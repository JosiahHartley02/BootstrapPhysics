#include "Transform.h"
#include "glm/gtc/matrix_transform.hpp"

void Transform::translate(glm::vec3 translation)
{
	m_position += translation;
	m_shouldUpdateLocalMatrix = true;
}

void Transform::translate(float x, float y, float z)
{
	translate(glm::vec3(x, y, z));
}

void Transform::rotate(glm::vec3 rotation)
{
	m_rotation += rotation;
	m_shouldUpdateLocalMatrix = true;
}

void Transform::rotate(float pitch, float yaw, float roll)
{
	rotate(glm::vec3(pitch, yaw, roll));
}

void Transform::scale(glm::vec3 scale)
{
	m_scale += scale;
	m_shouldUpdateLocalMatrix = true;
}

void Transform::scale(float x, float y, float z)
{
	scale(glm::vec3(x, y, z));
}

void Transform::setPosition(glm::vec3 position)
{
	m_position = glm::vec3(position);
	m_shouldUpdateLocalMatrix = true;

}

void Transform::setPosition(float x, float y, float z)
{
	setPosition(glm::vec3(x, y, z));
}

void Transform::setRotation(glm::vec3 rotation)
{
	m_rotation = rotation;
	m_shouldUpdateLocalMatrix = true;
}

void Transform::setRotation(float pitch, float yaw, float roll)
{
	
	setRotation(glm::vec3(pitch, yaw, roll));
}

void Transform::setScale(glm::vec3 scale)
{
	m_scale = glm::vec3(scale);
	m_shouldUpdateLocalMatrix = true;
}

void Transform::setScale(float x, float y, float z)
{
	setScale(glm::vec3(x, y, z));
}

glm::vec3 Transform::getRight()
{
	//Convert degrees to radians
	float yawRadians = glm::radians(m_rotation.y);
	float pitchRadians = glm::radians(m_rotation.x);
	//Calculate the right vector
	glm::vec3 right(
		-sin(yawRadians),
		0.0f,
		cos(yawRadians)
	);
	return right;
}

glm::vec3 Transform::getUp()
{
	return glm::cross(getRight(), getForward());
}

glm::vec3 Transform::getForward()
{
	//Convert degrees to radians
	float yawRadians = glm::radians(m_rotation.y);
	float pitchRadians = glm::radians(m_rotation.x);
	//Calculate the forward vector
	glm::vec3 forward(
		cos(pitchRadians) * cos(yawRadians),
		sin(pitchRadians),
		cos(pitchRadians) * sin(yawRadians)
	);
	return forward;
}

void Transform::setForward(glm::vec3 direction)
{
	//Ensure normalization
	glm::normalize(direction);
	//Find the angles
	float pitch = asin(direction.y) * 57.2957795131f;
	float yaw = atan2(-direction.x, direction.z) * 57.2957795131f;
	float roll = 0.0f;
	//Rotate
	setRotation(pitch, yaw, roll);
}

glm::mat4 Transform::getLocalMatrix()
{
	if (m_shouldUpdateLocalMatrix) {
		m_localMatrix = glm::lookAt(
			m_position,
			m_position + getForward(),
			getUp()
		);
		m_localMatrix = glm::rotate(m_localMatrix, m_rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
		m_localMatrix = glm::scale(m_localMatrix, m_scale);
	}

	return m_localMatrix;
}

glm::mat4 Transform::getGlobalMatrix()
{
	if (!m_parent) {
		m_globalMatrix = getLocalMatrix();
	}
	else if (m_shouldUpdateGlobalMatrix) {
		m_globalMatrix = m_parent->getGlobalMatrix() * getLocalMatrix();
	}

	return m_globalMatrix;
}
