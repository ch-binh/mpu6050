/**
 *******************************************************************************
 * @file    Test_adv_math_application.c
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
#define TEST_CASE_SIMPLIFY_FRAC(label, func, a, b, expect_a, expected_b, delta) \
  { label, func, a, b, expect_a, expected_b, delta }

/* Private typedefs --------------------------------------------------------- */

//* Test cases' inputs here =============================================== { */
// Add additional test cases to the table, don't adjust functions

// clang-format off
test_pair_transform_case_int_t cases_simplify_fraction[] = {
  // TESTCASE                                      |FUNC                    |A     |B     |EXPECTED A |EXPECTED B |DELTA |COMMENT
  //--------------------------------------------------------------------------------------------------------------
  TEST_CASE_SIMPLIFY_FRAC("basic",                 advm_simplify_fraction,  63,   21,     3,        1,      0), ///< 63/21 = 3/1
  TEST_CASE_SIMPLIFY_FRAC("already_simplified",    advm_simplify_fraction,   7,   13,     7,       13,      0), ///< 7/13 đã tối giản
  TEST_CASE_SIMPLIFY_FRAC("negative_numerator",    advm_simplify_fraction, -12,   18,    -2,        3,      0), ///< -12/18 = -2/3
  TEST_CASE_SIMPLIFY_FRAC("negative_denominator",  advm_simplify_fraction,  12,  -18,    -2,        3,      0), ///< 12/-18 = -2/3
  TEST_CASE_SIMPLIFY_FRAC("both_negatives",        advm_simplify_fraction, -12, -18,     2,        3,      0), ///< -12/-18 = 2/3
  TEST_CASE_SIMPLIFY_FRAC("zero_numerator",        advm_simplify_fraction,   0,   25,     0,        1,      0), ///< 0/x = 0/1
  TEST_CASE_SIMPLIFY_FRAC("one_as_numerator",      advm_simplify_fraction,   1,   5,      1,        5,      0), ///< 1/5 giữ nguyên
  TEST_CASE_SIMPLIFY_FRAC("equal_values",          advm_simplify_fraction,  42,   42,     1,        1,      0), ///< x/x = 1/1
  TEST_CASE_SIMPLIFY_FRAC("gcd_is_one",            advm_simplify_fraction,  25,   14,    25,       14,      0), ///< GCD = 1
  TEST_CASE_SIMPLIFY_FRAC("large_values",          advm_simplify_fraction,  1000, 250,    4,        1,      0), ///< 1000/250 = 4/1
  TEST_CASE_SIMPLIFY_FRAC("int_min_case",          advm_simplify_fraction, INT32_MIN, INT32_MAX, INT32_MIN, INT32_MAX, 0), ///< edge case, không chia được
};
// clang-format on
//* ======================================================================= } */

/* Test helpers ------------------------------------------------------------- */

/*
 * TEST CASES
 * =============================================================================
 */

TEST_GROUP(ADVM_APP);

TEST_SETUP(ADVM_APP)
{
  // intentionally left empty
}

TEST_TEAR_DOWN(ADVM_APP)
{
  // intentionally left empty
}

/*
 * ADDITION
 * =============================================================================
 */

TEST(ADVM_APP, simplify_fraction_non_zeros_positives)
{
  test_helper_pair_transform_int(cases_simplify_fraction, ARRAY_SIZE(cases_simplify_fraction));
}
/* End of File -------------------------------------------------------------- */