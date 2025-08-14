#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 100

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate Fibonacci series
void generateFibonacci(int n) {
    int a = 0, b = 1, next;

    printf("child process: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *printPrimes(void *arg) {
    int *n = (int *)arg;
    
    printf("parent process: ");
    for (int i = 2; i <= *n; i++) {
        if (isPrime(i)) {
            pthread_mutex_lock(&mutex);
            printf("%d ", i);
            pthread_mutex_unlock(&mutex);
        }
    }
    printf("\n");

    pthread_exit(NULL);
}

// Function to generate Fibonacci series
void *generateFibonacciSeries(void *arg) {
    int *n = (int *)arg;

    generateFibonacci(*n);

    pthread_exit(NULL);
}

int main() {
    pthread_t parentthread, childthread;
    int n;

    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &n);
    if (pthread_create(&parentthread, NULL, printPrimes, &n) != 0) {
        perror("Error creating parent thread");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&childthread, NULL, generateFibonacciSeries, &n) != 0) {
        perror("Error creating child thread");
        exit(EXIT_FAILURE);
    }
    pthread_join(parentthread, NULL);
    pthread_join(childthread, NULL);

    return 0;
}                           