#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;

int readcount=0;
pthread_mutex_t mutex,rw_mutex;
pthread_t tid,writethread[100],readerthread[100];

void *reader(void *param){
	//int n = *((int *)param);
    pthread_mutex_lock(&mutex);
    readcount++;
    if(readcount==1) pthread_mutex_lock(&rw_mutex);
    pthread_mutex_unlock(&mutex);
    printf("Reader %d is inside\n", readcount);
    pthread_mutex_lock(&mutex);
    readcount--;
    printf("Reader %d has left\n", readcount+1);
    if(readcount==0) pthread_mutex_unlock(&rw_mutex);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *writer(void *param){
    printf("writer is trying to enter\n");
    pthread_mutex_lock(&rw_mutex);
    printf("writer is writing\n");
    pthread_mutex_unlock(&rw_mutex);
    printf("writer is leaving\n");
    return NULL;
}

int main(){
	int n,i;
	printf("Enter the number of reader: ");
	cin>>n;
    pthread_mutex_init(&mutex,NULL);
    pthread_mutex_init(&rw_mutex,NULL);
    for(i=0;i<n;i++){
    	pthread_create(&writethread[i],NULL,writer,NULL);
    	pthread_create(&readerthread[i],NULL,reader,NULL);
    }
    for(i=0;i<n;i++){
    	pthread_join(writethread[i],NULL);
    	pthread_join(readerthread[i],NULL);
    }
    return(0);
}    
