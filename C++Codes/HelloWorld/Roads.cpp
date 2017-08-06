#include <iostream>
#include <map>

using namespace std;

typedef long long int Lint;

string toString( Lint n ) {
    string s = "", s2;
    char ch;
    
    while( n > 0 ) {
        ch = '0' + ( n % 10 );
        s2 = ch;
        s = s2 + s;
        n /= 10;
    }
    return s;
}

int main() {
    
    ios::sync_with_stdio(false);
    Lint n, m, v, q, i, e, a, b, ct, minVal, maxVal;
    string s;
    
    map<string, bool> M;
    
    cin >> n;
    e = n - 1;
    
    cin >> m;
    cin >> v;
    ct = 0;
    while( m-- ) {
        cin >> a >> b;
        minVal = min( a, b );
        maxVal = max( a, b );
        s = toString( minVal ) +","+ toString( maxVal );
        if( !M[ s ] ) {
            M[ s ] = true;
            ct++;
        }
    }
    cin >> q;
    cin >> v;
    
    while( q-- ) {
        cin >> a >> b;
        minVal = min( a, b );
        maxVal = max( a, b );
        s = toString( minVal ) +","+ toString( maxVal );
        if( !M[ s ] ) {
            M[ s ] = true;
            ct++;
        }
        cout << e - ct << " ";
    }
    cout << "\n";
    
    return 0;
}