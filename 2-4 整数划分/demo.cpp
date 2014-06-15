// 2-4 整数划分问题
#include <iostream>
using namespace std;

int q(int n, int m)
{
	if((n < 1) || (m < 1))
		return 0;
	if((n == 1) || (m == 1))
		return 1;
	if(n < m)
		return q(n, n);
	if(n == m)
		return q(n, m - 1) + 1;
	return q(n, m - 1) + q(n - m, m);
}

void main()
{
	int n;
	cout << "please input the number \"n\": "<<endl;
	cin >> n;
	cout << q(n, n);
	cout << endl;
}