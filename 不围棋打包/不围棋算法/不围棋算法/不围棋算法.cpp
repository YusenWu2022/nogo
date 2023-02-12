// 不围棋算法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int now[10][10], groupnum = 0, visited[10][10], group[10][10], air[100] = { 0 };
void search(int x, int y)
{
	if (now[x][ y] == 1 && visited[x][y]==0 )
	{
		group[x][y] = groupnum;
		visited[x][y] = 1;
		search(x, y + 1);
		search(x, y - 1);
		search(x + 1, y);
		search(x - 1, y);
		
	}
	return;
}
void search2(int x, int y)
{
	if (now[x][y] == 2 && visited[x][y] == 0)
	{
		group[x][y] = groupnum;
		visited[x][y] = 1;
		search2(x, y + 1);
		search2(x, y - 1);
		search2(x + 1, y);
		search2(x - 1, y);
		

	}
	return;
}
void divide()
{
	int i, j, k;
	groupnum = 0;
	for (i = 1; i <= 4; i++)
		for (j = 1; j <= 4; j++)

		{
			if (visited[i][j] == 0 && now[i][j] == 1)
			{
				groupnum++;
				search(i, j);
			}
		}
	
	for (i = 1; i <= 4; i++)
		for (j = 1; j <= 4; j++)
			visited[i][j] = 0;
	for (i = 1; i <= 4; i++)
		for (j = 1; j <= 4; j++)

		{
			if (visited[i][j] == 0 && now[i][j] == 2)
			{
				groupnum++;
				search2(i, j);
			}
		}

	
	return ;
}

int single_air(int x,int y)
{
	int z=0;
	if (now[x - 1][y] == 0)
		z++;
	if (now[x + 1][y] == 0)
		z++;
	if (now[x][y-1] == 0)
		z++;
	if (now[x][y+1] == 0)
		z++;
	return z;
}
void breath()
{
	int i, j;
	for (i = 1; i <= 4; i++)
		for(j=1;j<=4;j++)
		air[group[i][j]] += single_air(i, j);
	return;

}
bool judge()
{
	int i;
	for (i = 1; i <= groupnum; i++)

		if (air[i] == 0)
		{
			return true; 
		}
		if(i==groupnum+1)
			return false;
}
void premier()
{
	
	int i, j;
	for (i = 1; i <= 20; i++)
		air[i] = 0;
	for (i = 1; i <= 9; i++)
		for (j = 1; j <= 9; j++)
		{
			now[i][j] = 0;
			visited[i][j] = 0;
		}

	for (i = 0; i <= 9; i++)
		now[i][0] = 9;
	for (j = 0; j <= 9; j++)
		now[0][j] = 9;


}
	

int main()
{
	int i, j, k=0,x,y,player;
	premier();
	/*while (true) {
		
		k++;
		if (k % 2 == 1)
			player = 1;
		else player = 2;
		cin >> x >> y;
		now[x][y] = player;
		*/
	for (i = 1; i <= 4; i++)
		for (j = 1; j <= 4; j++)
		{
			cin >> now[i][j];
			if (now[i][j] == 2 || now[i][j] == 1)
				k++;
		}
		divide();
		breath();
		if (k % 2 == 1)
				player = 1;
			else player = 2;
		if (judge())
			
			printf("player%d lost!  ", player);

			
			
	
	system("pause");



		
	return 0;
}
