// 3-3 ʯ�Ӻϲ����� - ��̬�滮

#include <iostream>
using namespace std;

int sum(int begin, int n);
int stone_merge();

int N;		// ʯ�ӵĶ���
int num[100] = {0};  //ÿ��ʯ�Ӹ���
int score[100][100];

void main()
{
	int min_count = 0;
	cout << "������ʯ�ӵĶ���: " << endl;
	cin >> N;			// ʯ�ӵĶ���
//	while (N != 0)
//	{
		cout << "������ÿ��ʯ�ӵĸ���: " << endl;
		for (int i=1; i<=N; i++)
			cin >> num[i];		// ÿ��ʯ�ӵ�����, ��1��ʼ, num[0]����
		min_count = stone_merge();
		cout << "ʯ�ӵ���С�ϲ��÷�Ϊ: ";
		cout << min_count << endl;

	cout << "ʯ�Ӻϲ����̵Ĺ������±���ʾ: " << endl;
	for (int j=1; j<=N; j++)
	{
		for (int k=1; k<=N; k++)
			cout << score[j][k] << " ";
		cout << endl;
	}

/*		for (i=1; i<N; i++)		// ׼����һ��
			num[i] = 0;
		min_count = 0;
		cin >> N;
	}
*/
}

int sum(int begin, int n)
{
	int total = 0;
	for (int i=begin; i<=begin+n-1; i++)
	{
		if (i == N)
			total = total + num[N];    // ȡ��num[0]
		else
			total = total + num[i % N];
	}
	return total;
}

int stone_merge()
{
//	int score[100][100];		// score[i][j]: �ӵ�i��ʯ�ӿ�ʼ��j�Ѻϲ�����С�÷֡�
	int temp;
	
	for (int i=1; i<=N; i++)
		score[i][1] = 0;	// һ��ʯ��, �ϲ��÷�Ϊ0
	
	// num[0] = num[N];  // ��Ҫ: sum()������i=Nʱ, ȡnum[0]
	for (int n=2; n<=N; n++)
	{
		for (int i=1; i<=N; i++)
		{
			score[i][n] = score[i][1] + score[(i+1-1)%N+1][n-1];
			for (int k=2; k<=n-1; k++)		// �ض�λ��
			{
				temp = score[i][k] + score[(i+k-1)%N+1][n-k];
				if(temp < score[i][n])
					score[i][n] = temp;		// �ӵ�i��ʼ��k����: ��i+0�ѵ���(i+k-1)%N��
			}
			score[i][n] += sum(i,n);
		}
	}

	int min = 2147483647;
	for (i=1; i<=N; i++)
	{	
//		cout << score[i][N] << " " << endl;
		if(min > score[i][N])
			min = score[i][N];	// ȡ�ӵ�i�ѿ�ʼ��N�ѵ���С��
	}	

	return min;
}

