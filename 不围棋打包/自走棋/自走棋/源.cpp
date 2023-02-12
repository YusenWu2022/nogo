// 人机.cpp : 定义控制台应用程序的入口点。
//


#include<easyx.h>
#include <graphics.h>
#include <conio.h>
#include<iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;
int now[11][11], visited[11][11], copy1[11][11], round1 = 0;
int air_single(int x, int y)
{
	int z = 0;
	if (now[x - 1][y] == 0)
		z++;
	if (now[x + 1][y] == 0)
		z++;
	if (now[x][y - 1] == 0)
		z++;
	if (now[x][y + 1] == 0)
		z++;
	return z;

}
int air_singlecopy(int x, int y)
{
	int z = 0;
	if (copy1[x - 1][y] == 0)
		z++;
	if (copy1[x + 1][y] == 0)
		z++;
	if (copy1[x][y - 1] == 0)
		z++;
	if (copy1[x][y + 1] == 0)
		z++;
	return z;

}
int air(int x, int y)
{
	int i, j;
	visited[x][y] = 1;
	int z = 0;
	if (now[x + 1][y] == now[x][y] && visited[x + 1][y] == 0)
		z += air(x + 1, y);
	if (now[x - 1][y] == now[x][y] && visited[x - 1][y] == 0)
		z += air(x - 1, y);
	if (now[x][y - 1] == now[x][y] && visited[x][y - 1] == 0)
		z += air(x, y - 1);
	if (now[x][y + 1] == now[x][y] && visited[x][y + 1] == 0)
		z += air(x, y + 1);
	if (now[x + 1][y] == 0)
		z++;
	if (now[x - 1][y] == 0)
		z++;
	if (now[x][y - 1] == 0)
		z++;
	if (now[x][y + 1] == 0)
		z++;

	return z;
}
int aircopy(int x, int y)
{
	int i, j;
	visited[x][y] = 1;
	int z = 0;
	if (copy1[x + 1][y] == copy1[x][y] && visited[x + 1][y] == 0)
		z += aircopy(x + 1, y);
	if (copy1[x - 1][y] == copy1[x][y] && visited[x - 1][y] == 0)
		z += aircopy(x - 1, y);
	if (copy1[x][y - 1] == copy1[x][y] && visited[x][y - 1] == 0)
		z += aircopy(x, y - 1);
	if (copy1[x][y + 1] == copy1[x][y] && visited[x][y + 1] == 0)
		z += aircopy(x, y + 1);
	if (copy1[x + 1][y] == 0)
		z++;
	if (copy1[x - 1][y] == 0)
		z++;
	if (copy1[x][y - 1] == 0)
		z++;
	if (copy1[x][y + 1] == 0)
		z++;

	return z;
}
bool judge(int x, int y)
{
	int i, j, q, n;
	for (q = 0; q <= 10; q++)
		for (n = 0; n <= 10; n++)
			visited[q][n] = 0;
	if (air(x, y) == 0 && now[x][y] != 0)
		return true;
	for (i = 0; i <= 10; i++)
		for (j = 0; j <= 10; j++)
			visited[i][j] = 0;
	if (air(x + 1, y) == 0 && now[x + 1][y] != 0)
		return true;
	for (i = 0; i <= 10; i++)
		for (j = 0; j <= 10; j++)
			visited[i][j] = 0;
	if (air(x - 1, y) == 0 && now[x - 1][y] != 0)
		return true;
	for (i = 0; i <= 10; i++)
		for (j = 0; j <= 10; j++)
			visited[i][j] = 0;
	if (air(x, y + 1) == 0 && now[x][y + 1] != 0)
		return true;
	for (i = 0; i <= 10; i++)
		for (j = 0; j <= 10; j++)
			visited[i][j] = 0;
	if (air(x, y - 1) == 0 && now[x][y - 1] != 0)
		return true;
	for (i = 0; i <= 10; i++)
		for (j = 0; j <= 10; j++)
			visited[i][j] = 0;

	return false;

}
bool judgecopy(int x, int y)
{
	int i, j, q, n;
	for (q = 0; q <= 10; q++)
		for (n = 0; n <= 10; n++)
			visited[q][n] = 0;
	if (aircopy(x, y) == 0 && copy1[x][y] != 0)
		return true;
	for (i = 0; i <= 10; i++)
		for (j = 0; j <= 10; j++)
			visited[i][j] = 0;
	if (aircopy(x + 1, y) == 0 && copy1[x + 1][y] != 0)
		return true;
	for (i = 0; i <= 10; i++)
		for (j = 0; j <= 10; j++)
			visited[i][j] = 0;
	if (aircopy(x - 1, y) == 0 && copy1[x - 1][y] != 0)
		return true;
	for (i = 0; i <= 10; i++)
		for (j = 0; j <= 10; j++)
			visited[i][j] = 0;
	if (aircopy(x, y + 1) == 0 && copy1[x][y + 1] != 0)
		return true;
	for (i = 0; i <= 10; i++)
		for (j = 0; j <= 10; j++)
			visited[i][j] = 0;
	if (aircopy(x, y - 1) == 0 && copy1[x][y - 1] != 0)
		return true;
	for (i = 0; i <= 10; i++)
		for (j = 0; j <= 10; j++)
			visited[i][j] = 0;

	return false;

}

