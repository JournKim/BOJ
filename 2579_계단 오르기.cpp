#include<iostream>
using namespace std;


int stairs[303];
int arr[303][2];

//int max(int a, int b)
//{
//	return a > b ? a : b;
//}

#define max(a,b) a>b? a:b

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> stairs[i];
	arr[0][0] = stairs[0];
	arr[0][1] = stairs[0];
	if (n > 1) {
		arr[1][0] = stairs[1];
		arr[1][1] = stairs[0] + stairs[1];
	}

	for (int i = 2; i < n; i++)
	{
		// 매크로 함수 쓰면 예제 출력 오류남.. -> 괄호로 덮으면 잘 작동.
		arr[i][0] = (max(arr[i - 2][0], arr[i - 2][1])) + stairs[i];
		arr[i][1] = arr[i - 1][0] + stairs[i];
	}
	int result = max(arr[n - 1][0], arr[n - 1][1]);
	cout << result << endl;

}

/* 예제입력.
6
10
20
15
25
10
20

출력 : 75 , 매크로함수 쓰면 65로 나옴.
*/