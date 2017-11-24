#include <iostream>
#define sz 1000001

using namespace std;

int main()
{
	ios_base::sync_with_stdio( false );
	
	int t, n, i, j, count, maxVal;
	
	int A[ sz ];
	A[ 0 ] = 0;
	A[ 1 ] = 1;
	maxVal = 0;

	for( i = 2;i < sz;i++ ) {
		count = 0;
		for( j = 1;j * j <= i;j++ ) {

			if( ( i % j ) == 0 ) {

				if( j == i / j ) {
					count++;
				} else {
					count += 2;
				}
			}
		}
		A[ i ] = count;
		maxVal = max( maxVal, count );
	}

	cout << maxVal << "\n";
	
    return 0;
}
