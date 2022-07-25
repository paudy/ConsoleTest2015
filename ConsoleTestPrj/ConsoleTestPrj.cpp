// ConsoleTestPrj.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <atlconv.h>
#include "ProtoBufTest.h"


///functions declare
static void zdTest1();


///主入口函数main 
int main()
{
	testProtoBuf();

	person_serialize();
	person_unSerialize();

	//zdTest1();

	system("pause");
	return 0;
}

///测试函数
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

	printf_s("WStrLen=%s\n", sztmp);

}


