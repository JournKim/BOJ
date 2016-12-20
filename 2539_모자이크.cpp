#include<iostream>
using namespace std;

int paper[1000001] = { 0, };

int main()
{
	int col, row;
	cin >> row >> col;
	int num;
	cin >> num;
	int mistake;
	cin >> mistake;
	int min_size = 0;
	int tmpC,tmpR;
	for (int i = 0; i < mistake; i++)
	{
		scanf("%d %d", &tmpC, &tmpR);
		if (tmpC > min_size)
			min_size = tmpC;
		paper[tmpR-1] = 1;
	}
	
	int count;
	bool isPass = false;
	while (!isPass)
	{
		count = 0;
		for (int i = 0; i < col; i++)
		{
			if (paper[i] != 0)
			{
				count++;
				i = i + min_size - 1;
			}
		}
		if (count <= num)
			isPass = true;
		min_size++;

	}
	min_size--;
	cout << min_size << endl;
}