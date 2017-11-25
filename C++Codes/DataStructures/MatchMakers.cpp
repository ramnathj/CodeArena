#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio( false );
    int t, n, i, count;
    
    cin >> t;
    
    while( t-- ) {
        cin >> n;
        vector<int> A( n ), B( n );
        
        for( i = 0;i < n;i++ ) {
            cin >> A[ i ];
        }
        
        for( i = 0;i < n;i++ ) {
            cin >> B[ i ];
        }
        
        sort( A.begin(), A.end() );
        sort( B.rbegin(), B.rend() );
        
        count = 0;
        for( i = 0;i < n;i++ ) {
            if( ( A[ i ] % B[ i ] == 0 ) || ( B[ i ] % A[ i ] == 0 ) ) {
                count++;
            }
        }
        
        cout << count << "\n";
    }
    return 0;
}
