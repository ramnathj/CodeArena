#include <iostream>
#include <map>

#define MAXV 1000000007

typedef long long int Lint;

using namespace std;

Lint sumDigits( Lint n ) {
    
    Lint s = 0, r;
    
    while( n > 0 ) {
        r = n % 10;
        s += r;
        n /= 10;
    }
    
    return s;
}

int main()
{
    
    ios_base::sync_with_stdio( false );
    
    Lint n, i, v, val, coll, maxVal, minVal, maxVal2;
    
    cin >> n;
    
    map<Lint, Lint> M;
    coll = 0;
    
    for( i = 0;i < n;i++ ) {
        cin >> v;
        val = v ^ sumDigits( v );
        if( M[ val ] == 0 ) {
          M[ val ] = 1;  
        } else {
            M[ val ]++;
            coll++;
        }
    }
    
    map<Lint, Lint> :: iterator it;
    maxVal = -1;
    maxVal2 = -1;
    for( it = M.begin();it != M.end();it++ ) {
        maxVal = max( maxVal, it->first );
        maxVal2 = max( maxVal2, it->second );
    }
        
    if( coll == 0 ) {
        cout << maxVal << " " << coll << "\n";
    } else {
    
        minVal = MAXV;
        for( it = M.begin();it != M.end();it++ ) {
            if( maxVal2 == it->second ) {
                minVal = it->first;
                break;
            }
        }
        cout << minVal << " " << coll << "\n";
    }
    
    return 0;
}
