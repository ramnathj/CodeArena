#include <iostream>
#include <stdlib.h>

using namespace std;

int Cost( int A[][3], int B[][3] ) {

	int sum = 0, i, j;

	for( i = 0;i < 3;i++ ) {

		for( j = 0;j < 3;j++ ) {
			sum += (int)abs( A[ i ][ j ] - B[ i ][ j ] );
		}
	}

	return sum;
}
int main() {
	
	ios_base::sync_with_stdio( false );

	int i, j;

	int A[ 3 ][ 3 ];
	int B[ 3 ][ 3 ] =  { { 2, 7, 6 },{ 9, 5, 1 },{ 4, 3, 8 } };
	int C[ 3 ][ 3 ] = { { 4, 9, 2 }, { 3, 5, 7 }, { 8, 1, 6 } };

	for( i = 0;i < 3;i++ ) {
		for( j = 0;j < 3;j++ ) {
			cin >> A[ i ][ j ];
		}
	}

	cout << Cost( A, C ) << "\n";

	return 0;
}
