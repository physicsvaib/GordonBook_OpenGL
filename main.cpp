
#include "main.h"

GLuint CreateShaderProgram()
{
  const char *vShaderSource = "#version 430\n"
                              "void main(void)\n"
                              "{gl_Position = vec4(0.2,0.2,0.0,1.0);}";

  const char *fShaderSource = "#version 430\n"
                              "out vec4 color;\n"
                              "void main(void)\n"
                              "{color = vec4(0.0, 1.0, 1.0, 1.0);}";

  GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vShader, 1, &vShaderSource, NULL);
  glCompileShader(vShader);

  GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fShader, 1, &fShaderSource, NULL);
  glCompileShader(fShader);

  GLuint vfProgram = glCreateProgram();
  glAttachShader(vfProgram, vShader);
  glAttachShader(vfProgram, fShader);
  glLinkProgram(vfProgram);

  return vfProgram;
}

void init(GLFWwindow *window)
{
  renderingProgram = CreateShaderProgram();
  glGenVertexArrays(numVAOs, VAO);
  glBindVertexArray(VAO[0]);
  glPointSize(30.0f);
}

void display(GLFWwindow *window, double currentTime)
{
  glClearColor(0.0f, 0.2f, 0.1f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  glUseProgram(renderingProgram);
  glDrawArrays(GL_POINTS, 0, 1);
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
    ShowError("GLFW init failed");
  }

  SetWindowHints();

  GLFWwindow *window = CreateWindow();

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    ShowError("GLAD init failed");
  }

  glfwSwapInterval(1);

  init(window);

  Loop(window);

  TerminateApp(window);
}

GLFWwindow *CreateWindow()
{
  GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Base", NULL, NULL);
  if (!window)
  {
    ShowError("Window not created");
    return nullptr;
  }

  glfwMakeContextCurrent(window);
  return window;
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