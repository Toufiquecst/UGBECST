#include<stdio.h>
int n;
main(){
int hcf(int a[]);
int lcm(int b[]);
int b[100],a[100],x,y,i;
printf("\n\nEnter the value of 'n'\t\t");
scanf("%d",&n);
printf("\n\nEnter the %d numbers:\n\n",n);
for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
		}
a[i]='\0';
b[i]='\0';
x=hcf(a);
printf("\n\nThe GCF=%d\n",x);
y=lcm(b);
printf("\nThe LCM=%d\n\n",y);
}
int hcf(int a[])
{
  int t,k,l;
  if(a[1]=='\0'){
	return(a[0]);
	}else{
		if(a[0]>a[1]){
			t=a[0];
			a[0]=a[1];
			a[1]=t;
			}
		if(a[0]==0){
			l=a[1];
			}else{
				while(a[0]!=0){
					k=a[1]%a[0];
					a[1]=a[0];
					a[0]=k;
					}
				l=a[1];
				}
		a[1]=l;
		hcf(&a[1]);
		}
}
int lcm(int b[])
{
  int d[3],c,m1,m2;
  if(b[1]=='\0'){
	return(b[0]);
	}else{
		d[0]=b[0];
		d[1]=b[1];
		d[2]='\0';
		c=hcf(d);
		m1=b[0]/c;
		m2=b[1]/c;
		b[1]=m1*m2*c;
		lcm(&b[1]);
		}
}
