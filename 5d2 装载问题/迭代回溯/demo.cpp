//5d2 װ������ - ��������

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

	cout << "�ִ����������ֱ�Ϊ: " << endl;
	cout << "c(1)=" << c << ",c(2)=" << c2 << endl;

	cout << "��װ��װ�������ֱ�Ϊ: " << endl;
	cout << "w(i)=";
	for(int i=1; i<=n; i++)
	{
		cout << w[i] << " ";
	}
	cout << endl;

	cout << "����ѡ��Ľ��Ϊ: " << endl;
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
		cout << "��Ϊm(2)����c(2),����ԭ�����޽�!" << endl;
	}
	return 0;
}

template <class Type>
Type MaxLoading(Type w[], Type c, int n, int bestx[]) // �������ݷ�����������������������Ӧ�⣬��ʼ�������
{
	int i = 1; //��ǰ��, x[1:i-1]Ϊ��ǰ·��
	int *x = new int[n+1];

	Type bestw = 0,			//��ǰ����������
		 cw = 0,			//��ǰ������
		 r = 0;				//ʣ�༯װ������

	for(int j=1; j<=n; j++)
	{
		r += w[j];
	}

	while(true)
	{
		while(i<=n && cw+w[i]<=c) //����������
		{
			r -= w[i];
			cw += w[i];
			x[i] = 1;
			i++;
		}

		if(i>n)		//����Ҷ���
		{
			for(int j=1; j<=n; j++)
			{
				bestx[j] = x[j];
			}
			bestw = cw;
		}
		else		//����������
		{
			r -= w[i];
			x[i] = 0;
			i++;
		}

		while(cw+r <= bestw)
		{
			//��֦����
			i--;
			while(i>0 && !x[i])
			{
				r += w[i];
				i--;
			}

			//������������
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