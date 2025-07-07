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
// clang-format off
#define _TEST_CASE_ALL_ALGOS_GCD(label, a, b, expected, delta)                         \
  TEST_CASE(label " - euclid",         advm_gcd_iter_euclid,    a, b, expected, delta), \
  TEST_CASE(label " - recursion",      advm_gcd_recursion,      a, b, expected, delta), \
  TEST_CASE(label " - binary",         advm_gcd_binary,         a, b, expected, delta), \
  TEST_CASE(label " - stein",          advm_gcd_stein,          a, b, expected, delta), \
  TEST_CASE(label " - stein_naive",    advm_gcd_stein_naive,    a, b, expected, delta)


#define _TEST_CASE_ALL_ALGOS_LCM(label, a, b, expected, delta)                         \
  TEST_CASE(label " - classic",         advm_lcm_classic,    a, b, expected, delta)

// clang-format on

/* Private typedefs --------------------------------------------------------- */
/* Private function prototypes ---------------------------------------------- */

//* Test cases' inputs here =============================================== { */
// Add additional test cases to the table, no nedd to adjust functions

// clang-format off
/* Test cases for GCD algorithms */
test_comp_int_t cases_gcd[] = {
  // TESTCASE                          | A        | B          | EXPECTED            | DELTA | COMMENT
  //-----------------------------------------------------------------------------------------------
  _TEST_CASE_ALL_ALGOS_GCD("zero-zero",          0,           0, GCD_SPECIAL_CASE_RETURN, 0), // Both zero
  _TEST_CASE_ALL_ALGOS_GCD("zero-left",          0,      123456,                  123456, 0), // Left zero
  _TEST_CASE_ALL_ALGOS_GCD("zero-right",    123456,           0,                  123456, 0), // Right zero
  _TEST_CASE_ALL_ALGOS_GCD("reverse",           25,         100,                      25, 0), // GCD(25,100)
  _TEST_CASE_ALL_ALGOS_GCD("large",     UINT32_MAX,       65536,                       1, 0), // Large numbers
  _TEST_CASE_ALL_ALGOS_GCD("prime-diff",1000000000,   999999937,                       1, 0), // Large primes
  _TEST_CASE_ALL_ALGOS_GCD("same",               2,           2,                       2, 0), // Same numbers
  _TEST_CASE_ALL_ALGOS_GCD("complex",       987654,      123456,                       6, 0), // Arbitrary values
  _TEST_CASE_ALL_ALGOS_GCD("classic",           48,          18,                       6, 0), // Classic example
  _TEST_CASE_ALL_ALGOS_GCD("int-extreme",INT32_MIN,   INT32_MAX, GCD_SPECIAL_CASE_RETURN, 0), // Special case INT32_MIN
};

/* Test cases for LCM algorithms */
test_comp_int_t cases_lcm[] = {
  // TESTCASE                | A         | B         | EXPECTED                | DELTA | COMMENT
  //-----------------------------------------------------------------------------------------------
  _TEST_CASE_ALL_ALGOS_LCM("zero-zero",          0,           0, LCD_SPECIAL_CASE_RETURN, 0), // Both zero
  _TEST_CASE_ALL_ALGOS_LCM("zero-a",             0,          13,                       0, 0), // a = 0
  _TEST_CASE_ALL_ALGOS_LCM("zero-b",            42,           0,                       0, 0), // b = 0
  _TEST_CASE_ALL_ALGOS_LCM("basic-coprime",      3,           2,                       6, 0), // Coprime
  _TEST_CASE_ALL_ALGOS_LCM("equal",              5,           5,                       5, 0), // a == b
  _TEST_CASE_ALL_ALGOS_LCM("multiple",           5,          20,                      20, 0), // b is multiple of a
  _TEST_CASE_ALL_ALGOS_LCM("reverse-multiple",  20,           5,                      20, 0), // a is multiple of b
  _TEST_CASE_ALL_ALGOS_LCM("negative-positive", -4,           6,                      12, 0), // mix signs
  _TEST_CASE_ALL_ALGOS_LCM("positive-negative",  7,         -14,                      14, 0),
  _TEST_CASE_ALL_ALGOS_LCM("both-negative",    -12,         -15,                      60, 0),
  _TEST_CASE_ALL_ALGOS_LCM("large-numbers",  65535,       32767,              2147385345, 0), // near limit
  _TEST_CASE_ALL_ALGOS_LCM("self-multiplier",32768,       65536,                   65536, 0), // 
  _TEST_CASE_ALL_ALGOS_LCM("overflow",       32769,       65536, LCD_SPECIAL_CASE_RETURN, 0), // may trigger overflow
};

// clang-format on

//* ======================================================================= } */

/* Test helpers ------------------------------------------------------------- */

/*
 * TEST CASES
 * =============================================================================
 */

TEST_GROUP(ADVM_NUM_THEO);

TEST_SETUP(ADVM_NUM_THEO)
{
  // intentionally left empty
}

TEST_TEAR_DOWN(ADVM_NUM_THEO)
{
  // intentionally left empty
}

/*
 *
 * =============================================================================
 */

TEST(ADVM_NUM_THEO, gcd)
{
  test_helper_int(cases_gcd, ARRAY_SIZE(cases_gcd));
}

TEST(ADVM_NUM_THEO, lcm)
{
  test_helper_int(cases_lcm, ARRAY_SIZE(cases_lcm));
}

/* End of File -------------------------------------------------------------- */