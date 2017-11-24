#include <iostream>
#include <vector>

using namespace std;

bool checkMatrix( char** A, int n ) {

    int i, j;

    for( i = 0;i < n;i++ ) {

        for( j = 0;j < n / 2;j++ ) {
            if( A[ i ][ j ] != A[ i ][ n - j - 1 ] ) {
                return false;
            }
        }
    }

    for( i = 0;i < n;i++ ) {
        for( j = 0;j < n / 2;j++ ) {
            if( A[ j ][ i ] != A[ n - j - 1 ][ i ] ) {
                return false;
            }
        }
    }

    return true;
}

int main()
{   
    ios_base::sync_with_stdio( false );
    int t, n, i, j;
    bool flag;
    
    cin >> t;
    
    while( t-- ) {
        cin >> n;
        
        char **A = new char*[ n ];
        for( i = 0;i < n;i++ ) {
            A[ i ] = new char[ n ];
        }
        
        for( i = 0;i < n;i++ ) {
            for( j = 0;j < n;j++ ) {
                cin >> A[ i ][ j ];
            }
        }
        
        if( checkMatrix( A, n ) ) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
        for( i = 0;i < n;i++ ) {
            delete A[ i ];
        }
        
        delete A;
    }
    return 0;
}