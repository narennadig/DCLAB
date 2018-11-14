#include<omp.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#define N 1000
int main(int argc,char *argv[])
{
	int i;
	float a[N],b[N],sum;
	for(i=0;i<N;i++)
	{
		a[i]=b[i]=1.0*i;
	}

	#pragma omp parallel  for reduction(+:sum)
	
		for(i=0;i<N;i++)
		{
         sum=sum+(a[i]*b[i]);
			
	    }
	    printf("sum=%f \n",sum);
	
}