/**
 *******************************************************************************
 * @file    Test_adv_math_sort.c
 * @brief
 * @details
 *             -
 * @date    2025/06/27
 *
 * @author  Binh Pham
 *******************************************************************************
 */
/* Includes ----------------------------------------------------------------- */
#include "Test_adv_math.h"

/* Private defines ---------------------------------------------------------- */

/* Private typedefs --------------------------------------------------------- */
/* Private function prototypes ---------------------------------------------- */

//* Test cases' inputs here =============================================== { */
// Add additional test cases to the table, no nedd to adjust functions

// clang-format off
/* Test cases for GCD algorithms */

static int32_t arr_1[] = {};                             // Empty
static int32_t arr_2[] = {5};                            // One element
static int32_t arr_3[] = {3, 2, 1};                      // Reversed
static int32_t arr_4[] = {1, 2, 3};                      // Already sorted
static int32_t arr_5[] = {4, -1, 0, 3, 2};               // Random unsorted
static int32_t arr_6[20] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20
};
static int32_t arr_7[20] = {
    20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
    10, 9, 8, 7, 6, 5, 4, 3, 2, 1
};
static int32_t arr_8[100] = {
    5,  1,  8,  4,  2,  9,  3,  6,  0,  7,
    14, 11, 13, 12, 10, 15, 19, 18, 16, 17,
    25, 21, 28, 24, 22, 29, 23, 26, 20, 27,
    35, 31, 38, 34, 32, 39, 33, 36, 30, 37,
    45, 41, 48, 44, 42, 49, 43, 46, 40, 47,
    55, 51, 58, 54, 52, 59, 53, 56, 50, 57,
    65, 61, 68, 64, 62, 69, 63, 66, 60, 67,
    75, 71, 78, 74, 72, 79, 73, 76, 70, 77,
    85, 81, 88, 84, 82, 89, 83, 86, 80, 87,
    95, 91, 98, 94, 92, 99, 93, 96, 90, 97
};


test_array_int_t cases_sort_int32[] = {
    // TESTCASE                           | FUNC                        | ARRAY    | LENGTH                     | DELTA         | COMMENT
    //-----------------------------------------------------------------------------------------------------------------------------------
    TEST_CASE_SORT("zero element",        advm_sort_bubble_int32,     arr_1,     sizeof(arr_1)/sizeof(arr_1[0]), 0), //    "Empty array"
    TEST_CASE_SORT("one element",         advm_sort_bubble_int32,     arr_2,     sizeof(arr_2)/sizeof(arr_2[0]), 0), //    "Trivial case"
    TEST_CASE_SORT("reverse sorted",      advm_sort_bubble_int32,     arr_3,     sizeof(arr_3)/sizeof(arr_3[0]), 0), //    "Worst case"
    TEST_CASE_SORT("already sorted",      advm_sort_bubble_int32,     arr_4,     sizeof(arr_4)/sizeof(arr_4[0]), 0), //    "No-op sort"
    TEST_CASE_SORT("random unordered",    advm_sort_bubble_int32,     arr_5,     sizeof(arr_5)/sizeof(arr_5[0]), 0), //    "General case"
    TEST_CASE_SORT("already sorted (20)", advm_sort_bubble_int32,     arr_6,     sizeof(arr_6)/sizeof(arr_6[0]), 0),
    TEST_CASE_SORT("reverse sorted (20)", advm_sort_bubble_int32,     arr_7,     sizeof(arr_7)/sizeof(arr_7[0]), 0),
    TEST_CASE_SORT("random 100",          advm_sort_bubble_int32,     arr_8,     sizeof(arr_8)/sizeof(arr_8[0]), 0),
};

// clang-format on

//* ======================================================================= } */

/* Test helpers ------------------------------------------------------------- */

/*
 * TEST CASES
 * =============================================================================
 */

TEST_GROUP(ADVM_SORT);

TEST_SETUP(ADVM_SORT)
{
  // intentionally left empty
}

TEST_TEAR_DOWN(ADVM_SORT)
{
  // intentionally left empty
}

/*
 *
 * =============================================================================
 */

TEST(ADVM_SORT, bubble)
{
  test_helper_sort_array_int(cases_sort_int32, ARRAY_SIZE(cases_sort_int32));
}

/* End of File -------------------------------------------------------------- */