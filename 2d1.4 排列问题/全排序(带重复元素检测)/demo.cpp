// ȫ�������� -- ���ظ�Ԫ�ؼ��

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

/* ok���������б��ظ�Ԫ�� */
bool ok(int A[], int k, int i)
{
	if (i > k)
		for (int t=k; t<i; t++)			// ����֮ǰ�滻����ֵͬ, �򷵻�flase
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
			if(!ok(A, k, i))		// �����ظ����
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