#include <iostream>

using namespace std;

bool isEqual( char* s1, const char* s2, int n1, int n2 ) {
	
	int i;

	if( n1 != n2 ) {
		return false;
	} 
	for( i = 0;i < n1;i++ ) {
		if( s1[ i ] != s2[ i ] ) {
			return false;
		}
	}
	return true;
}

char convert( char* s, int len ) {

	if( isEqual( s, "ONE", len, 3 ) ) {
		return '1';
	} else if( isEqual( s, "TWO", len, 3 ) ) {
		return '2';
	} else if( isEqual( s, "THREE", len, 5 ) ) {
		return '3';
	} else if( isEqual( s, "FOUR", len, 4 ) ) {
		return '4';
	} else if( isEqual( s, "FIVE", len, 4 ) ) {
		return '5';
	} else if( isEqual( s, "SIX", len, 3 ) ) {
		return '6';
	} else if( isEqual( s, "SEVEN", len, 5 ) ) {
		return '7';
	} else if( isEqual( s, "EIGHT", len, 5 ) ) {
		return '8';
	} else if( isEqual( s, "NINE", len, 4 ) ) {
		return '9';
	} else if( isEqual( s, "ZERO", len, 4 ) ) {
		return '0';
	} else if( isEqual( s, "PLUS", len, 4 ) ) {
		return '+';
	} else if( isEqual( s, "MINUS", len, 5 ) ) {
		return '-';
	}
}

int main() {
	
	ios_base::sync_with_stdio( false );

	int t, n, i, len, sum, sign;
	char ch;

	cin >> t;

	while( t-- ) {

		cin >> n;
		sign = 1;
		sum = 0;
		for( i = 1;i <= n;i++ ) {
			char *s = new char[ 10 ];
			cin >> s;
			
			for( len = 0;s[ len ];len++ );

			if( i & 0x1 ) {
				ch = convert( s, len );
				sum += ( sign * ( ch - '0') );
			} else {
				ch = convert( s, len );
				if( ch == '+') {
					sign = 1;
				} else {
					sign = -1;
				}
			}
			delete s;
		}

		cout << sum << "\n";
	}

	return 0;
}