#include<iostream>
#include<cmath>
using namespace std;

double arr[10000003] = { 0, };



void bignum()
{
	int m;
	scanf("%d", &m);
	double logSum = 0;
	for (int i = 1; i <= m; i++)
	{
		if (arr[i] != 0)
		{
			continue;
		}
		arr[i] = arr[i - 1] + log10(i);
		//logSum = arr[i];
	}
	logSum = arr[m];
	
	/*
	int�� ����ȯ �ϸ� �´µ� 
	floor()�ϸ� Ʋ��.
	*/
	cout << (int)logSum + 1 << endl;
}


int main()
{
	int cases;
	cin >> cases;
	while (cases--)
	{
		bignum();
	}
}