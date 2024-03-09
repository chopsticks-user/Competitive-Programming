#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <vector>

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(m);
  for (auto &i : a) {
    std::cin >> i;
  }

  for (int i = 1, j = 0; i <= n && j < m;) {
    if (i > a[j]) {
      ++j;
    } else {
      std::cout << a[j] - i << std::endl;
      ++i;
    }
  }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}