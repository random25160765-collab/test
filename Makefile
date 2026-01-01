# 放置在项目根目录
CC = gcc
CFLAGS = -Wall -Wextra -g
SRC_DIR = src
BUILD_DIR = build

# 自动找到所有 .c 文件
SRCS = $(wildcard $(SRC_DIR)/*.c)
# 生成对应的可执行文件列表（在 build 目录）
EXES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%, $(SRCS))

# 默认目标：编译所有 .c 文件为可执行文件
all: $(EXES)
	@echo "✅ 所有可执行文件已编译完成！"
	@echo "📁 可执行文件在: $(BUILD_DIR)/"

# 模式规则：如何从 .c 文件生成可执行文件
$(BUILD_DIR)/%: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@      
	@echo "🔨 编译可执行文件: $< -> $@"

# 动态目标：让 make x 编译 src/x.c -> build/x（可执行文件）
.SECONDEXPANSION:
%: $$(BUILD_DIR)/%
	@echo "🎯 可执行文件 $@ 已生成：$<"

# 列出所有可编译的目标
list:
	@echo "📋 可编译的目标："
	@for file in $(SRCS); do \
		filename=$$(basename $$file .c); \
		echo "$$filename"; \
	done

# 运行某个可执行文件
run-%: $(BUILD_DIR)/%
	@echo "🏃 运行 $<"
	@./$<

# 清理
clean:
	rm -rf $(BUILD_DIR)
	@echo "🧹 清理完成！"

.PHONY: all list clean run-%
