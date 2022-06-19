#include <iostream.h>
#define SIZE 10
class stack
{
	int stck[SIZE];
	int top;
  public:
	stack()
	{
		top=-1;
		cout << "Stack Initialized\n";
	}
	~stack()
	{
		cout << "Stack Destroyed\n";
	}
	void push(int i)
	{
		if(top==SIZE-1)
		{
			cout << "Stack is full.\n";
			return;
		}
		top++;
		stck[top] = i;
	}
	int pop()
	{
		if(top==-1)
		{
			cout << "Stack underflow.\n";
			return 0;
		}
		top--;
		return stck[top+1];
	}
};
int main()
{
	stack a, b;
	a.push(1);
	b.push(2);
	a.push(3);
	b.push(4);
	cout << a.pop() ;
	cout << a.pop() ;
	cout << b.pop() ;
	cout << b.pop() <<"\n";
	return 0;
}
