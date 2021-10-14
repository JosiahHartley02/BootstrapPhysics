#pragma once
#include "Entity.h"
#include "glm\vec4.hpp"
#include "glm\mat4x4.hpp"

class Mesh : public Entity
{
public:
	struct Vertex {
		glm::vec4 position = glm::vec4(0.0f);
		glm::vec4 normal = glm::vec4(0.0f);
		glm::vec2 texCoord = glm::vec2(0.0f);
		glm::vec4 tangent = glm::vec4(0.0f);
		glm::vec4 color = glm::vec4(1.0f);
	};

public:
	Mesh();
	~Mesh();

	void onStart() override;
	void onDraw() override;

	virtual Vertex* generateVertices(unsigned int& vertexCount) = 0;
	virtual unsigned int* generateIndices(unsigned int& indexCount);

private:
	unsigned int m_triCount;
	unsigned int m_vertexArrayObject, m_vertexBufferObject, m_indexBufferObject;
};

