CC = gcc
CFLAGS = -Wall -Iinclude -MMD -MP
LDFLAGS = 
BUILD_DIR = build
SRC_DIR = src
OBJ_DIR = $(BUILD_DIR)/obj

# 任务配置yong
TASKS = task1 task2
TASK1_SRCS = $(SRC_DIR)/task1/main.c $(SRC_DIR)/task1/arg_parse.c
TASK2_SRCS = $(SRC_DIR)/task2/src/task2/main.c $(SRC_DIR)/task2/file_io.c $(SRC_DIR)/task2/preprocess.c

# 自动生成目标
TARGETS = $(addprefix $(BUILD_DIR)/, $(TASKS))
TASK1_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(TASK1_SRCS))
TASK2_OBJS = $(patsubst $(SRC_DIR)/task2/%.c,$(OBJ_DIR)/task2/%.o,$(TASK2_SRCS))
DEPS = $(TASK1_OBJS:.o=.d) $(TASK2_OBJS:.o=.d)

all: $(TARGETS)

# 任务构建规则
$(BUILD_DIR)/task1: $(TASK1_OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/task2: $(TASK2_OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

# 通用编译规则
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# 支持task2嵌套路径的编译规则
$(OBJ_DIR)/task2/%.o: $(SRC_DIR)/task2/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR) Minimake_cleared.mk

-include $(DEPS)

.PHONY: all clean