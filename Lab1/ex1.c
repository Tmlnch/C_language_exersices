#include <stdio.h>
#include <stdlib.h>  
#include <time.h>   

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
void handleSignal(int sig) {
    exit(0); }


int main() {
    signal(SIGINT, handleSignal);
    srand(time(0)); 
    while(1){
    int arr[100];
    for (int i = 0; i < 100; i++) {  
        arr[i] = (rand() % 100) + 1;  
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Sorted: \n");
    bubbleSort(arr,100);
    for (int i1 = 0; i1 < 100; i1++) {    
        printf("%d ", arr[i1]);
    }
    printf("\n\n");
    }
    return 0;
}