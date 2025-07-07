#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(BASIC_OP)
{
  RUN_TEST_CASE(BASIC_OP, add_float);
  RUN_TEST_CASE(BASIC_OP, sub_float);
  RUN_TEST_CASE(BASIC_OP, mul_float);
  RUN_TEST_CASE(BASIC_OP, div_float);
}

TEST_GROUP_RUNNER(ADVM_NUM_THEO)
{
  RUN_TEST_CASE(ADVM_NUM_THEO, gcd);
  RUN_TEST_CASE(ADVM_NUM_THEO, lcm);
}

TEST_GROUP_RUNNER(ADVM_SORT)
{
  RUN_TEST_CASE(ADVM_SORT, bubble);
}

TEST_GROUP_RUNNER(ADVM_APP)
{
  RUN_TEST_CASE(ADVM_APP, simplify_fraction_non_zeros_positives);
}
