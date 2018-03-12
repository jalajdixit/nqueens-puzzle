
/* N Queens Solution with system clear */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int num;
void priary(int a[][num]);
int findqueen(int a[][num],int,int);
int solve(int a[][num]);

void main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("Usage:  ./NQueens MatrixSize\n");
		return;
	}
	num=atoi(argv[1]);
	if(num<4 || num>100)
	{
		printf(" Matrix Size should be between 4 & 100\n");
		return;
	}
	
	int a[num][num],ret;
	memset(a,0,sizeof(a));

	priary(a);
	solve(a);
	system("clear");
	priary(a);
}

int solve(int a[][num])
{
	static int i;
	int j,fret,soret;

	if(i==num)
	return 1;

	for(j=0;j<num;j++)
	{
		fret=findqueen(a,i,j);
		if(fret==0)
		{
			a[i][j]=1;
			i++;
			system("clear");
			priary(a);
			for(unsigned long int k=0;k<10000000;k++);
			soret=solve(a);
			if(soret==0)
			{
				i--;
				a[i][j]=0;
			}
			else
			return 1;
		}
		
	}
	
	if(j==num)
	return 0;
}

int findqueen(int a[][num],int i,int j)
{
	int x,y;
	for(y=j-1;y>=0;y--)
		if(a[i][y]==1)
		return -1;
	for(x=i-1;x>=0;x--)
		if(a[x][j]==1)
		return -1;
	for(x=i-1,y=j+1;x>=0 && y<num;x--,y++)
		if(a[x][y]==1)
		return -1;
	for(x=i-1,y=j-1;x>=0 && y>=0;x--,y--)
		if(a[x][y]==1)
		return -1;
	return 0;
}

void priary(int a[][num])
{
	int i,j,k;
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			if(a[i][j]==0)
			printf("- ");
			else
			printf("Q ");
		}
		printf("\n");
	}
}
