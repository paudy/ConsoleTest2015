// ConsoleTestPrj.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <atlconv.h>

static void zdTest1()
{
	USES_CONVERSION;
	TCHAR szWstr[2048] = { 0 };
	for (int i = 0; i < 2046; i++)
	{
		szWstr[i] = L'A';
	}
	char *pstr = W2A(szWstr);
	int n = strlen(pstr);
	char sztmp[100] = { 0 };
	sprintf_s(sztmp, "%d", n);

}


int main()
{
	zdTest1();
    return 0;
}

