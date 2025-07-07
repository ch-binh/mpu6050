/**
 *******************************************************************************
 * @file    adv_math_algorithms.h
 * @brief   Advanced mathematical and algorithmic function declarations.
 * @details This is a high-level interface to various algorithms implemented in
 *C. Designed to support numerical computation, signal processing, and
 *          embedded-friendly math operations.
 *
 * @date    2025/06/15
 * @author  Binh Pham
 *******************************************************************************
 * @attention
 *
 *******************************************************************************
 */

/* Includes ----------------------------------------------------------------- */
#include "adv_math.h"
#include "stdlib.h"

/* Private defines ---------------------------------------------------------- */
#define _FUNC_TABLE              \
  {                              \
    ADVM_BASIC_OP_FUNC_TABLE,    \
    ADVM_GCD_LCM_FUNC_TABLE,     \
    ADVM_APPLICATION_FUNC_TABLE, \
  }

#define RAND_INT32() ((int32_t)(((uint32_t)(rand() & 0xFFFF) << 16) | ((uint32_t)(rand() & 0xFFFF))))

#define RAND_FLOAT(min, max) (min + ((float32_t)rand() / (float32_t)(RAND_MAX)) * (max - min))

/* Function definitions ----------------------------------------------------- */
void advm_init(void)
{
  advm_table_entry_t func_table[] = _FUNC_TABLE;

  for (uint_fast32_t i = 0; i < (sizeof(func_table) / sizeof(func_table[0])); i++)
  {
    advm_register_function(func_table[i].name, func_table[i].sig_type, func_table[i].func_ptr);
  }
}

void advm_randomize_arr_int32(int32_t *arr, uint32_t n, uint32_t min, uint32_t max)
{
  ADVM_CHECK_NO_RETURN(arr != NULL);
  ADVM_CHECK_NO_RETURN(n > 0);
  ADVM_CHECK_NO_RETURN(min < max);

  for (uint_fast32_t i = 0; i < n; ++i)
  {
    arr[i] = (int32_t)(min + (rand() % (max - min + 1)));
  }
}

void advm_randomize_arr_float32(float32_t *arr, uint32_t n, float32_t min, float32_t max)
{
  ADVM_CHECK_NO_RETURN(arr != NULL);
  ADVM_CHECK_NO_RETURN(n > 0);
  ADVM_CHECK_NO_RETURN(min < max);

  for (uint_fast32_t i = 0; i < n; ++i)
  {
    arr[i] = min + ((float32_t)rand() / (float32_t)(RAND_MAX)) * (max - min);
  }
}

/* End of file -------------------------------------------------------------- */
