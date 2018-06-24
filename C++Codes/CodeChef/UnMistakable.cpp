#include <iostream>

using namespace std;


int getLen( char* s ) {
	int n = 0;
	for(;s[ n ];n++ );
	return n;
}

int isUniqueCharCount( char* s, int k ) {
	
	int i, count = 0, idx;
	int A[ 26 ] = {0};

	for( i = 0;s[ i ];i++ ) {
		idx = s[ i ] - 97;
		if( A[ idx ] == 0 ) {
			A[ idx ] = 1;
			count++;
		}
	}
	return ( count <= k );
}

int main() {
	

	int n, k, i, maxVal = -1;

	cin >> n >> k;

	for( i = 0;i < n;i++ ) {
		char* s = new char[ 101 ];
		cin >> s;
		if( isUniqueCharCount( s, k ) ) {
			maxVal = max( maxVal, getLen( s ) );
		}
		delete s;
	}

	cout << maxVal << "\n";

	return 0;
}
