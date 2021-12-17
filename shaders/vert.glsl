#version 330 core 

//POSICAO DOS VERTICES
layout(location = 0) in vec3 In_Position; //ATRIBUTO 0

uniform mat4 ModelViewProjection; // 0

void main()
{
	gl_Position = ModelViewProjection * vec4(In_Position, 1.0);

}
