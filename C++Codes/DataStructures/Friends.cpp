#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int Lint;

int main() {

    ios::sync_with_stdio(false);
    int t, n, i, k;
    Lint sum;
    
    cin >> t;
    
    while( t-- ) {
        cin >> n;
        vector<int> A( n );
        for( i = 0;i < n;i++ ) {
            cin >> A[ i ];
        }
        sort( A.begin(), A.end() );
        cin >> k;
        sum = 0;
        for( i = 0;i < k;i++ ) {
            sum += A[ i ];
        }
        sum += ( ( n - k ) * A[ k - 1 ] );
        cout << sum << "\n";
    } 
}