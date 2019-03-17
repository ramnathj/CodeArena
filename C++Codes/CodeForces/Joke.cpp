#include <iostream>

using namespace std;

char s1[101];
char s2[101];
char s3[101];
int A[26];
bool flag;

int main() {
	
	register int i;

	for( i = 0;i < 26;i++ ) {
		A[ i ] = 0;
	}

	cin >> s1 >> s2 >> s3;

	for( i = 0;s1[i];i++ ) {
		A[ s1[i] - 'A' ]++;
	}

	for( i = 0;s2[i];i++ ) {
		A[ s2[i] - 'A' ]++;
	}

	for( i = 0;s3[i];i++ ) {
		A[ s3[i] - 'A' ]--;
	}

	flag = true;
	for( i = 0;i < 26;i++ ) {
		if( A[i] != 0 ) {
			flag = false;
			break;
		}
	}
	
	if( flag ) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}