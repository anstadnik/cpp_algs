#include "str.h"
using namespace std;

namespace algs {
namespace str {

/**
 * @brief Table generator for Knuth-Morris-Pratt algorithm
 *
 * @param W string to be searched
 */
static vector<int> kmpTable(const string& W) {
  vector<int> T = {-1};  // Vector of longest proper suffix which ends at T[i],
                         // which is a proper prefix of W
  int pos = 1,           // Position in the T
      cnd = 0;           // Position in the proper prefix which ends with T[i]
  while (pos < static_cast<int>(W.size())) {
    if (W[pos] == W[cnd])
      T.push_back(T[cnd]);  // If the symbol matches, copy value from the prefix
                            // As we've already checked that symbol If it's the
                            // first time, it means that there are same symbols
    else {
      T.push_back(cnd);  // Save the current index of the best guess on on which
                         // prefix of W we can be
      while (cnd >= 0 && W[pos] != W[cnd])
        cnd =
            T[cnd];  // If we found that there is a mismatch with the longest
                     // prefix on which we can be, it means that we can use this
                     // lookup table to move to the second longest prefix etc.
    }
    pos++, cnd++;
  }
  T.push_back(cnd);  // After we found an occurence, we can look up T[W.size()]
  return T;
}

std::vector<int> KMP(const std::string& S, const std::string& W) {
  if (!W.size()) {
    std::vector<int> v(S.size() + 1);
    std::iota(std::begin(v), std::end(v), 0);  // Fill with all numbers
    return v;
  }

  std::vector<int> P,   // Positions of occurences of W in S
      T = kmpTable(W);  // Lookup table
  int j = 0, k = 0;
  while (j < static_cast<int>(S.size())) {
    if (W[k] == S[j]) {
      j++, k++;
      if (k == static_cast<int>(W.size())) {
        P.push_back(j - k);  // Save match
        k = T[k];  // Go to the longest prefix of W which ends with S[k]
      }
    } else {
      k = T[k];   // Go to the longest prefix of W which ends with S[k]
      if (k < 0)  // If it can't even be start of the W
        j++, k++;
    }
  }
  return P;
}
}  // namespace str
}  // namespace algs
