#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
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

void solve(int nTests = 1) {
  using namespace std;
  using namespace util;

  if (nTests != 1) {
    scan(nTests);
  }
  while (nTests--) {
    int M, D, y, m, d;
    scan(M, D, y, m, d);

    if (d < D) {
      ++d;
    } else {
      d = 1;
      if (m < M) {
        ++m;
      } else {
        m = 1;
        ++y;
      }
    }

    println(y, " ", m, " ", d);
  }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve(1);
  return 0;
}