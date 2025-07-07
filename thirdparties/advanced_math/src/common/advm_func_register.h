/**
 *******************************************************************************
 * @file    advm_func_register.h
 * @brief
 * @details
 *
 * @date    2025/06/24
 * @author  Binh Pham
 *******************************************************************************
 * @attention
 *
 *******************************************************************************
 */
/* Prevent includes recursive ----------------------------------------------- */
#ifndef ADV_MATH_FUNC_REGISTER_H
#define ADV_MATH_FUNC_REGISTER_H

/* Includes ----------------------------------------------------------------- */
#include "advm_config.h"

/* Public macros ------------------------------------------------------------ */

#define MAX_REGISTERED_FUNCS 128

/* Public macros ------------------------------------------------------------ */

extern advm_table_entry_t g_advm_func_table[MAX_REGISTERED_FUNCS];
extern uint32_t           g_advm_func_table_count;

/* Function prototypes ------------------------------------------------------ */

void advm_register_function(const char *name, advm_func_sig_t sig, void *func);

#endif // ADV_MATH_FUNC_REGISTER_H

/* End of files ------------------------------------------------------------- */
