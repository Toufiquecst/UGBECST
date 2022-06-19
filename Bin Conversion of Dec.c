#include<stdio.h>
int n,b=0,w=1;
main(){
int x;
int binary(int);
printf("\n\nEnter the decimal number\t");
scanf("%d",&n);
x=binary(n);
printf("\n\nThe binary form of the number is\t %d\n\n",x);
}
int binary(int n){
	int c;
	if(n<2){
		b=b+w;
		return(b);
		}else{
			c=n%2;
			n=n/2;
			b=b+w*c;
			w=w*10;
			binary(n);
			}
		}
