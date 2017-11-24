#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void BFS( vector< vector<int> >& A, int n, vector<bool>& visit, int s ) {

	int u, v;

	visit[ s ] = true;
	queue<int> Q;
	Q.push( s );

	while( !Q.empty() ) {
		u = Q.front();
		Q.pop();
		vector<int> :: iterator it;
		for( it = A[ u ].begin();it != A[ u ].end();it++ ) {
			v = *it;
			if( !visit[ v ] ) {
				visit[ v ] = true;
				Q.push( v );
			}
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio( false );

	int n, i, j, k, x, p, q, v, u;
	bool flag;

	cin >> n;

	vector< vector<int> > A( n, vector<int> () );

	cin >> k;

	for( i = 0;i < k;i++ ) {
		cin >> p >> q;
		A[ p ].push_back( q );
		A[ q ].push_back( p );
	}

	vector<int> :: iterator it, it2;

	cin >> x;

	for( it = A[ x ].begin();it != A[ x ].end();it++ ) {
		v = *it;
		it2 = find( A[ v ].begin(), A[ v ].end(), x );
		A[ v ].erase( it2 );
	}

	A[ x ].clear();

	u = -1;

	for( i = 0;i < n;i++ ) {
		if( i != x ) {
			u = i;
			break;
		}
	}

	if( u != -1 ) {
		vector<bool> visit( n, false );
		BFS( A, n, visit, u );
		visit[ x ] = true;
		flag = true;
		
		for( i = 0;i < n;i++ ) {
			if( !visit[ i ] ) {
				flag = 0;
				break;
			}
		}
		
		if( flag ) {
			cout << "Connected\n";
		} else {
			cout << "Not Connected\n";
		}

	} else {
		cout << "Connected\n";
	}
	
	return 0;
}
