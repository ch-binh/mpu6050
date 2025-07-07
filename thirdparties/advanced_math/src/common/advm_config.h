/**
 *******************************************************************************
 * @file    advm_config.h
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
#ifndef ADV_MATH_CONFIG_H
#define ADV_MATH_CONFIG_H

/* Includes ----------------------------------------------------------------- */

#include "basetype.h"

/* Public defines ----------------------------------------------------------- */
/* Public macros ------------------------------------------------------------ */

// to build dll
#ifdef _WIN32
#define ADVM_API __declspec(dllexport)
#else
#define ADVM_API
#endif

// Logging
#if !defined(__USE_LOG)
#define LOG(msg, ...)        ((void)0)
#define LOG_DETAIL(msg, ...) ((void)0)
#else
#include <stdio.h>
#include <string.h>
#define LOG(msg, ...)        printf(msg "\n", ##__VA_ARGS__)
#define LOG_DETAIL(msg, ...) printf("[%s] " msg "\n", TAG, ##__VA_ARGS__)
#endif // __USE_LOG

#define PRINT_INT_ARR(arr, n)                \
  {                                          \
    for (uint_fast32_t _i = 0; _i < n; _i++) \
    {                                        \
      LOG("%d ", arr[_i]);                   \
    }                                        \
    LOG("\n");                               \
  }

// Assertion
#if !defined(__USE_FULL_ASSERTION)
#define ADVM_CHECK(cond, ret)      ((void)0)
#define ADVM_CHECK_NO_RETURN(cond) ((void)0)
#else

#define ADVM_CHECK(cond, ret)           \
  if (!(cond))                          \
  {                                     \
    LOG("Condition failed: %s", #cond); \
    return ret;                         \
  }

#define ADVM_CHECK_NO_RETURN(cond)      \
  if (!(cond))                          \
  {                                     \
    LOG("Condition failed: %s", #cond); \
    return;                             \
  }
#endif // __USE_FULL_ASSERTION

/* Helper macros ------------------------------------------------------------ */
#define SIGN(x)      ((x < 0) ? BS_NEG : BS_POS) ///< Sign of a number
#define IS_EVEN(num) (!((num) & 1))           ///< Check if input is an even number, return Boolean True/False
#define IS_ODD(num)  ((num) & 1)              ///< Check if input is an odd number, return Boolean True/False
#define ABS(x)       (((x) < 0) ? -(x) : (x)) ///< Absolute
/**
 * @brief Swap 2 intergers using XOR algorithm
 *
 * @warning Do not use this for floating numbers, use @ref SWAP_FLOAT instead
 *
 */
#define SWAP_XOR(a, b) \
  a ^= b;              \
  b ^= a;              \
  a ^= b;

#define SWAP_INT(a, b) SWAP_XOR(a, b)

#define SWAP_FLOAT(a, b) \
  float32_t temp = a;    \
  a              = b;    \
  b              = temp;

/* Public typedefs ---------------------------------------------------------- */
typedef int32_t (*op_func_int32_t)(int32_t a, int32_t b);
typedef float32_t (*op_func_float32_t)(float32_t a, float32_t b);
typedef void (*op_func_pair_transform_int_t)(int32_t *a, int32_t *b);
typedef void (*op_func_array_int32_t)(int32_t *arr, uint32_t n);
typedef void (*op_func_array_float32_t)(float32_t *arr, uint32_t n);

typedef enum
{
  FUNC_FLOAT32,     ///< @ref op_func_int32_t
  FUNC_INT32,       ///< @ref op_func_float32_t
  FUNC_INT32_PT,    ///< @ref op_func_pair_transform_int_t
  FUNC_INT32_ARR,   ///< @ref op_func_array_int32_t
  FUNC_FLOAT32_ARR, ///< @ref op_func_array_float32_t
} advm_func_sig_t;  ///< Function signature

typedef struct
{
  const char     *name;     ///< Function utility name (ex: add, sub)
  advm_func_sig_t sig_type; ///< Function type
  void           *func_ptr; ///< Pointer to the function
} advm_table_entry_t;

#endif /* ADV_MATH_CONFIG_H */

/* End of File -------------------------------------------------------------- */
