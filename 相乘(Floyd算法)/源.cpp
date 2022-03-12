#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>

#define INFINITY 999999
#define SIZE 2022

using namespace std;

int gcd(int a, int b)
{
	return b > 0 ? gcd(b, a % b) : a;
}
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}
int main()
{
	//auto dist = new int[2022][2022];
	
	

	vector<vector<int>> row(SIZE, vector<int>(SIZE,0));
	for (int i = 1; i <= SIZE-1; ++i)
	{
		for (int j = 1; j <= SIZE - 1; ++j)
		{
			if (i == j)
				row[i][j] = 0;
			if (abs(i - j) <= 21)
			{
				row[i][j] = lcm(i, j);
				row[j][i] = lcm(i, j);
			}
			else
			{
				row[i][j] = INFINITY;
			}
		}
	}
	
	//FloydËã·¨
	for(int k=1;k<= SIZE - 1;++k)
		for(int i=1;i<= SIZE - 1;++i)
			for (int j = 1; j <= SIZE - 1; ++j)
			{
				if (row[i][j] > row[i][k] + row[k][j])
					row[i][j] = row[i][k] + row[k][j];
				cout << "i:" << i
					<< "j:" << j
					<< "k:" << k
					<<endl;
			}
	
	cout << row[1][2021];
	return 0;
}