#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	
	int t, i, sum;

	scanf("%d\n", &t );

	while( t-- ) {
		
		char *s = new char[ 52 ];

		scanf("%s\n", s );
		sum = 0;
		for( i = 0;s[ i ];i++ ) {
			sum += ( s[ i ] - '0' );
		}

		printf("%d\n", sum );
		delete s;
	}
	return 0;
}