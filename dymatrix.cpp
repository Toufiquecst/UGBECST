#include<iostream>
using namespace std;
class matrix
	{
	int row,col;
     public:
     	int **p;
	matrix(int a,int b)
		{
			row=a;
			col=b;
			p=new int*[row];
			for(int i=0;i<row;i++)
				p[i]=new int[col];
			
		}
	int dim()
		{
		return col;
		}
	matrix()
		{}
	void get_matrix()
		{
			int i,j;
			for(i=0;i<row;i++)
				for(j=0;j<col;j++)
					cin>>p[i][j];
		}
	void display()
		{
			int i,j;
			for(i=0;i<row;i++)
			{
				for(j=0;j<col;j++)
					cout<<p[i][j]<<" ";
				cout<<"\n";
			}
		}
	matrix operator * (matrix n)
		{
			int i,j,k,s;
			matrix temp;
			s=n.dim();
			temp=matrix(row,s);
			for(i=0;i<row;i++)
				for(j=0;j<s;j++)
					{
					temp.p[i][j]=0;
					for(k=0;k<col;k++)
						temp.p[i][j]=temp.p[i][j]+p[i][k]*n.p[k][j];
					}
			return temp;
		}
};

main()
{
	matrix x,y,z;
	int p,q,r;
	cout<<"Enter the number of rows & columns of the first matrix :\t";
	cin>>p>>q;
	x=matrix(p,q);
	cout<<"Enter the elements of 1st matrix row wise\n";
	x.get_matrix();
	cout<<"Enter the number of columns of the second matrix :\t";
	cin>>r;
	y=matrix(q,r);
	cout<<"Enter the elements of 2nd matrix row wise\n";
	y.get_matrix();
	z=matrix(p,r);
	z=x*y;
	cout<<"The product of the 2 matrices is :\n";
	z.display();
}
