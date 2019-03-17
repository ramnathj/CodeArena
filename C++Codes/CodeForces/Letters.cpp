#include <iostream>

using namespace std;

char s[1001];
int A[26];

int main() {
	
	register int t, i, n, ct, j;
	register bool flag;
	
	cin >> t;

	while( t-- ) {

		cin >> s;
		
		for( i = 0;i < 26;i++ ) {
			A[i] = 0;
		}
		
		for( i = 0, n = 0;s[i];i++, n++) {
			A[ s[ i ] - 97 ]++;
		}

		flag = true;

		for( i = 0;i < n / 2;i++ ) {
			if( s[ i ] != s[ n - i - 1 ] ) {
				flag = false;
				break;
			}
		}

		if( !flag ) {

			cout << s << "\n";
		} else {

			ct = 0;
			for( i = 0;i < 26;i++ ) {
				if( A[ i ] ) {
					ct++;
				}
			}

			if( ct == 1 ) {
				cout << "-1\n";
			} else {

				for( i = 0;i < 26;i++ ) {
					for( j = 0;j < A[ i ];j++ ) {
						cout << (char)('a' + i);
					}
				}

				cout << "\n";
			}
		}
	}

	return 0;
}