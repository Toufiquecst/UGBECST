#include<stdio.h>
void mergesort(int,int []);
void merge(int,int,int,int [],int [],int []);
int count;
main(){
	int l,i,m=10,a[100];
	for(l=0;l<10;l++){
		for(i=0;i<m;i++)
			a[i]=rand()%100;
		count=0;
		mergesort(m,a);
		printf("NUMBER OF COMPARISON FOR %d ELEMENTS IS:%d\n",m,count);
		m=m+10;
		 }
      	}
void mergesort(int n,int s[]){
	int j=0,i,h,m,u[50],v[50];
	h=n/2;
	m=n-h;
	if(n>1){
		for(i=0;i<h;i++)
			u[i]=s[i];
		for(i=h;i<n;i++,j++)
			v[j]=s[i];
		mergesort(h,u);
		mergesort(m,v);
		merge(h,m,n,u,v,s);
		}
	}
void merge(int h,int m,int n,int u[],int v[],int s[]){
	int i,p=0,q=0,r=0;
	while((p<h) && (q<m)){
		s[r++]=(u[p]<v[q])?u[p++]:v[q++];
		count++;
	       }
	while(p<h)
		s[r++]=u[p++];
	while(q<m)
		s[r++]=v[q++];
     	}
