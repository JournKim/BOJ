#include<iostream>
using namespace std;
int map[2][10000] = { 0, };
int main()
{
	int n, m;
	cin >> n >> m;
	int sumx = 0;
	int sumy = 0;
	int x, y;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		sumy += y;
		sumx += x;
		map[0][x - 1] += 1;
		map[1][y - 1] += 1;
	}
	int tmpx,tmpy;
	int movx = -m, movy = -m;
	for (int i = 0; i < n; i++)
	{
		tmpx = sumx + movx;
		tmpy = sumy + movy;
		if (sumx > tmpx)
			sumx = tmpx;
		if (sumy > tmpy)
			sumy = tmpy;
		movx += map[0][i]*2;
		movy += map[1][i]*2;
	}
	
	cout << sumx + sumy << endl;

}