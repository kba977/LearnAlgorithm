// 4-7 �ദ���ŷ���������� -- ̰���㷨

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int greedy(vector<int> x, int s);

void main()
{
	vector<int> x;
	int n, s, temp;
	
	cin >> n >> s;

	for(int i=0; i<n; i++)
	{
		cin >> temp;
		x.push_back(temp);
	}

	cout << greedy(x, s) << endl;

	x.clear();
}

int greedy(vector<int> x, int s)
{
	vector<int> st(s+1, 0);			// ����һ��int����s+1��Ԫ��, ��ֵ��Ϊ0��vector����st
	vector<int> su(s+1, 0);			// ����һ��int����s+1��Ԫ��, ��ֵ��Ϊ0��vector����su
	int n = x.size();
	
	sort(x.begin(), x.end());
	
	int i=0, j=0;
	for(i; i<n; i++,j++)
	{
		j = i % s;			// ��i�������ɵ�i%s������
		st[j] += x[i];		// �ڵ�j���������������ʱ��֮��
		su[j] += st[j];		// �ڵ�j�����������ȴ�ʱ��֮��
	}
	
	double t = 0;
	
	for(i=0; i<s; i++)
		t += su[i];

	t /= n;

	return t;
}