#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void inorder( vector<int>&A, vector<int>& B, int i, int n ) {
	
	if( i < n) {
		inorder( A, B, i * 2 + 1, n );
		B.push_back( A[ i ] );
		inorder( A, B, i * 2 + 2, n );
	}	
}

int BinSearch( vector<int>& C, int val, int n ) {
	int start = 0, end = n - 1, mid;

	while( start <= end ) {
		mid = ( start + end ) >> 1;
		if( C[ mid ] > val ) {
			end = mid - 1;
		} else if( C[ mid ] < val ) {
			start = mid + 1;
		} else {
			return mid;
		}
	}

	return -1;
}

void DFS( vector<vector<int> >& A, int i, vector<bool>& visited, int& count ) {

	visited[ i ] = true;

	vector<int> :: iterator it;
	int j;

	for( it = A[ i ].begin();it != A[ i ].end();it++ ) {
		j = *it;
		if( !visited[ j ] ) {
			count++;
			DFS( A, j, visited, count );
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio( false );

	int n, i, idx, sum, count;

	cin >> n;

	vector<int> A( n );
	vector<int> B;

	for( i = 0;i < n;i++ ) {
		cin >> A[ i ];
	}

	inorder( A, B, 0, n );

	vector<int> C;
	C = B;

	sort( C.begin(), C.end() );

	vector< vector<int> > D( n, vector<int>() );

	for( i = 0;i < n;i++ ) {
		idx = BinSearch( C, B[ i ], n );
		D[ i ].push_back( idx );
	}

/*	cout << "Graph\n";
	for( i = 0;i < n;i++ ) {
		vector<int> :: iterator it;
		cout << i + 1 << "->";
		for( it = D[ i ].begin(); it != D[ i ].end();it++ ) {
			cout << *it + 1 << "->";
		}
		cout << "NULL\n";
	}
*/
	vector<bool> visited( n, false );

	sum = 0;
	for( i = 0;i < n;i++ ) {
		if( !visited[ i ] ) {
			count = 1;
			DFS( D, i, visited, count );
//			cout << count << "\n";
			sum += ( count - 1 );
		}
	}
	cout << sum << "\n";

	return 0;
}
