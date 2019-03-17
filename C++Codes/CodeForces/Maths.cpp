#include <iostream>

using namespace std;

char st[101];
int A[4];
int main() {
	
	int i;
	bool flag = false;
	cin >> st;

	for( i = 0;i < 4;i++ ) {
		A[i] = 0;
	}

	for( i = 0;st[i];i+=2 ) {
		A[st[i] - '0']++;
	}

	if( A[ 1 ] ) {
		flag = true;
		for( i = 0;i < A[ 1 ] - 1;i++ ) {
			cout << "1+";
		}
		cout << "1";
	}  

	if( A[ 2 ] ) {
		if( flag ) {
			cout << "+";
		}
		flag = true;
		for( i = 0;i < A[ 2 ] - 1;i++ ) {
			cout << "2+";
		}
		cout << "2";
	}  

	if( A[ 3 ] ) {
		if( flag ) {
			cout << "+";
		}
		for( i = 0;i < A[ 3 ] - 1;i++ ) {
			cout << "3+";
		}
		cout << "3";
	}  

	return 0;
}
