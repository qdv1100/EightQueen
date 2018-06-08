#include<stdio.h>
#define MAXSIZE 8
#define RESULTFILE "result.txt"
int place[MAXSIZE][MAXSIZE] = {};
void PrintPlace();
int Test(int row,int col);
void WriteTmpData(char *str);
void Try();

int row,col;
int totalCount = 1;
int main()
{
	Try();
	
	return 0;
}

void PrintPlace()
{
	int i,j;
	printf("%d\n",totalCount);
	for(i=0;i<MAXSIZE;++i)
	{
		for(j = 0;j<MAXSIZE;++j)
		{
			printf("%d ",place[i][j]);
		}
		printf("\n");
	}
}
//
int Test(int row,int col)
{
	int i,j;
	//rightdown
	for(i = row+1,j = col +1;i<MAXSIZE && j<MAXSIZE;++i,++j)
		if(place[i][j] == 1)
		{
			return 0;
		}
	//leftup
	for(i = row-1,j = col -1;i>=0 && j>=0;--i,--j)
		if(place[i][j] == 1)
			{
				return 0;
			}
	//rightup
	for(i = row-1,j = col +1;i>=0 && j<MAXSIZE;--i,++j)
		if(place[i][j] == 1)
			{
				return 0;
			}
	//leftdown
	for(i = row+1,j = col -1;i<MAXSIZE && j>=0;++i,--j)
		if(place[i][j] == 1)
			{
				return 0;
			}
	//vertical
	for(i = 0,j=col;i < MAXSIZE;++i)
		if(place[i][j] == 1 && i != row)
			{
				return 0;
			}
	//horizontal
	for(i = row,j = 0;j < MAXSIZE;++j)
		if(place[i][j] == 1 && j != col)
			{
				return 0;
			}
	return 1;
}
//write a result to file
void WriteTmpData(char *str)
{
	FILE *fp = fopen(RESULTFILE,"a");
	int i,j;
	fprintf(fp,"%d\n",totalCount++);
	for(i=0;i<MAXSIZE;++i)
	{
		for(j = 0;j<MAXSIZE;++j)
		{
			fprintf(fp,"%d ",place[i][j]);
		}
		fprintf(fp,"\n");
	}
	fprintf(fp,"\n");
	fclose(fp);
}
//set chessman
void Try()
{
	int i=0,j;
	while(i<MAXSIZE && i >=0)
	{
		for(j=0;j<MAXSIZE;++j)
		{
			if(place[i][j] == 1)
			{
				place[i][j] = 0;
				continue;
			}
			if(Test(i,j))
			{
				place[i][j] = 1;
				break;
			}			
		}
		if(j>= MAXSIZE)
		{
			--i;			
			continue;
		}
		++i;
		if(i>=MAXSIZE)
		{	
			WriteTmpData(RESULTFILE);
			--i;
		}
	}	
}





