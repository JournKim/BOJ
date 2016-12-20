#include<iostream>
using namespace std;

void run()
{
	char input[64];
	cin >> input;
	int t=0;
	bool result = true;
	for (int i = 0; input[i]; ++i)
	{
		if (input[i] == '(')
			++t;
		else if (input[i] == ')')
			--t;
		if (t < 0)
		{
			result = false;
			break;
		}
	}

	if (t > 0)
		result = false;

	cout << (result ? "YES" : "NO") << endl;
}

int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		run();
	}
}