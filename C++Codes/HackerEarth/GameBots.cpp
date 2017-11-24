#include <iostream>
#define sz 1000001

using namespace std;

int main() {
	
	ios_base::sync_with_stdio( false );

	int t, n1, n2, i, ct1, ct2, ct3, st1, st2, st3, val, val2;
	bool flag;

	cin >> t;

	while( t-- ) {
		char *s1 = new char[ sz ];
		char *s2 = new char[ sz ];

		cin >> s1 >> s2;

		for( n1 = 0;s1[ n1 ];n1++ );
		for( n2 = 0;s2[ n2 ];n2++ );

		if( n1 != n2 ) {
			cout << "No\n";
		} else {

			int *p1 = new int[ sz ];
			int *p2 = new int[ sz ];
			ct1 = ct2 = ct3 = 0;
			for( i = 0;i < n1;i++ ) {
				if( s1[ i ] == 'A' ) {
					p1[ ct1 ] = i;
					ct1++;
				} else if( s1[ i ] == 'B' ) {
					p2[ ct2 ] = i;
					ct2++;
				} else {
					ct3++;
				}
			}

			int *q1 = new int[ sz ];
			int *q2 = new int[ sz ];
			st1 = st2 = st3 = 0;
			for( i = 0;i < n2;i++ ) {
				if( s2[ i ] == 'A' ) {
					q1[ st1 ] = i;
					st1++;
				} else if( s2[ i ] == 'B' ) {
					q2[ st2 ] = i;
					st2++;
				} else {
					st3++;
				}
			}

			if( ( ct1 == st1 ) && ( ct2 == st2 ) && ( ct3 == st3 ) ) {

				flag = true;
				//Check for A

				for( i = 0;i < ct1;i++ ) {
					val = p1[ i ];
					val2 = q1[ i ];
					if( val < val2 ) {
						flag = false;
						break;
					}
				}

				if( flag ) {

					//Check for B

					for( i = 0;i < ct2;i++ ) {
						val = p2[ i ];
						val2 = q2[ i ];
						if( val > val2 ) {
							flag = false;
							break;
						}
					}

					if( flag ) {
						cout << "Yes\n";
					} else {
						cout << "No\n";
					}

				} else {
					cout << "No\n";
				}

			} else {
				cout << "No\n";
			}

			delete p1;
			delete q1;
			delete p2;
			delete q2;

		}

		delete s1;
		delete s2;
	}
	return 0;
}