#include <iostream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio( false );

	int n, i, count, maxVal;

	cin >> n;
	int *A = new int[ n ];

	for( i = 0;i < n;i++ ) {

		cin >> A[ i ];
	}

	maxVal = A[ 0 ];
	for( i = 1;i < n;i++ )
		maxVal = max( maxVal, A[ i ] );

	count = 0;
	for( i = 0;i < n;i++ ) {
		if( A[ i ] == maxVal )
			count++;
	}

	cout << count << "\n";

	delete A;

	return 0;
}