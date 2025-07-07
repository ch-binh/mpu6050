/**
 ******************************************************************************
 * @file    advm_basic_op.h
 * @brief   Basic arithmetic operation function declarations.
 * @details This header provides function prototypes for fundamental arithmetic
 *          operations such as addition, subtraction, multiplication, division,
 *          and modulus. Designed for use in numerical computation, signal
 *          processing, and embedded math applications.
 *
 * @date    2024/06/23
 * @author  Binh Pham
 ******************************************************************************
 * @attention
 *
 ******************************************************************************
 */
/* Prevent recursive inclusion ---------------------------------------------- */
#ifndef _ADVM_BASIC_OP_H
#define _ADVM_BASIC_OP_H

/* Includes ----------------------------------------------------------------- */
#include "advm_config.h"

/* Information -------------------------------------------------------------- */
#define ADVM_BASIC_OP_NAME     "Basic Operation" ///< Module's name
#define ADVM_BASIC_OP_TAG      "ADVM_BOP"        ///< Module's tag
#define ADVM_BASIC_OP_GRP      "basic_operation" ///< Module's group
#define ADVM_BOP_VERSION_MAJOR 0
#define ADVM_BOP_VERSION_MINOR 1
#define ADVM_BOP_VERSION_PATCH 0
#define ADVM_BOP_VERSION \
  ((ADVM_BOP_VERSION_MAJOR << 16) | (ADVM_BOP_VERSION_MINOR << 8) | (ADVM_BOP_VERSION_PATCH))

/* Public variables --------------------------------------------------------- */

/* Public macros ------------------------------------------------------------ */

/* Function tables ---------------------------------------------------------- */
//! add function here

// clang-format off
/**
 * @brief Function tables for module advm basic operation
 *
 * @note  This table follows @ref advm_table_entry_t format
 */
#define ADVM_BASIC_OP_FUNC_TABLE \
  { "add", FUNC_FLOAT32, advm_add }, \
  { "sub", FUNC_FLOAT32, advm_sub }, \
  { "mul", FUNC_FLOAT32, advm_mul }, \
  { "div", FUNC_FLOAT32, advm_div }, \
  { "mod", FUNC_INT32,   advm_mod }
// clang-format on

/* Function prototypes ------------------------------------------------------ */

/**
 * @brief   Add two **floating-point** numbers.
 *
 * @param[in]   a First operand.
 * @param[in]   b Second operand.
 *
 * @retval float32_t  Sum of a and b.
 */
ADVM_API float32_t advm_add(float32_t a, float32_t b);

/**
 * @brief   Subtract one **floating-point** number from another.
 *
 * @param[in]   a Minuend.
 * @param[in]   b Subtrahend.
 *
 * @retval float32_t  Difference of a and b.
 */
ADVM_API float32_t advm_sub(float32_t a, float32_t b);

/**
 * @brief   Multiply two **floating-point** numbers.
 * @param[in]   a First operand.
 * @param[in]   b Second operand.
 *
 * @retval float32_t  Product of a and b.
 */
ADVM_API float32_t advm_mul(float32_t a, float32_t b);

/**
 * @brief   Divide one floating-point number by another.
 *
 * @param[in]   a Dividend.
 * @param[in]   b Divisor.
 *
 * @retval float32_t  Quotient of a divided by b.
 */
ADVM_API float32_t advm_div(float32_t a, float32_t b);

/**
 * @brief   Compute the modulus of two integers.
 *
 * @param[in]   a Dividend.
 * @param[in]   b Divisor.
 *
 * @retval float32_t  Remainder of a divided by b.
 */
ADVM_API int32_t advm_mod(int32_t a, int32_t b);

#endif // _ADVM_BASIC_OP_H

/* End of File -------------------------------------------------------------- */
