/*more1.c --version 0.1
*readfile and print 24 lines then pause
*maohan
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PAGALEN 24
#define LINELEN 512
void do_more(FILE *);
int see_more();
int main(int ac, char *av[])
{
	FILE *fp;
	if(ac == 1)
		do_more(stdin);
	else
		while(--ac)
		if((fp=fopen(* ++av, "r"))!=NULL)
		{
			do_more(fp);
			fclose(fp);
		}
		else
			exit(1);
	return 0;
}
void do_more(FILE *fp)
	/*
	read PAGELEN lines,then call see_more() for further instruction
	 */
{
	char line[LINELEN];
	int num_of_lines=0;
	int see_more(),replay;
	while(fgets(line,LINELEN,fp)){/*more input*/
		if (num_of_lines==PAGALEN)/*full scree*/
		{
			replay=see_more();
			if(replay==0)
				break;
			num_of_lines-=replay;/*reset replay*/
		}
		if(fputs(line,stdout) == EOF)/*show lines*/
		exit(1);
		num_of_lines++;/*count it*/
	}
}
int see_more()
/*print message,wait for reposne,return #for  lines to advance
* q means no,space mens yes,CR means one lines;
*/
 {
 	int c;
 	printf("\033[7m more? \033[m");
 	while((c=getchar())!=EOF)
 	{
 		if(c=='q')
 			return 0;
 		if(c==' ')
 			return PAGALEN;
 		if(c=='\n')
 		{
 			return 1;
 		}
 	}
 return 0;
}