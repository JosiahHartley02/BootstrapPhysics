#include "Transform.h"
#include "glm/ext.hpp"

void Transform::translate(glm::vec3 translation)
{
	setPosition(m_position + translation);
}

void Transform::rotate(glm::vec3 rotation)
{
	setRotation(m_rotation + rotation);
}

void Transform::scale(glm::vec3 scale)
{
	setScale(m_scale + scale);
}

void Transform::setPosition(glm::vec3 position)
{
	m_position = position;
	m_shouldUpdateMatrix = true;
}

void Transform::setRotation(glm::vec3 angle)
{
	m_rotation = angle;
	m_shouldUpdateMatrix = true;
}

void Transform::setScale(glm::vec3 scale)
{
	m_scale = scale;
	m_shouldUpdateMatrix = true;
}

glm::mat4 Transform::getMatrix()
{
	glm::mat4 matrix = m_matrix;
	if (m_shouldUpdateMatrix) {
		matrix = glm::translate(matrix, m_position);
		matrix = glm::rotate(matrix, m_rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
		matrix = glm::rotate(matrix, m_rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
		matrix = glm::rotate(matrix, m_rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
		matrix = glm::scale(matrix, m_scale);
		m_matrix = matrix;
		m_shouldUpdateMatrix = false;
	}
	return m_matrix;
}
