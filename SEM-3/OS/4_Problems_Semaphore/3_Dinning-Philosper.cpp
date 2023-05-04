#include<semaphore.h>
#include<iostream>
#include<unistd.h>
#include<pthread.h>
using namespace std;

sem_t chopstick[5];
pthread_t philosopher[5];

void* func(void* i){
	int n = *((int *)i);
	printf("ph %d is thinking\n",n+1);
	sem_wait(&chopstick[n]);
	sem_wait(&chopstick[(n+1)%5]);
	printf("ph %d is eating\n",n+1);
	sleep(2);
	printf("ph %d finished eating\n",n+1);
	sem_post(&chopstick[n]);
	sem_post(&chopstick[(n+1)%5]);
	return NULL;
}
int main(){
	int k;
	for(int i=0; i<5; i++){
		sem_init(&chopstick[i],0,1);
	}
	for(int i=0; i<5; i++){
		pthread_create(&philosopher[i],NULL,func,(int*)&i);
	}
	for(int i=0; i<5; i++){
		pthread_join(philosopher[i],NULL);
	}
	for(int i=0;i<5;i++){
		sem_destroy(&chopstick[i]);
	}
	return 0;
}
