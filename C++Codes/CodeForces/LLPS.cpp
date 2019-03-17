#include <iostream>

using namespace std;

char st[11];
int A[26];

int main() {
	
	register int i, pos, j;
	register char ch;

	for( i = 0;i < 26;i++ ) {
		A[ i ] = 0;
	}

	cin >> st;
	for( i = 0;st[i];i++ ) {
		A[ st[i] - 97 ]++;
	}	

	pos = -1;
	for( i = 0;i < 26;i++ ) {
		if( A[ i ] ) {
			pos = i;
		}
	}

	if( pos != -1 ) {
		ch = (char)('a' + pos );
		for( j = 0;j < A[ pos ];j++ ) {
			cout << ch;
		}
	}

	cout << "\n";

	return 0;
}