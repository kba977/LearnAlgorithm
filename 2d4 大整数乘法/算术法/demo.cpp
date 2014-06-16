#include <iostream>
#include <string>
using namespace std;

void Bigmultiply(const char *a, const char *b);

void main()
{
	string num1, num2;		// 初始状态用string来存储大数
	cout << "please input two number: " << endl;
	cin >> num1 >> num2;

	const char *p1 = num1.c_str();		// 将string转为 const char *
	const char *p2 = num2.c_str();		// 将string转为 const char *

	Bigmultiply(p1, p2);

	system("pause");
}

void Bigmultiply(const char *a, const char *b)
{
	int i, j;
	int ca = strlen(a);
	int cb = strlen(b);
	int *s = (int *)malloc(sizeof(int)*(ca+cb));		// 分配存储空间

	for (i=0; i<ca+cb; i++)
		s[i] = 0;		// 每个元素赋初值0
	
	for (i=0; i<ca; i++)
		for (j=0; j<cb; j++)
			s[i+j+1] += (a[i] - '0') * (b[j] - '0');

	for (i=ca+cb-1; i>=0; i--)		// 这里实现进位操作
		if (s[i] >= 10)
		{
			s[i-1] += s[i] / 10;
			s[i] %= 10;
		}

	char *c = (char *)malloc((ca+cb)*sizeof(char));		// 分配字符数组空间, 因为它比int数组更省
	
	i = 0;
	while (s[i] == 0)		// 跳过头部的0
		i++;

	for (j=0; i<ca+cb; i++, j++)
		c[j] = s[i] + '0';
	c[j] = '\0';

	for (i=0; i<ca+cb; i++)
		cout << c[i];
	
	cout << endl;

	free(s);
}