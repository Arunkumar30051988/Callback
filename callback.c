#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
//typedef void (*callback)(int,int);
int (*callback)(int,int);
void CallbackRegister(int (*fun)(int,int));
int add(int a,int b)
{
	printf("Callback value:%d \n ",a+b);
}
void  CallbackRegister(int (*fun)(int a,int b))
{
	callback=fun;
}

void *Function_1(void * Arg)
{
	int a;
	while(1)
	{
		CallbackRegister(&add);
		break;
	}
}
void *Function_2(void *Arg)
{
	int a,b;
	while(1)
	{
		callback(5,5);
		break;			
	}
}
int main()
{
	pthread_t thread_1,thread_2;
	pthread_create(&thread_1,NULL,Function_1,NULL);
	pthread_create(&thread_2,NULL,Function_2,NULL);
	pthread_join(thread_1,NULL);
	pthread_join(thread_2,NULL);
}
