#include <iostream>
#define MAXSIZE 1000

using namespace std;

struct HEntry {
	int value;
	char *s;
	HEntry* next;
};

struct HEntry* createEntry( int val, char *str ) {
	struct HEntry* H = new HEntry;
	H->value = val;
	H->s = str;
	H->next = NULL;

	return H;
}

void Insert( struct HEntry** M, int val, char* str ) {
	int v = val % MAXSIZE;
	if( M[ v ] == NULL ) {
		M[ v ] = createEntry( val, str );
	} else {
		struct HEntry* head = M[ v ];
		while( M[ v ]->next != NULL ) {
			M[ v ] = M[ v ]->next;
		}
		M[ v ]->next = createEntry( val, str );
		M[ v ] = head;
	}
}

char* Get( struct HEntry** M, int val ) {
	int v = val % MAXSIZE;
	struct HEntry* head = M[ v ];

	while( M[ v ] != NULL ) {
		if( M[ v ]->value == val ) {
			char *p = M[ v ]->s;
			M[ v ] = head;
			return p;
		}
		M[ v ] = M[ v ]->next;
	}

	M[ v ] = head;
	return NULL;
}
int main() {
	int i, t, val, s, q;
	struct HEntry** tbl = new HEntry*[ MAXSIZE ];
	for( i = 0;i < MAXSIZE;i++ ) {
		tbl[ i ] = NULL;
	}
	
	cin >> t;

	while( t-- ) {
		char *str = new char[ 30 ];
		cin >> val >> str;
		Insert( tbl, val, str );
	}

	cin >> q;
	while( q-- ) {
		cin >> val;
		cout << Get( tbl, val ) << "\n";
	}
	return 0;
}