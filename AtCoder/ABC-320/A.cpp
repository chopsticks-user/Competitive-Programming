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
  int64_t a, b;
  std::cin >> a >> b;
  std::cout << static_cast<int64_t>(std::pow(a, b)) +
                   static_cast<int64_t>(std::pow(b, a))
            << '\n';
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}