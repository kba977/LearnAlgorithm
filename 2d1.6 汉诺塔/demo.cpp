//2-6 Hanoi����
#include <iostream>
using namespace std;

void hanoi(int n, char a, char b, char c);

void main()
{
	char a = 'A', b = 'B', c = 'C';
	hanoi(3,a,b,c);
}

//����c, ��n�����Ӵ�a�Ƶ�b
void hanoi(int n, char a, char b, char c)
{
	if(n > 0)
	{
		hanoi(n-1, a, b, c); //����b, ��n-1�����Ӵ�a�Ƶ�c
		cout<<"��"<<a<<"���������Ӵ�"<<a<<"�Ƶ�"<<b<<endl;  
		hanoi(n-1, c, b, a);
	}
}