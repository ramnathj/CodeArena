#include <iostream>

using namespace std;

bool isPalin( int* A, int n ) {
	int i;

	for( i = 0;i < n / 2;i++ ) {
		if( A[ i ] != A[ n - i - 1 ] ) {
			return false;
		}
	}

	return true;
}

int main(int argc, char* argv[]) {
	
	ios_base::sync_with_stdio( false );

	int t, n, i;
	bool flag;
	
	cin >> t;

	while( t-- ) {
		
		cin >> n;

		int *A = new int[ n ];
		for( i = 0;i < n;i++ ) {
			cin >> A[ i ];
		}

		if( isPalin( A, n ) ) {
			int B[ 8 ] = { 0, 0, 0, 0, 0, 0, 0, 0 };
			flag = true;
			B[ A[ 0 ] ] = 1;
			for( i = 1;i <= n / 2;i++) {
				if( A[ i ] < A[ i - 1 ] ) {
					flag = false;
					break;
				}
				B[ A[ i ] ] = 1;
			}
			if( !flag ) {
				cout << "no\n"; 
			} else {
				flag = true;
				for( i = 1;i < 8;i++ ) {
					if( !B[ i ] ) {
						flag = false;
						break;
					}
				}
				if( !flag ) {
					cout << "no\n";
				} else {
					cout << "yes\n";
				}
			}
						
		} else {
			cout << "no\n";
		}

		delete A;
	}

	return 0;
}
