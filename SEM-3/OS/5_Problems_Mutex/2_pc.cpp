#include <pthread.h>
#include <semaphore.h>
#include <bits/stdc++.h>
#define MaxItems 5 
#define BufferSize 5

sem_t empty,full;
int in = 0,out = 0,buffer[BufferSize];
pthread_mutex_t mutex;

void *producer(void *pno){ 
    for(int i = 0; i < MaxItems; i++) {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = rand();
        printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[in],in);
        in = (in+1)%BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *cno){   
    for(int i = 0; i < MaxItems; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, out);
        out = (out+1)%BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main(){   
    pthread_t pro[5],con[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,BufferSize);
    sem_init(&full,0,0);
    int a[5] = {1,2,3,4,5}; //Just used for numbering the producer and consumer
    for(int i = 0; i < 5; i++) {
        pthread_create(&pro[i], NULL, producer, (int *)&a[i]);
        pthread_create(&con[i], NULL, consumer, (int *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(pro[i], NULL);
        pthread_join(con[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}
