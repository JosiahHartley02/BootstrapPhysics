
#include "Mesh.h"
class Quad : public Mesh
{
public:
	Quad() : Mesh() {}
	Quad::Mesh::Vertex* generateVertices(unsigned int& vertexCount, unsigned int& triCount) override;
};
