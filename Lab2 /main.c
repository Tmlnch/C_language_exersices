#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <pthread.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_CHAR 256

struct PCB {
    int process_id;
    int priority;
    int state;           // 1 = Running, 0 = Stopped
    int process_counter;
};

// PCB definitions
struct PCB pcb1 = {1, 3, 1, 0};
struct PCB pcb2 = {2, 2, 1, 0};
struct PCB pcb3 = {3, 1, 1, 0};

// Signal handler
void handleSignal(int sig) {
    printf("\nProcess 1 - ID: %d, Priority: %d, State: %d, Counter: %d\n",
           pcb1.process_id, pcb1.priority, pcb1.state, pcb1.process_counter);
    printf("Process 2 - ID: %d, Priority: %d, State: %d, Counter: %d\n",
           pcb2.process_id, pcb2.priority, pcb2.state, pcb2.process_counter);
    printf("Process 3 - ID: %d, Priority: %d, State: %d, Counter: %d\n",
           pcb3.process_id, pcb3.priority, pcb3.state, pcb3.process_counter);
    exit(0);
}

// Bubble sort function
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Process 1
void* process1(void* arg) {
    srand(time(0));
    while (1) {
        int arr[100];
        for (int i = 0; i < 100; i++) {
            arr[i] = (rand() % 100) + 1;
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("Sorted: \n");
        bubbleSort(arr, 100);
        for (int i = 0; i < 100; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");

        pcb1.process_counter++;
    }
    return NULL;
}

// Function to print 2D arrays
void print(int arr[MAX_ROWS][MAX_COLS], int i, int j) {
    for (int q = 0; q < i; q++) {
        for (int q1 = 0; q1 < j; q1++) {
            printf("%d ", arr[q][q1]);
        }
        printf("\n");
    }
}

// Process 2
void* process2(void* arg) {
    srand(time(0));
    while (1) {
        int i = rand() % MAX_ROWS + 1;
        int j = rand() % MAX_COLS + 1;

        int arr1[MAX_ROWS][MAX_COLS] = {0};
        int arr2[MAX_ROWS][MAX_COLS] = {0};
        int arr3[MAX_ROWS][MAX_COLS] = {0};

        for (int t = 0; t < i; t++) {
            for (int t1 = 0; t1 < j; t1++) {
                arr1[t][t1] = (rand() % 100) + 1;
                arr2[t][t1] = (rand() % 100) + 1;
            }
        }

        printf("Array 1:\n");
        print(arr1, i, j);
        printf("\nArray 2:\n");
        print(arr2, i, j);

        for (int c = 0; c < i; c++) {
            for (int c1 = 0; c1 < j; c1++) {
                arr3[c][c1] = arr1[c][c1] - arr2[c][c1];
            }
        }

        printf("\nArray 3:\n");
        print(arr3, i, j);
        printf("\n");

        pcb2.process_counter++;
    }
    return NULL;
}

// Function to generate a random string
void generateRandomString(char *str, int length) {
    const char charset[] = "ABCDEFGHIJK";
    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % (sizeof(charset) - 1);
        str[i] = charset[randomIndex];
    }
    str[length] = '\0';
}

// Function to count character frequency
void countCharacters(char *str) {
    int freq[MAX_CHAR] = {0};
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            printf("%c = %d\n", i, freq[i]);
        }
    }
}

// Process 3
void* process3(void* arg) {
    int s = 10;
    char str[s + 1];
    srand(time(0));
    while (1) {
        generateRandomString(str, s);
        printf("Random String: %s\n", str);
        countCharacters(str);
        printf("\n");

        pcb3.process_counter++;
    }
    return NULL;
}

// Main function
int main() {
    pthread_t thread1, thread2, thread3;

    signal(SIGINT, handleSignal);

    pthread_create(&thread1, NULL, process1, NULL);
    pthread_create(&thread2, NULL, process2, NULL);
    pthread_create(&thread3, NULL, process3, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}