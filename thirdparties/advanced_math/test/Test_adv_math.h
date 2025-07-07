/**
 *******************************************************************************
 * @file    test_4.c
 * @brief   test case 4: Reading
 * @details
 *             -
 * @date    2025/05/19
 *
 * @author  Binh Pham
 *******************************************************************************
 */
/* Prevent recursion -------------------------------------------------------- */
#ifndef TEST_ADV_MATH_H
#define TEST_ADV_MATH_H

/* Includes ----------------------------------------------------------------- */
#include "unity.h"
#include "unity_fixture.h"
#include "adv_math.h"

/* Public defines ----------------------------------------------------------- */

/* Test group tag */
#define TEST_GRP_TAG_POSITIVE       "positive"
#define TEST_GRP_TAG_NEGATIVE       "negative"
#define TEST_GRP_TAG_OPPOSITE_SIGNS "opposite_signs"
#define TEST_GRP_TAG_EDGES          "edges"
// 2. Mathematical Properties

/* Macros */
#define TEST_CASE(label, func, a, b, expect, delta)    { label, func, a, b, expect, delta }
#define TEST_CASE_SORT(label, func, arr_ptr, n, delta) { label, func, arr_ptr, n, NULL, delta }

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/* Public typedefs ---------------------------------------------------------- */

/**
 * @brief Test case struct for integer comparison operations
 */
typedef struct
{
  const char     *label;    ///< Test label
  op_func_int32_t func;     ///< Operation function pointer (int32)
  int32_t         a;        ///< First operand
  int32_t         b;        ///< Second operand
  int32_t         expected; ///< Expected result
  int32_t         delta;    ///< Allowed delta for result comparison
} test_comp_int_t;

/**
 * @brief Test case struct for float comparison operations
 */
typedef struct
{
  const char       *label;    ///< Test label
  op_func_float32_t func;     ///< Operation function pointer (float)
  float_t           a;        ///< First operand
  float_t           b;        ///< Second operand
  float_t           expected; ///< Expected result
  float_t           delta;    ///< Allowed delta for result comparison
} test_comp_float_t;

/**
 * @brief Test case struct for pair transform operations on integers
 */
typedef struct
{
  const char                  *label;      ///< Test label
  op_func_pair_transform_int_t func;       ///< Operation function pointer (pair transform)
  int32_t                      a;          ///< First input value
  int32_t                      b;          ///< Second input value
  int32_t                      expected_a; ///< Expected output for first value
  int32_t                      expected_b; ///< Expected output for second value
  int32_t                      delta;      ///< Allowed delta for result comparison
} test_pair_transform_case_int_t;

/**
 * @brief Test struct for input type of integer array
 */
typedef struct
{
  const char           *label;    ///< Test label (e.g. Bubble Sort Extreme Case)
  op_func_array_int32_t func;     ///< Operation function pointer (array)
  int32_t              *arr;      ///< Input array
  uint32_t              n;        ///< Number of elements in the array
  int32_t              *expected; ///< Expected output array
  int32_t               delta;    ///< Allowed delta between each i/o element
} test_array_int_t;

/* Function prototypes ------------------------------------------------------ */

void test_helper_int(test_comp_int_t *test_case, uint32_t num_tests);
void test_helper_float(test_comp_float_t *test_case, uint32_t num_tests);
void test_helper_pair_transform_int(test_pair_transform_case_int_t *test_case, uint32_t num_tests);
void test_helper_sort_array_int(test_array_int_t *test_case, uint32_t num_tests);
#endif /* TEST_ADV_MATH_H */

/* End of File -------------------------------------------------------------- */
