#include <iostream>

using namespace std;

char s[2][11];
char s1[11];
char s2[11];

void strCopy( char* dest, char* src) {
	register int i = 0;
	while( ( dest[i] = src[i] ) != '\0' ) {
		i++;
	}
} 

int strComp( char* s1, char* s2 ) {
	register int i;
	for( i = 0;s1[i] && s2[i];i++ ) {
		if( s1[i] != s2[i] ) {
			break;
		}
	}
	return ( s1[i] - s2[i] );
}

int main() {
	
	register int n;

	cin >> s[0] >> s[1];
	cin >> n;

	cout << s[0] << " " << s[1] << "\n";
	while( n-- ) {
		cin >> s1 >> s2;
		if( strComp( s[0], s1 ) == 0 ) {
			strCopy( s[0], s2 );
		} else {
			strCopy( s[1], s2 );
		}
		cout << s[0] << " " << s[1] << "\n";
	}

	return 0;
}