// 简单算法.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include<easyx.h>
#include <graphics.h>
#include <conio.h>
#include<iostream>
using namespace std;

int now[11][11],visited[11][11];
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
int air(int x, int y)
{
	visited[x][y] = 1;
	int z=0;
	if (now[x + 1][y] == now[x][y]&&visited[x+1][y]==0)
		z += air(x + 1, y);
	if (now[x - 1][y] == now[x][y] && visited[x - 1][y] == 0)
		z += air(x - 1, y);
	if (now[x][y-1] == now[x][y] && visited[x ][y-1] == 0)
		z += air(x, y-1);
	if (now[x][y+1] == now[x][y] && visited[x][y+1] == 0)
		z += air(x, y+1);
	if (now[x + 1][y] == 0)
		z++;
	if (now[x - 1][y] == 0)
		z++;
	if (now[x ][y-1] == 0)
		z++;
	if (now[x][y+1] == 0)
		z++;
	return z;
}
bool judge(int x,int y)
{
	
	
			if(air(x,y) == 0)
				return true;
			if (air(x+1, y) == 0)
				return true;
			if (air(x-1, y) == 0)
				return true;
			if (air(x, y+1) == 0)
				return true;
			if (air(x, y-1) == 0)
				return true;
	
		return false;

}
void premier()
{

	int i, j;
	
	for (i = 1; i <= 9; i++)
		for (j = 1; j <= 9; j++)
		{
			now[i][j] = 0;
			
		}

	for (i = 0; i <= 10; i++)
		now[i][0] = 9;
	for (j = 0; j <= 10; j++)
		now[0][j] = 9;
	for (i = 0; i <= 10; i++)
		now[i][10] = 9;
	for (j = 0; j <= 10; j++)
		now[10][j] = 9;

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
int main()
{
	int i, j, k=0, player,x,y;
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
	MOUSEMSG m;
	premier();
	while (true) {
		for (i = 1; i <= 9; i++)
			for (j = 1; j <= 9; j++)
				visited[i][j] = 0;
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{

			k++;
			if (k % 2 == 1)
			{
				now[locate(m.y)][locate(m.x)] = 1;
				circle(locate(m.x) * 30 + 70, locate(m.y) * 30 + 70, 10);
			}
			else
			{
				now[locate(m.y)][locate(m.x)] = 2;
				solidcircle(locate(m.x) * 30 + 70, locate(m.y) * 30 + 70, 10);
			}
			
		if (k % 2 == 1)
			player = 1;
		else player = 2;
		
		now[locate(m.y)][locate(m.x)] = player;
		if (judge(locate(m.y), locate(m.x)))
		{
			printf("player%d  lost!", player);
			break;
		}
		}
		
	}




    return 0;
}

