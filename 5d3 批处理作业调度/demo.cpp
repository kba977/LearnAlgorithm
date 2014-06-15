//d53 批处理作业调度

#include <iostream>
using namespace std;

class Flowshop
{
	friend int Flow(int **M, int n, int bestx[]);
	private:
		void Backtrack(int i);

		int **M,		// 各作业所需的处理时间
			*x,			// 当前作业调度
			*bestx,		// 当前最优作业调度

			*f2,		// 机器2完成处理时间
			f1,			// 机器1完成处理时间 
			f,			// 完成时间和

			bestf,		// 当前最优值
			n;			// 作业数
};

int Flow(int **M, int n, int bestx[]);

template <class Type>
inline void Swap(Type &a, Type &b);

void main()
{
	int n = 3,bf;
	int M1[4][3]={{0,0,0},{0,2,1},{0,3,1},{0,2,3}};
	
	int **M = new int*[n+1];

	for(int i=0; i<=n; i++)
	{
		M[i] = new int[3];
	}
	cout << "M(i,j)值如下: " << endl;

	for(i=0; i<=n; i++)
	{
		for(int j=0;j<3;j++)
		{
			M[i][j] = M1[i][j];
		}
	}

	int bestx[4];
	for(i=1; i<=n; i++)
	{
		cout << "(";
		for(int j=1; j<3; j++)
			cout << M[i][j] << " ";
		cout << ")";
	}

	bf = Flow(M, n, bestx);

	for(i=0; i<=n; i++)
		delete []M[i];
	delete []M;

	M = 0;

	cout << endl << "最优值是: " << bf << endl;
	cout << "最优调度是: ";

	for (i=1; i<=n; i++)
		cout << bestx[i] << " ";
	cout << endl;
}

void Flowshop::Backtrack(int i)
{
	if (i > n)
	{
		for (int j=1; j<=n; j++)
		{
			bestx[j] = x[j];
		}
		bestf = f;
	}
	else
	{
		for (int j=i; j<=n; j++)
		{
			f1 += M[x[j]][1];
			// 机器2执行的是机器1已完成的作业,所以是i-1
			f2[i] = ((f2[i-1]>f1)?f2[i-1]:f1) + M[x[j]][2];

			f += f2[i];

			if(f < bestf)
			{
				Swap(x[i], x[j]);
				Backtrack(i+1);
				Swap(x[i], x[j]);
			}
			f1 -= M[x[j]][1];
			f -= f2[i];
		}
	}
}

int Flow(int **M, int n, int bestx[])
{
	int ub = 30000;

	Flowshop X;
	X.n = n;
	X.x = new int[n+1];
	X.f2 = new int[n+1];

	X.M = M;
	X.bestx = bestx;
	X.bestf = ub;

	X.f1 = 0;
	X.f = 0;

	for(int i = 0; i<=n; i++)
	{
		X.f2[i] = 0;
		X.x[i] = i;
	}
	X.Backtrack(1);
	delete []X.x;
	delete []X.f2;
	return X.bestf;
}

template <class Type>
inline void Swap(Type &a, Type &b)
{
	Type temp = a;
	a = b;
	b = temp;
}