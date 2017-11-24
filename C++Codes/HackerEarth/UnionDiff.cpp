#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define DIVI 1000000007

using namespace std;

int main()
{
	ios_base::sync_with_stdio( false );
	
	int n, i, m, j, val, sum;
	
	cin >> n;
	
	cin >> m;
	vector< vector<int> > A( n, vector<int>() );
	
	set<int> S;
	set<int> :: iterator it;
	
	for( j = 0;j < m;j++ ) {
		cin >> val;
		S.insert( val );
	}	
	
	for( it = S.begin();it != S.end();it++ )
		A[ 0 ].push_back( *it );
		
	for( i = 1;i < n;i++ ) {
		
		cin >> m;
		S.clear();
		
		for( j = 0;j < m;j++ ) {
			cin >> val;
			S.insert( val );
		}
		
		for( it = S.begin();it != S.end();it++ )
			A[ i ].push_back( *it );
		
	}
	
	if( n > 1 ) {
		set<int> S2;
		for( j = 0;j < A[ 0 ].size();j++ ) {
			if( binary_search(A[ 1 ].begin(), A[ 1 ].end(), A[ 0 ][ j ] ) )
				S2.insert( A[ 0 ][ j ] );
		}

		for( i = 2;i < n;i++ ) {

			for( it = S2.begin();it != S2.end();it++ ) {
				if( !binary_search(A[ i ].begin(), A[ i ].end(), *it ) )
					S2.erase( it );			
			}

		}

		sum = 0;
		for( it = S2.begin();it != S2.end();it++ )
			sum = ( sum + *it ) % DIVI;		
	} else {
		sum = 0;
		for( i = 0;i < A[ 0 ].size();i++ )
			sum = ( sum + A[ 0 ][ i ] ) % DIVI;
	}
		cout << ( -1 * sum ) << "\n";

    return 0;
}
