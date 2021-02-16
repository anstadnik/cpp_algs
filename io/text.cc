#include "io.h"

std::string readFileToString(const std::string& fn) {
  std::ifstream in(fn);
  if (in) {
    std::ostringstream contents;
    contents << in.rdbuf();
    in.close();
    return (contents.str());
  }
  throw(errno);
}

std::list<std::string> readFileToList(const std::string& fn) {
  std::ifstream in(fn);
  if (in) {
    std::string t;
    std::list<std::string> l;

    while (std::getline(in, t)) l.push_back(t);

    in.close();
    return l;
  }
  throw(errno);
}
