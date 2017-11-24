#include <iostream>

using namespace std;

int GCD( int a, int b ) {
	
	if( ( a % b ) == 0 ) {
		return b;
	} else {
		return GCD( b, a % b );
	}
}

int main() {
	
	ios_base::sync_with_stdio( false );

	int t, m, n, g, l;

	cin >> t;

	while( t-- ) {

		cin >> m >> n;
		g = GCD( m, n );
		l = ( m * n ) / g;
		cout << ( l / m ) - 1 << " " << ( l / n ) - 1 << "\n";
	}

}