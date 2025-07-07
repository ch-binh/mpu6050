/**
 *******************************************************************************
 * @file    advm_calculus.h
 * @brief   Advanced mathematical and algorithmic function declarations.
 * @details This is a high-level interface to various algorithms implemented in
 *C. Designed to support numerical computation, signal processing, and
 *          embedded-friendly math operations.
 *
 * @date    2025/06/15
 * @author  Binh Pham
 *******************************************************************************
 * @attention
 * ! Update information
 * ! This module is not implemented yet
 *******************************************************************************
 */
/* Prvent recursion --------------------------------------------------------- */
#ifndef _ADVM_CALCULUS_H
#define _ADVM_CALCULUS_H

/* Include ------------------------------------------------------------------ */
#include "advm_config.h"

/* Public defines ----------------------------------------------------------- */

/* Public variables --------------------------------------------------------- */

/* Public macros ------------------------------------------------------------ */

/* Function protoypes ------------------------------------------------------- */

double advm_derivative(double (*f)(double), double x,
                       double h); // f'(x) ≈ [f(x + h) - f(x)] / h
double advm_integrate(double (*f)(double), double a, double b,
                      int n); // numerical integration using Trapezoidal Rule

/* Function tables ---------------------------------------------------------- */

#endif // _ADVM_CALCULUS_H

/* End of File -------------------------------------------------------------- */
