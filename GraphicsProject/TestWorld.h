#pragma once
#include "World.h"
#include "PlayerCamera.h"
#include "Light.h"
#include "Quad.h"
#include "OBJMesh.h"

class TestWorld : public World
{
public:
	void onStart() override;
	void onEnd() override;

private:
	PlayerCamera* m_camera = nullptr;
	Quad* m_quad = nullptr;
	OBJMesh* m_obj = nullptr;
	Light* m_light = nullptr;
};

