#include <iostream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio( false );

	int t, n, i, pairCount, val, val2, maxVal;

	cin >> t;

	while( t-- ) {

		cin >> n;
		int *B = new int[ n ];
		int *G = new int[ n ];

		for( i = 0;i < n;i++ ) {
			cin >> B[ i ];
			B[ i ] -= 1;
		}

		for( i = 0;i < n;i++ ) {
			cin >> G[ i ];
			G[ i ] -= 1;
		}

		int *BCount = new int[ n ];
		int *GCount = new int[ n ];
		pairCount = 0;

		for( i = 0;i < n;i++ ) {
			BCount[ i ] = 0;
			GCount[ i ] = 0;
		}

		for( i = 0;i < n;i++ ) {
			val = G[ B[ i ] ];
			if( val != i ) {
				BCount[ val ]++;
				val2 = G[ B[ val ] ];
				if( val2 == i ) {
					pairCount++;
				}
			}
		}
		
		for( i = 0;i < n;i++ ) {
			val = B[ G[ i ] ];
			if( val != i ) {
				GCount[ val ]++;
				val2 = B[ G[ val ] ];
				if( val2 == i ) {
					pairCount++;
				}
			}
		}

		maxVal = 0;
		for( i = 0;i < n;i++ ) {
			maxVal = max( maxVal, BCount[ i ] );
		}

		for( i = 0;i < n;i++ ) {
			maxVal = max( maxVal, GCount[ i ] );
		}

		cout << maxVal << " " << pairCount / 2 << "\n";
		
		delete BCount;
		delete GCount;
		delete G;
		delete B;

	}
	return 0;
}