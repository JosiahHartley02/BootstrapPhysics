#include "PlayerCamera.h"
#include "GLFW/glfw3.h"

void PlayerCamera::onUpdate(float deltaTime)
{
    GLFWwindow* window = glfwGetCurrentContext();

    int keyForward = GLFW_KEY_W;
    int keyBack = GLFW_KEY_S;
    int keyLeft = GLFW_KEY_A;
    int keyRight = GLFW_KEY_D;
    int keyUp = GLFW_KEY_E;
    int keyDown = GLFW_KEY_Q;

    //Get the direction vectors
    glm::vec3 right = getTransform()->getRight();
    glm::vec3 up = getTransform()->getUp();
    glm::vec3 forward = getTransform()->getForward();

    //Check input
    if (glfwGetKey(window, keyForward)) {
        //Move forward
        getTransform()->translate(forward * m_moveSpeed * (float)deltaTime);
    }
    if (glfwGetKey(window, keyBack)) {
        //Move back
        getTransform()->translate(-forward * m_moveSpeed * (float)deltaTime);
    }
    if (glfwGetKey(window, keyLeft)) {
        //Move left
        getTransform()->translate(-right * m_moveSpeed * (float)deltaTime);
    }
    if (glfwGetKey(window, keyRight)) {
        //Move right
        getTransform()->translate(right * m_moveSpeed * (float)deltaTime);
    }
    if (glfwGetKey(window, keyUp)) {
        //Move up
        getTransform()->translate(up * m_moveSpeed * (float)deltaTime);
    }
    if (glfwGetKey(window, keyDown)) {
        //Move down
        getTransform()->translate(-up * m_moveSpeed * (float)deltaTime);
    }

    //Get current mouse coordinates
    glfwGetCursorPos(window, &m_currentMouseX, &m_currentMouseY);

    //Turn the camera based on the change in mouse position (delta mouse)
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_2)) {
        float pitch = m_lookSpeed * (m_currentMouseY - m_previousMouseY);
        float yaw = m_lookSpeed * (m_currentMouseX - m_previousMouseX);
        getTransform()->rotate(-pitch, yaw, 0.0f);
    }
    //Store previous mouse coordinates
    m_previousMouseX = m_currentMouseX;
    m_previousMouseY = m_currentMouseY;
}
