#include <iostream>
#include <stack>
#include <vector>
#include <limits.h>

using namespace std;

typedef long long int Lint;

int main() {
	
	ios_base::sync_with_stdio( false );

	int n, i, t;
	Lint maxArea, val;

	cin >> n;

	while( n ) {

		vector<int> A( n );

		for( i = 0;i < n;i++ ) {
			cin >> A[ i ];
		}

		stack<int> S;
		vector<Lint> area( n );

		for( i = 0;i < n;i++ ) {

			while( !S.empty() ) {
				if( A[ i ] <= A[ S.top() ] ) {
					S.pop();
				} else {
					break;
				}
			}
			if( S.empty() ) {
				t = -1;
			} else {
				t = S.top();
			}

			area[ i ] = ( i - t - 1 );
			S.push( i );
		}

		while( !S.empty() ) {
			S.pop();
		}

		for( i = n - 1;i >= 0;i-- ) {

			while( !S.empty() ) {
				if( A[ i ] <= A[ S.top() ] ) {
					S.pop();
				} else {
					break;
				}
			}
			if( S.empty() ) {
				t = n;
			} else {
				t = S.top();
			}

			area[ i ] += ( t - i - 1 );
			S.push( i );			
		}

		maxArea = INT_MIN;

		for( i = 0;i < n;i++ ) {
			val = A[ i ]* ( area[ i ] + 1 );
			maxArea = max( val, maxArea );
		}

		cout << maxArea << "\n";

		cin >> n;
	}

	return 0;
}
