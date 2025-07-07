# ==========================================
#   Unity Project - A Test Framework for C
# ==========================================

# === OS DETECTION ===
ifeq ($(OS),Windows_NT)
	UNAME_S := $(shell uname -s 2>/dev/null)
	ifneq ($(findstring MINGW,$(UNAME_S))$(findstring MSYS,$(UNAME_S))$(findstring CYGWIN,$(UNAME_S)),)
		# POSIX shell on Windows (Git Bash, MSYS2, etc.)
		CLEANUP = rm -rf
		CLEANDATA = rm -rf
		MKDIR = mkdir -p
	else
		# Native CMD or PowerShell
		CLEANUP = del /F /Q
		CLEANDATA = del /F /Q
		MKDIR = mkdir
	endif
	TARGET_EXTENSION = .exe
else
	CLEANUP = rm -f
	CLEANDATA = rm -rf
	MKDIR = mkdir -p
	TARGET_EXTENSION = .out
endif

# === COMPILER ===
C_COMPILER := gcc
ifeq ($(shell uname -s), Darwin)
	C_COMPILER := clang
endif

# === FLAGS ===
CFLAGS := -std=c99 -Wall -Wextra -Wpointer-arith -Wcast-align -Wwrite-strings \
	-Wswitch-default -Wunreachable-code -Winit-self -Wmissing-field-initializers \
	-Wno-unknown-pragmas -Wstrict-prototypes -Wundef -Wold-style-definition -g \
	-O0

DLFLAGS := -mconsole

# === PATHS ===
BIN_DIR      := ../bin
BUILD_DIR    := ../build
DATA_DIR     := ../data
UNITY_ROOT   := ../thirdparties/Unity
SRC_DIR      := ../src
SRC_INC_DIRS := $(shell find $(SRC_DIR) -type d)
TEST_DIR     := ../test
RUNNER_DIR   := $(TEST_DIR)/test_runners

# === SOURCE FILES ===
SRC_SRC       := $(shell find $(SRC_DIR) -name "*.c")
TEST_SRC      := $(wildcard $(TEST_DIR)/Test*.c)
RUNNER_SRC    := $(wildcard $(RUNNER_DIR)/*.c)
UNITY_SRC     := $(UNITY_ROOT)/src/unity.c
UNITY_FIXTURE := $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c

# === OBJECT FILES ===
SRC_OBJS     := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_SRC))
TEST_OBJS    := $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%.o, $(TEST_SRC))
RUNNER_OBJS  := $(patsubst $(RUNNER_DIR)/%.c, $(BUILD_DIR)/%.o, $(RUNNER_SRC))
UNITY_OBJS   := $(BUILD_DIR)/unity.o $(BUILD_DIR)/unity_fixture.o

OBJ_FILES := $(SRC_OBJS) $(TEST_OBJS) $(RUNNER_OBJS) $(UNITY_OBJS)

# === TARGET ===
TARGET_BASE := test_all
TARGET      := $(BIN_DIR)/$(TARGET_BASE)$(TARGET_EXTENSION)

# === INCLUDE + DEFINES ===

INC_DIRS := $(addprefix -I, $(SRC_INC_DIRS)) \
						-I$(UNITY_ROOT)/src \
						-I$(UNITY_ROOT)/extras/fixture/src

SYMBOLS  := -DUNITY_FIXTURE_NO_EXTRAS 
SYMBOLS  += -D_CONFIG_UNIT_TEST 
SYMBOLS  += -D__USE_FULL_ASSERTION
SYMBOLS  += -D__USE_LOG



#! ================================================================
#! =================== DEFAULT TARGET ============================
default: $(TARGET)

all: clean rm_data default 

run: rm_data default 
	@echo "==== Running Tests ===="
	@./$(TARGET) -v

clean:
	$(CLEANUP) $(BUILD_DIR)/* $(TARGET) *.gcno *.gcda *.gcov

rm_data:
	$(CLEANDATA) $(DATA_DIR)/* 
#! ================================================================
#! ================================================================

# === BUILD TARGET ===
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(dir $@)
	$(C_COMPILER) $(CFLAGS) $(DLFLAGS) $(OBJ_FILES) -o $@

# === BUILD RULE ===
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(C_COMPILER) $(CFLAGS) $(SYMBOLS) $(INC_DIRS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(dir $@)
	$(C_COMPILER) $(CFLAGS) $(SYMBOLS) $(INC_DIRS) -c $< -o $@

$(BUILD_DIR)/%.o: $(RUNNER_DIR)/%.c
	@mkdir -p $(dir $@)
	$(C_COMPILER) $(CFLAGS) $(SYMBOLS) $(INC_DIRS) -c $< -o $@

$(BUILD_DIR)/unity.o: $(UNITY_SRC)
	@mkdir -p $(dir $@)
	$(C_COMPILER) $(CFLAGS) $(SYMBOLS) $(INC_DIRS) -c $< -o $@

$(BUILD_DIR)/unity_fixture.o: $(UNITY_FIXTURE)
	@mkdir -p $(dir $@)
	$(C_COMPILER) $(CFLAGS) $(SYMBOLS) $(INC_DIRS) -c $< -o $@

# === CREATE BUILD DIR ===
$(BIN_DIR):
	$(MKDIR) $(BIN_DIR)
	
$(BUILD_DIR):
	$(MKDIR) $(BUILD_DIR)
# === CI ===
ci: CFLAGS += -Werror
ci: all

.PHONY: all clean ci rm_data default run
