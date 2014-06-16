// 4-1 会场安排问题 -- 贪心算法

/*
	方法: 1. 首先定义数据结构, 以时间为核心, 定义结构体point
		  2. 对所有对象按时间大小排序
		  3. 依次计算, 如果是开始时间则curr++, 如果是结束时间则curr--, 其中最大的curr即
		     是最少的会场数. curr表示目前开始且未结束的活动数
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point
{
	int t;		// 时间
	bool f;		// 表示是开始时间(true), 还是结束时间(false)
};

bool cmp(point x, point y)
{
	return x.t < y.t;
}

int greedy(vector <point> x)
{
	int sum=0,		  // sum: 最大的不兼容活动数
		curr=0,		  // curr: 目前开始且未结束的活动数
		n=x.size();   // x.size() 的值为 2n
	sort(x.begin(), x.end(), cmp);	 // 对所有对象按时间大小排序

	for(int i=0; i<n; i++)
	{
		if(x[i].f)
			curr++;
		else
			curr--;

		if((i == n-1 || x[i].t < x[i+1].t) && curr > sum)		// 处理x[i] = x[i+1]的情况
			sum = curr;
	}
	return sum;
}

void main()
{
	vector<point> x;
	int n, i;
	point temp;
	cin >> n;
//	while(cin >> n)
//	{
		for(i=0; i<n; i++)
		{
			temp.f = true;
			cin >> temp.t;
			x.push_back(temp);		// 将temp结点加入到容器x的尾部
			temp.f = false;
			cin >> temp.t;
			x.push_back(temp);
		}
		cout << greedy(x) << endl;
		x.clear();
//	}
}