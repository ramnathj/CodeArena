/* Program to find the 
 * number of elements in
 * the array <= x
 */

#include <stdio.h>
#include <stdlib.h>

int binSearch( int* A, int n, int s ) {
    
    int start, end, mid;
    start = 0;
    end = n - 1;
    
    while( start <= end ) {
        mid = ( start + end ) >> 1;
        if( A[ mid ] > s ) {
            if( ( mid > 0 ) && A[ mid - 1 ] <= s ) {
                return mid;
            } else {
                end = mid - 1;
            }
        } else {
            if( ( mid < n ) && A[ mid + 1 ] > s ) {
                return mid + 1;
            } else {
                start = mid + 1;
            }
        }
    }
    
    return -1;
}

int main() {
    int t, n, i, s, val;
    scanf("%d", &t );
    
    while( t-- ) {
        scanf("%d", &n );
        int* A = (int*) malloc( n * sizeof( int ) );
        for( i = 0;i < n;i++ ) {
            scanf("%d", &A[ i ] );
        }
        scanf("%d", &s );
        if( A[ n - 1 ] < s ) {
            printf("%d\n", n );
        } else if( A[ 0 ] > s ) {
            printf("0\n");
        }else {
            val = binSearch( A, n, s);
            if( val != -1 ) {
                printf("%d\n", val );
            } else {
                printf("0\n");
            }
        }
        free( A );
    }
	return 0;
}