#include <VExercise2.h>

#include <bit>
#include <catch2/catch_test_macros.hpp>
#include <cstdint>

/**
 * @brief Shift register implementation
 *
 */
struct LFSR {
  uint16_t value;
  static constexpr uint16_t mask = 0x50a;

  /**
   * @brief Step through each iteration of the shift function
   *
   */
  void step() {
    uint16_t bits = value & mask;
    value = (value << 1) | (std::popcount(bits) & 1);
  }
};

/**
 * @brief Step through model simulation
 * 
 * @param model 
 */
void step(VExercise2 &model) {
  model.clk = 1;
  model.eval();
  model.clk = 0;
  model.eval();
}

/**
 * @brief Tests module for inverse of initial value
 *        when reset is high
 *
 * @param init the initial value
 */
void test_initial_value(uint16_t init) {
  VExercise2 model;
  model.init = init;
  model.reset = 1;
  step(model);
  model.reset = 0;

  LFSR lfsr{(uint16_t)~init};

  for (uint8_t cycles = 0; cycles < 100; cycles++) {
    REQUIRE(model.out == lfsr.value);
    step(model);
    lfsr.step();
  }

  model.reset = 1;
  step(model);
  REQUIRE(model.out == (uint16_t)~init);
}

TEST_CASE("Initial value 0x00") {
  test_initial_value(0x00);
}

TEST_CASE("Initial value 0xFF") {
  test_initial_value(0xFF);
}

TEST_CASE("Initial value 0x55") {
  test_initial_value(0x55);
}

TEST_CASE("Initial value 0xAA") {
  test_initial_value(0xAABB);
}
