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
  int n;
  std::string s;
  std::cin >> n >> s;
  for (int i = 0; i < n - 2; ++i) {
    if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
      std::cout << i + 1 << '\n';
      return;
    }
  }
  std::cout << -1 << '\n';
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}