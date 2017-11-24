#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio( false );

	int n, i, ct, val, j;

	cin >> n;

	vector<int> A( n );

	for( i = 0;i < n;i++ ) {
		cin >> A[ i ];
	}

	val = A[ 0 ];
	j = 1;
	ct = 0;
	for( i = 1;i < n; ) {

		while( j <= val ) {
			i++;
			j++;
		}

		if( i < n ) {
			ct++;
			val = A[ i ];
			i++;
			j = 1;
		} else {
			ct++;
			break;
		}
	}
	
	cout << ct << "\n";

	return 0;
}
