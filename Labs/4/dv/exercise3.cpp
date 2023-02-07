#include <bit>
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <random>

#include <VExercise3.h>

/**
 * @brief Simulate Mystery1 module
 *
 * @param a a input
 * @param b b input
 * @param c c input
 *
 * @return uint8_t d output
 */
uint8_t mystery1(uint8_t a, uint8_t b, uint8_t c) {
  switch(a) {
    case 0:
      return ((b & 0x7) << 3) | (c & 0x7);
    case 1:
      return (1 << 6) | ((c & 0x7) << 3) | (b & 0x7);
    case 2:
      return b;
    default:
      return c;
  }
}

/**
 * @brief Simulate Mystery2 module
 *
 */
struct Mystery2 {
  uint8_t count = 0;
  uint16_t out;

  /**
   * @brief Reset module
   *
   * @param a alpha input
   * @param b beta input
   *
   * @return uint16_t output
   */
  uint16_t reset(uint8_t a, uint8_t b) {
    out = (b << 8) | a;
    count = 0;
    return out;
  }

  /**
   * @brief Step thorough module
   *
   * @param a alpha input
   * @param b beta input
   *
   * @return uint16_t output
   */
  uint16_t step(uint8_t a, uint8_t b) {
    count %= 5;
    switch(count++) {
      case 0:
        return out = (a << 8) | (out & 0xFF);
      case 1:
        return out = (out & 0xFF00) | b;
      case 2:
        return out = ((out & 0xFF) << 8) | (out >> 8);
      case 3:
        return out = ((out & 0xF) << 12) | ((out & 0xF0) << 4) |
            ((out >> 4) & 0xF0) | ((out >> 12) & 0xF);
      default:
        return out = std::popcount(out) & 1;
    }
  }
};

/**
 * @brief Simulate Exercise3 module
 *
 */
struct Exercise3Sim {
  Mystery2 state;

  /**
   * @brief Reset module
   *
   * @param a a input
   * @param b b input
   * @param c c input
   *
   * @return uint16_t Output after reset
   */
  uint16_t reset(uint8_t a, uint16_t b, uint16_t c) {
    uint8_t a_in = mystery1(a & 0x3, b & 0xFF, c & 0xFF);
    uint8_t b_in = mystery1(a >> 2, b >> 8, c >> 8);
    return state.reset(a_in, b_in);
  }

  /**
   *
   * @brief Step through module
   *
   * @param a a input
   * @param b b input
   * @param c c input
   *
   * @return uint16_t Output after step
   */
  uint16_t step(uint8_t a, uint16_t b, uint16_t c) {
    uint8_t a_in = mystery1(a & 0x3, b & 0xFF, c & 0xFF);
    uint8_t b_in = mystery1(a >> 2, b >> 8, c >> 8);
    return state.step(a_in, b_in);
  }
};

/**
 * @brief Step through model simulation
 *
 * @param model
 */
void step(VExercise3& model) {
  model.clk = 1;
  model.eval();
  model.clk = 0;
  model.eval();
};

TEST_CASE("Test Random") {
  VExercise3 model;
  Exercise3Sim sim;

  std::default_random_engine re {std::random_device {}()};
  std::uniform_int_distribution<uint8_t> rand4 {0, 15};
  std::uniform_int_distribution<uint16_t> rand16;

  model.a = rand4(re);
  model.b = rand16(re);
  model.c = rand16(re);
  model.reset = 1;
  step(model);
  REQUIRE(model.out == sim.reset(model.a, model.b, model.c));
  model.reset = 0;

  for(size_t cycles = 0; cycles < 100; ++cycles) {
    model.a = rand4(re);
    model.b = rand16(re);
    model.c = rand16(re);
    step(model);
    CAPTURE(cycles, cycles % 5, model.a, model.b, model.c);
    uint16_t result = sim.step(model.a, model.b, model.c);
    REQUIRE(model.out == result);
  }
}
