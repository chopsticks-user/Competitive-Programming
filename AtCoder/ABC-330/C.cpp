#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <vector>

typedef int i32;
typedef long i64;
typedef unsigned int u32;
typedef unsigned long u64;
typedef float f32;
typedef double f64;

namespace util {

template <typename... Type> void print(const Type &...args) {
  ((std::cout << args), ...);
}

template <typename... Type> void println(const Type &...args) {
  ((std::cout << args), ...);
  std::cout << '\n';
}

template <typename... Type> void scan(Type &...args) {
  ((std::cin >> args), ...);
}

} // namespace util

void solve() {
  i64 d;
  util::scan(d);
  if (d == 1 || d == 2 || d == 4) {
    util::println(0);
    return;
  }
  if (d == 3) {
    util::println(1);
    return;
  }
  i64 x = 1, y = 1, min = std::numeric_limits<i64>::max();
  while (x * x <= d / 2) {
    i64 xSq = x * x;
    i64 root = std::sqrt(d - xSq);
    min = std::min(min, std::abs(d - xSq - root * root));
    ++root;
    min = std::min(min, std::abs(d - xSq - root * root));
    ++x;
  }
  util::println(min);
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}