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
    int n, m, l;
    scan(n, m, l);

    std::vector<int> a(n);
    for (auto &e : a) {
      scan(e);
    }

    std::multimap<int, int, std::greater<int>> b;
    for (int i = 0; i < m; ++i) {
      int p;
      scan(p);
      b.insert({p, i});
    }

    std::map<int, std::set<int>> cd;
    while (l--) {
      int c, d;
      scan(c, d);
      cd[c - 1].insert(d - 1);
    }

    int max = 0;
    for (int i = 0; i < n; ++i) {
      auto bIt = b.begin();
      auto ci = cd[i];
      while (bIt != b.end()) {
        if (ci.find(bIt->second) == ci.end()) {
          max = std::max(max, a[i] + bIt->first);
          break;
        }
        bIt++;
      }
    }

    println(max);
  }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve(1);
  return 0;
}