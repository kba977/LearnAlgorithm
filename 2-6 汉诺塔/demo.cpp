//2-6 Hanoi问题
#include <iostream>
using namespace std;

void hanoi(int n, char a, char b, char c);

void main()
{
	char a = 'A', b = 'B', c = 'C';
	hanoi(3,a,b,c);
}

//借助c, 将n个盘子从a移到b
void hanoi(int n, char a, char b, char c)
{
	if(n > 0)
	{
		hanoi(n-1, a, b, c); //借助b, 将n-1个盘子从a移到c
		cout<<"将"<<a<<"中最大的盘子从"<<a<<"移到"<<b<<endl;  
		hanoi(n-1, c, b, a);
	}
}