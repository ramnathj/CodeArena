#include <iostream>

using namespace std;

char st[101];
int main() {
	
	int i, upper, lower;
	cin >> st;
	upper = lower = 0;

	for( i = 0;st[i];i++ ) {
		if( ( st[ i ] >= 'A' ) && ( st[ i ] <= 'Z' ) ) {
			upper++;
		} else {
			lower++;
		}
	}

	if( upper > lower ) {
		for( i = 0;st[i];i++ ) {
			if( ( st[ i ] >= 'a' ) && ( st[ i ] <= 'z' ) ) {
				st[ i ] = st[ i ] - 32;
			}
		}
	} else {
		for( i = 0;st[i];i++ ) {
			if( ( st[ i ] >= 'A' ) && ( st[ i ] <= 'Z' ) ) {
				st[ i ] = st[ i ] + 32;
			}
		}	
	}
	
	cout << st << "\n";

	return 0;
}