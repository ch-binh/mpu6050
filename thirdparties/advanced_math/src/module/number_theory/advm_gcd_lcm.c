/**
 *******************************************************************************
 * @file    advm_gcd_lcm.h
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
/* Include ------------------------------------------------------------------ */
#include "advm_gcd_lcm.h"

// Dependant modules
#include "advm_basic_op.h"

/* Private macros ----------------------------------------------------------- */
#define _GCD_PRE_CHECK(a, b)                \
  if ((a == INT32_MIN) || (b == INT32_MIN)) \
    return GCD_SPECIAL_CASE_RETURN;         \
  else if (a == 0 && b == 0)                \
    return GCD_SPECIAL_CASE_RETURN;         \
  else if (a == 0)                          \
    return b;                               \
  else if (b == 0)                          \
    return a;

#define _GCD_ABS_INPUTS(a, b) \
  a = ABS(a);                 \
  b = ABS(b);

/**
 * @brief Check legitimacy of inputs
 *
 * @retval 0 if either a or b equals 0
 */
#define _LCM_PRE_CHECK(a, b)                \
  if ((a == INT32_MIN) || (b == INT32_MIN)) \
    return LCD_SPECIAL_CASE_RETURN;         \
  else if ((a == 0) || (b == 0))            \
    return LCD_SPECIAL_CASE_RETURN;

/*
 *  GREATEST COMMON DIVISOR
 * =============================================================================
 */

int32_t advm_gcd_recursion(int32_t a, int32_t b)
{
  _GCD_PRE_CHECK(a, b);
  _GCD_ABS_INPUTS(a, b);

  return (b == 0) ? a : advm_gcd_recursion(b, a % b);
}

int32_t advm_gcd_iter_euclid(int32_t a, int32_t b)
{
  _GCD_PRE_CHECK(a, b);
  _GCD_ABS_INPUTS(a, b);

  while (b != 0)
  {
    int32_t temp = b;
    b            = advm_mod(a, b);
    a            = temp;
  }
  return a;
}

int32_t advm_gcd_binary(int32_t a, int32_t b)
{
  return advm_gcd_stein(a, b);
}

int32_t advm_gcd_stein(int32_t a, int32_t b)
{
  _GCD_PRE_CHECK(a, b);
  _GCD_ABS_INPUTS(a, b);

  int32_t shift = 0;

  //  1. If both a and b are even → GCD(a, b) = 2 × GCD(a/2, b/2)
  while (((a | b) & 1) == 0)
  {
    a >>= 1;
    b >>= 1;
    shift++;
  }

  //  2. If one is even and the other is odd → divide the even number by 2
  while (IS_EVEN(a))
    a >>= 1;

  //  3. If both are odd → GCD(a, b) = GCD(|a - b|, min(a, b))
  do
  {
    while (IS_EVEN(b))
      b >>= 1;

    if (a > b)
    {
      SWAP_INT(a, b);
    }

    b = b - a;
  } while (b != 0);

  //  4. If one number is 0 → GCD = the other number
  return a << shift;
}

int32_t advm_gcd_stein_naive(int32_t a, int32_t b)
{
  // Original algorithm:
  //
  // 1. If a == b → GCD is a
  // 2. If a == 0 → GCD is b; if b == 0 → GCD is a
  // 3. If both are even → GCD(a, b) = 2 × GCD(a/2, b/2)
  // 4. If a is even, b is odd → GCD(a, b) = GCD(a/2, b)
  // 5. If a is odd, b is even → GCD(a, b) = GCD(a, b/2)
  // 6. If both are odd and a > b → GCD(a, b) = GCD((a - b)/2, b)
  // 7. Otherwise → GCD(a, b) = GCD((b - a)/2, a)
  _GCD_PRE_CHECK(a, b);
  _GCD_ABS_INPUTS(a, b);

  if (a == b)
    return a;
  if (a == 0)
    return b;
  if (b == 0)
    return a;

  if (IS_EVEN(a) && IS_EVEN(b))
  {
    return 2 * advm_gcd_stein_naive(a >> 1, b >> 1);
  }
  else if IS_EVEN (a)
  {
    return advm_gcd_stein_naive(a >> 1, b);
  }
  else if IS_EVEN (b)
  {
    return advm_gcd_stein_naive(a, b >> 1);
  }
  else
  {
    return advm_gcd_stein_naive((a - b) >> 1, MIN(a, b));
  }
}

/*
 *  LEAST COMMON MULTIPLIER
 * =============================================================================
 */

int32_t advm_lcm_classic(int32_t a, int32_t b)
{
  _LCM_PRE_CHECK(a, b);

  // lcm(a, b) = |a * b| / gcd(a, b) = |a| / gcd(a, b) * |b|
  int64_t gcd = (int64_t)advm_gcd_iter_euclid(a, b);
  int64_t lcm = ABS((int64_t)(a)) / gcd * ABS((int64_t)(b));

  return (lcm > INT32_MAX) ? LCD_SPECIAL_CASE_RETURN : (int32_t)lcm;
}

/* End of File -------------------------------------------------------------- */
