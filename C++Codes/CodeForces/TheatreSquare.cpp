#include <iostream>

using namespace std;

typedef long long int Lint;

int main() {
	
	Lint n, m, a, v1, v2, v3;

	cin >> n >> m >> a;

	if( ( n % a ) == 0 ) {
		v1 = n / a;
	} else {
		v1 = ( n / a ) + 1;
	}

	if( ( m % a ) == 0 ) {
		v2 = m / a;
	} else {
		v2 = ( m / a ) + 1;
	}

	v3 = v1 * v2;
	cout << v3 << "\n";
	
	return 0;
}