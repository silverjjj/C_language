#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t counterMutex = PTHREAD_MUTEX_INITIALIZER; 
void *incrementCounter(void *arg) {
    for (int i = 0; i < 1000000; ++i) {
        pthread_mutex_lock(&counterMutex);      // race condition 예방
        counter++;
        pthread_mutex_unlock(&counterMutex);       // race condition 예방
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // 두 개의 스레드 생성
    pthread_create(&thread1, NULL, incrementCounter, NULL);
    pthread_create(&thread2, NULL, incrementCounter, NULL);

    // 각 스레드의 실행을 기다림
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // 최종 결과 출력
    printf("Counter: %d\n", counter);

    return 0;
}
