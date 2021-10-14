#pragma once
#include "Entity.h"

class Camera : public Entity
{
public:
	Camera() {}
	Camera(float fieldOfView, float nearClip, float farClip)
		: m_fieldOfView{ fieldOfView }, m_nearClip{ nearClip }, m_farClip{ farClip } {}
	~Camera() {}

	float getFieldOfView() { return m_fieldOfView; }
	void setFieldOfView(float fieldOfView) { m_fieldOfView = fieldOfView; }
	float getNearClip() { return m_nearClip; }
	void setNearClip(float nearClip) { m_nearClip = nearClip; }
	float getFarClip() { return m_farClip; }
	void setFarClip(float farClip) { m_farClip = farClip; }

private:
	float m_fieldOfView = 45.0f;
	float m_nearClip = 0.001f;
	float m_farClip = 1000.0f;
};

