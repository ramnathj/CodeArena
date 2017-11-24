#include <iostream>

using namespace std;

typedef long long int Lint;

struct Stack {
	
	int *A;
	int top;
	int sz;
};

struct Stack init( int n ) {
	struct Stack S;
	S.A = new int[ n + 10 ];
	S.top = -1;
	S.sz = 0;

	return S;
}

struct Stack Push( struct Stack S, int val ) {
	S.A[ S.top + 1 ] = val;
	S.top += 1;
	S.sz += 1;

	return S;
}

bool isEmpty( struct Stack S ) {

	return ( S.sz == 0 );
}

int Top( struct Stack S ) {
	
	if( !isEmpty( S ) ) {
		return S.A[ S.top ];
	}	
	return -1;
}

struct Stack Pop( struct Stack S ) {
	
	if( !isEmpty( S ) ) {
		S.top -= 1;
		S.sz -= 1;
	}

	return S;
}

int main() {
	
	ios_base::sync_with_stdio( false );

	int n, i, q, x, k, val, sum, pos;
	bool flag;

	cin >> n;

	int *A = new int[ n ];

	for( i = 0;i < n;i++ ) {
		cin >> A[ i ];
	}

	cin >> q >> x;

	struct Stack S = init( n );
	k = 0;
	sum = 0;
	flag = true;
	pos = -1;

	while( q-- ) {

		char* s = new char[ 10 ];
		cin >> s;
		if( s[ 0 ] == 'H' ) {

			S = Push( S, A[ k ] );
			sum += A[ k ];
			k++;
			if( sum == x && flag ) {
				pos = S.sz;
				flag = false;
			}
		} else {
			val = Top( S );
			sum -= val;
			S = Pop( S );
			if( sum == x && flag ) {
				pos = S.sz;
				flag = false;
			}
		}
		delete s;
	}

	cout << pos << "\n";

	delete A;

	return 0;
}