#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <vector>

namespace util {

typedef int i32;
typedef long i64;
typedef unsigned int u32;
typedef unsigned long u64;
typedef float f32;
typedef double f64;

#define repf(i, b, e) for (decltype(e) i = (b); (i) < (e); ++(i))
#define repb(i, b, e) for (decltype(e) i = (b); (i) >= (e); --(i))
#define repfs(i, b, e, s) for (decltype(e) i = (b); (i) < (e); (i) += (s))
#define repbs(i, b, e, s) for (decltype(e) i = (b); (i) >= (e); (i) -= (s))

template <typename... Type> //
void print(const Type &...args) {
  ((std::cout << args), ...);
}

template <typename... Type> //
void println(const Type &...args) {
  ((std::cout << args), ...);
  std::cout << '\n';
}

template <typename... Type> //
void scan(Type &...args) {
  ((std::cin >> args), ...);
}

template <typename Type> //
Type scan() {
  Type input;
  std::cin >> input;
  return input;
}

template <typename Type, u64 nInputs> //
std::array<Type, nInputs> scan() {
  std::array<Type, nInputs> inputs;
  for (auto &input : inputs) {
    std::cin >> input;
  }
  return inputs;
}

template <typename... Type> //
std::enable_if_t<std::tuple_size_v<std::tuple<Type...>> - 1,
                 std::tuple<Type...>>
scan() {
  std::tuple<Type...> inputs;
  ((std::cin >> std::get<Type>(inputs)), ...);
  return inputs;
}

// std::vector I/O
template <template <typename> typename Container, typename Type> //
void scan(Container<Type> &vec) {
  for (auto &element : vec) {
    scan(element);
  }
}

template <template <typename> typename Container, typename Type> //
void print(const Container<Type> &vec) {
  for (const auto &element : vec) {
    print(element, ' ');
  }
}

template <template <typename> typename Container, typename Type> //
void println(const Container<Type> &vec) {
  print(vec);
  println();
}

} // namespace util

struct rect {
  int a, b, c, d;
};

void solve(int nTests = util::scan<int>()) {
  using namespace std;
  using namespace util;

  while (nTests--) {
    int n = scan<int>();
    vector<int> a(n), p(n - 1);
    scan(a);
    scan(p);
    double sum = 0.0;
    bool hasOne = false;
    repf(i, 0, n - 1) {
      if (p[i] == 1) {
        hasOne = true;
        sum += double(a[i + 1] + a[p[i] - 1]);
      }
    }

    if (!hasOne) {
      sum = a[0];
    }

    if (sum > 0) {
      println('+');
    } else if (sum == 0) {
      println('0');
    } else {
      println('-');
    }
  }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
  try {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(1);
    return EXIT_SUCCESS;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Uncaught exception" << std::endl;
  }
  return EXIT_FAILURE;
}