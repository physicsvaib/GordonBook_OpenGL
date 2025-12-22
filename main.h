#ifndef __MAIN_H__
#define __MAIN_H__

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

const int HEIGHT = 600;
const int WIDTH = 600;

void init(GLFWwindow *window);
void display(GLFWwindow *window, double currentTime);

void SetWindowHints();

void ShowError(std::string str);

void TerminateApp(GLFWwindow *window);

void MainLogic();

void Loop(GLFWwindow *window);

#endif