#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define sz 10000

using namespace std;

typedef long long int Lint;

int main() {
	
//	ios_base::sync_with_stdio( false );
	
	Lint t, n, i, val;
	bool flag;

	vector<Lint> A( sz );
	
	A[ 0 ] = 0;

	for( i = 1;i < sz;i++ )
		A[ i ] = A[ i - 1 ] + i;

	scanf("%lld", &t );

	while( t-- ) {

		scanf("%lld", &n );
		if( n == 1 || n == 2 )
			printf("No\n");
		else {

			flag = false;
			for( i = 0;i < sz;i++ ) {
				if( A[ i ] > n ) {
					break;
				} else {
					val = A[ i ] + n;
					if( binary_search( A.begin(), A.end(), val ) ) {
						flag = true;
						break;
					}
				}
			}
			if( flag )
				printf("Yes\n");
			else
				printf("No\n");
		}
	}	

	return 0;
}
