#include "io.hpp"

std::string read_file(const std::string & fn) {
  std::ifstream in(fn);
  if (in)
  {
    std::ostringstream contents;
    contents << in.rdbuf();
    in.close();
    return(contents.str());
  }
  throw(errno);
}
