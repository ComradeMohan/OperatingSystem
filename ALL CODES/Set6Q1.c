#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
pthread_mutex_t mutex;
pthread_cond_t condition[NUM_PHILOSOPHERS];
int state[NUM_PHILOSOPHERS];
void test(int i) {
    if (state[i] == HUNGRY &&
        state[(i + 4) % NUM_PHILOSOPHERS] != EATING &&
        state[(i + 1) % NUM_PHILOSOPHERS] != EATING) {
        state[i] = EATING;
        pthread_cond_signal(&condition[i]);
    }
}
void take_forks(int i) {
    pthread_mutex_lock(&mutex);
    state[i] = HUNGRY;
    test(i);
    while (state[i] != EATING) {
        pthread_cond_wait(&condition[i], &mutex);
    }
    pthread_mutex_unlock(&mutex);
}
void put_forks(int i) {
    pthread_mutex_lock(&mutex);
    state[i] = THINKING;
    test((i + 4) % NUM_PHILOSOPHERS);
    test((i + 1) % NUM_PHILOSOPHERS);
    pthread_mutex_unlock(&mutex);
}
void *philosopher(void *arg) {
    int philosopher_id = *((int *)arg);
    while (1) {
        printf("Philosopher %d is thinking.\n", philosopher_id);
        sleep(2); 
        take_forks(philosopher_id);
        printf("Philosopher %d is eating.\n", philosopher_id);
        sleep(3); 
        put_forks(philosopher_id);
    }
}
int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int philosopher_ids[NUM_PHILOSOPHERS];
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_cond_init(&condition[i], NULL);
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_ids[i]);
    }
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_cond_destroy(&condition[i]);
    }
    return 0;
}
