#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_CHAR 256 
struct PCB{
        int process_id;
        int priority;
        int state;
        int process_counter;
    };
struct PCB pcb={3,1,1,1};

void generateRandomString(char *str, int length) {
    const char charset[] = "ABCDEFGHIJK";
    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % (sizeof(charset) - 1);  
        str[i] = charset[randomIndex];  
    }
    str[length] = '\0'; 
}

void countCharacters(char *str) {
    int freq[MAX_CHAR] = {0}; 

    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i]]++;
    }

    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            printf("%c = %d\n", i, freq[i]);
        }
    }
}
void handleSignal(int sig) {
    printf("\nProcess ID: %d \nPriority: %d \nState: %d \nCounter: %d\n",
           pcb.process_id,pcb.priority, 0, pcb.process_counter);
    exit(0); }

int main() {
    int s = 10;  
    char str[s + 1]; 
    srand(time(0));  
    signal(SIGINT, handleSignal);
    while(1){
    generateRandomString(str, s);
    printf("Random String: %s\n", str);
    countCharacters(str);
    sleep(2);
    pcb.process_counter++;
    }
}   