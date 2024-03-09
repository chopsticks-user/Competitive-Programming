#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <vector>

void solve() {
  int n, d, p;
  std::cin >> n >> d >> p;
  int n_cases = n / d + 2;
  std::vector<int64_t> f(n), dp(n_cases);
  int64_t sum = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> f[i];
    sum += f[i];
  }
  std::sort(f.begin(), f.end(), std::greater<int>());

  dp[0] = sum;
  int64_t min = dp[0];
  for (int i = 1; i < n_cases; ++i) {
    dp[i] = dp[i - 1];
    for (int j = (i - 1) * d; j < i * d && j < n; ++j) {
      dp[i] -= f[j];
    }
    dp[i] += p;
    min = std::min(min, dp[i]);
  }

  std::cout << min << '\n';
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}