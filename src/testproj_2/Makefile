CC = gcc
CFLAGS = -Wall -Iinclude -g -MMD -MP
TARGET = main
LIB = lib/libmathutils.a
HEADER = include/math_utils.h
BIN = bin

# 查找源文件
SRC_FILES = $(wildcard src/arithmetic/*.c) \
			$(wildcard src/number_theory/*.c) \
			$(wildcard src/statistics/*.c)

# 生成目标文件列表
OBJ_FILES = $(patsubst src/%.c, $(BIN)/%.o, $(SRC_FILES))

DEP_FILES = $(OBJ_FILES:.o=.d)

all: $(TARGET)

# 编译主程序
$(TARGET): main.c $(LIB) $(HEADER)
	$(CC) $(CFLAGS) main.c -Llib -lmathutils -o $(TARGET)
	@echo "正在编译main.c..."
	@echo "编译完成！"

# 构建库
$(LIB): $(OBJ_FILES)
	@mkdir -p lib
	ar rcs $@ $^
	@echo "正在构建库..."

# 编译库文件
$(BIN)/%.o: src/%.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "正在编译库文件..."

-include $(DEP_FILES)

# 初始化
clean:
	rm -rf $(TARGET) $(BIN) lib *.d
	@echo "初始化成功！"
	
.PHONY: all clean
