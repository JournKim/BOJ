#include<iostream>
using namespace std;

int sum = 0;
int now = 0;
char input[100001];

int main()
{
	cin >> input;
	for (int i = 0; input[i]; ++i)
	{
		if (input[i] == '(')
		{
			++now;
		}
		else
		{
			++sum;
			--now;
			if (input[i - 1] == '(')
			{
				sum += now;
				sum--;
			}
		}
	}
	cout << sum << endl;
}