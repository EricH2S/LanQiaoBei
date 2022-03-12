//答案为3181
#include<iostream>
using namespace std;
int main()
{
	int lst[10] ;
	for (int i =0;i<10;i++)
	{
		lst[i] = 2021;//每张牌各2021
	}
	int count=1;
	while (1)
	{
		int num = count;
		
		while (num!=0)
		{
			lst[num % 10] -= 1;
			num /= 10;
		}
		for (int i = 0; i < 10; i++)
		{
			if (lst[i] < 0)
				return 1;
		}
		cout << count << endl;
		count++;
	}
	return 0;
}