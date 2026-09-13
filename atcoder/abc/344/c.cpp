#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ranges>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace util {

//===================================Defs======================================

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
#define reprf(e, c, ...) for (__VA_OPT__(__VA_ARGS__;) auto &e : (c))
#define reprcf(e, c, ...) for (__VA_OPT__(__VA_ARGS__;) const auto &e : (c))
#define reprb(e, c, ...)                                                       \
  for (__VA_OPT__(__VA_ARGS__;) auto &e : std::ranges::reverse_view(c))
#define reprcb(e, c, ...)                                                      \
  for (__VA_OPT__(__VA_ARGS__;) const auto &e : std::ranges::reverse_view(c))

//===================================I/O=======================================

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

//===================================Graph=====================================

using AdjList = std::vector<std::unordered_set<u64>>;
template <typename TWeigth>
using WAdjList = std::vector<std::unordered_map<int, TWeigth>>;

class UWGraph;
template <typename TWeigth> class WGraph;

class UWGraph {
public:
  UWGraph() = default;
  ~UWGraph() = default;

  explicit UWGraph(u64 nVertices) noexcept : m_adjList{nVertices} {}

  auto size() const noexcept -> u64 { return m_adjList.size(); }

  auto resize(u64 nVertices) noexcept {
    m_adjList.resize(nVertices);
    return *this;
  }

  auto begin() noexcept { return m_adjList.begin(); }
  auto end() noexcept { return m_adjList.end(); }
  auto rbegin() noexcept { return m_adjList.rbegin(); }
  auto rend() noexcept { return m_adjList.rend(); }

  auto add(u64 u, u64 v) {
    m_adjList.at(u).insert(v);
    m_adjList.at(v).insert(u);
  }

  auto remove(u64 u, u64 v) {
    m_adjList.at(u).erase(v);
    m_adjList.at(v).erase(u);
  }

  auto adjList(u64 v) const noexcept -> const std::unordered_set<u64> & {
    return m_adjList.at(v);
  }

private:
  AdjList m_adjList;
};

template <typename TWeigth> //
class WGraph {
public:
private:
  WAdjList<TWeigth> m_adjList;
};

//===================================Misc======================================

template <typename T> //
concept hasIterator =
    std::same_as<std::void_t<decltype(std::begin(std::declval<T &>())),
                             decltype(std::end(std::declval<T &>()))>,
                 void>;

template <typename TContainer> //
void shuffle(TContainer &c)
  requires hasIterator<TContainer>
{
  std::shuffle(c.begin(), c.end(), std::mt19937{std::random_device{}()});
}

} // namespace util

void solve(int nTests = util::scan<int>()) {
  using namespace std;
  using namespace util;

  while (nTests--) {
    u64 n = scan<u64>();
    vector<u64> a(n);
    for (auto &i : a) {
      i = scan<u64>();
    }

    u64 m = scan<u64>();
    vector<u64> b(m);
    for (auto &i : b) {
      i = scan<u64>();
    }

    u64 l = scan<u64>();
    vector<u64> c(l);
    for (auto &i : c) {
      i = scan<u64>();
    }

    u64 q = scan<u64>();
    vector<u64> x(q);
    for (auto &i : x) {
      i = scan<u64>();
    }

    set<u64> possibleSums{};
    for (u64 i = 0; i < n; ++i) {
      for (u64 j = 0; j < m; ++j) {
        for (u64 k = 0; k < l; ++k) {
          possibleSums.insert(a[i] + b[j] + c[k]);
        }
      }
    }

    for (auto &i : x) {
      if (!possibleSums.contains(i)) {
        println("No");
        continue;
      }
      println("Yes");
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