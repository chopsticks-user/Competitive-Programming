#include <algorithm>
#include <cmath>
#include <iostream>
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
  int n, l, count = 0;
  util::scan(n, l);
  std::vector<int> a(n);
  for (auto &i : a) {
    util::scan(i);
    if (i >= l) {
      count++;
    }
  }
  util::println(count);
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}