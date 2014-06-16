// 4-1 �᳡�������� -- ̰���㷨

/*
	����: 1. ���ȶ������ݽṹ, ��ʱ��Ϊ����, ����ṹ��point
		  2. �����ж���ʱ���С����
		  3. ���μ���, ����ǿ�ʼʱ����curr++, ����ǽ���ʱ����curr--, ��������curr��
		     �����ٵĻ᳡��. curr��ʾĿǰ��ʼ��δ�����Ļ��
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point
{
	int t;		// ʱ��
	bool f;		// ��ʾ�ǿ�ʼʱ��(true), ���ǽ���ʱ��(false)
};

bool cmp(point x, point y)
{
	return x.t < y.t;
}

int greedy(vector <point> x)
{
	int sum=0,		  // sum: ���Ĳ����ݻ��
		curr=0,		  // curr: Ŀǰ��ʼ��δ�����Ļ��
		n=x.size();   // x.size() ��ֵΪ 2n
	sort(x.begin(), x.end(), cmp);	 // �����ж���ʱ���С����

	for(int i=0; i<n; i++)
	{
		if(x[i].f)
			curr++;
		else
			curr--;

		if((i == n-1 || x[i].t < x[i+1].t) && curr > sum)		// ����x[i] = x[i+1]�����
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
			x.push_back(temp);		// ��temp�����뵽����x��β��
			temp.f = false;
			cin >> temp.t;
			x.push_back(temp);
		}
		cout << greedy(x) << endl;
		x.clear();
//	}
}