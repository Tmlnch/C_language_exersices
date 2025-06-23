#include<stdio.h>
 int decToBinary(int n) {
    int binaryNum[32];
    int i = 0;
    int place = 1; 

    while (n > 0) {
        binaryNum[i] = n%2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d",binaryNum[j]);
    }
}
int BinaryToDec(int n){
    int num = n; 
    int dec_value = 0; 
    int base = 1; 
    int temp = num; 
    while (temp) { 
        int last_digit = temp % 10; 
        temp = temp / 10; 
        dec_value += last_digit * base; 
        base = base * 2; 
    } 
    return dec_value; 
}
int main()
{
    int n,s;
    printf("Enter Number: ");
    scanf("%d", &n);
    printf("Convert to Binary type 1 or Convert to Decimal type 0: ");
    scanf("%d", &s);
    if(s==1)
    decToBinary(n);
    else
    printf("%d",BinaryToDec(n));
    return 0;
}