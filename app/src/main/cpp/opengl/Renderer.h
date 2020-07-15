#pragma once

#include "GL.h"

#include <math.h>
#include "glm/glm.hpp"

class Renderer {
public:
    Renderer();
    void onSurfaceCreated();
    void onDrawFrame();
    void setScreenSize(int width, int height);
    void setRotationAngles(float width, float height);
    void addRotationAngles(float x, float y);
    void setScale(float scale);

private:
    GLuint loadShader(GLuint shaderType, const char* shaderSource);

	glm::mat4 m_view;
    glm::mat4 m_projection;
    glm::vec3 m_camPos;
	glm::vec3 m_targetPos;
	glm::vec3 m_up;
    int m_width = 0;
    int m_height = 0;
    int m_renderFrame = 0;
    float m_interpolation = 0.0f;
    float m_rotationX = 0.0f;
    float m_rotationY = 0.0f;
    float m_xAngle = 180.0f;
    float m_yAngle = 0.0f;
    float m_scale = 1.0f;
};

