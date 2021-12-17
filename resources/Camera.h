#pragma once
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include<glm/glm.hpp>
class Camera
{
public:
    //VIEW PROJECTION
    glm::mat4 GetViewProjectionMatrix(GLint WIDTH, GLint HEIGHT);
};