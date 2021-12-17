#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<string>
#include"Render.h"
#include<cassert>

#include<fstream>
#include<iostream>


std::string ReadFile(const char* filePath) {
	std::string fileContent;
	if (std::ifstream fileStream{ filePath, std::ios::in }) {
		//ler dentro do fileContent o conteudo do arquivo
		fileContent.assign(std::istreambuf_iterator<char>(fileStream), std::istreambuf_iterator<char>());
	}
	return fileContent;
}
void CheckShader(GLuint shaderId) {
	//shader id tem que ser um id de um shader compilado
	GLint result = GL_TRUE;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE) {
		//imprimir o erro que o log identificou

			//obter o tamanho do log
		GLint infoLogLength = 0;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLogLength);

		//se o log do erro nao esta vazio
		if (infoLogLength > 0) {
			std::string shaderInfoLog(infoLogLength, '\0');
			glGetShaderInfoLog(shaderId, infoLogLength, nullptr, &shaderInfoLog[0]);
			std::cout << "ERRO NO SHADER\n\n" << std::endl;
			std::cout << shaderInfoLog << std::endl;
			assert(false);
		}
	}
}
GLuint Render::LoadShaders(const char* vertexShaderPath, const char* fragmentShaderPath) {
	std::string vertexShaderSource = ReadFile(vertexShaderPath);
	std::string fragmentShaderSource = ReadFile(fragmentShaderPath);

	if(vertexShaderSource.empty()){
		std::cout<<"empty"<<std::endl;
		system("pause");
	}

	
	if(fragmentShaderSource.empty()){
		std::cout<<"empty"<<std::endl;
		system("pause");
	}

	assert(!vertexShaderSource.empty());
	assert(!fragmentShaderSource.empty());

	//criar identificadores do vertex e do fragment
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	
	std::cout << "Compilando " << vertexShaderPath << std::endl;
	const char* vertexShaderSourcePtr = vertexShaderSource.c_str();
	glShaderSource(vertexShaderID, 1, &vertexShaderSourcePtr, nullptr);
	glCompileShader(vertexShaderID);
	//VERIFICAR SE A COMPILACAO DO VERTEX DEU CERTO
	CheckShader(vertexShaderID);

	std::cout << "Compilando " << fragmentShaderPath << std::endl;
	const char* fragmentShaderSourcePtr = fragmentShaderSource.c_str();
	glShaderSource(fragmentShaderID, 1, &fragmentShaderSourcePtr, nullptr);
	glCompileShader(fragmentShaderID);
	//VERIFICAR SE A COMPILACAO DO FRAGMENT DEU CERTO
	CheckShader(fragmentShaderID);


	std::cout << "linkando o programa" << std::endl;
	GLuint ProgramId = glCreateProgram();
	//passando todos os shaders que fazem parte do programa que estamos criando
	glAttachShader(ProgramId, vertexShaderID);
	glAttachShader(ProgramId, fragmentShaderID);
	glLinkProgram(ProgramId);
	//checar o programa
	GLint result = GL_TRUE;


	glGetProgramiv(ProgramId, GL_LINK_STATUS, &result);

	if (result == GL_FALSE) {
		std::cout << "\nErro ao linkar o programa:\n" << std::endl;
		GLint infoLogLenght = 0;
		glGetProgramiv(ProgramId, GL_INFO_LOG_LENGTH, &infoLogLenght);

		if (infoLogLenght > 0) {
			std::string infoLog(infoLogLenght, '\0');
			glGetProgramInfoLog(ProgramId, infoLogLenght, nullptr, &infoLog[0]);
			std::cout << infoLog << std::endl;
			assert(false);

		}
	}
	else {
		std::cout << "Sucess compile shaders" << std::endl;
	}
	glDetachShader(ProgramId, vertexShaderID);
	glDetachShader(ProgramId, fragmentShaderID);

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
	return ProgramId;
}