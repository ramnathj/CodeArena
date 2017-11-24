#include <iostream>

using namespace std;

typedef long long int Lint;

int main() {
	
	ios_base::sync_with_stdio( false );

	Lint t, c, d, l, minVal, maxVal;

	cin >> t;

	while( t-- ) {

		cin >> c >> d >> l;

		if( c <= 2*d ) {
			minVal = 4 * d;
			maxVal = 4 * ( d + c );
		} else {
			minVal = 4 * d + ( c - 2 * d ) * 4;
			maxVal = 4 * ( d + c );
		}

		if( ( l >= minVal ) && ( l <= maxVal ) && ( ( l - minVal ) % 4 == 0 ) ) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}

}
