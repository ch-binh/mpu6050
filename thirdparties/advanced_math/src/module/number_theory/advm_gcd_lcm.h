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
#ifndef _ADVM_NUMBER_THEORY_GCD_LCM_H
#define _ADVM_NUMBER_THEORY_GCD_LCM_H

/* Include ------------------------------------------------------------------ */
#include "advm_config.h"

/* Function tables ---------------------------------------------------------- */
//! add function here
// clang-format off

/**
 * @brief Function table for module advm gcd and lcm algorithms
 *
 * @note  This table follows @ref advm_table_entry_t format
 */
#define ADVM_GCD_LCM_FUNC_TABLE \
  { "gcd",             FUNC_INT32, advm_gcd_iter_euclid }, \
  { "gcd_iter_euclid", FUNC_INT32, advm_gcd_iter_euclid }, \
  { "gcd_binary",      FUNC_INT32, advm_gcd_binary }, \
  { "gcd_stein",       FUNC_INT32, advm_gcd_stein }, \
  { "gcd_stein_naive", FUNC_INT32, advm_gcd_stein_naive }, \
  { "gcd_recursion",   FUNC_INT32, advm_gcd_recursion }, \
  { "lcm",             FUNC_INT32, advm_lcm_classic }, \
  { "lcm_classic",     FUNC_INT32, advm_lcm_classic }
// clang-format on

/* Public defines ----------------------------------------------------------- */
#define GCD_SPECIAL_CASE_RETURN 0 ///< inputs have 0
#define LCD_SPECIAL_CASE_RETURN 0 ///< special return value for LCD's invalid inputs
/// default GCD Algorithm
#if !defined(DEF_GCD_ALGORITHM)
#define DEF_GCD_ALGORITHM (GCD_ALGO_ITER_EUCLID)
#endif

/* Public variables --------------------------------------------------------- */
typedef enum
{
  GCD_ALGO_RECURSION = 0, ///< Simplest idea of GCD algorithm
  GCD_ALGO_ITER_EUCLID,   ///< Iterative Euclidean algorithm
  GCD_ALGO_BINARY,        ///< Different name for optimized Stein's GCD algorithm
  GCD_ALGO_STEIN,         ///< Optimized Stein's GCD algorithm
  GCD_ALGO_STEIN_NAIVE,   ///< Original Stein's GCD algorithm (for demonstration)
  GCD_NUM_OF_ALGO,
} advm_gcd_algo_t;

typedef enum
{
  LCM_ALGO_CLASSIC = 0, ///< Standard LCM: lcm(a, b) = |a * b| / gcd(a, b)
  // LCM_ALGO_BRUTE_FORCE, ///< Naive brute force (educational) - Not implemented
  // LCM_ALGO_FACTORIZE, ///< Prime factorization (if implemented) - Not implemented
  LCM_NUM_OF_ALGO
} advm_lcm_algo_t;

/* Public macros ------------------------------------------------------------ */

/* Function protoypes ------------------------------------------------------- */

/**
 * @brief   Compute the greatest common divisor (GCD) of two integers recursively using the Euclidean
 * algorithm.
 *
 * @param[in] a First integer.
 * @param[in] b Second integer.
 *
 * @retval    int32_t The greatest common divisor of a and b.
 */
int32_t advm_gcd_recursion(int32_t a, int32_t b);

/**
 * @brief   Compute the greatest common divisor (GCD) of two integers using the iterative Euclidean algorithm.
 *
 * @details This method uses modulo (division) operations for GCD calculation.
 *          For a division-free approach, use Stein's algorithm (@ref advm_gcd_stein).
 *
 * @param[in] a First integer.
 * @param[in] b Second integer.
 *
 * @retval    int32_t The greatest common divisor of a and b.
 * @retval    GCD_SPECIAL_CASE_RETURN (0) if either input a or b is zero.
 */
int32_t advm_gcd_iter_euclid(int32_t a, int32_t b);

/**
 * @brief   Compute the greatest common divisor (GCD) of two integers using the binary GCD (Stein's)
 * algorithm.
 *
 * @details This function is an alias for advm_gcd_stein(), providing a more descriptive name for the binary
 * GCD method.
 *
 * @param[in] a First integer.
 * @param[in] b Second integer.
 *
 * @retval    int32_t The greatest common divisor of a and b.
 */
int32_t advm_gcd_binary(int32_t a, int32_t b);

/**
 * @brief   Compute the greatest common divisor (GCD) of two integers using Stein's (binary GCD) algorithm.
 *
 * @details This algorithm avoids division and uses only subtraction, bit-shifts, and comparisons.
 *
 * @param[in] a First integer.
 * @param[in] b Second integer.
 *
 * @retval    int32_t The greatest common divisor of a and b.
 * @retval    GCD_SPECIAL_CASE_RETURN (0) if either input a or b is zero.
 */
int32_t advm_gcd_stein(int32_t a, int32_t b);

/**
 * @brief   Compute the greatest common divisor (GCD) of two integers using the naive recursive Stein's
 * algorithm.
 *
 * @details This is a straightforward recursive implementation of the binary GCD algorithm.
 *
 * @param[in] a First integer.
 * @param[in] b Second integer.
 *
 * @retval    int32_t The greatest common divisor of a and b.
 */
int32_t advm_gcd_stein_naive(int32_t a, int32_t b);

/*
 *  LEAST COMMON MULTIPLIER
 * =============================================================================
 */

/**
 * @brief Calculate the least common multiple (LCM) of two integers.
 *
 * @details Uses the formula: lcm(a, b) = |a * b| / gcd(a, b).
 *          Handles special cases for zero and INT32_MIN inputs.
 *
 * @param[in] a First integer.
 * @param[in] b Second integer.
 *
 * @return int32_t The LCM of a and b, or LCD_SPECIAL_CASE_RETURN for special cases/overflow.
 */
int32_t advm_lcm_classic(int32_t a, int32_t b);

#endif // _ADVM_NUMBER_THEORY_GCD_LCM_H

/* End of File -------------------------------------------------------------- */
