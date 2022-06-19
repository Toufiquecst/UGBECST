#include<stdio.h>
main(){
int check(int a[],int);
int a[100],n,m,i,x;
printf("\n\nEnter the value of 'n'\n");
scanf("%d",&n);
printf("\n\nEnter the list of numbers\n");
a[0]=0;
for(i=0;i<n;i++)
		scanf("%d",&a[i]);
a[n]='\0';
printf("Now enter the number to be checked\t");
scanf("%d",&m);
x=check(a,m);
if(x==0){
	printf("\n\nThe number is present in the list\n\n");
	}else{
		printf("\n\nThe number is not present in the list\n");
		}
}
int check(int a[],int m){
	if(a[0]=='\0'){
		return(1);
		}else{
			if(a[0]==m){
				return(0);
				}else{
					check(&a[1],m);
					}
			}
		}
