#include<stdio.h>
int x[100],n,count;
void quicksort(int [],int,int);
int partition(int [],int,int);
void quicksort(int x[],int lb,int ub)
{
	int j;
 	if(lb>=ub)
		return;
	j=partition(x,lb,ub);
	quicksort(x,lb,j-1);
	quicksort(x,j+1,ub);
}
int partition(int x[],int lb,int ub)
{
   	int range,random,up,down,a,temp,c;
   	up=ub;
   	down=lb;
	
	range=(ub-lb);			// for random pivotal element modification starts
	random=rand()%range;
	temp=x[lb];	
	x[lb]=x[lb+random];
	x[lb+random]=temp;		// for random pivital element modification ends

   	a=x[lb];
   	while(down<up)
   	{
     		while((x[down]<=a)&&(down<up))
		{
			down++;
			count++;
		}
		while(x[up]>a)
		{
			up--;
			count++;
		}
		if(up>down)
		{
			temp=x[up];
	  		x[up]=x[down];
	  		x[down]=temp;
		}
      	}
   	x[lb]=x[up];
   	x[up]=a;
   	c=up;
   	return c;
}
main()
{
	int n=10;
	int i;
	for(n=100;n<=500;n=n+50)
	{
		count=0;

		for(i=0;i<n;i++)
		  	x[i]=rand()%100;
/*		printf("\n\nthe random numbers generated are :\n");
		for(i=0;i<n;i++)
			printf("%d ",x[i]);
		printf("\n\n");	
*/
		quicksort(x,0,n-1);
		printf("COMPARISONS FOR QUICKSORT OF %d ELEMENTS=%d\n",n,count);
/*
		printf("\nThe sorted array is:\n");
		for(i=0;i<n;i++)
			printf("%d ",x[i]);
		printf("\n\n");	
*/		
	}
}
