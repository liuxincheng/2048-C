#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define MAX_ROW 4
#define MAX_COL 4

// �����ά����洢����
int g_arr[MAX_ROW][MAX_COL] = {0};

//����һά���鴦���ƶ�����
int g_arr_temp[MAX_ROW] = {0};

// �����������
void CreateData();

// ������ʾ
void UiShow();

int MoveData();

int DealData();

// ��Ϸ���� ����1����
int IsGameOver();

// ��Ϸʤ�� ����1ʤ��
int IsWin();