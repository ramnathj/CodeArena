#include <iostream>

using namespace std;

char st[101];
bool A[26];
int main() {
	
	int i, n;
	bool flag = true;

	for( i = 0;i < 26;i++ ) {
		A[i] = false;
	}

	cin >> n;
	cin >> st;

	for( i = 0;st[i];i++ ) {
		if( ( st[i] >= 'A' ) && ( st[i] <= 'Z' ) ) {
			A[st[i] - 'A'] = true;
		} else {
			A[st[i] - 'a'] = true;
		}
	}

	for( i =0 ;i < 26;i++ ) {
		if( !A[i] ) {
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