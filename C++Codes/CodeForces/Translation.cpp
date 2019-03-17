#include <iostream>

using namespace std;

char s1[101];
char s2[101];

int main() {
	
	int i, n1, n2;
	bool flag = true;

	cin >> s1 >> s2;

	for( n1 = 0;s1[n1];n1++ );
	for( n2 = 0;s2[n2];n2++ );

	if( n1 != n2 ) {
		cout << "NO\n";
	} else {
		for( i = 0;i < n1;i++ ) {
			if( s2[ i ] != s1[ n1 - i - 1 ] ) {
				flag = false;
				break;
			}
		}
		if( flag ) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}