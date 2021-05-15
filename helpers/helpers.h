#pragma once
#include <functional>
#include <iostream>
#include <tuple>

#include "3rd_party/dbg.h"

template <typename RET, typename... ARGS>
void test(std::function<RET(ARGS...)> f, const RET& right, ARGS&&... args) {
// Copy args in case if ARGS is an l-value reference
  RET wrong = f(args...);
  if (wrong != right) {
    dbg("Args: ");
    for (const auto& a : {args...}) dbg(a);
    dbg(right, wrong);
    std::cout << std::endl;
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
