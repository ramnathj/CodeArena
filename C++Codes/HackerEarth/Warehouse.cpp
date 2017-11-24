#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int Lint;

int main() {
    
    ios_base::sync_with_stdio( false );
    
    Lint n, m, i, p, q, sum;
    
    cin >> n >> m;

    vector<pair<Lint,Lint> > A( m );
    
    for( i = 0;i < m;i++ ) {
        cin >> p >> q;
        A[ i ].first = q;
        A[ i ].second = p;
    }
    
    sort( A.rbegin(), A.rend() );
    
    sum = 0;
    
    for( i = 0;i < m;i++ ) {
        if( A[ i ].second <= n ) {
            sum += ( A[ i ].first * A[ i ].second );
            n -= A[ i ].second;
        } else {
            sum += ( n * A[ i ].first );
            break;
        }
    }
    
    cout << sum << "\n";
    
    return 0;
}