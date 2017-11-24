#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio( false );

	int t, n, i, pos, count, sum;

	scanf("%d\n", &t);

	while( t-- ) {

		char *s = new char[ 10000 ];

		scanf(" %[^\n]s", s );

		pos = 0;
		count = 0;
		sum = 0;
		for( i = 0;s[ i ];i++ ) {
		
			if( s[ i ] == ' ' ) {
				pos = 0;
				count++;
			} else {
				if( s[ i ] == '0' ) {
					sum += 35;
				} else if( s[ i ] >= '1' && s[ i ] <= '9' ) {
					sum += ( 25 + s[ i ] - '0' );
				} else if( s[ i ] >= 'A' && s[ i ] <= 'Z' ) {
					sum += ( 36 + s[ i ] - 'A' );
				} else if( s[ i ] >= 'a' && s[ i ] <= 'z' ) {
					sum += ( s[ i ] -'a');
				}
				sum += pos;
				pos++;
			}
		}
		count++;
		cout << sum * count << "\n";

		delete s;
	}
	return 0;
}