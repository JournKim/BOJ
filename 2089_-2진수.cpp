/*
#2089 -2Áø¼ö
160818 Journ
*/
//160818 correct
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
char str[64];

void convert(int n)
{
	int div = -2;
	int i = 0;
	if (n == 0)
	{
		str[0] = '0';
		i++;
	}
	while (n != 0)
	{
		//cout << i << " : " << n/div <<" "<<n%div<< " "<<n<<endl;
		if (n % div == 0)
		{
			str[i] = '0';
			n = n / div;
		}
		else
		{
			str[i] = '1';
			if (n < 0)
			{
				n = n / div + 1;
			}
			else
			{
				n = n / div;
			}

		}
		//str[i] = n % div + '0';
		//n = n / div;
		i++;
	}
	str[i] = '\0';
	char tmp;
	for (int j = 0; j < i/2; j++)
	{
		tmp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = tmp;
	}
}

int main()
{
	int n;
	cin >> n;
	convert(n);

	cout << str << endl;

}