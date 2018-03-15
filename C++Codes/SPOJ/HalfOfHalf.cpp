#include <iostream>
using namespace std;

int main() {
	
	int t, n, i;
	
	cin >> t;
	
	while( t-- ) {
		char *s = new char[ 205 ];
		cin >> s;
		for( n = 0;s[ n ];n++ );
		
		for( i = 0;i < n / 2;i+=2 ) {
			cout << s[ i ];
		}
		cout << "\n";
		delete s;
	}
	return 0;
}