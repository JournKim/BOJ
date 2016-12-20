#include<iostream>
#include<cstring>
using namespace std;

#define BUFLEN 128

// command list
#define PUSH 123
#define POP 234
#define SIZE 345
#define EMPTY 456
#define TOP 567

int stack[10000];
int top = -1;

class command {
public:
	int cmd;
	int num;
	command(int _cmd, int _num)
	{
		cmd = _cmd;
		num = _num;
	}
};

command* parse(char* buf)
{
	int cmd, num = -1;
	
	if (!strcmp("push", buf))
		cmd = PUSH;
	if (!strcmp("pop", buf))
		cmd = POP;
	if (!strcmp("size", buf))
		cmd = SIZE;
	if (!strcmp("empty", buf))
		cmd = EMPTY;
	if (!strcmp("top", buf))
		cmd = TOP;
	if (cmd == PUSH)
		cin >> num;

	return new command(cmd, num);
}

void work(char* buf)
{
	command* cmd = parse(buf);
	switch (cmd->cmd)
	{
	case PUSH:
		top++;
		stack[top] = cmd->num;
		break;
	case POP:
		if (top >= 0)
		{
			cout << stack[top] << endl;
			top--;
		}
		else
		{
			cout << -1 << endl;
		}
		break;
	case SIZE:
		cout << top + 1 << endl;
		break;
	case EMPTY:
		if (top == -1)
			cout << 1 << endl;
		else
			cout << 0 << endl;
		break;
	case TOP:
		if (top == -1)
			cout << -1 << endl;
		else
			cout << stack[top] << endl;
		break;
	default:
		break;
	}
	

}


int main()
{
	int N;
	char buf[BUFLEN];

	cin >> N;
	while (N--)
	{
		//cin.getline(buf, BUFLEN - 1);
		cin >> buf;
		work(buf);
	}
}