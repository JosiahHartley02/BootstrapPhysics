#pragma once
#include "Camera.h"
class PlayerCamera : public Camera
{
public:
	PlayerCamera() : Camera() {}
	PlayerCamera(float fieldOfView, float nearClip, float farClip) : Camera(fieldOfView, nearClip, farClip) {}
	~PlayerCamera() {}

	void onUpdate(float deltaTime) override;

private:
	float m_moveSpeed = 1.0f;
	float m_lookSpeed = 1.0f;

	double m_currentMouseX = 0.0;
	double m_currentMouseY = 0.0;
	double m_previousMouseX = 0.0;
	double m_previousMouseY = 0.0;
};

