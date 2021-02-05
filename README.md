# This is a collection of useful C++ stuff

## 3rd_party

Here I have useful stuff I found on the internet that I use.

* [termcolor.hpp](https://github.com/ikalnytskyi/termcolor) can be used to change the parameters of the code which is printed to console.
```cpp
std::string s = "Hello, world!";
std::cout << termcolor::reset << "s: " << termcolor::green << s << "." << endl;
```

* [backward.hpp](https://github.com/bombela/backward-cpp) generates useful backtraces on errors.
```cpp
#define BACKWARD_HAS_DW 1
#include "backward.hpp"

namespace backward {

backward::SignalHandling sh;

} // namespace backward
```

* [icecream.hpp](https://github.com/renatoGarcia/icecream-cpp) make print-debug easier.
```cpp
IC();
int v = 0;
IC(v);
```
