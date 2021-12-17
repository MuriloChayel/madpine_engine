#include"Triangle.h"


GLuint Triangle::CreateTriangle(){
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f,-1.0f,0.0f,
        1.0f,-1.0f, 0.0f,
        0.0f,1.0f, 0.0f,
    };

    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    return VBO;
}