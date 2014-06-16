// 全排列问题 -- 带重复元素检测

#include <stdio.h>
#define num 4

void perm(int A[], int k, int m);
void swap(int &a, int &b);
bool ok(int A[], int k, int i);

int main()
{
	int A[num]={1,2,3,3};
	perm(A,0,num-1);
	return 0;
}

/* ok函数用于判别重复元素 */
bool ok(int A[], int k, int i)
{
	if (i > k)
		for (int t=k; t<i; t++)			// 若在之前替换过相同值, 则返回flase
			if(A[t] == A[i])
				return false;
	return true;
}

void perm(int A[], int k, int m)
{
	int i;

	if(k == m)
	{
		for(i=0; i<=m; i++)
			printf("%d ", A[i]);
		printf("\n");
	}
	else
		for(i=k; i<=m; i++)
		{
			if(!ok(A, k, i))		// 进行重复检测
				continue;
			swap(A[k], A[i]);
			perm(A, k+1, m);
			swap(A[k], A[i]);
		}
}

void swap(int &a, int &b)
{
	int temp = a;
		a = b;
		b = temp;
}