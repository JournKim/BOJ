#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> q;

int main()
{
	int N;
	string op;
	cin >> N;
	int tmp;

	while (N--)
	{
		cin >> op;
		if (op.compare("push") == 0)
		{
			cin >> tmp;
			q.push_back(tmp);
		}
		else if (op.compare("pop") == 0)
		{
			if (q.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << q[0] << endl;
				q.erase(q.begin());
			}
				
		}
		else if (op.compare("size") == 0)
		{
			cout << q.size() << endl;
		}
		else if (op.compare("empty") == 0)
		{
			cout << q.empty() << endl;
		}
		else if (op.compare("front") == 0)
		{
			if (q.empty())
			{
				cout << -1 << endl;
			}
			else
				cout << q[0] << endl;
		}
		else if (op.compare("back") == 0)
		{
			if (q.empty())
			{
				cout << -1 << endl;

			}
			else
				cout << q[q.size() - 1] << endl;
		}
	}
}