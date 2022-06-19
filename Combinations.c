#include<stdio.h>
void combination(int m[],int n,int k,int c[],int l);
void printcomb(int c[],int l);
main(){
int m[100],c[100],n,k,i;
printf("\nEnter the values of 'n' and 'k'\t\t\t");
scanf("%d%d",&n,&k);
printf("\nEnter the n values\n\n");
for(i=0;i<n;i++)
		scanf("%d",&m[i]);
m[i]='\0';
printf("The all combnations are:\n\n");
combination(m,n,k,c,0);
}
void combination(int m[],int n,int k,int c[],int l){
if(k==0){
	    printcomb(c,l);
	}else{
		if(n>=k){
			c[l]=m[0];
			combination(&m[1],n-1,k-1,c,l+1);
			combination(&m[1],n-1,k,c,l);
			}
		}
}
void printcomb(int c[],int l){
int j;
for(j=0;j<l;j++){
		 printf("\t%d",c[j]);
		 }
printf("\n");
}
