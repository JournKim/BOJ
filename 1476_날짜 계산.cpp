#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int E, S, M;
	cin >> E >> S >> M;

	int te, ts, tm;
	te = ts = tm = 1;

	bool a = false;
	int result = 1;
	while (!a)
	{
		if (te == E && ts == S && tm == M)
		{
			a = true;
			break;
		}
			
		++result;
		++te;
		++ts;
		++tm;
		if (te > 15)
			te = 1;
		if (ts > 28)
			ts = 1;
		if (tm > 19)
			tm = 1;
	}

	cout << result << endl;
}