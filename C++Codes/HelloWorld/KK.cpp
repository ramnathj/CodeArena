#include <stdio.h>
#define MAXV 100000007

void Merge( int* A, int p, int q, int r ) {

    int n1, n2, i, j, k;
    n1 = q - p + 1;
    n2 = r - q;
    int *L = (int*)malloc( sizeof( int ) * ( n1 + 2 ) );
    for( i = 1;i <= n1;i++ ) {
        L[ i ] = A[ p + i - 1 ];
    }
    L[ n1 + 1 ] = MAXV;

    int *R = (int*)malloc( sizeof( int ) * ( n2 + 2 ) );
    for( j = 1;j <= n2;j++ ) {
        R[ j ] = A[ q + j ];
    }
    R[ n2 + 1 ] = MAXV;
    
    i = j = 1;
    for( k = p; k <= r;k++ ) {
        if( L[ i ] <= R[ j ] ) {
            A[ k ] = L[ i ];
            i++;
        } else {
            A[ k ] = R[ j ];
            j++;
        }
    }
}

void MergeSort( int *A, int p, int r ) {
    int q;
    if( p < r ) {
        q = ( p + r ) >> 1;
        MergeSort( A, p, q );
        MergeSort( A, q + 1, r );
        Merge( A, p, q, r );
    }
}

int binSearch( int* A, int n, int s ) {
    int start, end, mid;
    start = 0;
    end = n - 1;
    
    while( start <= end ) {
        mid = ( start + end ) >> 1;
        if( A[ mid ] == s ) {
            return 1;
        } else if( A[ mid ] > s ) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return 0;
}

int main()
{
    int t, n, i, q, val;
    scanf("%d", &t );
    while( t-- ) {
        scanf("%d", &n );
        int *A = (int*)malloc( sizeof( int ) * n );
        for( i = 0;i < n;i++ ) {
            scanf("%d", &A[ i ] );
        }
        MergeSort( A, 0, n - 1 );
        scanf("%d", &q );
        while( q-- ) {
            scanf("%d", &val );
            if( binSearch( A, n, val ) ) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}
