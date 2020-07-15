#include <iostream>
#include "GL.h"
#include "Renderer.h"
#include <unistd.h>

static Renderer *pObject;
static double zoom = 1.0f;
static bool mouseButtonPress = false;
static float mouseXStart = 0, mouseXEnd = 0;

void handleWindowSizeCallback(GLFWwindow *window, int width, int height);
void handleMouseInputCallback(GLFWwindow *window, int button, int action, int mods);
void handleMouseCursor(GLFWwindow *window, double xpos, double ypos);
void handleScrollCallback(GLFWwindow *window, double xoffset, double yoffset);

int main(int argc, char *argv[])
{
    GLFWwindow *window;

    if (!glfwInit())
        exit(0);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow(640, 480, "MD2Loader", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(0);
    }

    glfwSetWindowSizeCallback(window, handleWindowSizeCallback);
    glfwSetMouseButtonCallback(window, handleMouseInputCallback);
    glfwSetScrollCallback(window, handleScrollCallback);
    glfwSetCursorPosCallback(window, handleMouseCursor);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // -------------------
    // RENDER MD2
    // -------------------
    pObject = new Renderer();
    pObject->setScreenSize(640, 480);
    pObject->onSurfaceCreated();

    while (!glfwWindowShouldClose(window)){
        pObject->onDrawFrame();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(1);
}

void handleWindowSizeCallback(GLFWwindow *window, int width, int height)
{
    pObject->setScreenSize(width, height);
}

void handleMouseInputCallback(GLFWwindow *window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
        mouseButtonPress = true;
    }
    else
    {
        mouseButtonPress = false;
    }
}

void handleMouseCursor(GLFWwindow *window, double xpos, double ypos)
{
    if (mouseButtonPress)
    {
        float dx = (mouseXStart - mouseXEnd);
        pObject->addRotationAngles(dx, 0);
    }
    mouseXStart = mouseXEnd;
    mouseXEnd = xpos;
}

void handleScrollCallback(GLFWwindow *window, double xoffset, double yoffset)
{
    zoom = (yoffset > 0 ? (zoom - 0.1f) : (zoom + 0.1f));
    pObject->setScale(zoom);
}