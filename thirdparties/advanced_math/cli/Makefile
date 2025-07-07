# ==========================================
#   DSP CLI - Command Line Interface Build
# ==========================================

# === OS DETECTION ===
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # Not bash
    CLEANUP = del /F /Q
    MKDIR = mkdir
  else
    CLEANUP = rm -rf
    MKDIR = mkdir -p
  endif
  TARGET_EXTENSION = .exe
else
  CLEANUP = rm -f
  MKDIR = mkdir -p
  TARGET_EXTENSION = .out
endif

# === COMPILER ===
C_COMPILER := gcc
ifeq ($(shell uname -s), Darwin)
  C_COMPILER := clang
endif

# === FLAGS ===
CFLAGS := -std=c99 -Wall -Wextra -g

# === PATHS ===
MAIN         := advm_cli
TARGET_BASE  := advm
BIN_DIR      := ../bin
BUILD_DIR    := ../build/cli
SRC_DIR      := ../src
SRC_INC_DIRS := $(shell find $(SRC_DIR) -type d)
INC_DIRS := $(addprefix -I, $(SRC_INC_DIRS)) \
            -I.\

# === FILES ===
SRC_SRC     := $(shell find $(SRC_DIR) -name "*.c")
SRC_OBJS    := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_SRC))

MAIN_SRC    := $(MAIN).c
MAIN_OBJ    := $(BUILD_DIR)/$(MAIN).o


TARGET      := $(BIN_DIR)/$(TARGET_BASE)$(TARGET_EXTENSION)

OBJ_FILES := $(SRC_OBJS) $(MAIN_OBJ)

# === DEFAULT ===
default: $(TARGET)

run: default
	@echo "==== Running CLI ===="
	@./$(TARGET) add 3 4

clean:
	$(CLEANUP) $(BUILD_DIR)/*

# === BUILD TARGET ===
$(TARGET): $(OBJ_FILES) | $(BIN_DIR)
	$(C_COMPILER) $(CFLAGS) $(OBJ_FILES) -o $@

# === BUILD OBJECT RULES ===
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) -c $< -o $@

$(BUILD_DIR)/$(MAIN).o: $(MAIN).c $(MAIN).h
	@mkdir -p $(dir $@)
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) -c $< -o $@

# === CREATE BUILD DIR ===
$(BIN_DIR):
	$(MKDIR) $(BIN_DIR)

$(BUILD_DIR):
	$(MKDIR) $(BUILD_DIR)

.PHONY: default run clean
