#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	
	int n, i, j, sum, len, maxVal, pos;
	char ch;

	scanf("%d\n", &n);
	int *A = new int[ 31 ];
	for( i = 0;i < 31;i++ ) {
		A[ i ] = 0;
	}

	for( i = 0;i < n;i++ ) {

		char *s = new char[ 1001 ];
		scanf(" %[^\n]s", s);
		for( len = 0;s[ len ];len++ );
		if( s[ 0 ] == 'M' && s[ 1 ] == ':' ) {

			for( j = 2;j < len; ) {
				ch = s[ j ];
				if( ch >= '0' && ch <= '9' ) {
					sum = 0;

					while( ( j < len ) && ( s[ j ] >= '0' && s[ j ] <= '9' ) ) {
						sum = ( sum * 10 ) + ( s[ j ] - '0' );
						j++;
					}
//					cout << "M: " << sum << "\n";
					A[ sum ]++;
					j++;
				} else {
					j++;
				}
			}
		} else if( s[ 0 ] == 'G' && s[ 1 ] == ':' ) {

			for( j = 2;j < len; ) {
				ch = s[ j ];
				if( ch >= '0' && ch <= '9' ) {
					sum = 0;

					while( ( j < len ) && ( s[ j ] >= '0' && s[ j ] <= '9' ) ) {
						sum = ( sum * 10 ) + ( s[ j ] - '0' );
						j++;
					}
//					cout << "G : " << sum << "\n";
					A[ sum ] += 2;
					j++;
				} else {
					j++;
				}
			}
		} 

		delete s;
	}

	maxVal = A[ 0 ];
	pos = 0;
//	cout << "Value Array\n";
	for( i = 1;i < 31;i++ ) {
//		cout << i << " : " << A[ i ] << "\n";
		if( maxVal < A[ i ] ) {
			maxVal = A[ i ];
			pos = i;
		}
	}
//	cout << "\n";
//	cout << "Pos : " << pos << "\n";
	if( pos == 19 || pos == 20 ) {
		printf("Date\n");
	} else {
		printf("No Date\n");
	}

	return 0;
}
