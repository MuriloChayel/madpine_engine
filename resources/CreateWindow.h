#pragma once

#include<GL/glew.h>
#include<GLFW/glfw3.h>

class CreateWindow{
public:
    GLFWwindow* InitWindow(GLint width, GLint height); // ENCERRA CASO A JANELA NAO INICILIZE
    void StartGame(GLFWwindow *gameWindow);
    void GameLoop(GLFWwindow *gameWindow, GLint width, GLint height);
};