#include <iostream>
#include "Camera.h"
#include <glm/glm.hpp>
#include<gtx/string_cast.hpp>


glm::mat4 Camera::GetViewProjectionMatrix(GLint WIDTH, GLint HEIGHT)
{
    //VIEW MATRIX
    glm::vec3 location{0, 0, -10};
    glm::vec3 target{0, 0, 0};
    glm::vec3 up{0, 1, 0};
    
    glm::mat4 view = glm::lookAt(location, target, up);

    //PROJECTION
    float fov = 45.0f;
    float aspectRatio = (GLfloat)WIDTH/HEIGHT;
    float near = 0.001f;
    float far = 1000.0f;

    glm::mat4 projection = glm::perspective(fov, aspectRatio, near, far);
    
    //  PROJECTION * VIEW * MODEL   //
    return projection * view;
}