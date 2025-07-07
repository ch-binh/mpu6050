##  Information

| Version | Update date |
| ------- | ----------- |
| 0.0.1   | 2025/07/04  |

## Table of Content

- [I. Template Module Header File](#i-template-module-header-file)
  - [1. Purpose](#1-purpose)
  - [2. File Overview](#2-file-overview)
  - [3. Section Description](#3-section-description)
  - [4. Tips](#4-tips)
- [II. Template Module Source File](#ii-template-module-source-file)
  - [1. Purpose](#1-purpose-1)
  - [2. File Structure](#2-file-structure)
  - [3. Section description](#3-section-description-1)
  - [4. Tips](#4-tips-1)


# I. Template Module Header File

This `template_module.h` file serves as a standardized starting point for writing embedded-friendly, scalable C header files. It is designed to enforce consistency, clarity, and maintainability across all C modules in your project.


---

## 1. Purpose

This header provides a **template structure** for organizing:
- Configuration options
- Public macros and constants
- Data types and structures
- API function prototypes
- Inline utilities

This structure is especially suited for:
- Embedded firmware development
- Modular C projects with shared utilities
- Long-term maintenance and documentation readiness

---

## 2. File Overview

```c
#ifndef TEMPLATE_MODULE_H
#define TEMPLATE_MODULE_H

// #ifdef __cplusplus
// extern "C" {
// #endif

/* Includes ----------------------------------------------------------------- */
/* Configuration ------------------------------------------------------------ */
/* Public defines ----------------------------------------------------------- */
/* Public macros ------------------------------------------------------------ */
/* Helper macros ------------------------------------------------------------ */
/* Public typedefs ---------------------------------------------------------- */
/* Enumerations ------------------------------------------------------------- */
/* Structures --------------------------------------------------------------- */
/* Error codes -------------------------------------------------------------- */
/* Function prototypes ------------------------------------------------------ */
/* Inline functions --------------------------------------------------------- */

// #ifdef __cplusplus
// }
// #endif

#endif /* TEMPLATE_MODULE_H */

/* End of File -------------------------------------------------------------- */
```

## 3. Section Description

| Section               | Description                                                    |
| --------------------- | -------------------------------------------------------------- |
| `Includes`            | Import standard libraries and other module headers.            |
| `Configuration`       | Module-level macros to configure behavior at compile-time.     |
| `Public defines`      | Constants exposed to other modules, e.g. `PI`, `MAX_SIZE`.     |
| `Public macros`       | Utility macro functions, e.g. `MIN(a, b)`.                     |
| `Helper macros`       | Internal use macros (logging, assertions, etc).                |
| `Public typedefs`     | Typedefs for structs or basic types shared across modules.     |
| `Enumerations`        | Enums for status codes, operation modes, etc.                  |
| `Structures`          | Public struct definitions for configurations or data exchange. |
| `Error codes`         | (Optionally) split out error code enums for readability.       |
| `Function prototypes` | Declare public APIs.                                           |
| `Inline functions`    | Small performance-critical helpers defined as `static inline`. |

## 4. Tips
- Do not define function implementations in the header unless using static inline.
- Keep private macros and helpers in the corresponding .c file unless needed by others.
- Use Doxygen-style comments (@brief, @param, @return) to ease documentation generation.
- Stick to this format across all modules to make collaboration and onboarding easier.

---
---

# II. Template Module Source File

This `template_module.c` file serves as a **starter skeleton for C source files** in embedded or modular C projects. It complements the corresponding `template_module.h` and follows a clear, maintainable structure suitable for professional development environments.

---

## 1. Purpose

This template provides:

- A clean structure for implementation of C modules
- Clear separation between private and public components
- A scalable format for both small utility modules and large functional blocks

It ensures uniformity across the codebase and reduces time spent organizing files.

---

## 2. File Structure

```c
/* Includes ----------------------------------------------------------------- */
/* Private includes --------------------------------------------------------- */
/* Private defines ---------------------------------------------------------- */
/* Private macros ----------------------------------------------------------- */
/* Private typedefs --------------------------------------------------------- */
/* Private variables -------------------------------------------------------- */
/* Private function prototypes ---------------------------------------------- */
/* Exported functions ------------------------------------------------------- */
/* Private function definitions --------------------------------------------- */
```

## 3. Section description

| Section                        | Description                                                                  |
| ------------------------------ | ---------------------------------------------------------------------------- |
| `Includes`                     | Include the corresponding `.h` file and other required headers.              |
| `Private includes`             | Additional includes only needed internally (`<string.h>`, `<math.h>`, etc.). |
| `Private defines`              | Constants local to this file (not exposed publicly).                         |
| `Private macros`               | Internal macros like clamping, debug wrappers, etc.                          |
| `Private typedefs`             | Structs, enums, or unions only used inside this `.c`.                        |
| `Private variables`            | `static` variables for internal state or buffers.                            |
| `Private function prototypes`  | Forward declarations of internal static functions.                           |
| `Exported functions`           | Implementation of public APIs declared in the `.h`.                          |
| `Private function definitions` | Internal helpers used only within this file.                                 |

## 4. Tips
- Keep all internal logic static to prevent symbol leakage across compilation units.

---