int locate(int x)
{
	float y = (x - 100) / 30.0;
	int z;
	z = (x - 100) / 30;
	if (y - z >= 0.5)
		x = z + 2;
	else x = z + 1;
	return x;
}
int accuracy(int round1)
{
	int accuracy1;
	if (round1 <= 15)
		accuracy1 = 250;
	else {
		if (round1 <= 60)
			accuracy1 = 1000;
		else accuracy1 = 3000;
	}
	return accuracy1;
}
float imitate(int x, int y)
{
	float z;
	int can_gox[82], can_goy[82], s;

	int i; int j; int win_2 = 0; int lose_2 = 0; int choose, q, n;
	int count; int player;

	for (count = 1; count <= accuracy(round1); count++)
	{
		for (i = 0; i <= 10; i++)
			for (j = 0; j <= 10; j++)
				copy1[i][j] = now[i][j];

		player = 0;
		copy1[x][y] = 2;
		while (true)
		{
			player++;
			s = 0;
			for (i = 1; i <= 9; i++)
				for (j = 1; j <= 9; j++)
				{
					if (copy1[i][j] == 0)
					{

						s++;
						can_gox[s] = i;
						can_goy[s] = j;


					}
				}

			//先后找当前玩家能走的位置

			//如果是零，结束，输出结果
			if (s > 1)
			{


				choose = rand() % s + 1;
			}
			else
				choose = 1;
			//随机走一步能走的
			copy1[can_gox[choose]][can_goy[choose]] = 2 - player % 2;

			
		}
	}
	z = win_2 / 500.0;

	return z;
}
float imitate2(int x, int y)
{
	float z;
	int can_gox[82], can_goy[82], s;

	int i; int j; int win_2 = 0; int lose_2 = 0; int choose, q, n;
	int count; int player;

	for (count = 1; count <= accuracy(round1); count++)
	{
		for (i = 0; i <= 10; i++)
			for (j = 0; j <= 10; j++)
				copy1[i][j] = now[i][j];

		player = 1;
		copy1[x][y] = 1;
		while (true)
		{
			player++;
			s = 0;
			for (i = 1; i <= 9; i++)
				for (j = 1; j <= 9; j++)
				{
					if (copy1[i][j] == 0)
					{

						s++;
						can_gox[s] = i;
						can_goy[s] = j;


					}
				}

			//先后找当前玩家能走的位置
			if (s==0)
			{
				if (player % 2 == 0)
				{
					win_2++;
					break;
				}
				else
					break;
			}
			//如果是零，结束，输出结果
			if (s > 1)
			{


				choose = rand() % s + 1;
			}
			else
				choose = 1;
			//随机走一步能走的
			copy1[can_gox[choose]][can_goy[choose]] = 2 - player % 2;

			
		}
	}
	z = win_2 / 500.0;

	return z;
}
void premier()
{

	int i, j;
	srand((unsigned int)time(0));
	for (i = 1; i <= 9; i++)
		for (j = 1; j <= 9; j++)
		{
			now[i][j] = 0;


		}
	for (i = 0; i <= 10; i++)
		for (j = 0; j <= 10; j++)
			visited[i][j] = 0;
	for (i = 0; i <= 10; i++)
		now[i][0] = 9;
	for (j = 0; j <= 10; j++)
		now[0][j] = 9;
	for (i = 0; i <= 10; i++)
		now[i][10] = 9;
	for (j = 0; j <= 10; j++)
		now[10][j] = 9;
	initgraph(800, 800);
	for (j = 1; j <= 8; j++)
		rectangle(100, 100, 100 + 30 * j, 340);
	for (j = 1; j <= 8; j++)
		rectangle(100, 100, 340, 100 + 30 * j);

	for (i = 1; i <= 9; i++)
	{
		TCHAR s1[5];
		_stprintf_s(s1, _T("%d"), i);
		outtextxy(70 + 30 * i, 80, s1);
	}
	for (i = 1; i <= 9; i++)
	{
		TCHAR s[5];
		_stprintf_s(s, _T("%d"), i);


		outtextxy(80, 60 + 30 * i, s);
	}

}
int main()
{
	int s, i, j, k, choose, q, n;
	float max = 0, temp;
	int can_gox[82], can_goy[82];
	premier();
	
	while (true)
	{
		max = 0;
		round1++;
		
		s = 0;
		for (i = 1; i <= 9; i++)
			for (j = 1; j <= 9; j++)
			{
				if (now[i][j] == 0)
				{
					now[i][j] = 1;
					if (!judge(i, j))
					{
						s++;
						can_gox[s] = i;
						can_goy[s] = j;

					}now[i][j] = 0;

				}
			}//机器举出所有能落子的地方
		if (s == 0)
		{

			rectangle(10, 10, 400, 60);
			RECT rmain = { 10, 10, 400, 60 };
			drawtext(_T("Player 2 have won!"), &rmain, DT_CENTER | DT_VCENTER | DT_SINGLELINE); break;
		}//若无，玩家获胜
		for (k = 1; k <= s; k++)
		{
			temp = imitate2(can_gox[k], can_goy[k]);
			if (max < temp)
			{
				max = temp;
				choose = k;
			}
		}
		now[can_gox[choose]][can_goy[choose]] = 1;
		circle(can_goy[choose] * 30 + 70, can_gox[choose] * 30 + 70, 10);
		s = 0;
		for (i = 1; i <= 9; i++)
			for (j = 1; j <= 9; j++)
			{
				if (now[i][j] == 0)
				{
					now[i][j] = 2;
					if (!judge(i, j))
					{
						s++;
						can_gox[s] = i;
						can_goy[s] = j;

					}now[i][j] = 0;

				}
			}//机器举出所有能落子的地方
		if (s == 0)
		{

			rectangle(10, 10, 400, 60);
			RECT rmain = { 10, 10, 400, 60 };
			drawtext(_T("Player 1 have won!"), &rmain, DT_CENTER | DT_VCENTER | DT_SINGLELINE); break;
		}//若无，玩家获胜
		max = 0;
		for (k = 1; k <= s; k++)
		{
			temp = imitate(can_gox[k], can_goy[k]);
			if (max < temp)
			{
				max = temp;
				choose = k;
			}
		}


		//否则模拟，计算每个可落子地方的胜率
		now[can_gox[choose]][can_goy[choose]] = 2;
		solidcircle(can_goy[choose] * 30 + 70, can_gox[choose] * 30 + 70, 10);
		//选最好的地方落子
		

		


	}
	


	system("pause");
	return 0;
}

