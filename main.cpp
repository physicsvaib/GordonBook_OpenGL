
#include "main.h"

void init(GLFWwindow *window) {}

void display(GLFWwindow *window, double currentTime)
{
  glClearColor(0.8f, 1.2f, 0.1f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

void SetWindowHints()
{
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
}

void ShowError(std::string str)
{
  std::cerr << str << '\n';
  exit(EXIT_FAILURE);
}

void TerminateApp(GLFWwindow *window)
{
  glfwDestroyWindow(window);
  glfwTerminate();
  exit(EXIT_SUCCESS);
}

void Loop(GLFWwindow *window)
{
  while (!glfwWindowShouldClose(window))
  {
    display(window, glfwGetTime());
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}

void MainLogic()
{
  if (!glfwInit())
  {
    ShowError("GLFW Failed to Init");
  }

  SetWindowHints();

  GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Base Title", NULL, NULL);

  if (window == nullptr)
  {
    ShowError("Failed to create a GLFW Window");
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    ShowError("Failed to Init GLAD");
  }

  glfwSwapInterval(1);

  init(window);

  Loop(window);

  TerminateApp(window);
}

int main(void)
{
  MainLogic();
}

/*
* GLFWInit
* Hints
* Window creation
* Set Window Context
* Gladinit

*/