#include <stdio.h>
int main() {
int n;
printf("Elementiin too:\n");
    scanf("%d", &n);
int a[n],c[n];
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    c[i]=0;
}
int s=0;
for(int i1=0;i1<n;i1++){
    for(int i2=i1+1;i2<n;i2++){
        if(a[i1]==a[i2]&&c[i2]==0&&c[i1]==0){
            c[i2]=1;
            break;
        }
    }
}
for(int m=0;m<n;m++){
    if(c[m]==1){
        s++;
    }
}
if(s>0){
int ar[s];
int x=0;
for(int ai=0;ai<n;ai++){
        if(c[ai]==1){
        ar[x]=a[ai];
        x++;
        }   
    }
for(int t=0;t<s;t++){
    printf("%d ",ar[t]);
}   printf("\n");

    int q,r;
    printf("Muriin too:\n");
    scanf("%d", &q);
    printf("Baganiin too:\n");
    scanf("%d", &r);
    int a2[q][r];
    for(int s1=0;s1<q;s1++){
        for(int s2=0;s2<r;s2++){
            scanf("%d",&a2[s1][s2]);
        }
    }
 
    for(int s3=0;s3<q;s3++){
        for(int s4=0;s4<r;s4++){
            printf("%d ",a2[s3][s4]);
        }
        printf("\n");
    }
    
    for(int o=0;o<s;o++){
        for(int o1=0;o1<q;o1++){
            for(int o2=0;o2<r;o2++){
                if(ar[o]==a2[o1][o2]){
                printf("%d elementiin bairlal=%d,%d\n",ar[o],o1,o2);
                }
            }
        }
    }
}else{
    printf("Davhardsan too baihgui");
}
}

