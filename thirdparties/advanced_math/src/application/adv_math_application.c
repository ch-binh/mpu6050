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

/* Include ------------------------------------------------------------------ */
#include "adv_math_application.h"

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
void advm_simplify_fraction(int32_t *numerator, int32_t *denominator)
{
  sign_t numerator_sign   = SIGN(*numerator);
  sign_t denominator_sign = SIGN(*denominator);

  /* Simplify components */
  int32_t gcd = advm_gcd_iter_euclid(*numerator, *denominator);
  if (!gcd)
    return;

  *numerator   = (*numerator / gcd);
  *denominator = (*denominator / gcd);

  /* Simplify signs */
  // -a/-b -> a/b
  // a/-b  -> -a/b
  if (((denominator_sign == BS_NEG) && (numerator_sign == BS_POS)) ||
      ((denominator_sign == BS_NEG) && (numerator_sign == BS_NEG)))
  {
    *numerator   = -(*numerator);
    *denominator = -(*denominator);
  }

  return;
}

/* End of File -------------------------------------------------------------- */
