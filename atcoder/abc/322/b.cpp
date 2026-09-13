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
  std::string s, t;
  std::cin >> n >> m >> s >> t;

  bool prefix = true, suffix = true;
  for (int i = 0; i < n; ++i) {
    if (prefix && s[i] != t[i]) {
      prefix = false;
    }

    if (suffix && s[i] != t[m - n + i]) {
      suffix = false;
    }
  }

  if (prefix) {
    if (suffix) {
      std::cout << "0\n";
    } else {
      std::cout << "1\n";
    }
  } else if (suffix) {
    std::cout << "2\n";
  } else {
    std::cout << "3\n";
  }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}