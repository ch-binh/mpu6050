/**
 *******************************************************************************
 * @file    cli.h
 * @brief   Command Line Interface for Advanced Math Library
 * @details
 *
 * @date    2025/06/24
 * @author  Binh Pham
 *******************************************************************************
 * @attention
 *
 *******************************************************************************
 */
/* Includes ----------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "advm_cli.h"
#include "adv_math.h"

/* Functions ---------------------------------------------------------------- */
#define STR_EQUAL(a, b) (strcmp(a, b) == 0)

int main(int argc, char *argv[])
{

  advm_init();

  if (argc < 4)
  {
    printf("Usage: %s <name> <a> <b>\n", argv[0]);
    return 1;
  }

  const char *target = argv[1];

  for (uint32_t i = 0; i < g_advm_func_table_count; ++i)
  {
    if (!STR_EQUAL(g_advm_func_table[i].name, target))
    {
      continue;
    }

    switch (g_advm_func_table[i].sig_type)
    {
    case (FUNC_FLOAT32):
    {
      float32_t         a    = atof(argv[2]);
      float32_t         b    = atof(argv[3]);
      op_func_float32_t func = (float32_t (*)(float32_t, float32_t))g_advm_func_table[i].func_ptr;
      float32_t         res  = func(a, b);
      printf("Result: %f\n", res);
    }
    break;
    case (FUNC_INT32):
    {
      int32_t a = atoi(argv[2]);
      int32_t b = atoi(argv[3]);

      op_func_int32_t func = (int32_t (*)(int32_t, int32_t))g_advm_func_table[i].func_ptr;
      int32_t         res  = func(a, b);
      printf("Result: %d\n", res);
    }
    break;
    case (FUNC_INT32_PT):
    {
      int32_t a = atoi(argv[2]);
      int32_t b = atoi(argv[3]);

      op_func_pair_transform_int_t func = (void (*)(int32_t, int32_t))g_advm_func_table[i].func_ptr;
      func(&a, &b);
      printf("Result: %d:%d\n", a, b);
    }
    break;
    default:
      printf("error\n");
      break;
    }

    return 0;
  }

  printf("Unknown function: %s\n", target);
  return 1;
}
/* End of file -------------------------------------------------------------- */
