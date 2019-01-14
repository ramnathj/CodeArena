#include <iostream>

using namespace std;

int n;
int m;

void print(int** A ) {
	
	int i, j;

	for( i = 0;i < n;i++ ) {
		for( j = 0;j < n;j++ ) {
			cout << A[ i ][ j ] << " ";
		}
		cout << "\n";
	}
}

int** rotate(int **M) {
	
	int i, j;
	int **B = new int*[ n ];
	
	for( i = 0;i < n;i++ ) {
		B[ i ] = new int[ n ];
	}

	for( i = 0;i < n;i++ ) {
		for( j = 0;j < n;j++ ) {
			B[ i ][ j ] = M[ j ][ i ];
		}
	}
	for( i = 0;i < n / 2;i++ ) {
		for( j = 0;j < n;j++ ) {
			swap( B[ j ][ i ], B[ j ][ n - i - 1 ] );	
		}
	}

	return B;
}

int main() {
	
	int i, j, p;

	cin >> n >> m;

	int** A = new int*[ n ];
	for( i = 0;i < n;i++ ) {
		A[ i ] = new int[ n ];
	}

	for( i = 0;i < n;i++ ) {
		for( j = 0;j < n;j++ ) {
			cin >> A[ i ][ j ];
		}
	}
	
	int** B = rotate(A);
	int** C = rotate(B);	
	int** D = rotate(C);	

	while( m-- ) {
		
		cin >> p;
		p = p % 360;

		switch( p ) {
			case 0 : print(A);
			break;
			case 90 : print(B);
			break;
			case 180 : print(C);
			break;
			case 270 : print(D);
			break;
		}
		cout << "\n";
	}

	for( i = 0;i < n;i++ ) {
		delete A[ i ];
		delete B[ i ];
		delete C[ i ];
		delete D[ i ];
	}
	delete A;
	delete B;
	delete C;
	delete D;

	return 0;
}
