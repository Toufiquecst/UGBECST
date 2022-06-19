#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
main()
{
	FILE *fp;
	char *c;
	char s[30];
	fp=fopen("sample.txt","r");
	fgets(s,30,fp);
	printf("\n %s \n",s);
}
