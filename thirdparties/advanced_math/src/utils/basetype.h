/**
 *******************************************************************************
 * @file    base_type.h
 * @brief
 * @details
 *
 * @date    2025/06/15
 * @author  Binh Pham
 *******************************************************************************
 * @attention
 *
 *******************************************************************************
 */
/* Prevent includes recursive ----------------------------------------------- */
#ifndef BASE_TYPE_H
#define BASE_TYPE_H

/* Includes ----------------------------------------------------------------- */
#include <stdint.h>
#include <float.h>

/* Information -------------------------------------------------------------- */
#define BASE_TYPE_VERSION_MAJOR 0
#define BASE_TYPE_VERSION_MINOR 1
#define BASE_TYPE_VERSION_PATCH 0
#define BASE_TYPE_VERSION \
  ((BASE_TYPE_VERSION_MAJOR << 16) | (BASE_TYPE_VERSION_MINOR << 8) | (BASE_TYPE_VERSION_PATCH))
#define BASE_TYPE_NAME "Base Type Library"
#define BASE_TYPE_TAG  "BS"

/* Public macros ------------------------------------------------------------ */

#if !defined(NOT)
#define NOT(x) ((x) ? BS_FALSE : BS_TRUE)
#endif

#if !defined(MAX)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#if !defined(MIN)
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#if !defined(_CONFIG_UNIT_TEST)
#define _STATIC static
#else
#define _STATIC
#endif

#if !defined(__CONFIG_USE_INT64__)
#define POS_INF UINT32_MAX
#define NEG_INF INT32_MIN
#else
#define POS_INF UINT64_MAX
#define NEG_INF INT64_MIN
#endif

/* Public typedef ----------------------------------------------------------- */
typedef enum
{
  BS_OK      = 0x00,
  BS_ERR     = 0x01,
  BS_BUSY    = 0x02,
  BS_TIMEOUT = 0x03
} base_status_t;

typedef enum
{
  BS_FALSE = 0x00,
  BS_TRUE  = 0x01
} bool_t;

typedef enum
{
  BS_NEG = -0x01, ///< Positive
  BS_POS = 0x01,  ///< Negative
} sign_t;

typedef float float32_t;

// not that double is very uncommon in embedded systems, so we use float by default
#if !defined(__CONFIG_USE_DOUBLE__)
typedef float float64_t;
#else
typedef double float64_t;
#endif

/* Public variables --------------------------------------------------------- */
/* Public function prototypes ----------------------------------------------- */

#endif // __BASE_TYPE_H

/* End of file -------------------------------------------------------------- */
