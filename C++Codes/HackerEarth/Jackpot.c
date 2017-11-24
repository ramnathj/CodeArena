#include <stdio.h>
#include <malloc.h>

int maxim( int a, int b ) {
	
	return ( ( a > b ) ? a : b );
}

int main() {
	
	int n, i, maxVal, fMaxVal;

	scanf("%d", &n );

	while( n ) {

		int *A = (int*)malloc( n * sizeof(int) );

		for( i = 0;i < n;i++ )
			scanf("%d", &A[ i ] );

		maxVal = A[ 0 ];
		fMaxVal = A[ 0 ];

		for( i = 1;i < n;i++ ) {
			maxVal = maxim( maxVal + A[ i ], A[ i ] );
			fMaxVal = maxim( fMaxVal, maxVal );
		}

		if( fMaxVal > 0 )
			printf("The maximum winning streak is %d.\n", fMaxVal );
		else
			printf("Losing streak.\n");

		free( A );

		scanf("%d", &n );

	}

	return 0;
}
