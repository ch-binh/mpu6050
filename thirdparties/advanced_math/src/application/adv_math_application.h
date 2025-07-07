/**
 *******************************************************************************
 * @file    adv_math_application.h
 * @brief
 * @details
 *
 * @date    2025/06/23
 * @author  Binh Pham
 *******************************************************************************
 * @attention
 *
 *******************************************************************************
 */
/* Prevent includes recursive ----------------------------------------------- */
#ifndef _ADVM_APPLICATION_H
#define _ADVM_APPLICATION_H

/* Include ------------------------------------------------------------------ */
#include "adv_math.h"

/* Function tables ---------------------------------------------------------- */
//! add function here
// clang-format off
#define ADVM_APPLICATION_FUNC_TABLE \
  { "simplify-fraction", FUNC_INT32_PT, advm_simplify_fraction } // clang-format on

/* Public defines ----------------------------------------------------------- */

/* Public variables --------------------------------------------------------- */

/* Public macros ------------------------------------------------------------ */

/* Function prototypes ------------------------------------------------------- */

/**
 * @brief Simplify a fraction.
 *
 * @param[in, out] numerator Pointer to the numerator
 * @param[in, out] denominator Pointer to the denomerator
 *
 * @return Simplified numerator and denominator
 */
void advm_simplify_fraction(int32_t *numerator, int32_t *denominator);

/* Function tables ---------------------------------------------------------- */

// extern op_func_int32_t g_advm_gcd_func_table[GCD_NUM_OF_ALGO];

#endif // _ADVM_APPLICATION_H

/* End of File -------------------------------------------------------------- */
