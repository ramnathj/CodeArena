#include <iostream>
using namespace std;

int main() {
	
	int t, n, m, i, j, count, maxCount;
	
	cin >> t;
	
	while( t-- ) {
	    cin >> n >> m;
	    int** A = new int*[ n ];
	    for( i = 0;i < n;i++ ) {
	        A[ i ] = new int[ m ];
	    }
	    
	    for( i = 0;i < n;i++ ) {
	        for( j = 0;j < m;j++ ) {
	            cin >> A[ i ][ j ];
	        }
	    }

	    for( i = 0;i < n;i++ ) {
	        for( j = 0;j < m;j++ ) {
	            cout << A[ i ][ j ] << " ";
	        }
	        cout << "\n";
	    }
	    
	    i = 0;
	    j = m - 1;
	    
	    maxCount = 0;
	    
	    while( j >= 0 ) {
	        
	        count = maxCount;
	        while( ( j >= 0 ) && A[ i ][ j ] ) {
	            cout << "Visited " << "A[ " << i << " ][ " << j << " ]\n";
	            count++;
	            j--;
	        }
	        
	        maxCount = max( maxCount, count );
	        
	        if( j >= 0 ) {
	           
	           while( ( i < n ) && !A[ i ][ j ] ) {
	               cout << "Visited " << "A[ " << i << " ][ " << j << " ]\n";
	               i++;
	           }
	        }
	    }
	    
	    cout << maxCount << "\n";
	    
	    for( i = 0;i < n;i++ ) {
	        delete A[ i ];
	    }
	    delete A;
	}
	return 0;
}