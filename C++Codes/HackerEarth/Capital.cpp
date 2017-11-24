#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int findIndex( vector<pair<int,int> >& A, int s ) {
	
	int n = A.size(), start, end, mid;

	start = 0;
	end = n - 1;

	while( start <= end ) {

		mid = ( start + end ) >> 1;
		if( A[ mid ].first == s ) {
			return A[ mid ].second + 1;
		} else if( A[ mid ].first > s ) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return -1;
}

int main() {
	
	ios_base::sync_with_stdio( false );

	int t, n, i, p, q, val;

	cin >> t;

	while( t-- ) {

		cin >> n;
		vector<pair<int,int> > A( n );
		set<int, std::greater<int> > S;
		for( i = 0;i < n;i++ ) {
			cin >> val;
			A[ i ].first = val;
			A[ i ].second = i;
			S.insert( val );
		}

		vector< vector<int> > B( n, vector<int>() );
		vector<int> :: iterator it;

		for( i = 0;i < n;i++ ) {
			B[ i ].push_back( A[ i ].first );
		}

		for( i = 0;i < n - 1;i++ ) {
			cin >> p >> q;
			B[ p - 1 ].push_back( A[ q - 1 ].first );
			B[ q - 1 ].push_back( A[ p - 1 ].first );
		}

		sort( A.begin(), A.end() );

		for( i = 0;i < n;i++ ) {
			for( it = B[ i ].begin();it != B[ i ].end();it++ ) {
				S.erase( *it );
			}

			if( S.size() == 0 ) {
				cout << "0 ";
			} else {
				cout << findIndex( A, *S.begin() ) << " ";
			}

			for( it = B[ i ].begin();it != B[ i ].end();it++ ) {
				S.insert( *it );
			}
		}

		cout << "\n";
	}
	return 0;
}
