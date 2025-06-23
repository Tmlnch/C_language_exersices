#include <stdio.h>
int main ( ) {
int n , m ;
printf ( "Husnegtiin Mur:\n" ) ;
    scanf ( "%d " , & n ) ;
printf ( "HusnegtiinBagana:\n" ) ;
    scanf ( "%d" , & m ) ;
int arr [ n ] [ m ] ;
for ( int i = 0 ; i < n ; i ++ ) {
    for ( int i1 = 0 ; i1 < m ; i1 ++ ) {
        scanf ( "%d" , & arr [ i ] [ i1 ] ) ;
    }
}
printf ( "Husnegt:\n" ) ;
for ( int i5 = 0 ; i5 < n ; i5 ++ ) {
    for ( int i6 = 0 ; i6 < m ; i6 ++ ) {
        printf ( "%d" , arr [ i5 ] [ i6 ] ) ;
    }
    printf ( "\n" ) ;
}

int h [ n ] ;
int max ;
for ( int i2 = 0 ; i2 < n ; i2 ++ ) {
    max = arr [ i2 ] [ 0 ] ;
    for ( int i3 = 0 ; i3 < m ; i3 ++ ) {
        if ( arr [ i2 ]  [ i3 ] > max )
            max = arr [ i2 ] [ i3 ] ;
        }
        h [ i2 ] = max ;
    }
printf ( "Ih elementuud:\n" ) ;
for ( int i4 = 0 ;i4 < n ; i4 ++ ) {
    printf ( " %d " , h [ i4 ] ) ;
}
printf ( "\n" ) ;

for ( int i7 = 1 ; i7 < n ; i7 ++ ) {
        int k = h [ i7 ] ;
        int j ;

        for (j = i7 - 1 ; j >= 0 && h [ j ] > k ; j -- ) {
            h [ j + 1 ] = h [ j ] ;
        }
        h [ j + 1 ] = k ;
}
printf ( "Eremblegdsen n:\n" ) ;
for ( int i8 = 0 ; i8 < n ; i8 ++ ) {
    printf ( "%d" , h [ i8 ] ) ;
}
printf ( "\n" ) ;
int s , h1 , l , m1 ; 
printf ( "Haih too:\n" ) ;
    scanf ( "%d" , & s ) ;
    h1 = n - 1 ;
    l = 0 ;
    int o = 0 ;
    while ( l < = h1 ) {
        m1 = ( l + h1 ) / 2;
        if ( s == h [ m1 ] ) {
            printf ( "%d" , m1 ) ;
            o = 1 ;
            break ; }
        else if ( s < h [ m1 ] ) {
            h1 = m1 - 1 ; }
        else {
            l = m1 + 1 ; }
    } 
    if ( o == 0 )
    printf ( "Elementoldsongui") ; 
    
}
    

