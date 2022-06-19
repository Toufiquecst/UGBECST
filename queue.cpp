#include<iostream>
#include<stdlib.h>
using namespace std;
#define SIZE 20
class que
{
	int front,rear;
public:
	int item[SIZE];
	que()
	{
		rear=-1;front=-1;
	}
	void remove();
	void insert(int);
};
void que::insert(int b)
{
	if(rear==SIZE-1)
		rear=0;
	else
		rear++;
	if(rear==front)
	{
		cout<<"queue overflow";
		exit(1);
	}
	item[rear]= b;
		return;
}
 void que::remove()
{
	if(rear==front)
	{
		cout<<"queue underflow";
		exit(1);
	}
	if(front==SIZE-1)
		front=0;
	else
		front++;
	cout<<item[front]<<"removed\n";
}
main(){
	int i=0;
	que pq;
	for(i=0;i<SIZE;i++)
	{
		pq.insert(i);
	}
	cout<<"after insertion\n";
	for(i=0;i<SIZE;i++)
		cout<<pq.item[i]<<"\n";
	pq.remove();
	pq.remove();
	pq.insert(100);
	for(i=0;i<SIZE;i++)
		cout<<pq.item[i]<<"\n";	
	return 0;
}
