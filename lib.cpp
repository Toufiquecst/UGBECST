#include<iostream>
#include<string>
using namespace std;
int cop=0;
class book
{
	char *title,*author;
  public:
	int price,copies,serial;
	int find(book temp)
	{
		if(((strcmp(title,temp.title)==0))&&((strcmp(author,temp.author)==0)))
		{
			if(copies==0)
				cout<<"no copy of this book available";
			else
				cout<<copies<<"available";
			return(1);
		}
		return(0);
	}
	void copy(int c)
	{
		if(c>copies)
			cout<<"Requested copies not in stock";
		else
		{
			cout<<"total price="<<(c*price);
			copies=copies-c;
			cout<<"now available copies ="<<copies;
			cop=copies;
		}
	}
	void books(char *x,char *y,int p,int s)
	{
		title=new char[strlen(x)+1];
		strcpy(title,x);
		author=new char[strlen(y)+1];
		strcpy(author,y);
		price=p;
		copies=s;
	}
	book()
	{
		copies=-1;
	}
	void store(char a[],char c[])
	{
		title=new char[strlen(a)+1];
		strcpy(title,a);
		author=new char[strlen(c)+1];
		strcpy(author,c);
	}
};
main()
{
	char a[20],c[20],m,y,n;
	int i,j=0,list=2,co;
	book temp,b[5];
	b[0].books("math","Sastry",540,22);
	b[1].books("c","Xavier",200,35);
L:	cout<<"enter the TITLE & AUTHOR :\t";
	cin>>a>>c;
	temp.store(a,c);
	j=0;
 	for(i=0;((i<list)&&(j==0));i++)
	{
		j=b[i].find(temp);
		if(j==1)
			temp=b[i];
	}
	if(temp.copies==-1)
		cout<<"this book is not in the store\n";
	else
	{
		cout<<"\nenter the number of copies required:\t";
		cin>>co;
		temp.copy(co);
		b[i-1].copies=cop;
		cop=0;
	}
	cout<<"\ndo you want to continue?? y or n\t";
	cin>>m;
	if(m=='y')
		goto L;
	
}
