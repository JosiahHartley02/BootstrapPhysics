#include "Cube.h"

Cube::Cube(glm::vec4 color) : Cube::Cube()
{
	m_color = color;
}

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount)
{
	//Set the number of vertices
	vertexCount = 12;

	//Define the vertices for a quad
	Vertex* vertices = new Vertex[vertexCount];

	//Top Face
	vertices[0].position = { -0.5f, 0.0f, 0.5f, 1.0f };
	vertices[1].position = { 0.5f, 0.0f, 0.5f, 1.0f };
	vertices[2].position = { -0.5f, 0.0f, -0.5f, 1.0f };
	vertices[3].position = { 0.5f, 0.0f, -0.5f, 1.0f };
	vertices[4].position = vertices[1].position;
	vertices[5].position = vertices[2].position;

	//Bottom Face
	vertices[6].position = { -0.5f, -1.0f, 0.5f, 1.0f };
	vertices[7].position = { 0.5f, -1.0f, 0.5f, 1.0f };
	vertices[8].position = { -0.5f, -1.0f, -0.5f, 1.0f };
	vertices[9].position = { 0.5f, -1.0f, -0.5f, 1.0f };
	vertices[10].position = { 0.5f, -1.0f, 0.5f, 1.0f };
	vertices[11].position = { -0.5f, -1.0f, -0.5f, 1.0f };

	for (int i = 0; i < vertexCount; i++) {
		vertices[i].normal = { 0.0f, 1.0f, 0.0f, 0.0f };

		int color = rand() % 4;
		switch (color)
		{
		case 1:
			vertices[i].color = glm::vec4(0.8f, 0.0f, 0.0f, 1.0f);
			break;
		case 2:
			vertices[i].color = glm::vec4(0.0f, 0.5f, 0.5f, 1.0f);
			break;
		case 3:
			vertices[i].color = glm::vec4(0.0f, 0.0f, 0.8f, 1.0f);
			break;
		}
	}


	return vertices;
}

unsigned int* Cube::generateIndices(unsigned int& indexCount)
{
	//Set the number of indices
	indexCount = 36;

	unsigned int* indices = new unsigned int[indexCount] {
		0, 1, 2,
			2, 1, 3,
			6, 7, 8,
			8, 7, 9,
			0, 1, 6,
			6, 1, 7,
			2, 3, 8,
			8, 3, 9,
			0, 2, 6,
			6, 2, 8,
			1, 3, 7,
			7, 3, 9
	};

	return indices;
}

//Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount)
//{
//	//Set the number of vertices
//	vertexCount = 36;
//
//	//Define the vertices for a quad
//	Vertex* vertices = new Vertex[vertexCount];
//
//	//Top Face
//	vertices[0].position = { -0.5f, 0.0f, 0.5f, 1.0f };
//	vertices[1].position = { 0.5f, 0.0f, 0.5f, 1.0f };
//	vertices[2].position = { -0.5f, 0.0f, -0.5f, 1.0f };
//	vertices[3].position = { 0.5f, 0.0f, -0.5f, 1.0f };
//	vertices[4].position = vertices[1].position;
//	vertices[5].position = vertices[2].position;
//
//	//Bottom Face
//	vertices[6].position = { -0.5f, -1.0f, 0.5f, 1.0f };
//	vertices[7].position = { 0.5f, -1.0f, 0.5f, 1.0f };
//	vertices[8].position = { -0.5f, -1.0f, -0.5f, 1.0f };
//	vertices[9].position = { 0.5f, -1.0f, -0.5f, 1.0f };
//	vertices[10].position = { 0.5f, -1.0f, 0.5f, 1.0f };
//	vertices[11].position = { -0.5f, -1.0f, -0.5f, 1.0f };
//
//	//Front Face
//	vertices[12].position = vertices[0].position;
//	vertices[13].position = vertices[1].position;
//	vertices[14].position = vertices[6].position;
//	vertices[15].position = vertices[7].position;
//	vertices[16].position = vertices[13].position;
//	vertices[17].position = vertices[14].position;
//
//	//Right Face
//	vertices[18].position = vertices[2].position;
//	vertices[19].position = vertices[3].position;
//	vertices[20].position = vertices[8].position;
//	vertices[21].position = vertices[9].position;
//	vertices[22].position = vertices[19].position;
//	vertices[23].position = vertices[20].position;
//
//	//Left Face
//	vertices[24].position = vertices[0].position;
//	vertices[25].position = vertices[2].position;
//	vertices[26].position = vertices[6].position;
//	vertices[27].position = vertices[8].position;
//	vertices[28].position = vertices[25].position;
//	vertices[29].position = vertices[26].position;
//
//	//Right Face
//	vertices[30].position = vertices[1].position;
//	vertices[31].position = vertices[3].position;
//	vertices[32].position = vertices[7].position;
//	vertices[33].position = vertices[9].position;
//	vertices[34].position = vertices[25].position;
//	vertices[35].position = vertices[26].position;
//
//	for (int i = 0; i < vertexCount; i++) {
//		vertices[i].normal = { 0.0f, 1.0f, 0.0f, 0.0f };
//		int color = rand() % 4;
//		switch (color)
//		{
//		case 1:
//			vertices[i].color = glm::vec4(0.8f, 0.0f, 0.0f, 1.0f);
//			break;
//		case 2:
//			vertices[i].color = glm::vec4(0.0f, 0.5f, 0.5f, 1.0f);
//			break;
//		case 3:
//			vertices[i].color = glm::vec4(0.0f, 0.0f, 0.8f, 1.0f);
//			break;
//		}
//	}
//
//
//	return vertices;
//}

//unsigned int* Cube::generateIndices(unsigned int& indexCount)
//{
//	//Set the number of indices
//	indexCount = 36;
//
//	unsigned int* indices = new unsigned int[indexCount] {
//		0, 1, 2,
//			2, 1, 3,
//				6, 7, 8,
//					8, 7, 9,
//						12, 13, 14,
//							14, 13, 15,
//								18, 19, 20,
//									20, 19, 21,
//										24, 25, 26,
//											26, 25, 27,
//												30, 31, 32,
//													32, 31, 33
//	};
//
//	return indices;
//}
