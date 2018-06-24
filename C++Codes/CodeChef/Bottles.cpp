#include <iostream>
#include <stdio.h>

using namespace std;

int min( int a, int b ) {
	return ( a < b ? a : b );
}

int main() {
	
	int i, a, b, c, sum = 0;

	for( i = 0;i < 3;i++ ) {
		scanf("%d %d %d\n", &a, &b, &c );
		sum += min( a, min( b, c ) );
	}
	printf("%d\n", sum );
	return 0;
}
