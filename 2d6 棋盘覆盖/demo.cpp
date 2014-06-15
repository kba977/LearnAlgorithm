//2d6 ���̸�������

#include <iostream>
using namespace std;

int tile = 1; //ȫ�ֱ��� ���Ʊ��
int Board[4][4]; //����
void ChessBoard(int tr, int tc, int dr, int dc, int size);

int main()
{
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			Board[i][j] = 0;
		}
	}

	ChessBoard(0,0,2,3,4);

	for(i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			cout << Board[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

/**
 * tr: �������Ͻǵ��к�, tc�������Ͻǵ��к� 
 * dr: ���ⷽ�����Ͻǵ��к�, dc���ⷽ�����Ͻǵ��к�
 * size: size = 2^k ���̹��Ϊ 2^k * 2^k
 */
void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
	if(size == 1)
	{
		return ;
	}
	int t = tile++;  //L�͹��Ʊ��
	int s = size / 2;

	// �������Ͻ�����
	if(dr<tr+s && dc<tc+s) //���ⷽ���ڴ�������
	{
		ChessBoard(tr,tc,dr,dc,s);
	}
	else // ����Ÿ����ڴ�������
	{
		// �ñ��Ϊt�Ĺ��Ƹ������½�
		Board[tr+s-1][tc+s-1] = t;
		// �������෽��
		ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
	}

	// �������Ͻ�����
	if(dr<tr+s && dr>=tc+s)
	{
		ChessBoard(tr,tc+s,dr,dc,s);
	}
	else
	{
		Board[tr+s-1][tc+s] = t;
		ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
	}

	// �������½�����
	if(dr>=tr+s && dr<tc+s)
	{
		ChessBoard(tr+s,tc,dr,dc,s);
	}
	else
	{
		Board[tr+s][tc+s-1] = t;
		ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
	}

	// �������½�����
	if(dr>=tr+s && dc>=tc+s)
	{
		ChessBoard(tr+s,tc+s,dr,dc,s);
	}
	else
	{
		Board[tr+s][tc+s] = t;
		ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
	}

}