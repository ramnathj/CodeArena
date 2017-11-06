#include <iostream>
#define sz 100001

using namespace std;

int main() {
	
	ios_base::sync_with_stdio( false );

	int t, n, i, countA, countB, prev;
	cin >> t;

	while( t-- ) {
		
		char *s = new char[ sz ];
		cin >> s;

		for( n = 0;s[ n ];n++ );

		int* A = new int[ n ];
		int *B = new int[ n ];
		
		prev = -1;
		
		for( i = 0;i < n;i++ ) {
			if( s[ i ] == 'A' ) {
				prev = 1;
			} else if( s[ i ] == 'B' ) {
				prev = 2;
			}
				A[ i ] = prev;
		}		

		prev = -1;
		
		for( i = n - 1;i >= 0;i-- ) {
			if( s[ i ] == 'A' ) {
				prev = 1;
			} else if( s[ i ] == 'B' ) {
				prev = 2;
			}
				B[ i ] = prev;
		}


		countA = countB = 0;
		for( i = 0;i < n;i++ ) {
			if( A[ i ] == B[ i ] ) {
				if( A[ i ] == 1 ) {
					countA++;
				} else if( A[ i ] == 2 ) {
					countB++;
				}
			}
		}

		cout << countA << " " << countB << "\n";

		delete s;
		delete A;
		delete B;
	}

	return 0;
}
