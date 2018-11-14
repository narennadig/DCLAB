#include<stdio.h>
#include<omp.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
	int a,b,c,d,e,nthreads,tid;
    #pragma omp parallel private(tid,nthreads)
	 tid=omp_get_thread_num();
	 if(tid==0)
	 {
	 	nthreads=omp_get_num_threads();
	 	printf("%d thread executing everything",nthreads);
	 }
	a=omp_get_num_procs();
	b=omp_in_parallel();
	c=omp_get_dynamic();
	d=omp_get_nested();
    e=omp_get_num_threads();
    printf("a=%d b=%d c=%d d=%d e=%d\n",a,b,c,d,e );
}