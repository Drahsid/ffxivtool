GCD_NO_DIV ?= 1

BASENAME = ffxivtool
BUILD_DIR = build
SRC_DIR = src
INC_DIR = include

SRC_DIRS = $(SRC_DIR)

C_FILES = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
O_FILES	= $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file).o)
TARGET = $(BUILD_DIR)/$(BASENAME)

# Flags
OPT_FLAGS = -Os
INCLUDE_CC_FLAGS = -Iinclude
ifeq ($(GCD_NO_DIV),1)
D_FLAGS = -D_LANGUAGE_C -DGCD_NO_DIV
else
D_FLAGS = -D_LANGUAGE_C
endif
L_FLAGS = -lm
CC_FLAGS = $(OPT_FLAGS) $(D_FLAGS) $(INCLUDE_CC_FLAGS) $(L_FLAGS)

default: all

all: dirs $(TARGET)

dirs:
	$(foreach dir,$(SRC_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(dir)))

clean:
	rm -rf $(BUILD_DIR)

$(TARGET):
	$(CC) -o $@ $(C_FILES) $(CC_FLAGS)
