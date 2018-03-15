#include <iostream>

using namespace std;

int main() {
	
	int t, n, m, i, j;
	char ch;

	cin >> t;

	while( t-- ) {
		cin >> n >> m;

		for( i = 1;i <= n;i++ ) {
			
			if( i & 0x1 ) {
				ch = '*';
			} else {
				ch = '.';
			}

			for( j = 1;j <= m;j++ ) {
				cout << ch;
				ch = ( ch == '.' ) ? '*' : '.';
			}

			cout << "\n";
		}

		cout << "\n";
	}

	return 0;
}
