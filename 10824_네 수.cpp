#include<iostream>

using namespace std;

int main()
{
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	long long mula = 1;
	long long mulb = 1;
	while (mula <= b)
		mula *= 10;
	while (mulb <= d)
		mulb *= 10;
	a = a*mula + b;
	c = c*mulb + d;
	cout << a + c << endl;
}