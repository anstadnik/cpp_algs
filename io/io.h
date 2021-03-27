#pragma once

#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>

namespace algs {
namespace io {
#define DEBUG_DISABLED true
#define DEBUG_STREAM    \
  if (DEBUG_DISABLED) { \
  } else                \
    std::cerr

/**
 * @brief Read contents of file into a string
 *
 * @param fn filename
 */
std::string readFileToString(const std::string& fn);

/**
 * @brief Read contents of file into a list of strings
 *
 * @param fn filename
 */
std::list<std::string> readFileToList(const std::string& fn);
}  // namespace io
}  // namespace algs
