#include <iostream>
using namespace std;

int list[50000];
bool judge(int n)//ÅĞ¶ÏÊÇ·ñÎªËØÊı
{
	if (n == 2)
		return true;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
void merge()
{
	
	int index = 0;
	for (int i = 2; i <= 50000; i++)
	{
		if (judge(i))
		{
			list[index] = i;
			index++;
		}
	}
}
int main()
{
	merge();
	int index = 0;
	int step=0;
	bool flag = true;
	while (flag)
	{
		step++;
		int i = 0;
		for (; i < 6; i++)
		{
			if (!judge(list[index] + step * i))
				break;
		}
		if (i == 7)
		{
			flag = false;
		}
		index++;
	}
	cout << step<<endl;
	return 0;
}