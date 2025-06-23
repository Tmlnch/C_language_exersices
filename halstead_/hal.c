#include <stdio.h>
#include <string.h>       
#include<math.h>

int main() {
    int n1=0,n2=0,N1=0,N2=0;
    char lines[1000][100];
    int c_l = 0;      
    char *c_ops[100];
    int c_ops_i=0;
    char *c_opends[100]; 
    char c_opends_i=0;     
    char filename[100];         
    FILE *file;
    printf("file neree oruulna uu");
    scanf("%s",filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(lines[c_l],1000, file) != NULL) {
        
        lines[c_l][strcspn(lines[c_l], "\n")] = '\0';
        c_l++;
    }
    fclose(file);
     
    char *operators[] = {"if","else","char","double","scanf","printf","main","int","+", "-", "*", "/", "=", "++", "--", "==", "!=", "<", 
    ">", "<=", ">=", "&&", "||", "!", "&", "|", "^", "%", "{","(","[","()",",",";"};
    int numOperators = sizeof(operators) / sizeof(operators[0]);  

    for (int i = 0; i < c_l; i++) {
        char *token = strtok(lines[i], " ");
       
        while (token != NULL) {
            int is_operator = 0;
            for (int j = 0; j < numOperators; j++) {
                if (strcmp(token, operators[j]) == 0) {
                    N1++;
                    int is_unique = 1;
                    for (int j1 = 0; j1 < c_ops_i; j1++) {
                        if (strcmp(token, c_ops[j1]) == 0) {
                            is_unique = 0;
                        }
                    }
                    if (is_unique) {
                        c_ops[c_ops_i] = token;  
                        c_ops_i++;  
                        n1++; 
                    }

                    is_operator = 1;
                    break;
                }
            }
            if (!is_operator && strcmp(token,")")!=0 && strcmp(token,"}")!=0) {
                N2++;
                int is_unique_o = 1;
                    for (int j2 = 0; j2 < c_opends_i; j2++) {
                        if (strcmp(token, c_opends[j2]) == 0) {
                            is_unique_o = 0;
                        }
                    }
                    if (is_unique_o) {
                        c_opends[c_opends_i] = token;  
                        c_opends_i++;  
                        n2++; 
                    }
            }

            token = strtok(NULL, " ");
        }
    }
       int n = n1 + n2;
       int N = N1 + N2;

    double N_ = n1*log2(n1)+n2*log2(n2);
    double V = N * log2(n);
    double D = (n2 > 0 ? (double)n1 / 2 * (double)N2 / n2 : 0);
    double E = D * V;
    double T = E / 18;
    double B = V/ 3000 ;

     printf("N1: %d\n", N1);
     printf("N2: %d\n", N2);
     printf("N: %d\n", N1+N2);
     printf("n1: %d\n", n1);
     printf("n2: %d\n", n2);
     printf("n: %d\n", n1+n2);
     printf("N': %.2f\n", N_);
     printf("V: %.2f\n", V);
     printf("D: %.2f\n", D);
     printf("E: %.2f\n", E);
     printf("T: %.2fseconds\n", T);
     printf("B: %.2f\n", B);
     
    return 0;
}