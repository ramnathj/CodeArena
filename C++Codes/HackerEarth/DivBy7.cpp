#include <iostream>
#include <math.h>

using namespace std;

bool ModDiv( string s, int n ) {

//	cout << "Checking Divisiblity of " << s << " by 7 \n";
	int i, sum = 0;
	for( i = 0;i < n;i++ ) {
		sum = ( sum * 10 ) + ( s[ i ] - '0' );
		sum = ( sum % 7 );
	}

	return ( sum == 0 );
}

int main()
{
	ios_base::sync_with_stdio( false );
	
	string s;
	int n, i, val, q, l, r;
	
	cin >> s;
	n = s.length();

	cin >> q;
	
	while( q-- ) {
		
		cin >> l >> r;
		val = r - l + 1;
		string str = s.substr( l - 1, val );
		
		if( ModDiv( str, val ) ) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
		
    return 0;
}
