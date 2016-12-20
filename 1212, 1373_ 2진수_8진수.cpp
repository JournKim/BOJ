/*
acmicpc.net #1373, #1212 2진수-8진수 변환
*/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
/*
void BinToOct(string Bin)
{
	string Oct;
	int n = 0;
	int rm;

	char c[2] = { '\0' };
	for (int i = Bin.length()-1; i >=0; i -=3)
	{
		
		if (i >= 2)
		{
			rm = Bin.at(i) - '0';
			rm += (Bin.at(i - 1) - '0') * 2;
			rm += (Bin.at(i - 2) - '0') * 4;

			//cout << "rm : " << rm << endl;
		}
		else
		{
			rm = 0;
			for(int j=0; j<=i;j++)
			{
				rm *= 2;
				rm += Bin.at(j) - '0';
			}
			
		}
		c[0] = rm + '0';
		//cout << "c : " <<c<< endl;
		Oct.append(c);
	}
	reverse(Oct.begin(), Oct.end());
	cout << Oct << endl;
	//cout << "Bin : " << Bin << endl;
	//cout << "Oct : " << Oct << endl;
}
*/


char arr[1048577] = { '\0', };

void OctToBin(string Oct)
{
	int len = Oct.length();
	int n = 4;
	int j = 0;
	n = Oct.at(0) - '0';
	if (n & (int)04)
	{
		arr[j] = '1';
		j++;
		if (n&(int)02)
		{
			arr[j] = '1';
			j++;
		}
		else
		{
			arr[j] = '0';
			j++;
		}
		if (n&(int)01)
		{
			arr[j] = '1';
			j++;
		}
		else
		{
			arr[j] = '0';
			j++;
		}
	}
	else if (n&(int)02)
	{
		arr[j] = '1';
		j++;
		if (n&(int)01)
		{
			arr[j] = '1';
			j++;
		}
		else
		{
			arr[j] = '0';
			j++;
		}
	}
	else if (n&(int)01)
	{
		arr[j] = '1';
		j++;
	}
	
	//cout << arr << endl;

	for (int i = 1; i < len; i++) {
		n = Oct.at(i)-'0';
		if (n & (int)04)
		{
			arr[j] = '1';
			j++;
		}
		else
		{
			arr[j] = '0';
			j++;
		}
		if (n&(int)02)
		{
			arr[j] = '1';
			j++;
		}
		else
		{
			arr[j] = '0';
			j++;
		}
		if (n&(int)01)
		{
			arr[j] = '1';
			j++;
		}
		else
		{
			arr[j] = '0';
			j++;
		}
	}
	cout << arr << endl;
}

int main()
{
	string n;
	cin >> n;
	OctToBin(n);
}