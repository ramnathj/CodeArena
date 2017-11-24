#include <iostream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio( false );

	int n, i, k, val;

	cin >> n;

	char* s = new char[ n + 1 ];
	cin >> s;
	cin >> k;

	for( i = 0;i < n;i++ ) {

		if( ( s[ i ] >= 'A' ) && ( s[ i ] <= 'Z' ) ) {
			val = ( s[ i ] - 'A' + k ) % 26;
			s[ i ] = 'A' + val;
		} else if( ( s[ i ] >= 'a' ) && ( s[ i ] <= 'z' ) ) {
			val = ( s[ i ] - 'a' + k ) % 26;
			s[ i ] = 'a' + val;			
		}
	}

	cout << s << "\n";

	return 0;
}
