#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
main()
{
	FILE *fp;
	int c,a;
	char *cs;
	char *s;
	fp=fopen("sample.txt","r");
	a=1;
	c=5;
	while(c!='\t')
	{
		a=1;
		c=getc(fp);
		while(((c!='\n')||(c!='\t'))&&(a==1))
		{
			a=0;
			printf("%c",c);
			if(c==' ')
				break;
		}
	}
}
