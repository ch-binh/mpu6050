/**
 ******************************************************************************
 * @file    adv_math_algorithms.h
 * @brief   Advanced mathematical and algorithmic function declarations.
 * @details This is a high-level interface to various algorithms implemented in
 *C. Designed to support numerical computation, signal processing, and
 *          embedded-friendly math operations.
 *
 * @date    2025/06/15
 * @author  Binh Pham
 ******************************************************************************
 */

/* Includes ----------------------------------------------------------------- */
#include "advm_basic_op.h"

/* Implementation ----------------------------------------------------------- */
float32_t advm_add(float32_t a, float32_t b)
{
  return a + b;
}

float32_t advm_sub(float32_t a, float32_t b)
{
  return a - b;
}

float32_t advm_mul(float32_t a, float32_t b)
{
  return a * b;
}

float32_t advm_div(float32_t a, float32_t b)
{
  // note: float32_t type has already handle special case (EX: 0/0) so we don't
  // need to implement self guard here.
  return a / b;
}

int32_t advm_mod(int32_t a, int32_t b)
{
  return a % b;
}

/* End of File -------------------------------------------------------------- */
