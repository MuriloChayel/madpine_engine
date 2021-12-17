#include "CreateWindow.h"
    
#include <glm/glm.hpp>
#include<gtx/string_cast.hpp>
#include <gtc/type_ptr.hpp>

#include "Render.h"
#include "Camera.h"
#include "Triangle.h"
#include"GameLoop.h"

#include <cassert>

Game game;


GLFWwindow *CreateWindow::InitWindow(GLint width, GLint height) //CRIA A JANELA 
{
    GLFWwindow *window;

    assert(glfwInit() == GL_TRUE);
    window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);

    assert(window);

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    assert(glewInit() == GLEW_OK);
    return window;
}
void CreateWindow::StartGame(GLFWwindow* gameWindow) // USA A JANELA CRIADA
{ 
    game.Start();
}
void CreateWindow::GameLoop(GLFWwindow *gameWindow, GLint width, GLint height)
{
    Render render;
    Camera cam;
    Triangle triangle;

    GLuint shader = render.LoadShaders("shaders/vert.glsl", "shaders/frag.glsl");

    GLuint myTriangle = triangle.CreateTriangle();

    while (!glfwWindowShouldClose(gameWindow))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.3f, 0.3f, 0.3f, 0.3f);

        glEnableVertexAttribArray(0); // HABILITANDO O ATRIBUTO

        glBindBuffer(GL_ARRAY_BUFFER, myTriangle);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

        glUseProgram(shader);
        glm::mat4 modelMatrix = glm::identity<glm::mat4>();
        glm::mat4 mvp = cam.GetViewProjectionMatrix(width, height) * modelMatrix;

        GLint modelViewProjectionLoc = glGetUniformLocation(shader, "ModelViewProjection");
        glUniformMatrix4fv(modelViewProjectionLoc, 1, GL_FALSE, glm::value_ptr(mvp));

        game.Update(); //GAME LOOP CALL

        glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
        glDisableVertexAttribArray(0);

        glfwSwapBuffers(gameWindow);

        glfwPollEvents();
    }
}