# ==============================================================================
# 
# ==============================================================================

# COMPILER =====================================================================

# FLAGS ========================================================================

# PATHS ========================================================================

# SOURCE FILES =================================================================

# OBJECT FILES =================================================================

# TARGET OUTPUT ================================================================

# INCLUDE + DEFINES ============================================================

# BUILD TARGET =================================================================

# BUILD RULE ===================================================================

# CREATE BUILD DIR =============================================================

# CI ===========================================================================
.PHONY: 

#! Belows are makefile settings, irrelevant to the project
#! =============================================================================

# ==============================================================================
# OS Detection & Platform-Specific Configuration
# ==============================================================================

OS_NAME := $(shell uname -s)

ifeq ($(OS_NAME),Linux)
    DETECTED_OS := Linux
    REMOVE := rm -f
    MKDIR := mkdir -p
    TARGET_EXTENSION := .out
endif

ifeq ($(OS_NAME),Darwin)
    DETECTED_OS      := macOS
    REMOVE           := rm -f
    MKDIR            := mkdir -p
    TARGET_EXTENSION := .out
endif

ifeq ($(findstring MINGW64_NT,$(OS_NAME)),MINGW64_NT)
    DETECTED_OS      := MINGW64_NT
    REMOVE           := rm -f
    MKDIR            := mkdir -p
    TARGET_EXTENSION := .exe
endif

ifeq ($(findstring MSYS,$(OS_NAME)),MSYS)
    DETECTED_OS := Windows_MSYS
    REMOVE := rm -f
    MKDIR := mkdir -p
    TARGET_EXTENSION := .exe
endif

ifeq ($(findstring CYGWIN,$(OS_NAME)),CYGWIN)
    DETECTED_OS := Windows_CYGWIN
    REMOVE := rm -f
    MKDIR := mkdir -p
    TARGET_EXTENSION := .exe
endif

# Fallback for native CMD or powershell where uname fails
ifeq ($(OS_NAME),)
    DETECTED_OS := Windows_CMD
    REMOVE := del /Q
    MKDIR := if not exist $(subst /,\,$1) mkdir $(subst /,\,$1)
    TARGET_EXTENSION := .exe
endif

$(info [INFO] Detected OS: $(DETECTED_OS))

