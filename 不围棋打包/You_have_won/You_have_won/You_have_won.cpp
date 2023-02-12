// You_have_won.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;
int main()
{
	
	initgraph(800, 800);
	loadimage(NULL, _T("..\\..\\victory.jpeg"), 800, 800);
	RECT r = { 0, 0, 100, 100 };
	drawtext(_T("You have won!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	MOUSEMSG m;
	while (true)
	{
		

		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			closegraph();
			system("..\\..\\mainbranch\\Debug\\ConsoleApplication1.exe");

			return 0;
		}
	}
	
	

	
		
}

