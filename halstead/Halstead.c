#include <stdio.h>
#include <string.h>

int main() {
    int n1 = 0, n2=0, N1=0, N2=0;
    char code[1000];
    char *operators[] = {"scanf","printf","main","int","+", "-", "*", "/", "=", "++", "--", "==", "!=", "<", 
    ">", "<=", ">=", "&&", "||", "!", "&", "|", "^", "%", "{","(","]",")"};
    int numOperators = sizeof(operators) / sizeof(operators[0]);  
    printf("Code oo oruulna uu:\n");
    fgets(code, sizeof(code), stdin);

    char *token = strtok(code, " ");
    while (token != NULL) {
        printf("token: %s\n",token);
        for (int i = 0; i < numOperators; i++) {
            if (strcmp(token, operators[i]) == 0) {
                printf("Matched operator: %s\n", token);
                n1++;  
                break; 
            }
        }
        token = strtok(NULL, " ");
        n2++;
    }


     printf("Total Operators (n1): %d\n", n1);
     printf("Total Operands (n2): %d\n", n2);

    return 0;
}