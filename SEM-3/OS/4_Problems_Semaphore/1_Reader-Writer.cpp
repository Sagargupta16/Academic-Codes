#include<iostream>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
using namespace std;

sem_t mutex,rw_mutex;
pthread_t tid;
pthread_t writerthread[100],readerthread[100];
int readercount = 0;

void* reader(void* param){
	sem_wait(&mutex);
	readercount++;
	if(readercount == 1) sem_wait(&rw_mutex);
	sem_post(&mutex);
//	cout<<"Reader "<<readercount << " is inside \n";
	printf("Reader %d is inside. \n",readercount);
	sleep(3);
	sem_wait(&mutex);
	readercount--;
	printf("Reader %d is Leaving. \n",readercount+1);
	if(readercount == 0) sem_post(&rw_mutex);
	sem_post(&mutex);
//	cout<<"Reader "<<(readercount+1)<< " is leaving \n";
	
	return NULL;
}

void* writer(void* param){
	cout<<"Writer is trying to enter \n";
	sem_wait(&rw_mutex);
	cout<<"Writer has entered \n";
	sem_post(&rw_mutex);
	cout<<"Writer is leaving \n";
	return NULL;
}

int main(){
	int n,i;
	cout<<"Enter number of readers: ";
	cin>>n;
	cout<<endl;
	int n1[n];
	sem_init(&mutex,0,1);
	sem_init(&rw_mutex,0,1);
	for(i = 0; i < n ; i++){
		pthread_create(&writerthread[i],NULL,writer,NULL);
		pthread_create(&readerthread[i],NULL,reader,NULL);
	}
	for(int i = 0 ; i <= n ; i ++){
		pthread_join(writerthread[i],NULL);
		pthread_join(readerthread[i],NULL);
	}
	return 0;
}
