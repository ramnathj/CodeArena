#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>

#define DIVI 1000000007
#define sz 999999

using namespace std;

typedef long long int Lint;

int main()
{
	
	ios_base::sync_with_stdio( false );
	
	Lint n, i, m, v, minVal = INT_MAX, sum, val, diff, s, j;
	
	cin >> n;
	vector< vector<int> > A( n, vector<int> () );
	vector<int> h( n );

	for( i = 0;i < n;i++ ) {
		
		cin >> m;
		h[ i ] = m;
		v = pow( 2, m ) - 1;
		A[ i ].push_back( -1 );
		for( j = 1;j <= v;j++ ) {
			cin >> val;
			A[ i ].push_back( val );
		}
		minVal = min( m, minVal );
	}
	
	sum = 0;
	for( i = 0;i < n;i++ ) {
		
		if( h[ i ] != minVal ) {

			diff = h[ i ] - minVal;
			val = pow( 2, diff ) - 1;
			s = 0;
			for( j = 1;j <= val;j++ )
				s += A[ i ][ j ];
			sum += s;
		}
	}

	cout << sum << "\n";

    return 0;
}
