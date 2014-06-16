//2-4 ≈≈¡–Œ Ã‚
#include <iostream>
using namespace std;


template<class Type>
void Perm(Type list[], int first, int last)
{
	if(first == last)
	{
		for(int i = 0; i <= last; i++)
			cout<<list[i]<<" ";
		cout<<endl;
	}
	else
	{
		for(int i = first; i <= last; i++)
		{
			Swap(list[first],list[i]);
			Perm(list,first+1,last);
			Swap(list[first],list[i]);
		}
	}
}

template<class Type>
inline void Swap(Type &a, Type &b)
{
	Type temp = a;
		 a = b;
		 b = temp;
}

void main()
{
	int list[]={1,2,3};
	Perm(list,0,2);
}
