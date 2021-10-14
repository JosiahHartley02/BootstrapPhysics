#pragma once
#include "Mesh.h"

class Quad : public Mesh
{
public:
	Quad() : Mesh() {}
	Quad(glm::vec4 color);

	Vertex* generateVertices(unsigned int& vertexCount) override;
	unsigned int* generateIndices(unsigned int& indexCount) override;

	glm::vec4 getColor() { return m_color; }
	void setColor(glm::vec4 color) { m_color = color; }

private:
	glm::vec4 m_color = glm::vec4(1.0f);
};

