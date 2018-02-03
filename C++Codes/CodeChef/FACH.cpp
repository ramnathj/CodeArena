#include <iostream>

using namespace std;

using namespace std;

int main(int argc, char* argv[]) {
	
	ios_base::sync_with_stdio( false );
	
	int *A = new int[ 1002 ];
	int i, n, t;

	A[ 0 ] = 0;
	A[ 1 ] = 1;

	for( i = 2;i < 1002;i++ ) {
		A[ i ] = ( A[ i - 1 ] + A[ i - 2 ] ) % 10;
	}

	cin >> t;

	while( t-- ) {
		
		cin >> n;
		if( A[ n ] == 0 ) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}

	delete A;

	return 0;
}