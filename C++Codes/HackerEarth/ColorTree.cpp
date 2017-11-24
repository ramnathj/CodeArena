#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio( false );

	int n, c, i, val, k;

	cin >> n >> c;
	vector<int> par( n ), C( n );
	par[ 0 ] = -1;

	for( i = 0;i < n - 1;i++ ) {
		cin >> val;
		par[ i + 1 ] = val - 1; 
	}

	for( i = 0;i < n;i++ ) {
		cin >> C[ i ];
	}

/*	for( i = 0;i < n;i++ ) {
		cout << i << "->" << par[ i ] << "\n"; 
	}
*/
	for( k = 0;k < n;k++ ) {
		val = C[ k ];
		i = k;
		while( par[ i ] != -1 && val != C[ par[ i ] ] ) {
			i = par[ i ];
		}
		if( par[ i ] != -1 && val == C[ par[ i ] ] ) {
			cout << par[ i ] + 1 << " ";
		} else {
			cout << "-1 ";
		}
	} 

	cout << "\n";

 	return 0;
}
