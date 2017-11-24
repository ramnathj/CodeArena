#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

void DFS( vector<vector<int> >& A, vector<bool>& visit, int u, int& ct ) {

	vector<int> :: iterator it;
	int v;

	visit[ u ] = true;
	ct++;

	for( it = A[ u ].begin();it != A[ u ].end();it++ ) {
		v = *it;
		if( !visit[ v ] ) {
			DFS( A, visit, v, ct );
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio( false );

	int t, n, m, k, q, ct, i, a, b, sum;
	bool flag;

	scanf("%d", &t);

	while( t-- ) {

		scanf("%d %d %d %d", &n, &m, &k, &q);

		vector< vector<int> > A( n + 1, vector<int> () );

		for( i = 0;i < n;i++ ) {

			scanf("%d %d", &a, &b);
			A[ a - 1 ].push_back( b - 1 );
			A[ b - 1 ].push_back( a - 1 );
		}

		vector<bool> visit( n, false );
		vector<int> B;

		for( i = 0;i < n;i++ ) {
			if( !visit[ i ] ) {
				ct = 0;
				DFS( A, visit, i, ct );
				B.push_back( ct );
			}
		}

		sort( B.rbegin(), B.rend() );
		
		flag = false;
		sum = 0;
		for( i = 0;i < B.size();i++ ) {
			sum += B[ i ];
			if( ( sum >= q ) && ( ( i + 1 )<= k ) ) {
				flag = true;
				break;
			} 
		}

		if( flag )
			cout << "Satisfied\n";
		else
			cout << "Unsatisfied\n";

		A.clear();
	}

	return 0;
}