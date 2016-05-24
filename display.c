#include <stdio.h>
void main(int argc, char const *argv[])
{
	/* code */
	int ch;
	FILE *fp;
	if (argc!=2)
	{
		/* code */
		printf("error format,uasge:display filename\n");
	}
	if ((fp=fopen(argv[1],"r"))==NULL)
	{
		/* code */
		printf("the file <%s> can not be opened.\n",argv[1] );
		return;
	}
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	fclose(fp);
}