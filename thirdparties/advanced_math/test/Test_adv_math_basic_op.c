/**
 *******************************************************************************
 * @file    Test_adv_math_basic_op.c
 * @brief   Test case for basic arithmetic operations in advanced math library.
 * @details
 *             -
 * @date    2025/05/19
 *
 * @author  Binh Pham
 *******************************************************************************
 */
/* Includes ----------------------------------------------------------------- */
#include "Test_adv_math.h"

/* Private defines ---------------------------------------------------------- */
/* Private typedefs --------------------------------------------------------- */

//* Test cases' inputs here =============================================== { */
// Add additional test cases to the table, don't adjust functions

// clang-format off


test_comp_float_t cases_add_float[] = {
//TESTCASE                         |FUNC     |FLOAT A,     |FLOAT B,         |EXPECTED RESULT      |DELTA             |COMMENT
//------------------------------------------------------------------------------------------------------------
  TEST_CASE("epsilon_vs_zero",     advm_add, FLT_EPSILON,  0.0f,              FLT_EPSILON,         FLT_EPSILON),       ///< test sai nếu bị rounded
  TEST_CASE("min_add_min",         advm_add, FLT_MIN,      FLT_MIN,           2.0f * FLT_MIN,      FLT_EPSILON),       ///< dễ fail nếu mất precision
  TEST_CASE("max_plus",            advm_add, FLT_MAX,      1e32f,             INFINITY,            FLT_EPSILON),       ///< overflow detection
  TEST_CASE("inf_add",             advm_add, INFINITY,     1000.0f,           INFINITY,            FLT_EPSILON),       ///< propagate infinity
  TEST_CASE("nan_add",             advm_add, NAN,          123.0f,            NAN,                 FLT_EPSILON),       ///< propagate nan
  TEST_CASE("cancel_out",          advm_add, 1e20f,        -1e20f,            0.0f,                FLT_EPSILON),       ///< catastrophic cancellation
  TEST_CASE("near_one",            advm_add, 1.0f,         FLT_EPSILON,       1.0f + FLT_EPSILON,  FLT_EPSILON),       ///< detect ULP error
  TEST_CASE("precision_loss",      advm_add, 1e-3f,        1e-7f,             0.0010001f,          FLT_EPSILON),       ///< loss of significance
  TEST_CASE("underflow",           advm_add, 1e-45f,       -1e-45f,           0.0f,                FLT_EPSILON),       ///< denormal test (1 bit diff)
  TEST_CASE("associativity_fail",  advm_add, 1e30f,        -1e30f + 1.0f,     0.0f,                FLT_EPSILON),       ///< floating point associative broken
};

/* Subtraction test cases */
test_comp_float_t cases_sub_float[] = {
//TESTCASE                         |FUNC     |FLOAT A,     |FLOAT B,         |EXPECTED RESULT        |DELTA              |COMMENT
//------------------------------------------------------------------------------------------------------------
  TEST_CASE("basic",               advm_sub, 10.0f,         3.0f,               7.0f,                FLT_EPSILON),       ///< simple subtraction
  TEST_CASE("zero",                advm_sub, 0.0f,          0.0f,               0.0f,                FLT_EPSILON),       ///< zero minus zero
  TEST_CASE("negative_result",     advm_sub, 5.0f,          10.0f,              -5.0f,               FLT_EPSILON),       ///< negative result
  TEST_CASE("inf_minus",           advm_sub, INFINITY,      1.0f,               INFINITY,            FLT_EPSILON),       ///< inf - x = inf
  TEST_CASE("minus_inf",           advm_sub, 1.0f,          INFINITY,           -INFINITY,           FLT_EPSILON),       ///< x - inf = -inf
  TEST_CASE("nan_minus",           advm_sub, NAN,           1.0f,               NAN,                 FLT_EPSILON),       ///< nan - x = nan
  TEST_CASE("sub_nan",             advm_sub, 1.0f,          NAN,                NAN,                 FLT_EPSILON),       ///< x - nan = nan
  TEST_CASE("inf_minus_inf",       advm_sub, INFINITY,      INFINITY,           NAN,                 FLT_EPSILON),       ///< undefined (inf - inf)
  TEST_CASE("near_cancel",         advm_sub, 1.000001f,     1.000000f,          0.000001f,           FLT_EPSILON),       ///< precision sensitive
  TEST_CASE("eps_sub",             advm_sub, 1.0f,          FLT_EPSILON,        1.0f - FLT_EPSILON,  FLT_EPSILON),       ///< subtract epsilon
  TEST_CASE("min_sub_min",         advm_sub, FLT_MIN,       FLT_MIN,            0.0f,                FLT_EPSILON),       ///< min - min
  TEST_CASE("underflow",           advm_sub, 1e-45f,        1e-45f,             0.0f,                FLT_EPSILON),       ///< denormal underflow
  TEST_CASE("assoc_fail",          advm_sub, (1e30f + 1.0f) - 1e30f, 1.0f,      -1.0f,               FLT_EPSILON),       ///< breaks associativity
};

