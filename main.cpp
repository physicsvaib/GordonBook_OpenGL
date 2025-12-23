
#include "main.h"

bool GLCheckErrors()
{
  bool errorFound = false;

  for (GLuint error = glGetError(); error != GL_NO_ERROR; error = glGetError())
  {
    std::cerr << "glError: " << error << std::endl;
    errorFound = true;
  }

  return errorFound;
}

void GetShaderCompileError(GLuint shader)
{
  int len = 0;
  int charWritten = 0;
  char *log;

  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);

  if (len > 0)
  {
    log = new char[len];
    glGetShaderInfoLog(shader, len, &charWritten, log);
    std::cerr << "Shader Info Log:" << log << std::endl;
    delete[] log;
  }
}

void GetProgramCompileError(GLuint program)
{
  int len = 0;
  int charWritten = 0;
  char *log;

  glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);

  if (len > 0)
  {
    log = new char[len];
    glGetProgramInfoLog(program, len, &charWritten, log);
    std::cerr << "Program Info Log:" << log << std::endl;
    delete[] log;
  }
}

GLuint CreateGLShader(GLuint type, const char *source)
{
  GLuint shader = glCreateShader(type);
  glShaderSource(shader, 1, &source, NULL);
  glCompileShader(shader);

  GLCheckErrors();
  GLint shaderCompiling;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &shaderCompiling);

  if (shaderCompiling != 1)
  {
    GetShaderCompileError(shader);
    exit(EXIT_FAILURE);
  }

  return shader;
}

GLuint CreateShaderProgram()
{
  const char *vShaderSource = "#version 430\n"
                              "void main(void)\n"
                              "{gl_Position = vec4(0.2,0.2,0.0,1.0);}";

  const char *fShaderSource = "#version 430\n"
                              "out vec4 color;\n"
                              "void main(void)\n"
                              "{color = vec4(gl_FragCoord.xy / 600,0.5, 1.0);}";

  GLuint vShader = CreateGLShader(GL_VERTEX_SHADER, vShaderSource);
  GLuint fShader = CreateGLShader(GL_FRAGMENT_SHADER, fShaderSource);

  GLuint vfProgram = glCreateProgram();
  glAttachShader(vfProgram, vShader);
  glAttachShader(vfProgram, fShader);
  glLinkProgram(vfProgram);

  GLCheckErrors();
  GLint programLinked;
  glGetProgramiv(vfProgram, GL_LINK_STATUS, &programLinked);
  if (programLinked != 1)
  {
    GetProgramCompileError(vfProgram);
  }

  return vfProgram;
}

void init(GLFWwindow *window)
{
  renderingProgram = CreateShaderProgram();

  glGenVertexArrays(numVAOs, VAO);
  glBindVertexArray(VAO[0]);

  glPointSize(300.0f);
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