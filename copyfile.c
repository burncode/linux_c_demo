/*copyfile demo*/
#include<stdio.h>
void main(int argc, char const *argv[])
{
	/* */
	int ch;
	FILE *fin,*fout;//定义输入和输出两个文件类型指针
	if (argc!=3)
	{
		printf("error in format,Usage:copyfile filename1 filenam2\n");
		return;
	}
	if ((fin=fopen(argv[1],"r"))==NULL)
	{
		printf("the file <%s> can not be opened.\n",argv[2]);
		return;
	}
	if ((fout=fopen(argv[2],"w"))==NULL)
	{
		printf("the file <%s> can not be opened.\n",argv[2]);
		return;
	}
	ch=fgetc(fin);
	while(ch!=EOF)
	{
		fputc(ch,fout);
		ch=fgetc(fin);
	}
	fclose(fin);
	fclose(fout);

}
