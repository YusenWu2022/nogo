// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//
#include <graphics.h>
#include <conio.h>
#include"stdafx.h"
#include<easyx.h>
#include<iostream>
using namespace std;
int locate(int x)
{
	float y=(x-100)/30.0;
	int z;
	z = (x - 100) / 30;
	if (y - z >= 0.5)
		x = z+2;
	else x = z+1;
	return x;
}
int main()
{
	
	
	int i = 0,j;
	
	initgraph(800, 800);
	loadimage(NULL, _T("..\\..\\chess.jpg"), 800, 800);
	for (j = 1; j <= 8; j++)
		rectangle(100, 100, 100 + 30 * j, 340);
	for (j = 1; j <= 8; j++)
		rectangle(100, 100, 340, 100 + 30 * j);
	rectangle(500, 200, 700, 300);
	RECT r1 = { 500, 200, 700, 300 };
	drawtext(_T("Easy AI"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	rectangle(500, 400, 700, 500);
	RECT r = { 500, 400, 700, 500 };
	drawtext(_T("Middle AI"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	rectangle(500, 10, 700, 100);
	RECT r2 = { 500, 10, 700, 100 };
	drawtext(_T("Cruel AI"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	rectangle(600, 550, 700, 600);
	RECT r3 = { 600, 550, 700, 600 };
	drawtext(_T("Exit"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

MOUSEMSG m;	
	while (true)
	{

		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 600 && m.x <= 700 && m.y <= 600 && m.y >= 550)
		{
			system("..\\..\\mainbranch\\Debug\\ConsoleApplication1.exe");
			return 0;
		}
		if (m.uMsg == WM_LBUTTONDOWN&&m.x <= 700 && m.x >= 500 && m.y >= 200 && m.y <= 300)
		{
			solidrectangle(500, 200, 700, 300);
			Sleep(20);
			rectangle(500, 200, 700, 300);
			system("..\\..\\简单的电脑\\debug\\简单的电脑.exe");
			return 0;
			break;
		}
		if (m.uMsg == WM_LBUTTONDOWN&&m.x <= 700 && m.x >= 500 && m.y >= 400 && m.y <= 500)
		{
			solidrectangle(500, 400, 700, 500);
			Sleep(20);
			rectangle(500, 400, 700, 500);
			system("..\\..\\中等的电脑\\debug\\中等的电脑.exe");
			return 0;
			break;
		}
		if (m.uMsg == WM_LBUTTONDOWN&&m.x <= 700 && m.x >= 500 && m.y >=0 && m.y <= 100)
		{
			solidrectangle(500, 0, 700, 100);
			Sleep(20);
			rectangle(500, 0, 700, 100);
			system("..\\..\\冷酷的电脑\\debug\\人机.exe");
			return 0;
			break;
		}
		if (m.uMsg == WM_RBUTTONDOWN)
		{
			
	system("..\\..\\mainbranch\\Debug\\ConsoleApplication1.exe");
return 0;

			
		}
	}
	
	
	closegraph();


}

