#include <iostream>
#define DIVI 1000000007

using namespace std;

typedef unsigned long long int Lint;

Lint Raise( Lint a, Lint b, Lint c ) {
    
    Lint v, v2, v3;
    
    if( b == 0 )
        return 1;
    else {
        if( ( b & 0x1 ) == 0 ) {
            v = Raise( a, b >> 1, c );
            v2 = ( v * v ) % c; 
        } else {
            v = Raise( a, ( b - 1 ) >> 1, c );
            v3 = ( v * v ) % c;
            v2 = ( a * v3 ) % c;
        }
        return v2;
    }
}

int main() {
    
    ios_base::sync_with_stdio( false );
    
    Lint a, b, t, v, v1, v2, v3, v4;
    
    cin >> a >> b >> t;
    v = a + b;
    
    v1 = Raise( v, t, DIVI );
    v2 = Raise( 2, DIVI - 2, DIVI );
    v3 = Raise( v2, t, DIVI );
    v4 = ( v1 * v3 ) % DIVI;
    
    cout << v4 << "\n";
    
    return 0;
}
