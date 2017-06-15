#include<iostream>
#include<stack>
using namespace std;

int diff(int a, int b)
{
	if (a > b)
		return a - b;
	else
		return b - a;
}
int A[10];
int maxsum = 0;
bool checked[10];
stack<int> s;
void calc(int n, int sum)
{
	if (s.size() == n)
	{
		if (sum > maxsum)
			maxsum = sum;
		//cout << sum << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!checked[i])
		{
			int top;
			if (!s.empty())
				top = s.top();
			s.push(A[i]);
			checked[i] = true;
			if (s.size() == 1)
				calc(n, sum);
			else
			{
				calc(n, sum + diff(top, A[i]));
			}
			checked[i] = false;
			s.pop();
		}
	}
}

int main()
{
	int N;
	

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin>>A[i];
	}

	calc(N,0);
	cout << maxsum << endl;
	
}