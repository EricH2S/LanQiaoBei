#include<iostream>
#include<time.h>
#include<stdio.h>
using namespace std;

int main()
{
	//test: 46800999 , 1618708103123
	unsigned long long time= 46800999;
	//cin >> time;

	//1000ms = 1s
	int ss = time / 1000 % 60;
	int mm = time / 1000 / 60 % 60;
	int hh = time / 1000 / 60 /60 % 60;
	/*cout <<hh<<":"<< mm << ":" << ss;*/
	//用c的格式输出
	printf("%02d:%02d:%02d",hh,mm,ss);
	return 0;
}