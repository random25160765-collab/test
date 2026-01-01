#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

int maze[MAX_ROW][MAX_COL] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0},
};

// 打印迷宫
void print_maze(void)
{
    int i, j;
    for (i = 0; i < MAX_ROW; i++) {
        for (j = 0; j < MAX_COL; j++)
            printf("%d ", maze[i][j]);
        putchar('\n');
    }
    printf("*********\n");
}

// 检查坐标是否有效
int is_valid(int row, int col)
{
    return (row >= 0 && row < MAX_ROW && 
            col >= 0 && col < MAX_COL);
}

// 递归DFS函数
// 返回1表示找到路径，0表示未找到
int dfs(int row, int col)
{
    // 如果到达终点，打印并返回成功
    if (row == MAX_ROW - 1 && col == MAX_COL - 1) {
        printf("(%d, %d) <-- 终点\n", row, col);
        return 1;
    }
    
    // 如果越界或不是通路，返回失败
    if (!is_valid(row, col) || maze[row][col] != 0) {
        return 0;
    }
    
    // 标记当前位置已访问
    maze[row][col] = 2;
    
    // 打印当前状态（可选）
    printf("探索: (%d, %d)\n", row, col);
    print_maze();
    
    // 按右、下、左、上的顺序尝试
    // 注意：递归调用顺序会影响路径选择
    
    // 尝试向右
    if (dfs(row, col + 1)) {
        printf("(%d, %d) <-- 从左边来\n", row, col);
        return 1;
    }
    
    // 尝试向下
    if (dfs(row + 1, col)) {
        printf("(%d, %d) <-- 从上边来\n", row, col);
        return 1;
    }
    
    // 尝试向左
    if (dfs(row, col - 1)) {
        printf("(%d, %d) <-- 从右边来\n", row, col);
        return 1;
    }
    
    // 尝试向上
    if (dfs(row - 1, col)) {
        printf("(%d, %d) <-- 从下边来\n", row, col);
        return 1;
    }
    
    // 四个方向都走不通，回溯时清除标记（可选）
    // maze[row][col] = 0;  // 如果要找所有路径，需要清除标记
    return 0;
}

int main(void)
{
    printf("开始递归DFS寻路...\n");
    
    // 从起点开始递归搜索
    if (dfs(0, 0)) {
        printf("找到路径！\n");
    } else {
        printf("没有找到路径！\n");
    }
    
    return 0;
}

