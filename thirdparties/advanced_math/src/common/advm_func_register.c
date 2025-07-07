/**
 *******************************************************************************
 * @file    advm_func_register.c
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

/* Includes ----------------------------------------------------------------- */
#include "advm_func_register.h"
/* Public macros ------------------------------------------------------------ */

advm_table_entry_t g_advm_func_table[MAX_REGISTERED_FUNCS];
uint32_t           g_advm_func_table_count = 0;
/* Public macros ------------------------------------------------------------ */

/* Function implementations ------------------------------------------------- */

void advm_register_function(const char *name, advm_func_sig_t sig, void *func)
{
  if (g_advm_func_table_count >= MAX_REGISTERED_FUNCS)
  {
    return;
  }

  g_advm_func_table[g_advm_func_table_count++] = (advm_table_entry_t){
    .name     = name,
    .sig_type = sig,
    .func_ptr = func,
  };
}

/* End of File -------------------------------------------------------------- */
