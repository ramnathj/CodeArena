#include <iostream>

using namespace std;

char s1[101];
char s2[101];

int strComp() {
	int i;
	for( i=  0;s1[i]&&s2[i];i++ ) {
		if( s1[i] != s2[i] ) {
			break;
		}
	}
	return (s1[i] - s2[i]);
}

int main() {
	
	int val, i;
	cin >> s1;
	cin >> s2;

	for(i = 0;s1[i];i++){
		if( ( s1[i] >= 'A' ) && (s1[i] <= 'Z') ) {
			s1[i] = s1[i] + 32;
		}
		if( ( s2[i] >= 'A' ) && (s2[i] <= 'Z') ) {
			s2[i] = s2[i] + 32;
		}
	}

	val = strComp();

	if( val < 0 ) {
		cout << "-1\n";
	} else if( val > 0 ) {
		cout << "1\n";
	} else {
		cout << "0\n";
	}

	return 0;
}