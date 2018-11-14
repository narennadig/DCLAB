#include<stdio.h>
#include<omp.h>
#include<unistd.h>

void A(int *a)
{
	printf("a++\n");
	(*a)++;
}
void B(int *a)
{
	printf("a--\n");
	(*a)--;
}
void F(int *a)
{
	#pragma omp critical
	
	printf("I am thread %d of %d\n",omp_get_num_threads(),omp_get_thread_num());
	
	A(a);
	sleep(5);

	#pragma omp critical
	
	printf("I am thread %d of %d\n",omp_get_num_threads(),omp_get_thread_num());
	
	B(a);
	


}
int main(int argc,char* argv[])
{
	int i;
	int a=0;
	#pragma omp parallel for 
	for(i = 0; i < 4; i++)
	{
		printf("numbers of threads triggered are %d",omp_get_thread_num());
		F(&a);
	}
	return 0;
}