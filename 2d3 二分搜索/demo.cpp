//2d3 二分搜索技术

#include <iostream>
using namespace std;

template <class Type>
int BinarySearch(Type a[], const Type &x, int n);

void main()
{
	int x = 2;
	int array[] = {3,1,2,5,6};
	cout << "The answer is: ";
	cout << BinarySearch(array,x,4) << endl;
}


template <class Type>
int BinarySearch(Type a[], const Type &x, int n)
{
	int left = 0;
	int right = n - 1;
	while(left <= right)
	{
		int middle = (left + right) / 2;
		if (x == a[middle])
			return middle;
		if (x > a[middle])
			left = middle + 1;
		else
			right = middle - 1;
	}
	return -1;
}

