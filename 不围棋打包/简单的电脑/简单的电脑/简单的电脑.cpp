// 简单的电脑.cpp : 定义控制台应用程序的入口点。
//

// 人机.cpp : 定义控制台应用程序的入口点。
//

#include"stdafx.h"
#include<easyx.h>
#include <graphics.h>
#include <conio.h>
#include<iostream>
#include<time.h>
#include <stdlib.h>
using namespace std;
int now[11][11], visited[11][11];
void copy()
{
	FILE * fp1,*fp2;
	fopen_s(&fp1, "..\\..\\上上盘.txt", "w");
	fopen_s(&fp2, "..\\..\\上一盘.txt", "r");
	int i, j,a[11][11];
	char x;
	for (i = 1; i <= 9; i++)
		for (j = 1; j <= 9; j++)
		{
			fscanf_s(fp2, "%c", &x);
			a[i][j] = x - '0';
			fprintf(fp1, "%d", a[i][j]);
		}
	fclose(fp1);
	fclose(fp2);
	return;

}
void readstorelastlast()
{
	FILE * fp1;
	fopen_s(&fp1, "..\\..\\上上盘.txt", "r");
	int i, j;
	char x;
	loadimage(NULL, _T("..\\..\\背景.jpeg"), 800, 800);
	clearrectangle(500, 200, 700, 300);
	clearrectangle(500, 400, 700, 500);
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
	rectangle(500, 200, 700, 300);
	RECT r1 = { 500, 200, 700, 300 };
	drawtext(_T("Store Game"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	rectangle(500, 400, 700, 500);
	RECT r2 = { 500, 400, 700, 500 };
	drawtext(_T("Load Game"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	rectangle(600, 550, 700, 600);
	RECT r3 = { 600, 550, 700, 600 };
	drawtext(_T("Exit"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	rectangle(450,550, 550, 600);
	RECT r10 = {450, 550, 550, 600 };
	drawtext(_T("Undo last move"), &r10, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	for (i = 1; i <= 9; i++)
		for (j = 1; j <= 9; j++)
		{
			fscanf_s(fp1, "%c", &x);
			now[i][j] = x - '0';
			if (now[i][j] == 1)
			{
				setfillcolor(BLACK);
				solidcircle(j * 30 + 70, i * 30 + 70, 11);
				circle(j * 30 + 70, i * 30 + 70, 10);
				setfillcolor(WHITE);
			}
			if (now[i][j] == 2)
				solidcircle(j * 30 + 70, i * 30 + 70, 10);
		}
	fclose(fp1);
	return;
}
void readstore()
{
	FILE * fp1;
	fopen_s(&fp1, "..\\..\\储存区.txt", "r");
	int i, j;
	char x;
	loadimage(NULL, _T("..\\..\\背景.jpeg"), 800, 800);
	clearrectangle(500, 200, 700, 300);
	clearrectangle(500, 400, 700, 500);
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
	rectangle(500, 200, 700, 300);
	RECT r1 = { 500, 200, 700, 300 };
	drawtext(_T("Store Game"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	rectangle(500, 400, 700, 500);
	RECT r2 = { 500, 400, 700, 500 };
	drawtext(_T("Load Game"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	rectangle(600, 550, 700, 600);
	RECT r3 = { 600, 550, 700, 600 };
	drawtext(_T("Exit"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	rectangle(450,  550, 550, 600);
	RECT r10 = { 450, 550, 550, 600 };
	drawtext(_T("Undo last move"), &r10, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	for (i = 1; i <= 9; i++)
		for (j = 1; j <= 9; j++)
		{
			fscanf_s(fp1, "%c", &x);
			now[i][j] = x - '0';
			if (now[i][j] == 1)
			{
				setfillcolor(BLACK);
				solidcircle(j * 30 + 70, i * 30 + 70, 11);
				circle(j * 30 + 70, i * 30 + 70, 10);
				setfillcolor(WHITE);
			}
			if (now[i][j] == 2)
				solidcircle(j * 30 + 70, i * 30 + 70, 10);
		}
	fclose(fp1);
	return;
}
void store()
{
	FILE * fp1;
	int i, j;


	fopen_s(&fp1, "..\\..\\储存区.txt", "w");
	for (i = 1; i <= 9; i++)
		for (j = 1; j <= 9; j++)
			fprintf(fp1, "%d", now[i][j]);
	fclose(fp1);
	return;
}
void storelast()
{
	FILE * fp1;
	int i, j;


	fopen_s(&fp1, "..\\..\\上一盘.txt", "w");
	for (i = 1; i <= 9; i++)
		for (j = 1; j <= 9; j++)
			fprintf(fp1, "%d", now[i][j]);
	fclose(fp1);
	return;
}
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
bool judge(int x, int y)
{
	int i, j;

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

void premier()
{

	int i, j;
	for (i = 0; i <= 10; i++)
		for (j = 0; j <= 10; j++)
			visited[i][j] = 0;
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
	initgraph(800, 800);
	loadimage(NULL, _T("..\\..\\背景.jpeg"), 800, 800);
	clearrectangle(500, 200, 700, 300);
	clearrectangle(500, 400, 700, 500);
	clearrectangle(450, 550, 500, 600);
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
	rectangle(500, 200, 700, 300);
	RECT r1 = { 500, 200, 700, 300 };
	drawtext(_T("Store Game"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	rectangle(500, 400, 700, 500);
	RECT r2 = { 500, 400, 700, 500 };
	drawtext(_T("Load Game"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	rectangle(600, 550, 700, 600);
	RECT r3 = { 600, 550, 700, 600 };
	drawtext(_T("Exit"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	rectangle(450,  550, 550, 600);
	RECT r10 = { 450, 550, 550, 600 };
	drawtext(_T("Undo last move"), &r10, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

}
int main()
{
	bool judge1 = false;
		
	int s, i, j, k, choose, x, y, q, n;
	float max = 0;
	int can_gox[82], can_goy[82];
	premier();
	MOUSEMSG m;
	while (true)
	{


		while (true)
		{
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				if (m.x >= 600 && m.x <= 700 && m.y <= 600 && m.y >= 550)
				{
					system("..\\..\\singleplayer\\Debug\\ConsoleApplication2.exe");
					return 0;
				}
				if (m.x <= 700 && m.x >= 500 && m.y >= 200 && m.y <= 300)
				{
				
					solidrectangle(500, 200, 700, 300);
					Sleep(20);
					clearrectangle(500, 200, 700, 300);
					
					rectangle(500, 200, 700, 300);
					RECT r1 = { 500, 200, 700, 300 };
					drawtext(_T("Store Game"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					
					store();
					continue;
				}else if(m.x <= 550 && m.x >= 450 && m.y >= 550 && m.y <= 600)
				{
					solidrectangle(450, 650, 550, 600);
					Sleep(20);
					clearrectangle(450, 650, 550, 600);

					rectangle(450, 650, 550, 600);
					RECT r10 = { 450, 650, 550, 600 };
					drawtext(_T("Undo last move"), &r10, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					readstorelastlast();
					judge1 = true;
					continue;
					
				}
				else if(m.x <= 700 && m.x >= 500 && m.y >= 400 && m.y <= 500)
				{
					solidrectangle(500, 400, 700, 500);
					Sleep(20);
					clearrectangle(500, 400, 700, 500);
					rectangle(500, 400, 700, 500);
					RECT r2 = { 500, 400, 700, 500 };
					drawtext(_T("Load Game"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					readstore();
				
					continue;
				}
				else 
				{
					if(judge1==false)
					copy();
					judge1 = false;
					now[locate(m.y)][locate(m.x)] = 1;
					setfillcolor(BLACK);
					circle(locate(m.x) * 30 + 70, locate(m.y) * 30 + 70, 11);
					solidcircle(locate(m.x) * 30 + 70, locate(m.y) * 30 + 70, 10);
					setfillcolor(WHITE);
					break;
				}
			}
		}
		
			if (judge(locate(m.y), locate(m.x)))
			{
				cleardevice();
				loadimage(NULL, _T("..\\..\\fail.jpeg"), 800, 800);
				rectangle(10, 10, 400, 60);
				RECT rmain = { 10, 10, 400, 60 };
				drawtext(_T("You have lost!"), &rmain, DT_CENTER | DT_VCENTER | DT_SINGLELINE); 
			 break;
			}
		
		//人先走
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
				}for (q = 0; q <= 10; q++)
					for (n = 0; n <= 10; n++)
						visited[q][n] = 0;
			}//机器举出所有能落子的地方

		if (s == 0)
		{
			cleardevice();
			loadimage(NULL, _T("..\\..\\victory.jpeg"), 800, 800); 

			rectangle(10, 10, 400, 60);
			RECT rmain = { 10, 10, 400, 60 };
			drawtext(_T("You have won!"), &rmain, DT_CENTER | DT_VCENTER | DT_SINGLELINE); 
						break;
		}//若无，玩家获胜
		else {
			choose = rand() % (s - 1) + 1;


		}
		now[can_gox[choose]][can_goy[choose]] = 2;
		solidcircle(can_goy[choose] * 30 + 70, can_gox[choose] * 30 + 70, 10);
		storelast();
		//选任意的地方落子
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


					}now[i][j] = 0;
				}for (q = 0; q <= 10; q++)
					for (n = 0; n <= 10; n++)
						visited[q][n] = 0;
			}
		if (s == 0)
		{
			cleardevice();
			loadimage(NULL, _T("..\\..\\fail.jpeg"), 800, 800); 
			rectangle(10, 10, 400, 60);
			RECT rmain = { 10, 10, 400, 60 };
			drawtext(_T("You have lost!"), &rmain, DT_CENTER | DT_VCENTER | DT_SINGLELINE); 
			
			break;
		}
		//举出玩家能落子地方，若无，玩家失败





		//否则重复以上过程


	}
	while (true)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{


			system("..\\..\\mainbranch\\Debug\\ConsoleApplication1.exe");
			return 0;
			break;
		}
	}

	system("pause");

	return 0;
}


