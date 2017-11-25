#include <iostream>
#include <vector>
#define sz 1000001

using namespace std;

bool isPalindrome( int n, int base ) {

	int* arr = new int[ 100 ];
	int ctr = 0, index;
	bool flag = true;
	
	while( n > 0 ) {
		arr[ ctr++ ] = n % base;
		n /= base;
	}
	
	for( index = 0;index < ctr / 2;index++ ) {
		if( arr[ index ] != arr[ ctr - index - 1 ] ) {
			flag = false;
			break;
		}
	}
	
	return flag;
}

int main() {
	
	ios_base::sync_with_stdio( false );
	int index, n, limit, q;
	vector<int> A, B( sz, 0 ), C( sz, 0);

	for( index = 1;index < sz;index++ ) {
		if( isPalindrome( index, 10 ) ) {
			A.push_back( index );
		}
	}

	n = A.size();
	
	for( index = 0;index < n;index++ ) {
		if( isPalindrome( A[ index ], 2 ) ) {
			B[ A[ index ] ] = 1;
		}
	}

	for( index = 1;index < sz;index++ ) {
		if( B[ index ] ) {
			C[ index ] = C[ index - 1 ] + B[ index ];
		} else {
			C[ index ] = C[ index - 1 ];
		}
	}
	
	cin >> q;
	
	while( q-- ) {
		cin >> limit;
		cout << C[ limit ] << "\n";
	}
	
	return 0;
}
