#include <iostream>

using namespace std;

void maxHeapify( int *A, int n, int i ) {

	int left = 2*i;
	int right = 2*i + 1;
	int largest, tmp;

	if( left <= n && A[ left ] > A[ i ] ) {
		largest = left;
	} else {
		largest = i;
	}

	if( right <= n && A[ right ] > A[ largest ] ) {
		largest = right;
	}

	if( largest != i ) {
		tmp = A[ i ];
		A[ i ] = A[ largest ];
		A[ largest ] = tmp;
		maxHeapify( A, n, largest );
	}
}

void buildHeap( int*A , int n ) {
	
	int i;

	for( i = n / 2;i >= 1;i-- ) {
		maxHeapify( A, n , i );
	}	
}

void printArray( int* A, int n ) {

	for( int i = 1;i <= n;i++ ) {
		cout << A[ i ] << " ";
	}
	cout << "\n";
}

int main() {
	
	ios_base::sync_with_stdio( false );

	int n, k, i, sum;

	cin >> n >> k;

	int *A = new int[ n +  1 ];
	for( i = 1;i <= n;i++ ) {
		cin >> A[ i ];
	}

	buildHeap( A, n );
	sum = 0;

	while( k-- ) {
		sum += A[ 1 ];
		A[ 1 ]--;
		maxHeapify( A, n, 1 );
	}

	cout << sum << "\n";

	delete A;
	
	return 0;
}