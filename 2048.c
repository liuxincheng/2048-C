#include "2048.h"

int main()
{
	int change = 1;  //����Ƿ�ɹ��ƶ� δ�ƶ����� �������µ������
	srand((unsigned int)time(NULL));
	while(1)
	{
		if (change != 0)
		{
			CreateData();
		}

		UiShow();

		if (IsWin())
		{
			printf("\n����2048����Ϸʤ����\n");
			return 0;
		}

		if (IsGameOver())
		{
			printf("\n��Ϸ������\n");
			return 0;
		}

		change = MoveData();
	}

	return 0;
}

void CreateData()
{
	int row, col;

	do 
	{
		row = rand()%MAX_ROW;
		col = rand()%MAX_COL;

	} while (g_arr[row][col] != 0);

	if (rand()%3 == 0)
	{
		g_arr[row][col] = 4;
	} 
	else
	{
		g_arr[row][col] = 2;
	}
}

void UiShow()
{
	int row, col;
	system("cls"); //��������
	printf("��Ϸ��2048\n");
	printf("������W-�� A-�� S-�� D-��\n");
	printf("\n|----------------------|\n");
	for (row = 0; row < MAX_ROW; row++)
	{
		for (col = 0; col < MAX_COL; col++)
		{
			if (g_arr[row][col] != 0)
			{
				printf("%5d",g_arr[row][col]);
			}
			else
			{
				printf("     ");
			}
		}
		printf("\n|----------------------|\n");
	}
}

int MoveData()
{
	int row,col;
	int change = 0;
	char key;
	key = _getch();

	switch (key)
	{
	case 'w':
	case 'W':
		for(col = 0; col < MAX_COL; col++)
		{
			for(row = 0; row < MAX_ROW; row++)
			{
				g_arr_temp[row] = g_arr[row][col];

			}
			change += DealData();
			for(row = 0; row < MAX_ROW; row++)
			{
				g_arr[row][col] = g_arr_temp[row];

			}
		}
		break;

	case 'a':
	case 'A':
		for(row = 0; row < MAX_ROW; row++)
		{
			for(col = 0; col < MAX_COL; col++)
			{
				g_arr_temp[col] = g_arr[row][col];
			}
			change += DealData();
			for(col = 0; col < MAX_COL; col++)
			{
				g_arr[row][col] = g_arr_temp[col];
			}
		}
		break;

	case 's':
	case 'S':
		for(col = 0; col < MAX_COL; col++)
		{
			for(row = MAX_ROW -1; row >= 0; row--)
			{
				g_arr_temp[(MAX_ROW -1) - row] = g_arr[row][col];

			}
			change += DealData();
			for(row = MAX_ROW -1; row >= 0; row--)
			{
				g_arr[row][col] = g_arr_temp[(MAX_ROW -1) - row];

			}
		}
		break;

	case 'd':
	case 'D':
		for(row = 0; row < MAX_ROW; row++)
		{
			for(col = MAX_COL -1; col >= 0; col--)
			{
				g_arr_temp[(MAX_COL -1) - col] = g_arr[row][col];
			}
			change += DealData();
			for(col = MAX_COL -1; col >= 0; col--)
			{
				g_arr[row][col] = g_arr_temp[(MAX_COL -1) - col];
			}
		}
		break;
	}

	return change;
}

int DealData()
{
	int i,j;
	int change = 0;

	//�ƶ�
	for (i = 0; i < MAX_ROW-1; i++)
	{
		for (j = 0; j < MAX_ROW-1; j++)
		{
			if (g_arr_temp[j] == 0 && g_arr_temp[j+1] != 0)
			{
				g_arr_temp[j] = g_arr_temp[j+1];
				g_arr_temp[j+1] = 0;
				change = 1;
			}
		}
	}

	//���
	for (i = 0; i < MAX_ROW-1; i++)
	{
		if (g_arr_temp[i] == g_arr_temp[i+1] && g_arr_temp[i] != 0)
		{
			g_arr_temp[i] = 2 * g_arr_temp[i];
			g_arr_temp[i+1] = 0;
			change = 1;
		}
	}

	//�ƶ�
	for (i = 0; i < MAX_ROW-1; i++)
	{
		for (j = 0; j < MAX_ROW-1; j++)
		{
			if (g_arr_temp[j] == 0 && g_arr_temp[j+1] != 0)
			{
				g_arr_temp[j] = g_arr_temp[j+1];
				g_arr_temp[j+1] = 0;
				change = 1;
			}
		}
	}

	return change;
}

int IsGameOver()
{
	// �������� ���޷��ƶ� ��Ϸ���� ����1
	int row, col;

	// �жϸ����Ƿ�����
	for (row = 0; row < MAX_ROW; row++)
	{
		for (col = 0; col < MAX_COL; col++)
		{
			if (g_arr[row][col] == 0)
			{
				return 0;
			}
		}
	}

	// �������� �ж������Ƿ���ƶ�
	for (row = 0; row < MAX_ROW; row++)
	{
		for (col = 0; col < MAX_COL-1; col++)
		{
			if (g_arr[row][col] == g_arr[row][col+1])
			{
				return 0;
			}
		}
	}

	// �������� �ж������Ƿ���ƶ�
	for (col = 0; col < MAX_COL; col++)
	{
		for (row = 0; row < MAX_ROW-1; row++)
		{
			if (g_arr[row][col] == g_arr[row+1][col])
			{
				return 0;
			}
		}
	}

	return 1;
}

int IsWin()
{
	int row, col;

	for (row = 0; row < MAX_ROW; row++)
	{
		for (col = 0; col < MAX_COL; col++)
		{
			if (g_arr[row][col] == 2048)
			{
				return 1;
			}
		}
	}

	return 0;
}