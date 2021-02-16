#pragma once

#include <fstream>
#include <sstream>
#include <list>
#include <iostream>
#include <iterator>

/**
 * @brief Read contents of file into a string
 *
 * @param fn filename
 */
std::string readFileToString(const std::string & fn);

/**
 * @brief Read contents of file into a list of strings
 *
 * @param fn filename
 */
std::list<std::string> readFileToList(const std::string & fn);
