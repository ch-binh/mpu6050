#include "unity_fixture.h"

static void RunAllTests(void)
{
  RUN_TEST_GROUP(BASIC_OP);
  RUN_TEST_GROUP(ADVM_NUM_THEO);
  RUN_TEST_GROUP(ADVM_SORT);
  RUN_TEST_GROUP(ADVM_APP);
}

int main(int argc, const char *argv[])
{
  return UnityMain(argc, argv, RunAllTests);
}