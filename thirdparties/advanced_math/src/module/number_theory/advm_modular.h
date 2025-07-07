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
/* Prvent recursion --------------------------------------------------------- */
#ifndef _ADVM_NUMBER_THEORY_MODULAR_H
#define _ADVM_NUMBER_THEORY_MODULAR_H

/* Include ------------------------------------------------------------------ */
#include "advm_config.h"

/* Public defines ----------------------------------------------------------- */

/* Public variables --------------------------------------------------------- */

/* Public macros ------------------------------------------------------------ */

/* Function protoypes ------------------------------------------------------- */

int32_t advm_mod_pow(int32_t base, int32_t exp, int32_t mod); // base^exp % mod

/* Function tables ---------------------------------------------------------- */

// extern op_func_int32_t g_advm_gcd_func_table[GCD_NUM_OF_ALGO];

#endif // _ADVM_NUMBER_THEORY_MODULAR_H

/* End of File -------------------------------------------------------------- */
