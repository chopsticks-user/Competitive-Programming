#pragma once

#include <chrono>
#include <cmath>
#include <iostream>
#include <print>

using i64 = std::int64_t;
using i32 = std::int32_t;
using i16 = std::int16_t;
using i8 = std::int8_t;

using u64 = std::uint64_t;
using u32 = std::uint32_t;
using u16 = std::uint16_t;
using u8 = std::uint8_t;

using f32 = float;
using f64 = double;
using b8 = bool;
using b32 = u32;
using c8 = char;
using szt = std::size_t;

namespace config {
extern b8 const multipleTests;
}

namespace rv = std::ranges::views;
namespace rng = std::ranges;

auto solve() -> void;

auto main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) -> i32 {
  try {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i32 nTests = 1;
    if (config::multipleTests) {
      std::cin >> nTests;
    }
    while (nTests--) {
      solve();
    }
    return EXIT_SUCCESS;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Uncaught exception" << std::endl;
  }
  return EXIT_FAILURE;
}