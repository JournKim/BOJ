#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M;
queue<vector<int>> q;
char map[128][128];

void visit(int row, int col)
{
	if (row < 0 || row == N)
	{
		return;
	}
	if (col < 0 || col == M)
	{
		return;
	}

	

	if (map[row][col] == '1')
	{
		q.push({ row, col });
	}
}


int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", map[i]);
	}

	/*for (int i = 0; i < N; ++i)
	{
		printf("%s\n", map[i]);
	}*/
	q.push({ 0,0 });
	map[0][0] = '0';
	int round = 1;
	vector<int> pos;
	while (map[N - 1][M - 1] == '1')
	{
		++round;
		int size = q.size();

		for (int i = 0; i < size; ++i)
		{
			pos = q.front();
			//printf("(row, col) : (%d, %d)\n", pos[0], pos[1]);
			visit(pos[0]-1, pos[1]);
			visit(pos[0]+1, pos[1]);
			visit(pos[0], pos[1]-1);
			visit(pos[0], pos[1]+1);
			if(pos[0] != 0)
				map[pos[0]-1][pos[1]] = '0';
			if(pos[0] != N-1)
				map[pos[0]+1][pos[1]] = '0';
			if(pos[1] != 0)
				map[pos[0]][pos[1]-1] = '0';
			if(pos[1] != M-1)
				map[pos[0]][pos[1]+1] = '0';
			q.pop();
		}
	}
	printf("%d\n", round);
}