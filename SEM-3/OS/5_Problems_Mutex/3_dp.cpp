#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

pthread_t ph[5];
pthread_mutex_t cs[5];

void *func(void* i){
    int n = *((int*)i);
    printf("ph %d is thinking.\n",n+1); 
    pthread_mutex_lock(&cs[n]);
    pthread_mutex_lock(&cs[(n+1)%5]);
    printf("ph %d is eating.\n",n+1);
    sleep(2);
    printf("ph %d finished eating.\n",n+1);
    pthread_mutex_unlock(&cs[n]);
    pthread_mutex_unlock(&cs[(n+1)%5]);
    return NULL;
}

int main() {
    int i;
    void* nsg;
    for(i=0;i<=4;i++){
        pthread_mutex_init(&cs[i],NULL);
    }
    for(i=0;i<=4;i++){
        pthread_create(&ph[i],NULL,func,(int*)&i);
    }
    for(i=0;i<=4;i++){
        pthread_join(ph[i],&nsg);
    }
    for(i=0;i<=4;i++){
        pthread_mutex_destroy(&cs[i]);
    }

    return 0;
}
