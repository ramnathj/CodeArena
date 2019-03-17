#include <iostream>
#include <cstdio>

using namespace std;

char s[100];
int A[11][11];
int main() {
	
	register int val, j, k, n, i, tmp;
	
	j = 0;
	
	while( scanf(" %[^\n]s", s ) > 0 ) {
		val = 0;
		k = 0;
		for( i = 0;s[i];i++ ) {
			if( s[ i ] != ' ' ) {
				val = ( val * 10 ) + ( s[ i ] - '0' );
			} else {
				A[ j ][ k ] = val;
				k++;
				val = 0;
			}
		}
		A[ j ][ k++ ] = val;
		j++;
	}

	n = j;
	
	for( i = 0;i < n;i++ ) {
		for( j = 0;j < i;j++ ) {
			tmp = A[ i ][ j ];
			A[ i ][ j ] = A[ j ][ i ];
			A[ j ][ i ] = tmp;
		}
	}
	
	for( j = 0;j < n / 2;j++ ) {

		for( i = 0;i < n;i++ ) {
			tmp = A[ i ][ j ];
			A[ i ][ j ] = A[ i ][ n - j - 1 ];
			A[ i ][ n - j - 1 ] = tmp;
		}
	}


	for( i = 0;i < n;i++ ) {
		for( j = 0;j < n - 1;j++ ) {
			cout << A[ i ][ j ] << " ";
		}
		cout << A[ i ][ j ] << "\n";
	}

	return 0;
}