/* Multiplication test cases */
test_comp_float_t cases_mul_float[] = {
//TESTCASE                         |FUNC     |FLOAT A,     |FLOAT B,            |EXPECTED RESULT     |DELTA             |COMMENT
//------------------------------------------------------------------------------------------------------------
  TEST_CASE("zero",                advm_mul, 0.0f,          1234.5f,            0.0f,                FLT_EPSILON),       ///< zero times anything
  TEST_CASE("negative",            advm_mul, -3.0f,         2.0f,               -6.0f,               FLT_EPSILON),       ///< negative result
  TEST_CASE("inf",                 advm_mul, INFINITY,      2.0f,               INFINITY,            FLT_EPSILON),       ///< inf * x = inf
  TEST_CASE("nan",                 advm_mul, NAN,           1.0f,               NAN,                 FLT_EPSILON),       ///< nan * x = nan
  TEST_CASE("small",               advm_mul, FLT_MIN,       2.0f,               2.0f * FLT_MIN,      FLT_EPSILON),       ///< small value
  TEST_CASE("large",               advm_mul, FLT_MAX/2.0f,  2.0f,               FLT_MAX,             FLT_EPSILON),       ///< large value
  TEST_CASE("overflow",            advm_mul, FLT_MAX,       2.0f,               INFINITY,            FLT_EPSILON),       ///< overflow
  TEST_CASE("denorm",              advm_mul, 1e-38f,        1e-10f,             0,                   FLT_EPSILON),       ///< denormalized result
  TEST_CASE("epsilon",             advm_mul, 1.0f,          FLT_EPSILON,        FLT_EPSILON,         FLT_EPSILON),       ///< multiply by epsilon
};


/**
 * @brief Division test cases (using float)
 * 
 */
test_comp_float_t cases_div_float[] = {
//TESTCASE                         |FUNC     |FLOAT A,     |FLOAT B,            |EXPECTED RESULT    |DELTA              |COMMENT
//------------------------------------------------------------------------------------------------------------
  TEST_CASE("basic",               advm_div, 10.0f,         2.0f,               5.0f,                FLT_EPSILON),       ///< simple division
  TEST_CASE("div_by_zero",         advm_div, 1.0f,          0.0f,               INFINITY,            FLT_EPSILON),       ///< divide by zero
  TEST_CASE("neg_div_by_zero",     advm_div, -23.0f,        0.0f,               -INFINITY,           FLT_EPSILON),       ///< negative divided by zero
  TEST_CASE("zero_div_zero",       advm_div, 0.0f,          0.0f,               NAN,                 FLT_EPSILON),       ///< zero divided by zero
  TEST_CASE("inf_div",             advm_div, INFINITY,      2.0f,               INFINITY,            FLT_EPSILON),       ///< inf / x = inf
  TEST_CASE("div_inf",             advm_div, 2.0f,          INFINITY,           0.0f,                FLT_EPSILON),       ///< x / inf = FLT_EPSILON
  TEST_CASE("nan",                 advm_div, NAN,           1.0f,               NAN,                 FLT_EPSILON),       ///< nan / x = nan
  TEST_CASE("rounding",            advm_div, 1.0f,          3.0f,               1.0f / 3.0f,         FLT_EPSILON),       ///< rounding test
  TEST_CASE("tiny",                advm_div, FLT_MIN,       2.0f,               FLT_MIN / 2.0f,      FLT_EPSILON),       ///< tiny / 2
  TEST_CASE("large",               advm_div, FLT_MAX,       2.0f,               FLT_MAX / 2.0f,      FLT_EPSILON),       ///< large / 2
};
// clang-format on
//* ======================================================================= } */

/* Test helpers ------------------------------------------------------------- */

/*
 * TEST CASES
 * =============================================================================
 */

TEST_GROUP(BASIC_OP);

TEST_SETUP(BASIC_OP)
{
  // intentionally left empty
}

TEST_TEAR_DOWN(BASIC_OP)
{
  // intentionally left empty
}

/*
 * ADDITION
 * =============================================================================
 */

TEST(BASIC_OP, add_float)
{
  test_helper_float(cases_add_float, ARRAY_SIZE(cases_add_float));
}

/*
 * SUBTRACTION
 * =============================================================================
 */

TEST(BASIC_OP, sub_float)
{
  test_helper_float(cases_sub_float, ARRAY_SIZE(cases_sub_float));
}

/*
 * MULTIPLICATION
 * =============================================================================
 */

TEST(BASIC_OP, mul_float)
{
  test_helper_float(cases_mul_float, ARRAY_SIZE(cases_mul_float));
}

/*
 * DIVISION
 * =============================================================================
 */

TEST(BASIC_OP, div_float)
{
  test_helper_float(cases_div_float, ARRAY_SIZE(cases_div_float));
}

/* End of File -------------------------------------------------------------- */