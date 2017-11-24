#include <iostream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio( false );

	int n, i, count, val;
	bool isValley;

	cin >> n;
	char *s = new char[ n + 1 ];
	cin >> s;

	int *A = new int[ n ];
	val = 0;
	
	for( i = 0;i < n ;i++ ) {

		if( s[ i ] == 'U' ) {
			val++;
			A[ i ] = val;
		} else {
			val--;
			A[ i ] = val;
		}
	}

/*	cout << s << "\n";
	for( i = 0;i < n;i++ )
		cout << A[ i ] << " ";
	cout << "\n";
*/
	isValley = ( A[ 0 ] == -1 ? true : false );
	count = 0;

	for( i = 1;i < n;i++ ) {

		if( ( A[ i ] == 0 ) ) {

			if( isValley ) {
				count++;
				if( ( i < n - 1 ) && A[ i + 1 ] == -1 ) {
					isValley = true;
				} else {
					isValley = false;
				}
			} else {
				if( ( i < n - 1 ) && A[ i + 1 ] == -1 ) {
					isValley = true;
				}
			}
		}
	}

	cout << count << "\n";

	delete s;
	delete A;

	return 0;
}