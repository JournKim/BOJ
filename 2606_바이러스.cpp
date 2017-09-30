#include<iostream>

using namespace std;

bool network[128][128];
int N, M;
int main()
{
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		network[a][b] = true;
		network[b][a] = true;
	}
	
	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (!network[i][j] && network[i][k] && network[j][k])
				{
					network[i][j] = true;
					network[j][i] = true;
				}
			}
		}
	}

	int infested = 0;
	for (int i = 1; i <= N; ++i)
	{
		if(network[1][i])
			++infested;
	}
	cout << infested-1 << endl;
}

