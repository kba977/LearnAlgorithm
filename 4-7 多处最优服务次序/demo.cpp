// 4-7 多处最优服务次序问题 -- 贪心算法

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
	vector<int> st(s+1, 0);			// 创建一个int类型s+1个元素, 且值均为0的vector容器st
	vector<int> su(s+1, 0);			// 创建一个int类型s+1个元素, 且值均为0的vector容器su
	int n = x.size();
	
	sort(x.begin(), x.end());
	
	int i=0, j=0;
	for(i; i<n; i++,j++)
	{
		j = i % s;			// 第i的任务由第i%s处处理
		st[j] += x[i];		// 在第j处处理的任务运行时间之和
		su[j] += st[j];		// 在第j处处理的任务等待时间之和
	}
	
	double t = 0;
	
	for(i=0; i<s; i++)
		t += su[i];

	t /= n;

	return t;
}