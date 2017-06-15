#include<iostream>
#include<string>
using namespace std;

string s;
int itr;

void L()
{
	if (itr != 0)
		itr--;
}

void D()
{
	if (itr != s.length())
		itr++;
}

void B()
{
	if (itr != 0)
	{
		itr--;
		s.erase(s.begin() + itr);
	}
}

void P(char c)
{
	s.insert(s.begin() + itr,c);
	itr++;
}

int main()
{
	cin >> s;
	itr = s.length();

	int N;
	cin >> N;
	char op;
	while (N--)
	{
		cin >> op;

		switch (op)
		{
		case 'L':
			L();
			break;
		case 'D':
			D();
			break;
		case 'B':
			B();
			break;
		case 'P':
			cin >> op;
			P(op);
			break;
		}
	}

	cout << s << endl;
}