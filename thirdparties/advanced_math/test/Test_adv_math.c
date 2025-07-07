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

/* Inlcludes ---------------------------------------------------------------- */
#include "Test_adv_math.h"

#define TEST_FAIL_MSG_LEN (128)

/* Test helpers ------------------------------------------------------------- */

void test_helper_int(test_comp_int_t *test_case, uint32_t num_tests)
{
  char msg[TEST_FAIL_MSG_LEN];
  for (uint32_t i = 0; i < num_tests; ++i)
  {
    int32_t result = test_case[i].func(test_case[i].a, test_case[i].b);

    snprintf(msg, sizeof(msg), "[%s][%d] %d op %d = %d, expected %d, delta: %d", test_case[i].label, i,
             test_case[i].a, test_case[i].b, result, test_case[i].expected, test_case[i].delta);

    TEST_ASSERT_INT32_WITHIN_MESSAGE(test_case[i].delta, test_case[i].expected, result, msg);
  }
}

void test_helper_float(test_comp_float_t *test_case, uint32_t num_tests)
{
  char msg[TEST_FAIL_MSG_LEN];
  for (uint32_t i = 0; i < num_tests; ++i)
  {
    float32_t result = test_case[i].func(test_case[i].a, test_case[i].b);

    snprintf(msg, sizeof(msg), "[%s][%d] %.5f op %.5f = %.5f, expected %.5f, delta %.5f", test_case[i].label,
             i, test_case[i].a, test_case[i].b, result, test_case[i].expected, test_case[i].delta);

    if (isnan(test_case[i].expected))
      TEST_ASSERT_TRUE_MESSAGE(isnan(result), msg);
    else
      TEST_ASSERT_FLOAT_WITHIN_MESSAGE(test_case[i].delta, test_case[i].expected, result, msg);
  }
}

void test_helper_pair_transform_int(test_pair_transform_case_int_t *test_case, uint32_t num_tests)
{
  char msg[TEST_FAIL_MSG_LEN];
  for (uint32_t i = 0; i < num_tests; ++i)
  {
    int32_t origin_a = test_case[i].a;
    int32_t origin_b = test_case[i].b;
    test_case[i].func(&test_case[i].a, &test_case[i].b);

    snprintf(msg, sizeof(msg), "[%s][%d] %d:%d, expected %d:%d, delta: %d", test_case[i].label, i, origin_a,
             origin_b, test_case[i].expected_a, test_case[i].expected_b, test_case[i].delta);

    TEST_ASSERT_INT32_WITHIN_MESSAGE(test_case[i].delta, test_case[i].expected_a, test_case[i].a, msg);
    TEST_ASSERT_INT32_WITHIN_MESSAGE(test_case[i].delta, test_case[i].expected_b, test_case[i].b, msg);
  }
}


/**
 * @brief
 *
 * @param test_case
 *  test_case->expected  is ignored since the test expects a sorted array
 *  test_case->delta is ignored since the test expects a sorted array
 * @param num_tests
 */
void test_helper_sort_array_int(test_array_int_t *test_case, uint32_t num_tests)
{
  char msg[TEST_FAIL_MSG_LEN];
  for (uint32_t i = 0; i < num_tests; ++i)
  {
    test_case[i].func(test_case[i].arr, test_case[i].n);

    snprintf(msg, sizeof(msg), "[%s][%d] is not sorted properly", test_case[i].label, i);

    for (uint_fast32_t j = 1; j < test_case[i].n; j++)
    {
      if (test_case[i].arr[j - 1] > test_case[i].arr[j])
      {
        PRINT_INT_ARR(test_case[i].arr, test_case[i].n);
        TEST_FAIL_MESSAGE(msg);
      }
    }
  }
}

/* End of File -------------------------------------------------------------- */