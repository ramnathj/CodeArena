#include <iostream>

using namespace std;

char st[101];
int A[26];
int main() {
	
	int i, ct;
	for( i=  0;i < 26;i++ ) {
		A[ i] = 0;
	}

	cin >> st;

	for( i = 0;st[i];i++ ) {
		A[ st[i] - 97 ]++;
	}

	ct = 0;
	for( i = 0;i < 26;i++ ) {
		if( A[ i ] ) {
			ct++;
		}
	}

	if( ct & 0x1 ) {
		cout << "IGNORE HIM!\n";
	} else {
		cout << "CHAT WITH HER!\n";
	}
	
	return 0;
}