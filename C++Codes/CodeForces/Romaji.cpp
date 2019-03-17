#include <iostream>

using namespace std;

char s[101];

bool isVowel( char ch ) {
	return ( ( ch == 'a') || ( ch == 'e') || ( ch == 'i') || ( ch == 'o') || ( ch == 'u') );
}

int main() {
	
	int i, n;
	bool flag = true;
	
	cin >> s;
	for( n = 0;s[n];n++ );

	for( i = 0;i < n - 1;i++ ) {
		if( !isVowel(s[i] ) ) {
			if( s[i] != 'n' ) {
				if( !isVowel( s[i+1] ) ) {
					flag = false;
					break;
				}
			}
		}
	}

	if( flag ) {
		if( ( !isVowel(s[i] ) ) && ( s[i] != 'n' ) ) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	} else {
		cout << "NO\n";
	}
	return 0;
}
