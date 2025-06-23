#include<stdio.h>
#include<string.h>
void DecToHex(int d)
{
    int i = 1, j, temp;
    char hex[100];
    while (d>0) {
        temp=d%16;
        if(temp<10)
            temp=temp+48;
         else    
            temp=temp+55;
        hex[i++]=temp;
        d=d/16; }
    for(j=i-1;j>0;j--) 
        printf("%c",hex[j]);
}

int HexToDec(char *hex){
    int dec=0, i, digit, base=1;
    for (i = (strlen(hex) - 1); i >= 0; i--) {
        switch (hex[i]) { 
        case 'A': 
            digit = 10; 
            break; 
        case 'B': 
            digit = 11; 
            break; 
        case 'C': 
            digit = 12; 
            break; 
        case 'D': 
            digit = 13; 
            break; 
        case 'E': 
            digit = 14; 
            break; 
        case 'F': 
            digit = 15; 
            break; 
        default: 
            digit = hex[i]-0x30; 
        } 
        dec=dec+digit*base;
        base*=16;
    }
    return dec; 
}

    void DecToOct(int n)
{
    int OctNum[32];
    int i = 0;
    while (n > 0) {
        OctNum[i] = n % 8;
        n = n / 8;
        i++;
    }
 
    for (int j = i - 1; j >= 0; j--){
       printf("%d",OctNum[j]);
        } 
}
    int OctToDec(char *n){
        int dec=0,i,digit,base=1;
    for (i = (strlen(n) - 1); i >= 0; i--) {
        digit=n[i]-'0';
        dec=dec+digit*base;
        base*=8;
    }
    return dec;
}
int main()
{
    int i,s;
    char n[100];
    printf("Enter Number: ");
    scanf("%s",n);
    printf("Convert to Hex type 1 or Convert to Octal type 0: ");
    scanf("%d", &s);
    if(s==1)
        DecToHex(OctToDec(n));
    else    
        DecToOct(HexToDec(n));
    return 0;
}