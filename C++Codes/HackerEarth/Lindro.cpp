#include <iostream>

using namespace std;


int main() {
	
	ios_base::sync_with_stdio( false );

	int t, n, i, even, odd;

	cin >> t;

	while( t-- ) {

		char *s = new char[ 10001 ];
		cin >> s;

		for( n = 0;s[ n ];n++ );

		for( i = 0;i < n;i++ ) {
			if( ( s[ i ] >= 'A' ) && ( s[ i ] <= 'Z' ) ) {
				s[ i ] = s[ i ] + 32;
			}
		}

		int *B = new int[ 26 ];
		for( i = 0;i < 26;i++ ) {
			B[ i ] = 0;
		}

		for( i = 0;i < n;i++ ) {
			B[ s[ i ] - 'a' ]++;
		}

		even = 0;
		odd = 0;

		for( i = 0;i < 26;i++ ) {
			if( B[ i ] & 0x1 ) {
				odd++;
			} else {
				even++;
			}
		}

		if( odd > 1 ) {
			cout << "No\n";
		} else {	
			cout << "Yes\n";
		}

		delete s;
		delete B;

	}

	return 0;
}