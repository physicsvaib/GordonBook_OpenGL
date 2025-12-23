#ifndef __MAIN_H__
#define __MAIN_H__

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

const int HEIGHT = 600;
const int WIDTH = 800;

const int numVAOs = 1;

GLuint renderingProgram;
GLuint VAO[numVAOs];

bool GLCheckErrors();
void GetShaderCompileError(GLuint shader);
void GetProgramCompileError(GLuint program);

GLuint CreateGLShader(GLuint type, const char *source);
GLuint CreateShaderProgram();
void init(GLFWwindow *window);
void display(GLFWwindow *window, double currentTime);

void SetWindowHints();

void ShowError(std::string str);

void TerminateApp(GLFWwindow *window);

void MainLogic();

GLFWwindow *CreateWindow();

void Loop(GLFWwindow *window);

#endif