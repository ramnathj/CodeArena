#include <iostream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio( false );

	int t, n, i, sum;

	cin >> t;

	while( t-- ) {

		cin >> n;

		int *A = new int[ n ];
		int *B = new int[ n ];
		int *C = new int[ n ];

		for( i = 0;i < n;i++ ) {
			cin >> A[ i ];
		}

		B[ 0 ] = A[ 0 ];
		C[ n - 1 ] = A[ n - 1 ];

		for( i = 1;i < n;i++ ) {
			B[ i ] = max( A[ i ], B[ i - 1 ] );
		}

		for( i = n - 2;i >= 0;i-- ) {
			C[ i ] = max( C[ i + 1 ], A[ i ] );
		}

		sum = 0;
		for( i = 0;i < n;i++ ) {
			sum += ( min( B[ i ], C[ i ] ) - A[ i ] );
		}

		cout << sum << "\n";

		delete A;
		delete B;
		delete C;
	}
	return 0;
}