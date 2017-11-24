#include <iostream>
#include <map>

using namespace std;

int n;
map<pair<int, int>, bool> M;

bool isSafe( int r, int c ) {
	if( ( r >= 1 ) && ( r <= n ) && ( c >= 1 ) && ( c <= n ) ) {
		pair<int,int> P;
		P.first = r;
		P.second = c;
		return !M[ P ];
	}
	return false;
}

int moveUp( int r, int c ) {

	int ct = 0;
	r += 1;
	while( isSafe( r, c ) ) {
		ct++;
		r += 1;
	}

//	cout << " moveUp : " << ct << "\n";

	return ct;
}

int moveDown( int r, int c ) {

	int ct = 0;
	r -= 1;
	while( isSafe( r, c ) ) {
		ct++;
		r -= 1;
	}

//	cout << " moveDown : " << ct << "\n";

	return ct;
}

int moveLeft( int r, int c ) {

	int ct = 0;
	c -= 1;
	while( isSafe( r, c ) ) {
		ct++;
		c -= 1;
	}

//	cout << " moveLeft : " << ct << "\n";

	return ct;
}

int moveRight( int r, int c ) {

	int ct = 0;
	c += 1;
	while( isSafe( r, c ) ) {
		ct++;
		c += 1;
	}

//	cout << " moveRight : " << ct << "\n";

	return ct;
}

int moveLeftDiagUp( int r, int c ) {

	int ct = 0;
	r += 1;
	c -= 1;
	while( isSafe( r, c ) ) {
		ct++;
		r += 1;
		c -= 1;
	}

//	cout << " moveLeftDiagUp : " << ct << "\n";

	return ct;
}

int moveLeftDiagDown( int r, int c ) {

	int ct = 0;
	r -= 1;
	c -= 1;
	while( isSafe( r, c ) ) {
		ct++;
		r -= 1;
		c -= 1;
	}

//	cout << " moveLeftDiagDown : " << ct << "\n";

	return ct;
}

int moveRightDiagUp( int r, int c ) {

	int ct = 0;
	r += 1;
	c += 1;
	while( isSafe( r, c ) ) {
		ct++;
		r += 1;
		c += 1;
	}

//	cout << " moveRightDiagUp : " << ct << "\n";

	return ct;
}

int moveRightDiagDown( int r, int c ) {

	int ct = 0;
	r -= 1;
	c += 1;
	while( isSafe( r, c ) ) {
		ct++;
		r -= 1;
		c += 1;
	}

//	cout << " moveRightDiagDown : " << ct << "\n";
	
	return ct;
}

int main() {
	
	ios_base::sync_with_stdio( false );
	int k, sum = 0, r, c, i, p, q;

	cin >> n >> k;
	cin >> r >> c;

	for( i = 0;i < k;i++ ) {
		cin >> p >> q;
		pair<int, int> P;
		P.first = p;
		P.second = q;
		M[ P ] = true;
	}

	sum += moveUp( r, c );
	sum += moveDown( r, c );
	sum += moveLeft( r, c );
	sum += moveRight( r, c );
	sum += moveLeftDiagUp( r, c );
	sum += moveLeftDiagDown( r, c );
	sum += moveRightDiagUp( r, c );
	sum += moveRightDiagDown( r, c );

	cout << sum << "\n";

	return 0;
}
