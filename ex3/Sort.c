#include <stdio.h>
int main() {
    int n,i,t,s,m,h,l;
    printf("Husnegtiin too:\n");
    scanf("%d", &n);
    int arr[n];  
    printf("Elementuud:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i2 = 0; i2 < n; i2++) {
        printf("%d ", arr[i2]);
    }
    printf("\n");

   for (int i1 = 0; i1 < n - 1; i1++) {
        int m=i1;
        for (int j = i1 + 1; j < n; j++) {
            if (arr[j] < arr[m]) {
                m=j;
        }
    }   
        t=arr[m];
        arr[m]=arr[i1];
        arr[i1]=t;
        for (int i3 = 0; i3 < n; i3++) {
        printf("%d ", arr[i3]);
    }
    printf("\n");
    }
    
    printf("Haih too:\n");
    scanf("%d",&s);
    h=n-1;
    l=0;
    int o=0;
    while(l<=h){
        m=(l+h)/2;
        if(s==arr[m]){
            printf("%d",m);
            o=1;
            break;}
        else if(s<arr[m]){
            h=m-1;}
        else{
            l=m+1;}
    }
    if(o==0)
    printf("Element oldsongui");
}