#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;

typedef long long int Lint;

int main() {
	
	ios_base::sync_with_stdio( false );

	Lint t, n, q, i, val, v;

	scanf("%lld", &t );

	while( t-- ) {

		scanf("%lld %lld", &n, &q );

		set<Lint> S;

		for( i = 0;i < n;i++ ) {
			scanf( "%lld", &v );
			S.insert( v );
		}

		while( q-- ) {

			scanf( "%lld", &val );
			
			if( S.find( val ) != S.end() ) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
			S.insert( val );
		}
	}

	return 0;
}