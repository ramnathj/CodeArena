#include <iostream>

using namespace std;

typedef long long int Lint;

Lint DigitSum( Lint n ) {
		
	Lint c = 0;
	while( n > 0 ) {
		c += ( n % 10 );
		n /= 10;
	}

	return c;
}

bool Check( Lint n, Lint val ) {
	
	Lint s1, s2;

	s1 = DigitSum( n );
	s2 = DigitSum( s1 );

	return ( ( n + s1 + s2 ) == val );
}

int main() {
	
	ios_base::sync_with_stdio( false );

	Lint n, i, ct = 0;

	cin >> n;

	for( i = n - 100;i <= n;i++ ) {
		if( Check( i, n ) ) {
			ct++;
		}
	}

	cout << ct << "\n";

	return 0;
}