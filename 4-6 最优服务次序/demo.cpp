// 4-6 最优服务次序问题 -- 贪心算法

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int greedy(vector<int> x);

void main()
{
	vector<int> x;
	int n;
	int temp;
	
	cin >> n;

	for(int i=0; i<n; i++)
	{
		cin >> temp;
		x.push_back(temp);
	}

	cout << greedy(x) << endl;
	x.clear();
}

int greedy(vector<int> x)
{
	int n = x.size();
	sort(x.begin(), x.end());
	
	for (int i=1; i<n; i++)		// 后一个需要等待前一个
		x[i] += x[i-1];

	double t = 0;
	for (int j=0; j<n; j++)
		t += x[j];

	t /= n;			// 计算平均值

	return t;
}