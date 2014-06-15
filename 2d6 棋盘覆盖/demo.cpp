//2d6 棋盘覆盖问题

#include <iostream>
using namespace std;

int tile = 1; //全局变量 骨牌编号
int Board[4][4]; //棋盘
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
 * tr: 棋盘左上角的行号, tc棋盘左上角的列号 
 * dr: 特殊方格左上角的行号, dc特殊方格左上角的列号
 * size: size = 2^k 棋盘规格为 2^k * 2^k
 */
void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
	if(size == 1)
	{
		return ;
	}
	int t = tile++;  //L型骨牌编号
	int s = size / 2;

	// 覆盖左上角棋盘
	if(dr<tr+s && dc<tc+s) //特殊方格在此棋盘中
	{
		ChessBoard(tr,tc,dr,dc,s);
	}
	else // 特殊放个不在此棋盘中
	{
		// 用编号为t的骨牌覆盖右下角
		Board[tr+s-1][tc+s-1] = t;
		// 覆盖其余方格
		ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
	}

	// 覆盖右上角棋盘
	if(dr<tr+s && dr>=tc+s)
	{
		ChessBoard(tr,tc+s,dr,dc,s);
	}
	else
	{
		Board[tr+s-1][tc+s] = t;
		ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
	}

	// 覆盖左下角棋盘
	if(dr>=tr+s && dr<tc+s)
	{
		ChessBoard(tr+s,tc,dr,dc,s);
	}
	else
	{
		Board[tr+s][tc+s-1] = t;
		ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
	}

	// 覆盖右下角棋盘
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