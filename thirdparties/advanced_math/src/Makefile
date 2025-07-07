# ============================
# Build DLL from src/
# ============================


# === OS DETECTION ===
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # Not bash
    CLEANUP = del /F /Q
    CLEANDATA = del /F /Q
    MKDIR = mkdir
  else
    CLEANUP = rm -rf
    CLEANDATA = rm -rf
    MKDIR = mkdir -p
  endif
  TARGET_EXTENSION = .exe
  DLL_EXT = dll
else
  CLEANUP = rm -f
  CLEANDATA = rm -rf
  MKDIR = mkdir -p
  TARGET_EXTENSION = .out
endif


# === COMPILER ===
CC := gcc
ifeq ($(shell uname -s), Darwin)
  CC := clang
endif

# === FLAGS ===


IMPLIB_FILE = $(BUILD_DIR)/libadvm.a
IMPLIB_FLAG = -Wl,--out-implib,$(IMPLIB_FILE)

CFLAGS := -std=c99 -Wall -Wextra -O2 -fPIC
LDFLAGS := -shared $(IMPLIB_FLAG)

# === PATHS ===
SRC_DIR    := ../src
BUILD_DIR  := ../build
BIN_DIR    := ../bin

# === SOURCE & INCLUDE ===
SRC_FILES := $(shell find $(SRC_DIR) -name "*.c")
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))
INC_DIRS  := $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I, $(INC_DIRS))

# === TARGET ===
TARGET_NAME := libadvm
TARGET      := $(BIN_DIR)/$(TARGET_NAME).$(DLL_EXT)

# === TARGET RULES ===

all: $(TARGET)

$(TARGET): $(OBJ_FILES) | $(BIN_DIR) $(BUILD_DIR)
	@echo "== Linking DLL: $@"
	$(CC) $(LDFLAGS) $(OBJ_FILES) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "== Compiling: $<"
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

$(BIN_DIR):
	$(MKDIR) $(BIN_DIR)

$(BUILD_DIR):
	$(MKDIR) $(BUILD_DIR)

clean:
	$(CLEANUP) $(BUILD_DIR)/* $(TARGET) 

.PHONY: all clean
