#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
main()
{
	FILE *fp;
	int c;
	char *cs;
	fp=fopen("sample.txt","w");
	while((c=getchar())!='\t')
		fputc(c,fp);
	fputc(c,fp);
	fclose(fp);
}		
