#include<iostream>
using namespace std;

char str[1000002];

int main()
{
	bool flag = false;
	str[0] = '\0';
	int word = 0;

	cin.getline(str, 1000001);
	if (str[0] != '\0' && str[0] != ' ')
	{
		flag = true;
	}
	for (int i = 0; str[i] != '\0';i++)
	{
		if (str[i] == ' ' && flag){
			word++;
			flag = false;
		}
		if (str[i] != ' ')
		{
			//if (word == 0)
				//word = 1;
			flag = true;
		}
	}
	if (flag == true)
		word++;
	cout << word << endl;
}

// 170206 correct