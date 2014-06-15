//5d2 装载问题 - 递归回溯

/*  
	当i<=n时，当前扩展结点z是子集树中的一个内部结点。该结点有x[i]=1和x[i]=0  
	的两个儿子结点。其左儿子结点表示x[i]=1的情形，仅当cw+w[i]<=c的时候才进入左子树，递归地对  
	左子树进行搜索。其右儿子结点表示x[i]=0的情形。由于可行结点的右儿子结点总是  
	可行的，故进入右子树时不需检查可行性  
	函数Backtrack动态地生成问题的解空间树。在每个结点处算法花费o(1)时间。  
	子集树中结点个数为o(2^n)，故Backtrack所需计算时间为o(2^n)  
	另外Backtrack还需要额外的o(n)的递归栈空间  
*/   
/*  
	构造最优解，必须在算法中记录与当前最优值相应的当前最优解  
	。为此在类Loading中增加两个私有数据成员x和bestx。x用于记录从根至  
	当前结点的路径；bestx记录当前最优解。算法搜索到一个叶结点处，就修正bestx的值。  
*/  

#include <iostream>
using namespace std;

template <class Type>
class Loading
{
	friend Type MaxLoading(Type [], Type, int, int []);
	private:
		void Backtrack(int i);
		int n,			//集装箱数
			*x,			//当前解
			*bestx;		//当前最优解
		Type *w,		//集装箱重量数组
			  c,		//第一艘轮船载重量
			  cw,		//当前载重量
			  bestw,	//当前最优载重量
			  r;		//剩余集装箱重量
};

template <class Type>
void Loading <Type>::Backtrack(int i);

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
	
	// 计算第二个集装箱的装货量
	int m2 = 0;
	for(int j=1; j<=n; j++)
	{
		// 除去装在第一个集装箱上的货物,其他都装到第二个集装箱上
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
void Loading <Type> :: Backtrack(int i)    
{
	//搜索第i层结点
	if(i > n)		
	{	
		//到达叶结点
		if(cw > bestw)
		{	
			//当前载重量大于当前最优载重量
			for(int j=1; j<=n; j++)
			{
				bestx[j] = x[j];	 //更新最优解	
			}
			bestw = cw;
		}
		return;
	}
	
	// 搜索子树
	r -= w[i];

	if(cw + w[i] <= c)		// 搜索左子树
	{
		x[i] = 1;
		cw += w[i];
		Backtrack(i+1);
		cw -= w[i];
	}

	if(cw + r > bestw)
	{
		x[i] = 0;			// 搜索右子树
		Backtrack(i+1);
	}

	r += w[i];
}

template <class Type>
Type MaxLoading(Type w[], Type c, int n, int bestx[])  //返回最优载重量
{
	Loading<Type> X;    
	// 初始化 X
	X.x = new int[n+1];
	X.w = w;
	X.c = c;
	X.n = n;
	X.bestx = bestx;
	X.bestw = 0;
	X.cw = 0;
	// 初始化 r
	X.r = 0;

	for(int i=1; i<=n; i++)
	{
		X.r += w[i];
	}
	
	X.Backtrack(1);
	delete []X.x;
	return X.bestw;
}