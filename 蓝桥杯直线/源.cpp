//暴力法解题，答案4441
#include<iostream>
#define RANGE_LEN 20
#define RANGE_WIDTH 21
using namespace std;
typedef struct Line
{
	//y = kx + b;
	double y;
	double x;
	double k;
	double b;
}Line;
typedef struct SqList
{
	int head = 0;
	int tail = 0;
	Line line_list[10000];
	int len;
}SqList;
bool equals(Line one, Line two)
{
	return (one.b == two.b) && (one.k == two.k) &&(one.y==two.y)&&(one.x==two.x);
}
void add(SqList &sqList, Line line)
{
	//判断line在不在list里
	for (int i = sqList.head; i <= sqList.tail; i++)
	{
		if (equals(line, sqList.line_list[i]))
			return;
	}
	sqList.line_list[sqList.tail] = line;
	sqList.tail++;
}
int main()
{
	SqList sqList;

	for(int x1=0;x1<RANGE_LEN;x1++)
		for(int y1=0;y1< RANGE_WIDTH;y1++)
			for(int x2=0;x2<RANGE_LEN;x2++)
				for (int y2 = 0; y2 < RANGE_WIDTH; y2++)
				{
					if (x1 == x2 && y1 == y2)//两个相同的点肯定不能成线啦
						continue;
					Line line;
					if (x1 - x2 == 0)
					{
						line.x = x1;
						line.b = 0;
						line.k = 0;
						line.y = 0;
					}
					else if (y1 - y2 == 0)
					{
						line.x = 0;
						line.b = 0;
						line.k = 0;
						line.y = y1;
					}
					else
					{
						line.k = (y1 - y2) / (x1 - x2);
						line.b = y1 - line.k * x1; //b = y - kx
						line.y = 0;
						line.x = 0;
					}
					add(sqList, line);
				}
	sqList.len = sqList.tail + 1;//下标从0开始，所以长度为tail+1
	cout << "个数:" << sqList.len << endl;
	return 0;
}