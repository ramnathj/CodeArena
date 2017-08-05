#include <iostream>

using namespace std;

typedef unsigned long long int Lint;

int main() {
	
	ios_base::sync_with_stdio( false );
		
	int t;
	Lint n, k, digitCount, next, prev, index;
	
	cin >> t;
	
	while( t-- ) {
		cin >> n >> k;
		next = k;
		prev = 0;
		digitCount = 0;
		index = 1;
		while( next <= n ) {
			digitCount += ( ( next - prev ) * index );
			prev = next;
			next = ( next * k );
			index++;
		}
		
		digitCount += ( ( n - prev + 1 ) * index );
		cout << digitCount << "\n";
	}
	return 0;
}