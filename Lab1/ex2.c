#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

void print(int arr[10][10], int i, int j) {
    for (int q = 0; q < i; q++) {
        for (int q1 = 0; q1 < j; q1++) {
            printf("%d ", arr[q][q1]);
        }
        printf("\n");
    }
}
void handleSignal(int sig) {
    exit(0); }

int main() {
    signal(SIGINT, handleSignal);
    srand(time(0));
    while(1){
    int i = rand() % 10 + 1;  
    int j = rand() % 10 + 1;  

    int arr1[10][10]={0};
    int arr2[10][10]={0};
    int arr3[10][10]={0};

    for (int t = 0; t < i; t++) {
        for (int t1 = 0; t1 < j; t1++) {
            arr1[t][t1] = (rand() % 100) + 1;
            arr2[t][t1] = (rand() % 100) + 1;
        }
    }

    printf("Array 1:\n");
    print(arr1, i, j);
    printf("\n");
    printf("Array 2:\n");
    print(arr2, i, j);

    for (int c = 0; c < i; c++) {
        for (int c1 = 0; c1 < j; c1++) {
            arr3[c][c1] = arr1[c][c1] + arr2[c][c1];
        }
    }

    printf("\nArray 3: \n");
    print(arr3, i, j);  
    printf("\n");
    }
    return 0;
}   