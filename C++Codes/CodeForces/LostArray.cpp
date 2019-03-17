#include <iostream>
#define sz 100005
#define MAXV 1000000000009

using namespace std;

typedef long long int Lint;

Lint A[sz];
Lint L[sz];
Lint R[sz];

void Merge( Lint p, Lint q, Lint r ) {
	Lint n1, n2, i, j, k;

	n1 = q - p + 1;
	n2 = r - q;

	for( i = 1;i <= n1;i++ ) {
		L[ i ] = A[ p + i - 1 ];
	}
	L[ n1 + 1 ] = MAXV;

	for( j = 1;j <= n2;j++ ) {
		R[ j ] = A[ q + j ];
	}
	R[ n2 + 1 ] = MAXV;

	i = j = 1;
	for( k = p;k <= r;k++ ) {
		if( L[ i ] <= R[ j ] ) {
			A[ k ] = L[ i ];
			i++;
		} else {
			A[ k ] = R[ j ];
			j++;
		}
	}
}

void MergeSort( Lint p, Lint r ) {

	Lint q;
	if( p < r ) {
		q = ( p + r ) >> 1;
		MergeSort( p, q );
		MergeSort( q + 1, r );
		Merge( p, q, r );
	}
}

int main() {
	
	Lint t, n, i, val;

	cin >> t;

	while( t-- ) {
		cin >> n;

		val = 1;
		for( i = 1;i <= n;i++ ) {
			val = val << 1;
		}

		for( i = 0;i < val;i++ ) {
			cin >> A[ i ];
		}

		MergeSort( 0, val - 1 );

		for( i = 1;i < n;i++ ) {
			cout << A[ i ] << " ";
		}
		cout << A[ i ] << "\n";
	}
	return 0;
}
