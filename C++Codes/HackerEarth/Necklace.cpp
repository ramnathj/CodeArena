#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    
    int t, n, i, len, maxLen;
    char prev;
    scanf("%d", &t );
    
    while( t-- ) {
        cin.ignore();
        char *s = new char[ 1010 ];
        scanf("%s", s );

        for( n = 0;s[ n ];n++ );
        
        prev = s[ 0 ];
        len = maxLen = 1;
        
        for( i = 1;i < n; ) {
            if( s[ i ] != prev ) {
                while( ( i < n ) && ( s[ i ] != prev ) ) {
                    prev = s[ i ];
                    i++;
                    len++;
                }
                maxLen = max( len, maxLen );
                if( i != n ) {
                    prev = s[ i ];
                    len = 1;
                    i++;
                } else {
                    break;
                }
            } else {
                maxLen = max( len, maxLen );
                prev = s[ i ];
                len = 1;
                i++;
                
            }
        }
        
        printf("%d\n", n - maxLen );
        
        delete s;
    }

    return 0;
}