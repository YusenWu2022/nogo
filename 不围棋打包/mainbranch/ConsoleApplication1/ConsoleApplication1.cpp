// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//



// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//
#include <graphics.h>
#include <conio.h>
#include"stdafx.h"
#include<easyx.h>
#include<iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	
	
	int i = 0, j;
	initgraph(800, 800);
	LOGFONT f;
	gettextstyle(&f);						
	f.lfHeight = 40;
	_tcscpy_s(f.lfFaceName, _T("黑体"));
	loadimage(NULL, _T("..\\..\\chess.jpg"),800,800);
	rectangle(10, 10, 400, 60);
	RECT rmain = { 10, 10, 400, 60 };
	drawtext(_T("NO GO CHESS ALARM"), &rmain, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	rectangle(600, 550, 700, 600);
	RECT r3 = { 600, 550, 700, 600 };
	drawtext(_T("Exit"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	rectangle(500, 200, 700, 300);
	RECT r1 = { 500, 200, 700, 300 };
	drawtext(_T("Single Mode"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	rectangle(500, 400, 700, 500);
	RECT r = { 500, 400, 700, 500 };
	drawtext(_T("Pair Mode"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	for (j = 1; j <= 8; j++)
		rectangle(100, 100, 100 + 30 * j, 340);
	for (j = 1; j <= 8; j++)
		rectangle(100, 100, 340, 100 + 30 * j);//生成界面
	
	
	
	MOUSEMSG m;
	while (true)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 600 && m.x <= 700 && m.y <= 600 && m.y >= 550)
			goto a;
		if (m.uMsg== WM_LBUTTONDOWN&&m.x <= 700 && m.x >= 500 && m.y >= 200 && m.y <= 300)
		{
			solidrectangle(500, 200, 700, 300);
			Sleep(20);
			rectangle(500, 200, 700, 300);
			system("..\\..\\singleplayer\\Debug\\ConsoleApplication2.exe");
			break;
		}
		if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 500 && m.x <= 700 && m.y >= 400 && m.y <= 500)
		{
			solidrectangle(500, 400, 700, 500);
			Sleep(20);
			rectangle(500, 400, 700, 500);
			system( "..\\..\\pairplayer\\Debug\\pairplayer.exe");
			break;
			}
	}


	


	
closegraph();
	a:return 0;
	

}



