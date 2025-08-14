#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *f1,*f2;
	char FN[100],c;
	printf("Enter file name : ");
	scanf("%s",FN);
	f1=fopen(FN,"r");
	if(	f1== NULL)
	{
		printf("Cannot open file ");
		exit(0);
	}
	printf("Enter file name : ");
	scanf("%s",FN);
	f2=fopen(FN,"w");
	if(	f2== NULL)
	{
		printf("Cannot open file ");
		exit(0);
	}
	c=fgetc(f1);
	while(c!=EOF)
	{
		fputc(c,f2);
		c=fgetc(f1);
	}
	printf("Content copied");
	fclose(f1);
	fclose(f2);
}