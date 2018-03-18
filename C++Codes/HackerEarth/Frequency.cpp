#include <iostream>
#define sz 2069
#define MAXV 10000007

using namespace std;

struct Node {
	char* data;
	int count;
	struct Node* next;
};

struct Node** hMap;

void strCopy( char* dest, char* src ) {
	int i = 0;
	while( ( dest[ i ] = src[ i ] ) != '\0' ) {
		i++;
	} 	
}

int strComp( char* s1, char* s2 ) {
	
	int i = 0;

	for( ;s1[ i ] && s2[ i ];i++ ) {
		if( s1[ i ] != s2[ i ] ) {
			break;
		}
	}
	return s1[ i ] - s2[ i ];
}

struct Node* createNode( char* s ) {
	struct Node* p = new Node;
	p->data = new char[ 101 ];
	strCopy(p->data, s);
	p->count = 1;
	p->next = NULL;
	return p;
}

int computeHash( char* s ) {
	
	int  i, sum = 0;
	for( i = 0;s[ i ];i++ ) {
		sum = ( sum + ( s[ i ] * 10 + i + 1 ) ) % 2069;
	}
	return sum;
}

void insertNode( struct Node** hMap, char* s ) {
	
	int val = computeHash( s );
	struct Node* head = hMap[ val ];
	struct Node* prev = head;
	while( head != NULL ) {
		if( strComp( head->data, s ) == 0 ) {
			(head->count)++;
			return;
		}
		prev = head;
		head = head->next;
	}
	prev->next = createNode( s );
}

void merge( char** A, int* B, int p, int q, int r ) {
	
	int n1, n2, i, j, k;
	n1 = q - p + 1;
	n2 = r - q;
	char** L1 = new char*[ n1 + 2 ];
	int* L2 = new int[ n1 + 2 ];
	for( i = 1;i <= n1;i++ ) {
		L1[ i ] = new char[ 101 ];
		strCopy( L1[ i ], A[ p + i - 1 ] );
		L2[ i ] = B[ p + i - 1 ];
	}
	L1[ n1 + 1 ] = new char[ 101 ];
	strCopy( L1[ n1 + 1 ], "\0" );
	L2[ n1 + 1 ] = MAXV;

	char** R1 = new char*[ n2 + 2 ];
	int* R2 = new int[ n2 + 2 ];
	for( j = 1;j <= n2;j++ ) {
		R1[ j ] = new char[ 101 ];
		strCopy( R1[ j ], A[ q + j ] );
		R2[ j ] = B[ q + j ];
	}
	R1[ n2 + 1 ] = new char[ 101 ];
	strCopy( R1[ n2 + 1 ], "\0" );
	R2[ n2 + 1 ] = MAXV;
	
	i = j = 1;
	
	for( k = p;k <= r;k++ ) {
		if( !strComp( L1[ i ], "\0" ) ) {
			strCopy( A[ k ], R1[ j ] );
			B[ k ] = R2[ j ];
			j++;		
		} else if( !strComp( R1[ j ], "\0" ) ) {
			strCopy( A[ k ], L1[ i ] );
			B[ k ] = L2[ i ];
			i++;						
		} else if( strComp( L1[ i ], R1[ j ] ) < 0 ) {
			strCopy( A[ k ], L1[ i ] );
			B[ k ] = L2[ i ];
			i++;			
		} else {
			strCopy( A[ k ], R1[ j ] );
			B[ k ] = R2[ j ];
			j++;
		}
	}	
}

void mergeSort( char** A, int* B, int p, int r ) {
	int q;
	if( p < r ) {
		q = ( p + r ) >> 1;
		mergeSort( A, B, p, q );
		mergeSort( A, B, q + 1, r );
		merge( A, B, p, q, r );
	}
}

int main() {
	
	int n, i, k;
	hMap = new Node*[ sz ];

	for( i = 0;i < sz;i++ ) {
		hMap[ i ] = createNode("\0");
	}
	cin >> n;

	for( i = 0;i < n;i++ ) {
		char* s = new char[ 101 ];
		cin >> s;
		insertNode( hMap, s );
		delete s;
	}

	char** A = new char*[ n ];
	for( i = 0;i < n;i++ ) {
		A[ i ] = new char[ 101 ];
	}
	int *B = new int[ n ];
	k = 0;
	for( i = 0;i < sz;i++ ) {
		
		if( hMap[ i ]->next != NULL ) {
			struct Node* head = hMap[ i ]->next;

			while( head != NULL ) {
				strCopy( A[ k ], head->data );
				B[ k ] = head->count;
				k++;
				head = head->next;
			}
		}
	}

	mergeSort( A, B, 0, k - 1 );

	for( i = 0;i < k;i++ ) {
		cout << A[ i ] << " " << B[ i ] << "\n";
	}

	for( i = 0;i < n;i++ ) {
		delete A[ i ];
	}
	delete A;
	delete B;

	for( i = 0;i < sz;i++ ) {
		delete hMap[ i ];
	}
	delete hMap;
	
	return 0;
}