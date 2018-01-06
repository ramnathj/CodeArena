#include <iostream>

using namespace std;

typedef long long int Lint;

int main(int argc, char* argv[] ) {
	
	int t, n, i, j, maxVal, maxNum;
	Lint maxSum;

	bool flag;

	cin >> t;
	
	while( t-- ) {
		
		cin >> n;
			
		int **A = new int*[ n ];

		for( i = 0;i < n;i++ ) {
			A[ i ] = new int[ n ];
		}

		for( i = 0;i < n;i++ ) {
			for( j = 0;j < n;j++ ) {
				cin >> A[ i ][ j ];
			}
		}

		maxVal = A[ n - 1 ][ 0 ];
		for( i = 1;i < n;i++ ) {
			if( A[ n - 1 ][ i ] > maxVal ) {
				maxVal = A[ n - 1 ][ i ];
			}
		}

		maxSum = maxVal;
		flag = true;
		for( i = n - 2;i >= 0;i-- ) {
			maxNum = -1;
			for( j = 0;j < n;j++ ) {
				
				if( A[ i ][ j ] < maxVal ) {
					
					if( A[ i ][ j ] > maxNum ) {
						maxNum = A[ i ][ j ];
					}
				}
			}
			if( maxNum == -1 ) {
				flag = false;
				break;
			} else {
				maxSum += maxNum;
				maxVal = maxNum;
			}
		}

		if( flag ) {
			cout << maxSum << "\n";
		} else {
			cout << "-1\n";
		}

		for( i = 0;i < n;i++ ) {
			delete A[ i ];
		}

		delete A;
	}	
	return 0;
}