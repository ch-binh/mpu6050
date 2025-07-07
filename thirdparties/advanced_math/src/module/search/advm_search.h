/**
 *******************************************************************************
 * @file    advm_search.h
 * @brief   Advanced mathematical and algorithmic function declarations.
 * @details
 *
 * @date    2025/07/01
 * @author  Binh Pham
 *******************************************************************************
 * @attention
 * ! Update information
 *******************************************************************************
 */
/* Prvent recursion --------------------------------------------------------- */
#ifndef _ADVM_SEARCH_H
#define _ADVM_SEARCH_H

/* Include ------------------------------------------------------------------ */
#include "advm_config.h"

/* Function tables ---------------------------------------------------------- */
// clang-format off
/**
 * @brief Function tables for module advm search algorithm
 *
 * @note  This table follows @ref advm_table_entry_t format
 */
#define ADVM_BASIC_OP_FUNC_TABLE \
  { "lin_search", FUNC_FLOAT32, advm_linear_search }, \
  { "bin_search", FUNC_FLOAT32, advm_binary_search },
// clang-format on
/* Public defines ----------------------------------------------------------- */

/* Public variables --------------------------------------------------------- */

/* Public macros ------------------------------------------------------------ */

/* Function prototypes ------------------------------------------------------ */

void advm_linear_search(const float32_t arr[], uint32_t n, float32_t target);
void advm_binary_search(const float32_t arr[], float32_t l, uint32_t r, float32_t target);

#endif // _ADVM_SEARCH_H

/* End of File -------------------------------------------------------------- */
