#pragma once

#include <numeric>
#include <stdexcept>
#include <string>
#include <vector>

namespace algs {
namespace str {
/**
 * @brief Knuth-Morris-Pratt algorithm
 * The main idea is that after we found that certain substring in S is not W, we
 * don't have to go to the beginning, but can use a special lookup table to find
 * the longest possible prefix of W, which ends in the current position:
 *
 * Consider
 * m: 01234567890123456789012
 * S: ABC ABCDAB ABCDABCDABDE
 * W:            ABCDABD
 * i:            0123456
 *
 * After we found that the 17th value of S in C, and the 6th value of W is D, we
 * can instead of starting from position 12, note that the longest possible
 * substring of S which is W (the longest prefix of W which ends on the 17th
 * position of S) is ABCD. Thus, we can start from that point instead.
 * Furthermore, as we've already checked that the prefix matches S, we can avoid
 * doing that again, and act like we've already did.
 *
 * @param S String in which the word is searched
 * @param W The search word
 *
 */
std::vector<int> KMP(const std::string& S, const std::string& W);

}  // namespace str
}  // namespace algs
