#include<iostream>
using namespace std;
class complex
{
  float real,imag;
  public:
   complex sum(complex c1,complex c2)
	{
		real=c1.real+c2.real;
		imag=c1.imag+c2.imag;
	}
	complex sub(complex c1,complex c2)
	{
		real=c1.real-c2.real;
		imag=c1.imag-c2.imag;
	}
	complex()
		{}
	complex(float r,float i)
	{
		real=r;
		imag=i;
	}
	void display()
	{
		cout<<"("<<real<<","<<imag<<")";
	}
};
main()
{     
	float i,r;
	complex c3;
	complex c4;
	cout<<"enter the real & imaginary part of the 1st no :"<<"\t";
	cin>>i>>r;
        complex	c5(i,r);
	cout<<"enter the real & imaginary part of the 2nd no :"<<"\t";
	cin>>i>>r;
	complex c6(i,r);
	cout<<"the two numbers are :";
	c5.display();
	cout<<";";
	c6.display();
	c3.sum(c5,c6);
	c4.sub(c5,c6);
	cout<<"\nthe sum is :";
	c3.display();
	cout<<"\nthe difference is :";
	c4.display();
	cout<<"\n";
	return 0;
}
