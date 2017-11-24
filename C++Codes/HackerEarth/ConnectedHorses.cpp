#include <iostream>
#define DIVI 1000000007
#define sz 1000001

using namespace std;

typedef long long int Lint;

int n;
int m;

bool isSafe( int i, int j ) {

	if( ( i >= 0 ) && ( i < n ) && ( j >= 0 ) && ( j < m ) ) {
		return true;
	}
	return false;
}

int DFS( int **A, bool **visit, int i, int j ) {
	
	visit[ i ][ j ] = true;
	int count = 1;
	if( isSafe( i + 1, j + 2 ) && A[ i + 1 ][ j + 2 ] && !visit[ i + 1 ][ j + 2 ] ) {
		count += DFS( A, visit, i + 1, j + 2 );
	}	
	if( isSafe( i + 1, j - 2 ) && A[ i + 1 ][ j - 2 ] && !visit[ i + 1 ][ j - 2 ] ) {
		count += DFS( A, visit, i + 1, j - 2 );
	}	
	if( isSafe( i - 1, j + 2 ) && A[ i - 1 ][ j + 2 ] && !visit[ i - 1 ][ j + 2 ] ) {
		count += DFS( A, visit, i - 1, j + 2 );
	}	
	if( isSafe( i - 1, j - 2 ) && A[ i - 1 ][ j - 2 ] && !visit[ i - 1 ][ j - 2 ] ) {
		count += DFS( A, visit, i - 1, j - 2 );
	}	
	if( isSafe( i - 2, j - 1 ) && A[ i - 2 ][ j - 1 ] && !visit[ i - 2 ][ j - 1 ] ) {
		count += DFS( A, visit, i - 2, j - 1 );
	}	
	if( isSafe( i - 2, j + 1 ) && A[ i - 2 ][ j + 1 ] && !visit[ i - 2 ][ j + 1 ] ) {
		count += DFS( A, visit, i - 2, j + 1 );
	}	
	if( isSafe( i + 2, j - 1 ) && A[ i + 2 ][ j - 1 ] && !visit[ i + 2 ][ j - 1 ] ) {
		count += DFS( A, visit, i + 2, j - 1 );
	}	
	if( isSafe( i + 2, j + 1 ) && A[ i + 2 ][ j + 1 ] && !visit[ i + 2 ][ j + 1 ] ) {
		count += DFS( A, visit, i + 2, j + 1 );
	}	
	return count;
}

int main() {
	
	ios_base::sync_with_stdio( false );

	int t, q, i, j, count, a, b;
	Lint val, pro;
	Lint B[ sz ];

	B[ 0 ] = 1;
	
	for( i = 1;i < sz;i++ ) {
		B[ i ] = ( B[ i - 1 ] * i ) % DIVI;
	}

	cin >> t;

	while( t-- ) {

		cin >> n >> m >> q;

		int **A = new int*[ n ];
		bool **visit = new bool*[ n ];

		for( i = 0;i < n;i++ ) {
			A[ i ] = new int[ m ];
			visit[ i ] = new bool[ m ];
		}

		for( i = 0;i < n;i++ ) {
			for( j = 0;j < m;j++ ) {
				A[ i ][ j ] = 0;
				visit[ i ][ j ] = false;
			}
		}

		while( q-- ) {
			cin >> a >> b;
			A[ a - 1 ][ b - 1 ] = 1;
		}

		pro = 1;
		for( i = 0;i < n;i++ ) {

			for( j = 0;j < m;j++ ) {
				if( A[ i ][ j ] && !visit[ i ][ j ] ) {
					count = DFS( A, visit, i, j );
					val = B[ count ];
					pro = ( pro * val ) % DIVI;
				}
			}
		}

		cout << pro << "\n";

		for( i = 0;i < n;i++ ) {
			delete A[ i ];
			delete visit[ i ];
		}
		delete A;
		delete visit;
	}

	return 0;
}
