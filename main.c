#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main(int argc,char *argv[])
{
	time_t t;
	clock_t start,stop;
	FILE *file_ptr=fopen("file.txt","w");
	for(int k=1;k<argc;k++)
	{
		start=clock();
	
		int n=atoi(argv[k]);
		int a[n];
		int query;
		srand((unsigned) time(&t));
	
		for(int i=0;i<n;i++)
		{
			a[i]=rand();
		}
		for(int i=0;i<10000;i++)
		{
			if(rand()%2==0)
			{
				query=rand();
			}
			else
			{
				query=a[rand()%n];
			}
			for(int j=0;j<n;j++)
			{
				if(query==a[j])
				{
					break;
				}
			}
		}
	
		stop=clock();
		double time;
		time=(double)(stop-start)/CLOCKS_PER_SEC;
		fprintf(file_ptr,"%d		%f\n",n,time);
	}
	fclose(file_ptr);
	
}



