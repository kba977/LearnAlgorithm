// 2d4 大整数乘法 --分治法

#include <iostream>
#include <cmath>

#define SIGN(A) ((A > 0) ? 1 : -1)

using namespace std;

int IntegerMultiply(int X, int Y, int N)
{
	int sign = SIGN(X) * SIGN(Y);
	int x = abs(X);
	int y = abs(Y);

	if ((x == 0) || (y == 0))
		return 0;
	if ( N == 1)
		return sign * x * y;
	else
	{
		int XL = x / (int)pow(10., (int)N/2);
		int XR = x - XL * (int)pow(10., N/2);
		int YL = y / (int)pow(10., (int)N/2);
		int YR = y - YL * (int)pow(10., N/2);

		int XLYL = IntegerMultiply(XL, YL, N/2);
		int XRYR = IntegerMultiply(XR, YR, N/2);
		int XLYRXRYL = IntegerMultiply(XL - XR, YR - YL, N/2) + XLYL + XRYR;
		return sign * (XLYL * (int)pow(10., N) + XLYRXRYL * (int)pow(10., N/2) + XRYR);
	}
}

void main()
{
	int x = 1234;
	int y = 4321;
	cout << "x * y = " << IntegerMultiply(x, y, 4) << endl;
	cout << "x * y = " << x * y << endl;
}