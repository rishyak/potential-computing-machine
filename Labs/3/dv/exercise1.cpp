#include <VExercise1.h>
#include <catch2/catch_test_macros.hpp>

void test_op(uint8_t code,
             uint8_t a_start,
             uint8_t a_end,
             uint8_t b_start,
             uint8_t b_end,
             uint8_t(op)(uint8_t, uint8_t)) {
  VExercise1 model;
  model.op = code;

  for (model.a = a_start;; model.a++) {
    for (model.b = b_start;; model.b++) {
      model.eval();
      uint8_t result = op(model.a, model.b);
      CAPTURE(model.a, model.b, result, model.out);
      REQUIRE(result == model.out);

      if (model.b == b_end) break;
    }
    if (model.a == a_end) break;
  }
}

TEST_CASE("Opcode 0, XOR") {
  test_op(0, 0, UINT8_MAX, 0, UINT8_MAX, [](uint8_t a, uint8_t b) -> uint8_t { return a ^ b; });
}

TEST_CASE("Opcode 1, Left-shift") {
  test_op(1, 0, UINT8_MAX, 0, 8, [](uint8_t a, uint8_t b) -> uint8_t { return a << b; });
}

TEST_CASE("Opcode 2, Modulo") {
  test_op(2, 0, UINT8_MAX, 1, UINT8_MAX, [](uint8_t a, uint8_t b) -> uint8_t { return a % b; });
}

TEST_CASE("Opcode 3, De Morgan") {
  test_op(3, 0, UINT8_MAX, 0, UINT8_MAX, [](uint8_t a, uint8_t b) -> uint8_t { return ~(a & b); });
}
