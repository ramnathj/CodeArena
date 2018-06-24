#include <iostream>

using namespace std;

int flag;

int getCount( char* s1, char* s2 ) {
	
	int ct = 0, i;
//	cout << "Comparing " << s1 << " and " << s2 << " : ";

	for( i = 0;s1[ i ] && s2[ i ];i++ ) {
		if( s1[ i ] != s2[ i ] ) {
			ct++;
			return ct;
		}
		ct++;
	}	
	flag = true;
	return ct;
}

int main() {
	
	ios_base::sync_with_stdio( false );

	int n, q, i, count, val, j;

	cin >> n;

	char **A = new char*[ n ];
	int *B = new int[ n ];

	for( i = 0;i < n;i++ ) {
		A[ i ] = new char[ 30001 ];
	}

	for( i = 0;i < n;i++ ) {
		cin >> A[ i ];	
		for( j = 0;A[ i ][ j ];j++ );
	}
	
	cin >> q;

	while( q-- ) {
		flag = false;
		char* s = new char[ 30001 ];
		cin >> s;

		count = 0;

		for( i = 0;i < n;i++ ) {
			val = getCount( A[ i ], s );
			count += val;
			if( flag ) {
				break;
			}
		}

		if( flag ) {
			cout << count + 1 << "\n";
		} else {
			cout << count << "\n";
		}
	}

	for( i = 0;i < n;i++ ) {
		delete A[ i ];
	}

	delete A;
	delete B;
	return 0;
}