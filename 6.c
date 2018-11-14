#include<stdio.h>
#include<omp.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
	float a[10],max;
	int tid,nthreads,i;
	for(i=0;i<10;i++)
	{
		a[i]=1.5*i;
	}
	max=a[0];
	#pragma omp parallel shared(a,max,nthreads) private(i,tid)
    tid=omp_get_thread_num();
    if(tid==0)
    {
    	nthreads=omp_get_num_threads();
    	printf("thread %d executing",nthreads);
    }
    
    #pragma omp parallel for
     
    for(i=0;i<10;i++)
    {
    	if(a[i]>max)
    	{
    		max=a[i];
    	}
    }
    printf("maximum is %f",max);

}