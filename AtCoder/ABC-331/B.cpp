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
    int n, s, m, l;
    scan(n, s, m, l);

    if (n <= 6) {
      println(std::min(s, std::min(m, l)));
      return;
    }
    if (n <= 8) {
      println(std::min(2 * s, std::min(m, l)));
      return;
    }
    if (n <= 12) {
      println(std::min(2 * s, std::min(2 * m, l)));
      return;
    }

    int minPrice = std::numeric_limits<int>::max();
    for (int i = 0; i * 6 < n + 6; ++i) {
      for (int j = 0; j * 8 < n + 8; ++j) {
        int total = s * i + m * j;
        int bought = i * 6 + j * 8;

        if (bought < n) {
          total += ((n - bought) / 12) * l;
          total += (n - bought) % 12 ? l : 0;
        }

        minPrice = std::min(minPrice, total);
      }
    }

    println(minPrice);
  }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve(1);
  return 0;
}