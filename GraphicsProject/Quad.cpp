#include "Quad.h"
Quad::Vertex* Quad::generateVertices(unsigned int& vertexCount, unsigned int& triCount)
{
	Vertex* vertices = nullptr;
	vertexCount = 6;
	triCount = 2;

	//Define the vertices for a quad
	vertices = new Vertex[vertexCount];

	//triangle 0
	vertices[0].position = { -0.5f,0.0f,0.5f,1.0f };
	vertices[1].position = { 0.5f,0.0f,0.5f,1.0f };
	vertices[2].position = { -0.5f,0.0f,-0.5f,1.0f };
	//traingle 1
	vertices[0].position = { 0.5f,0.0f,0.5f,1.0f };
	vertices[0].position = { -0.5f,0.0f,-0.5f,1.0f };
	vertices[0].position = { 0.5f,0.0f,-0.5f,1.0f };

	for (int i = 0; i < vertexCount ; i++) {
		vertices[i].color = { 0.0f,0.5f,0.4f,1.0f };
	}

	return vertices;
}