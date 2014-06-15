//2d7-1 递归实现二路归并排序
#include <iostream>
using namespace std;

int a[] = {10,5,9,4,3,7,8};
int b[7];

template<class Type>
void Merge(Type c[], Type d[],int l, int m, int r);

template<class Type>
void MergeSort(Type a[], int left, int right);

void main()
{
	for(int i=0; i<7; i++)
	{
		cout << a[i] << " ";
	}
	
	cout << endl;

	MergeSort(a,0,6);

	for(int j=0; j<7; j++)
	{
		cout << a[i] << " ";
	}

	cout << endl;
}

template <class Type>
void Merge(Type c[], Type d[],int l, int m, int r)
{
	int i = l, j = m + 1, k = l;
	while((i<=m) && (j<=r))
	{
		if(c[i]<=c[j])
		{
			d[k++] = c[i++];
		}
		else
		{
			d[k++] = c[j++];
		}
	}

	if(i > m)
	{
		for(int q=j; q<=r; q++)
		{
			d[k++] = c[q];
		}
	}
	else
	{
		for(int q=i; q<=m; q++)
		{
			d[k++] = c[q];
		}
	}
}

template <class Type>
void MergeSort(Type a[], int left, int right)
{
	if(left < right)
	{
		int i = (left + right) / 2;
		MergeSort(a,left,i);
		MergeSort(a,i+1,right);
		Merge(a,b,left,i,right);

		for(int g=left; g<=right; g++)
		{
			a[g] = b[g];
		}
	}
}
