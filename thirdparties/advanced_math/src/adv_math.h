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

/* Prevent includes recursive ----------------------------------------------- */
#ifndef ADV_MATH_H
#define ADV_MATH_H

/* Includes ----------------------------------------------------------------- */

#include "advm_basic_op.h"

#include "advm_gcd_lcm.h"
#include "advm_modular.h"
#include "advm_prime.h"
#include "advm_sort.h"

#include "adv_math_application.h"
#include "advm_func_register.h"

/* Public defines ----------------------------------------------------------- */

/* Public macros ------------------------------------------------------------ */

typedef struct
{
  const advm_table_entry_t *table;
  const int32_t             size;
} advm_table_group_t;

/* Helper macros ------------------------------------------------------------ */

/* Public typedefs ---------------------------------------------------------- */

/* Function prototypes ------------------------------------------------------ */

void advm_init(void);

/**
 * @brief     Randomizes an array of int32_t values within a specified range.
 *
 * @param[in] arr Pointer to the array of int32 values to be randomized.
 * @param[in] n   Number of elements in the array.
 * @param[in] min Minimum value for the randomization range.
 * @param[in] max Maximum value for the randomization range.
 *
 */
void advm_randomize_arr_int32(int32_t *arr, uint32_t n, uint32_t min, uint32_t max);

/*
 *  ALGEBRA / LINEAR ALGEBRA
 * =============================================================================
 */
void  advm_matrix_add(const float *A, const float *B, float *C, int rows, int cols);
void  advm_matrix_mul(const float *A, const float *B, float *C, int m, int n,
                      int p);                       // A[m x n] * B[n x p] = C[m x p]
float advm_determinant(const float *matrix, int n); // square matrix only

/*
 *  DYNAMIC PROGRAMMING
 * =============================================================================
 */
int advm_fibonacci_dp(int n);
int advm_knapsack_01(const int *w, const int *v, int n, int W);

/*
 *  GRAPH THEORY (BASIC)
 * =============================================================================
 */
void advm_dfs(int graph[][100], int n, int start, bool_t *visited);
void advm_bfs(int graph[][100], int n, int start);

/*
 *  MISCELLANEOUS
 * =============================================================================
 */
void advm_swap(int *a, int *b);
void advm_reverse(int arr[], int n);
void advm_shuffle(int arr[], int n); // Fisher–Yates shuffle

/*
 *  SEARCHING ALGORITHMS
 * =============================================================================
 */
int advm_linear_search(const int arr[], int n, int target);
int advm_binary_search(const int arr[], int l, int r, int target);

#endif /* ADV_MATH_H */

/* End of File -------------------------------------------------------------- */
