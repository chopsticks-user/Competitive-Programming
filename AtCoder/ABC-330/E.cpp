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
  int n, q;
  util::scan(n, q);
  std::vector<int> a(n);
  std::map<int, int> m;
  for (auto &e : a) {
    util::scan(e);
    m[e]++;
  }

  std::vector<int> idx(q), v(q);
  for (int i = 0; i < q; ++i) {
    util::scan(idx[i], v[i]);

    m[a[idx[i] - 1]]--;
    if (m[a[idx[i] - 1]] == 0) {
      m.erase(a[idx[i] - 1]);
    }
    m[v[i]]++;
    a[idx[i] - 1] = v[i];

    int next = 0;
    bool found = false;
    for (const auto &p : m) {
      if (p.first != next) {
        util::println(next);
        found = true;
        break;
      }
      ++next;
    }

    if (!found) {
      util::println(m.end()->first);
    }
  }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}