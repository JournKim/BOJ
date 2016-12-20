#include<iostream>
#include<cmath>
using namespace std;


int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
	int a, b;
	cin >> a >> b;
	int mod, div, max;
	if (b % a == 0)
	{
		mod = b / a;
		div = 1;
		max = 1;
		while (div <= sqrt((double)mod))
		{
			if (mod % div == 0)
			{
				if(gcd(div,mod/div) == 1)
					max = div;
			}
			div++;
		}
	}
	cout << a * max << " " << a * mod / max << endl;
	return 0;
}