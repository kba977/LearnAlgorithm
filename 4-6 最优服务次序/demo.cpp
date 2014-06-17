// 4-6 ���ŷ���������� -- ̰���㷨

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
	
	for (int i=1; i<n; i++)		// ��һ����Ҫ�ȴ�ǰһ��
		x[i] += x[i-1];

	double t = 0;
	for (int j=0; j<n; j++)
		t += x[j];

	t /= n;			// ����ƽ��ֵ

	return t;
}