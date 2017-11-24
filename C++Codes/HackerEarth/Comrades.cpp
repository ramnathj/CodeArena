#include <iostream>
#include <vector>

using namespace std;

typedef long long int Lint;

Lint countEdges( Lint v, vector<Lint>& A, Lint n ) {
	
	Lint ct = 0;
	Lint par = A[ v ];
	vector<Lint> visit( n, false );
	visit[ v ] = true;
	while( par != -1 && !visit[ par ] ) {
		ct++;
		visit[ par ] = true;
		par = A[ par ];
	}

	return ct;
}

int main() {
	
	ios_base::sync_with_stdio( false );

	Lint t, n, i, e, val, total, sum;

	cin >> t;

	while( t-- ) {

		cin >> n;
		vector<Lint> A( n );

		for( i = 0;i < n;i++ ) {
			cin >> A[ i ];
			A[ i ] -= 1;
		}

		sum = 0;
		for( i = 0;i < n;i++ ) {

			e = countEdges( i, A, n );
			val = ( e * ( e + 1 ) ) >> 1;
			sum += val;
		}

		total = ( n * ( n - 1 ) ) >> 1;

		cout << sum << " " << total - sum << "\n";
	}

	return 0;
}