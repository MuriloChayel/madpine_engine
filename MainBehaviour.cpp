#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <gtc/type_ptr.hpp>

#include <iostream>
#include<cassert>

#include"CreateWindow.h"

GLint width = 800;
GLint height = 600;

int main(void)
{
    CreateWindow window;
    GLFWwindow* gameWindow =  window.InitWindow(width, height);
    window.StartGame(gameWindow);
    window.GameLoop(gameWindow, width, height);
    glfwTerminate();
    return 0;
}