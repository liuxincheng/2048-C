#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define MAX_ROW 4
#define MAX_COL 4

// 定义二维数组存储数据
int g_arr[MAX_ROW][MAX_COL] = {0};

//定义一维数组处理移动数据
int g_arr_temp[MAX_ROW] = {0};

// 创建随机数据
void CreateData();

// 界面显示
void UiShow();

int MoveData();

int DealData();

// 游戏结束 返回1结束
int IsGameOver();

// 游戏胜利 返回1胜利
int IsWin();