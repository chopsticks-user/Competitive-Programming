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
  int n, m, p;
  std::cin >> n >> m >> p;
  if (n < m) {
    std::cout << 0 << '\n';
    return;
  }
  int count = 1;
  if (n == m) {
    std::cout << count << '\n';
    return;
  }
  n -= m;
  count += n / p;
  std::cout << count << '\n';
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}