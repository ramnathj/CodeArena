#include <iostream>
using namespace std;

int main()
{   
    ios_base::sync_with_stdio( false );
    int t, n, i, j;
    bool flag;
    
    cin >> t;
    
    while( t-- ) {
        cin >> n;
        
        int **A = new int*[ n ];
        for( i = 0;i < n;i++ ) {
            A[ i ] = new int[ n ];
        }
        
        for( i = 0;i < n;i++ ) {
            for( j = 0;j < n;j++ ) {
                cin >> A[ i ][ j ];
            }
        }
        
        flag = true;    
        for( i = 0;i < n;i++ ) {
            for( j = 0;j <= i;j++ ) {
                if( A[ i ][ j ] != A[ j ][ i ] ) {
                    flag = false;
                    break;    
                }
            }
            if( !flag ) {
                break;
            }
        }
        
        if( flag ) {
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
