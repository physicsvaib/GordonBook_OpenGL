#include "reader.h"

std::string ReadDataFromFile(const char *path)
{
  std::ifstream stream(path, std::ios::in);
  if (!stream)
  {
    std::cout << path;
    return "Not found"; // or throw an exception if you prefer
  }

  std::string content;
  std::string line;

  while (std::getline(stream, line))
  {
    content.append(line);
    content.push_back('\n'); // add newline explicitly
  }

  return content;
}