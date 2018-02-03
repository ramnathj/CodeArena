#include <iostream>

using namespace std;

typedef long long int Lint;

int main(int argc, char* argv[]) {
	
	ios_base::sync_with_stdio( false );

	Lint t, n, q, i, p, val, v;

	cin >> t;
	
	while( t-- ) {
		
		cin >> n >> q;
		p = 1;

		for( i = 0;i < n;i++ ) {
			cin >> v;
			p *= v;		
		}

		while( q-- ) {
			cin >> val;
			cout << ( val / p ) << " ";
		}

		cout << "\n";
	}

	return 0;
}