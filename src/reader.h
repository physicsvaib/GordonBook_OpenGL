#pragma once
#include <string>
#include <fstream>
#include <sstream>

std::string ReadDataFromFile(const char *path)
{
  std::string content;
  std::ifstream stream(path, std::ios::in);

  std::string line = "";
  while (!stream.eof())
  {
    getline(stream, line);
    content.append(line + '\n');
  }

  stream.close();
  return content;
}
