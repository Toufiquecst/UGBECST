#include<stdio.h>
#include<stdlib.h>
struct sold
       {
             char c;
       	     struct sold* next;
       }*start;
int m;
void joseph(struct sold* node,int a)
{
	int i;
	struct sold* temp;
	if(a!=1)
		while(node!=node->next)
                    {
			for(i=1;i<(a-1);i++)
			 	node=node->next;
			printf("The Soldier %c stay in battle\n\n",node->next->c);
			temp=node->next->next;
			free(node->next);
			node->next=temp;
			node=node->next;
		    }
	else{	
               while(node!=node->next)
                    {
			printf("The Soldier %c stay in battle\n\n",node->c);
			temp=node;
			while(node->next!=temp)
				node=node->next;
			temp=node->next->next;
			free(node->next); 
			node->next=temp;
			node=node->next;
		    }
	    }
	printf("The Soldier %c goes for reinforcement\n",node->c);
}
main()
{
	int a,d;
	char ch,s;
	struct sold* node;
	printf("\nEnter the no. of soldiers:");
	scanf("%d",&a);
	start=node;
	for(d=0;d<a;d++)
           {
		node->next=(struct sold*)malloc(sizeof(struct sold));
		node=node->next;
		node->c=(d+65);
	   }
	node->next=start->next;
	start=start->next;
	printf("There are %d soldiers :",a);
	for(d=0;d<a;d++)
           {
                node=node->next;
		printf("%c  ",node->c);
	   }
	d=rand()%a;
	d++;
	m=rand()%a;
	printf("\n\nNumber from the first hat is: %d\n",m);
	ch=m+65;
	s=m+64;
	printf("Number from the second hat is: %d\n",d);
	printf("\nThe counting starts from %c\n",s);
	while(start->c!=ch)
		start=start->next;
	joseph(start,d);
	//printf("\n%c",start->c);
}
