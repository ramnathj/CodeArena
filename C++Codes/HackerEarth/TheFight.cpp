#include <iostream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio( false );

	int t, n, i, count, fCount;

	cin >> t;

	while( t-- ) {

		string s;
		cin >> s;
		n = s.length();
		count = 0;
		fCount = 0;
		for( i = 0;i < n;) {

			if( s[ i ] == '1' ) {

				while( ( i < n ) && ( s[ i ] == '1' ) ) {
					i++;
					count++;
				}
				fCount = max( fCount, count );
				if( i != n ) {
					count = 0;
					i++;
				}
			} else {
				i++;
			}
		}

		cout << fCount << "\n"; 
	}
	return 0;
}