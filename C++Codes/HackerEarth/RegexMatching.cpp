#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	
	int t, n1, n2, i, j;

	char *s1 = NULL;
	char *s2 = NULL;
	bool flag = false, flag2 = false;

	scanf("%d", &t );

	while( t-- ) {

		s1 = new char[ 1001 ];
		s2 = new char[ 1001 ];

		scanf("%s", s1 );
		scanf("%s", s2 );

		for( n1 = 0;s1[ n1 ];n1++ );
		for( n2 = 0;s2[ n2 ];n2++ );

		if( ( s1[ 0 ] == '^' ) && ( n2 + 1 >= n1 ) ) {

			flag = true;

			for( i = 1;i < n1;i++ ) {
				if( s1[ i ] != s2[ i - 1 ] ) {
					flag = false;
					break;
				}
			}

		} else if( ( s1[ n1 - 1 ] == '$') && ( n2 + 1 >= n1 ) ) {

			for( i = 1;i < n1;i++ ) {

				flag = true;
				if( s2[ n2 - i ] != s1[ n1 - i - 1 ] ) {
					flag = false;
					break;
				}				
			}

		} else {

			flag = false;
			if( n2 >= n1 ) {

				for( i = 0;i <= n2 - n1;i++ ) {
					flag2 = true;
					for( j = 0;j < n1;j++ ) {
						if( s2[ i + j ] != s1[ j ] ) {
							flag2 = false;
							break;
						}
					}
					if( flag2 ) {
						flag = true;
						break;
					}
				}
			}
		}

		if( flag )
			cout << "1\n";
		else
			cout << "0\n";


		delete s1;
		delete s2;
	}

	return 0;
}