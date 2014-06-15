//5d2 装载问题 - 迭代回溯

#include <iostream>
using namespace std;

template <class Type>
Type MaxLoading(Type w[], Type c, int n, int bestx[]);

int main()
{
	int n = 3, m;
	int c = 50, c2 = 50;

	int w[4] = {0, 10, 40, 40};
	int bestx[4];

	m = MaxLoading(w, c, n, bestx);

	cout << "轮船的载重量分别为: " << endl;
	cout << "c(1)=" << c << ",c(2)=" << c2 << endl;

	cout << "待装集装箱重量分别为: " << endl;
	cout << "w(i)=";
	for(int i=1; i<=n; i++)
	{
		cout << w[i] << " ";
	}
	cout << endl;

	cout << "回溯选择的结果为: " << endl;
	cout << "m(1)=" << m << endl;
	cout << "x(i)=";
	for(i=1; i<=n; i++)
	{
		cout << bestx[i] << " ";
	}
	
	int m2 = 0;
	for(int j=1; j<=n; j++)
	{
		m2 = m2 + w[j]*(1-bestx[j]);
	}
	cout <<"m(2)=" << m2 << endl;

	if(m2 > c2)
	{
		cout << "因为m(2)大于c(2),所以原问题无解!" << endl;
	}
	return 0;
}

template <class Type>
Type MaxLoading(Type w[], Type c, int n, int bestx[]) // 迭代回溯法，返回最优载重量及其相应解，初始化根结点
{
	int i = 1; //当前层, x[1:i-1]为当前路径
	int *x = new int[n+1];

	Type bestw = 0,			//当前最优载重量
		 cw = 0,			//当前载重量
		 r = 0;				//剩余集装箱重量

	for(int j=1; j<=n; j++)
	{
		r += w[j];
	}

	while(true)
	{
		while(i<=n && cw+w[i]<=c) //进入左子树
		{
			r -= w[i];
			cw += w[i];
			x[i] = 1;
			i++;
		}

		if(i>n)		//到达叶结点
		{
			for(int j=1; j<=n; j++)
			{
				bestx[j] = x[j];
			}
			bestw = cw;
		}
		else		//进入右子树
		{
			r -= w[i];
			x[i] = 0;
			i++;
		}

		while(cw+r <= bestw)
		{
			//剪枝回溯
			i--;
			while(i>0 && !x[i])
			{
				r += w[i];
				i--;
			}

			//从右子树返回
			if (i==0)
			{
				delete []x;
				return bestw;
			}
			x[i] = 0;
			cw -= w[i];
			i++;
		}

	}

}