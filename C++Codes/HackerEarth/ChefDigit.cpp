#include <iostream>

using namespace std;


int main() {
	
	int t, n, i, zro, one;

	cin >> t;

	while( t-- ) {
		
		string s;
		cin >> s;
		n = s.length();
		zro = one = 0;

		for( i = 0;i < n;i++ ) {
			if( s[ i ] == '0' )
				zro++;
			else
				one++;
		}

		if( ( zro == 1 && one == ( n - 1 ) ) || ( one == 1 && zro == ( n - 1 ) ) )
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}