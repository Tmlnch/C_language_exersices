#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>

struct PCB {
    int process_id;
    int priority;
    int state;           // 1 = Running, 0 = Stopped
    int process_counter;
};

struct PCB pcb = {1, 3, 1, 1};

void handleSignal(int sig) {
    printf("\nProcess ID: %d \nPriority: %d \nState: %d \nCounter: %d\n",
           pcb.process_id,pcb.priority, 0, pcb.process_counter);
    exit(0);
}

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

int main() {
    signal(SIGINT, handleSignal);

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

        pcb.process_counter++;
    }

    return 0; 
}