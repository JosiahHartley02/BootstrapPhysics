#include "Cube.h"

Cube::Cube(glm::vec4 color) : Cube::Cube()
{
	m_color = color;
}

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount)
{
	//Set the number of vertices
	vertexCount = 24;

	//Define the vertices for a quad
	Vertex* vertices = new Vertex[vertexCount];

	//Top Face
	vertices[0].position = { -0.5f, 0.0f, 0.5f, 1.0f };
	vertices[1].position = { 0.5f, 0.0f, 0.5f, 1.0f };
	vertices[2].position = { -0.5f, 0.0f, -0.5f, 1.0f };
	vertices[3].position = { 0.5f, 0.0f, -0.5f, 1.0f };
	vertices[4].position = vertices[1].position;
	vertices[5].position = vertices[2].position;

	for (int i = 0; i < 6; i++) {
		vertices[i].normal = { 0.0f, 1.0f, 0.0f, 0.0f };
		vertices[i].color =  glm::vec4(0.3f,0.5f,0.9f,1.0f);
	}

	//Bottom Face
	vertices[6].position = { -0.5f, -1.0f, 0.5f, 1.0f };
	vertices[7].position = { 0.5f, -1.0f, 0.5f, 1.0f };
	vertices[8].position = { -0.5f, -1.0f, -0.5f, 1.0f };
	vertices[9].position = { 0.5f, -1.0f, -0.5f, 1.0f };
	vertices[10].position = { 0.5f, -1.0f, 0.5f, 1.0f };
	vertices[11].position = { -0.5f, -1.0f, -0.5f, 1.0f };

	for (int i = 6; i < 12; i++) {
		vertices[i].normal = { 0.0f, 1.0f, 0.0f, 0.0f };
		vertices[i].color = glm::vec4(0.5f, 0.3f, 0.9f, 1.0f);
	}

	//Front Face
	vertices[12].position = vertices[0].position;
	vertices[13].position = vertices[1].position;
	vertices[14].position = vertices[6].position;
	vertices[15].position = vertices[7].position;
	vertices[16].position = vertices[13].position;
	vertices[17].position = vertices[14].position;

	for (int i = 12; i < 18; i++) {
		vertices[i].normal = { 0.0f, 1.0f, 0.0f, 0.0f };
		vertices[i].color = glm::vec4(0.9f, 0.3f, 0.4f, 1.0f);
	}

	//Back Face
	vertices[18].position = vertices[2].position;
	vertices[19].position = vertices[3].position;
	vertices[20].position = vertices[8].position;
	vertices[21].position = vertices[9].position;
	vertices[22].position = vertices[19].position;
	vertices[23].position = vertices[20].position;

	for (int i = 18; i < 24; i++) {
		vertices[i].normal = { 0.0f, 1.0f, 0.0f, 0.0f };
		vertices[i].color = m_color;
	}

	//Right Face
	//Left Face


	return vertices;
}

unsigned int* Cube::generateIndices(unsigned int& indexCount)
{
	//Set the number of indices
	indexCount = 24;

	unsigned int* indices = new unsigned int[indexCount] {
		0, 1, 2,
			2, 1, 3,
				6, 7, 8,
					8, 7, 9,
						12, 13, 14,
							14, 13, 15,
								18, 19, 20,
									20, 19, 21
	};

	return indices;
}
