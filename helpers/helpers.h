#pragma once
#include <functional>
#include <iostream>
#include <sstream>
#include <tuple>
#include <type_traits>

#include "3rd_party/dbg.h"

namespace
{
  template <typename T>
  T& get_value(T& x) {
    return x;
  }
  
  template <typename T>
  T& get_value(T* x) {
    return *x;
  }

  template <typename T>
  bool not_equal(const T& a, const T& b) {
    if constexpr (std::is_pointer_v<T>) {
      if (!a && !b)
        return false;
      else if (!a || !b)
        return true;
      return *a != *b;
    }
    return a != b;
  }

  template <typename RET, typename... ARGS>
  void test(std::function<RET(ARGS...)> f, const RET& expected, ARGS&&... args) {
    // Copy args in case if ARGS is an l-value reference
    RET original = f(args...);
    if (not_equal(original, expected)) {
      ((dbg(get_value(args))), ...);
      dbg(get_value(expected), get_value(original));
      std::cout << std::endl;
    }
  }
}

// C has to be not const if m is not const
template <class CL, typename RET, typename... ARGS>
void test(CL&& cl, RET (CL::*m)(ARGS...), const RET& ans, ARGS&&... args) {
  using fun_type = std::function<RET(ARGS...)>;
  fun_type f = [&](ARGS... args) { return (cl.*m)(args...); };
  return test(f, ans, std::forward<ARGS>(args)...);
}

template <typename CL, typename RET, typename... ARGS>
void test(RET (CL::*m)(ARGS...), const RET& ans, ARGS&&... args) {
  return test(CL(), m, ans, std::forward<ARGS>(args)...);
}
