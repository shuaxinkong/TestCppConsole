#include <iostream>
#include <conio.h>
using namespace std;

char* getMem(int num)
{
	char* p1 = nullptr;
	p1 = (char*)malloc(num*sizeof(char));
	printf("p1: %d, p1: %s\n", p1, p1);
	return p1;
}

char* getMem2(int num)
{
	char p1[33];
	strcpy(p1, "Hello world!");
	printf("p1: %d, p1: %s\n", p1, p1);
	return p1;
}

int checkEndian()
{
	union w { int a; char b; } c;
	c.a = 1;
	return (c.b == 1);
}


int getStrData(int* len, char** ptrData)
{
	char* tmp = new char[33];
	strcpy(tmp, "Hello world!");

	*len = strlen(tmp);
	*ptrData = tmp;
	return 1;
}


int getStrData2(int* len, char* data)
{
	strcpy(data, "Hello world!");
	*len = strlen(data);
	return 1;
}

int getStrDataViaRef(int& len, char* data)
{
	strcpy(data, "Hello world!");
	len = strlen(data);
	return 1;
}

void TestInt(const int& num)
{

}

int main()
{
	// 1. Version 1
	int strLen = 0;
	char* strData = nullptr;
	getStrData(&strLen, &strData);
	cout << strData << endl;
	cout << strLen << endl;
	if (strData != nullptr)
	{
		delete(strData);
	}

	// exit
	cout << "Press to exit...";
	_getch();
	return 1;
}