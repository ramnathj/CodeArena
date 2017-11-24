#include <iostream>

using namespace std;

int GCD( int a, int b ) {
	if( ( a % b ) == 0 ) {
		return b;
	} else {
		return GCD( b, a % b );
	}
}

int LCM( int a, int b ) {
	return ( a * b ) / GCD( a, b );
}

int phi( int n ) {

	int i, s = n;

	for( i = 2;i <= n;i++ ) {
		if( ( n  % i ) == 0 ) {

			s = ( s * ( i - 1 ) ) / i;

			while( ( n % i ) == 0 ) {
				n = n / i;
			}
 
		}
	}

	return s;
}

int Raise( int a, int b, int c ) {
	
	int v, v2, v3;
	
	if( b == 0 )
		return 1;
	else {
		if( ( b & 0x1 ) == 0 ) {
			v = Raise( a, b >> 1, c );
			v3 = ( v * v ) % c;
		} else {
			v = Raise( a, ( b - 1 ) >> 1, c );
			v2 = ( v * v ) % c;
			v3 = ( a * v2 ) % c;
		}
		return v3;
	}
}

int main() { 
	
	ios_base::sync_with_stdio( false );

	int t, n, i, lcm, s1, s2, val, v1, v2;

	cin >> t;

	while( t-- ) {

		cin >> n;

		int *A = new int[ n ];
		int *B = new int[ n ];

		for( i = 0;i < n;i++ ) {
			cin >> A[ i ];
		}

		for( i = 0;i < n;i++ ) {
			cin >> B[ i ];
		}

		lcm = A[ 0 ];
		for( i = 1;i < n;i++ ) {
			lcm = LCM( lcm, A[ i ] );
		}
		
		s1 = s2 = 0;
		for( i = 0;i < n;i++ ) {
			val = lcm / A[ i ];
			s1 = ( s1 +  val ) % lcm ;
			s2 = ( s2 + ( ( ( B[ i ] % lcm ) * ( val % lcm ) ) % lcm ) ) % lcm;
		}

		if( GCD( s1, lcm ) == 1 ) {
			val = phi( lcm );
			v1 = Raise( s1, val - 1, lcm );
			v2 = ( v1 * s2 ) % lcm;
			cout << v2 << "\n";
		} else {
			cout << "0\n";
		}

		delete B;
		delete A;
	}
	return 0;
}