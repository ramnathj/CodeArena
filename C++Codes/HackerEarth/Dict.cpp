#include <iostream>

using namespace std;

typedef long long int Lint;

Lint fact( Lint n ) {
	Lint p = 1, i;
	for( i = 1;i <= n;i++ ) {
		p *= i;
	}

	return p;
}

Lint Count( char* s, int pos, int n ) {
	
	int ct = 0, i;
	char ch = s[ pos ];
	for( i =  pos + 1;i < n;i++ ) {
		if( s[ i ] < ch ) {
			ct++;
		}
	}

	return ct;
}

int main() {
	
	ios_base::sync_with_stdio( false );

	Lint t, n, i, mul, sum, dup;

	cin >> t;

	while( t-- ) {

		char *s = new char[ 21 ];
		cin >> s;

		for( n = 0;s[ n ];n++ );

		mul = fact( n );
		dup = mul;
		sum = 1;
		for( i = 0;i < n - 1;i++ ) {
			mul /= ( n - i );
			sum += ( mul * Count( s, i, n ) );
		}

		cout << dup - sum << "\n";

		delete s;
	}

	return 0;
}
