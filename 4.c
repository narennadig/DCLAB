#include<stdio.h>
#include<unistd.h>
#include<omp.h>
int main(int argc,char *argv[])
{
	float a[10][10],b[10][10],c[10][10];
	int i,j,k,nthreads,tid;
	int chunk=10;
	#pragma omp parallel shared(a,b,c,nthreads,chunk) private (tid,i,j,k)
	tid=omp_get_thread_num();
	if(tid==0)
	{
		nthreads=omp_get_num_threads();
		printf("starting with %d threads\n", nthreads);
		printf("initializing matrices\n");
	}
	#pragma omp for schedule(static,chunk)
	
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				a[i][j]=i*j;
			}
		}
	
	#pragma omp for schedule(static,chunk)
	
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				b[i][j]=i+j;
			}
		}
	
	#pragma omp for schedule(static,chunk)
	
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				c[i][j]=0.0;
			}
		}
	
	#pragma omp for schedule(static,chunk)
	
		for(i=0;i<10;i++)
		{
			printf("thread %d implementing row :%d \n",tid,i);
			 for(j=0;j<10;j++)
			 {
			 	for(k=0;k<10;k++)
			 	{
			 		c[i][j]+=a[i][j]*b[i][j];
			 	}
			 }

		}
	for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				printf("%f   ",c[i][j]);
			}
			printf("\n");
		}


	


}