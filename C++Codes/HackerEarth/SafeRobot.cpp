#include <iostream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio( false );

	int t, n, m, i, j, udCount, lrCount, L, R, U, D;
	bool flag;

	cin >> t;

	while( t-- ) {

		cin >> n >> m;
		char *s = new char[ 20 ];
		cin >> s;
		udCount = lrCount = 0;
		flag = true;

		for( i = 0;s[ i ];i++ ) {
			if( s[ i ] == 'L' ) {
				L = 1;
				R = -1;
				break;
			}else if( s[ i ] == 'R' ) {
				R = 1;
				L = -1;
				break;
			}
		}

		for( i = 0;s[ i ];i++ ) {
			if( s[ i ] == 'U' ) {
				U = 1;
				D = -1;
				break;
			}else if( s[ i ] == 'D' ) {
				D = 1;
				U = -1;
				break;
			}
		}

		for( i = 0;s[ i ];i++ ) {

			switch( s[ i ] ) {
				case 'L' : lrCount += L;
				break;
				case 'R' : lrCount += R;
				break;
				case 'U' : udCount += U;
				break;
				case 'D' : udCount += D;
				break;
			}

			if( ( lrCount > m - 1 ) || ( udCount > n - 1 ) ) {
				flag = false;
				break;
			}
		}

		if( flag ) {
			cout << "safe\n";
		} else {
			cout << "unsafe\n";
		}

		delete s;
	}

	return 0;
}