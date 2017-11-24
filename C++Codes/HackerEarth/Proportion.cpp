#include <iostream>

using namespace std;

bool Permute( int A[], int i, int n ) {
	
	int k;

	if( i == n ) {

		if( A[ 0 ]*A[ 3 ] == A[ 1 ]*A[ 2 ] )
			return true;
	}

	for( k = i;k <= n;k++ ) {
		swap( A[ i ], A[ k ] );
		if( Permute( A, i + 1, n ) )
			return true;
		swap( A[ i ], A[ k ] );
	}

	return false;
}

int main() {
	
	ios_base::sync_with_stdio( false );

	int A[ 4 ];
	cin >> A[ 0 ] >> A[ 1 ] >> A[ 2 ] >> A[ 3 ];

	if( Permute( A, 0, 3 ) )
		cout << "Possible\n";
	else
		cout << "Impossible\n";

	return 0;
}