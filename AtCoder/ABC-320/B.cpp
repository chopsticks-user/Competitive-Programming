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

int is_palindrome(const std::string &str, int start, int end) {
  int s = start, e = end;
  while (s < e) {
    if (str[s++] != str[e--]) {
      return 0;
    }
  }
  return end - start + 1;
}

void solve() {
  std::string s;
  std::cin >> s;

  int l = 1;
  for (int i = 0; i < s.length() - 1; ++i) {
    for (int j = i + 1; j < s.length(); ++j) {
      l = std::max(l, is_palindrome(s, i, j));
    }
  }
  std::cout << l << '\n';
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}