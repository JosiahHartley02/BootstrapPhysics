#include "Mesh.h"
#include "gl_core_4_4.h"

Mesh::Mesh()
{
	m_triCount = 0;
	m_vertexArrayObject = 0;
	m_vertexBufferObject = 0;
	m_indexBufferObject = 0;
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vertexArrayObject);
	glDeleteBuffers(1, &m_vertexBufferObject);
	glDeleteBuffers(1, &m_indexBufferObject);
}

void Mesh::onStart()
{
	assert(m_vertexArrayObject == 0);

	//Generate vertex buffer and array
	glGenBuffers(1, &m_vertexBufferObject);
	glGenVertexArrays(1, &m_vertexArrayObject);

	//Bind vertex array and buffer
	glBindVertexArray(m_vertexArrayObject);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);

	//Generate the vertices
	unsigned int vertexCount = 0u;
	Vertex* vertices = generateVertices(vertexCount);

	//Set the triangle count
	m_triCount = vertexCount / 3u;

	//Fill vertex buffer
	glBufferData(
		GL_ARRAY_BUFFER,				//type of buffer
		sizeof(Vertex) * vertexCount,	//size in bytes of all vertices
		vertices,						//all vertices
		GL_STATIC_DRAW					//how the data will update
	);

	unsigned int memoryPosition = 0u;

	//Enable vertex POSITION as first attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0,						//attribute index
		4,						//number of values within attribute
		GL_FLOAT,				//type of each value
		GL_FALSE,				//whether to normalize
		sizeof(Vertex),			//size in bytes of one vertex
		(void*)memoryPosition	//memory position of this attribute
	);
	memoryPosition += sizeof(Vertex::position);

	//Enable vertex NORMAL as second attribute
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(
		1,						//attribute index
		4,						//number of values within attribute
		GL_FLOAT,				//type of each value
		GL_TRUE,				//whether to normalize
		sizeof(Vertex),			//size in bytes of one vertex
		(void*)memoryPosition	//memory position of this attribute
	);
	memoryPosition += sizeof(Vertex::normal);

	//Enable vertex TEXTURE COORDINATE as third attribute
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(
		2,						//attribute index
		2,						//number of values within attribute
		GL_FLOAT,				//type of each value
		GL_FALSE,				//whether to normalize
		sizeof(Vertex),			//size in bytes of one vertex
		(void*)memoryPosition	//memory position of this attribute
	);
	memoryPosition += sizeof(Vertex::texCoord);

	//Enable vertex TANGENT as fourth attribute
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(
		3,						//attribute index
		4,						//number of values within attribute
		GL_FLOAT,				//type of each value
		GL_FALSE,				//whether to normalize
		sizeof(Vertex),			//size in bytes of one vertex
		(void*)memoryPosition	//memory position of this attribute
	);
	memoryPosition += sizeof(Vertex::tangent);

	//Enable vertex COLOR as fifth attribute
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(
		4,						//attribute index
		4,						//number of values within attribute
		GL_FLOAT,				//type of each value
		GL_FALSE,				//whether to normalize
		sizeof(Vertex),			//size in bytes of one vertex
		(void*)memoryPosition	//memory position of this attribute
	);
	memoryPosition += sizeof(Vertex::color);

	//Generate the indices
	unsigned int indexCount = 0u;
	unsigned int* indices = generateIndices(indexCount);

	if (indexCount > 0u) {
		//Generate index buffer
		glGenBuffers(1, &m_indexBufferObject);

		//Bind index buffer
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBufferObject);

		//Fill index buffer
		glBufferData(
			GL_ELEMENT_ARRAY_BUFFER,
			indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW
		);

		//Set the triangle count
		m_triCount = indexCount / 3u;
	}

	//Unbind buffer and array
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Deallocate vertices and indices
	delete[] vertices;
	delete[] indices;
}

void Mesh::onDraw()
{
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);

	if (program == -1) {
		printf("No shader bound!\n");
		return;
	}

	//Bind the global transform matrix as uniform modelMatrix
	int modelMatrix = glGetUniformLocation(program, "modelMatrix");
	if (modelMatrix >= 0)
		glUniformMatrix4fv(modelMatrix, 1, false, &(getTransform()->getGlobalMatrix())[0][0]);

	glBindVertexArray(m_vertexArrayObject);
	if (m_indexBufferObject != 0)
		glDrawElements(GL_TRIANGLES, 3 * m_triCount, GL_UNSIGNED_INT, 0);
	else
		glDrawArrays(GL_TRIANGLES, 0, m_triCount * 3);
}

unsigned int* Mesh::generateIndices(unsigned int& indexCount)
{
	indexCount = 0u;
	return nullptr;
}
