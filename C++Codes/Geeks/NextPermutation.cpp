#include <iostream>
#define MAXV 1000000

using namespace std;

void Merge( int* A, int p, int q, int r ) {
    int n1, n2, i, j, k;

    n1 = q - p + 1;
    n2 = r - q;
    
    int* L = new int[ n1 + 2 ];
    for( i = 1;i <= n1;i++ ) {
        L[ i ] = A[ p + i - 1 ]; 
    }
    L[ n1 + 1 ] = MAXV;
    
    int* R = new int[ n2 + 2 ];
    for( j = 1;j <= n2;j++ ) {
        R[ j ] = A[ q + j ]; 
    }
    R[ n2 + 1 ] = MAXV;
    
    i = j = 1;
    for( k = p;k <= r;k++ ) {
        if( L[ i ] <= R[ j ] ) {
            A[ k ] = L[ i ];
            i++;
        } else {
            A[ k ] = R[ j ];
            j++;
        }
    }
}

void MergeSort( int* A, int p, int r ) {
    int q;
    if( p < r ) {
        q = ( p + r ) >> 1;
        MergeSort( A, p, q );
        MergeSort( A, q + 1, r );
        Merge( A, p, q, r );
    }
}

int main() {
	
	int t, n, i, pos, pos2, p, q, tmp, j;
	
	cin >> t;
	
	while( t-- ) {
	    
	    cin >> n;
	    
	    int* A = new int[ n ];
	    
	    for( i = 0;i < n;i++ ) {
	        cin >> A[ i ];
	    }
	    
	    pos = -1;
	    for( i = 0;i < n - 1;i++ ) {
	        if( A[ i ] < A[ i + 1 ] ) {
	            pos = i;
	        }
	    }
	    
	    if( pos == -1 ) {
	        MergeSort( A, 0, n - 1 );
	    } else {
	        
	        pos2 = -1;
	        for( j = pos + 1;j < n;j++ ) {
	            if( A[ j ] > A[ pos ] ) {
	                pos2 = j;
	            }
	        }
	        
	        tmp = A[ pos ];
	        A[ pos ] = A[ pos2 ];
	        A[ pos2 ] = tmp;
	        
	        for( p = pos + 1, q = n - 1;p < q;p++, q-- ) {
    	        tmp = A[ p ];
    	        A[ p ] = A[ q ];
    	        A[ q ] = tmp;
	        }
	    }
	    
	    for( i = 0;i < n;i++ ) {
	        cout << A[ i ] << " ";
	    }
	    cout << "\n";
	    
	    delete A;
	}
	return 0;
}