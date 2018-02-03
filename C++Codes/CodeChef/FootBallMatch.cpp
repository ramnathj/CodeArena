#include <iostream>
#define sz 2069

using namespace std;

struct HEntry {
	
	char* s;
	int count;
	struct HEntry* next;	
};

int getHashCode( char* s ) {
	
	int i, sum = 0;
	for( i = 0;s[ i ];i++ ) {
		sum = ( sum + ( s[ i ]*10 + i ) ) % sz;
	}
	return sum;
}

void strCopy( char* dest, char* src ) {
	
	int i = 0;
	while( src[ i ] != '\0' ) {
		dest[ i ] = src[ i ];
		i++;
	}	

	dest[ i ] = '\0';
}

int strComp( char* s1, char* s2 ) {
	
	int i;
	for( i = 0;s1[ i ] && s2[ i ];i++ ) {
		if( s1[ i ] != s2[ i ] ) {
			return 0;
		}
	}

	return ( s1[ i ] == s2[ i ] );
}

struct HEntry* createNode( char* str ) {
	
	struct HEntry* p = new HEntry;
	p->count = 0;
	p->s = new char[ 21 ];
	strCopy( p->s, str );
	p->next = NULL;
	return p;
}

void insertNode( struct HEntry** HTbl, char* str) {
	
	int hCode;
	hCode = getHashCode( str );
	if( HTbl[ hCode ] == NULL ) {
		HTbl[ hCode ] = createNode( str );
	} else {
		
		struct HEntry* head = HTbl[ hCode ];
		struct HEntry* prev = head;
		cout << "List ";
		while( head != NULL ) {
			cout << head->s << " ";
			if( strComp( head->s, str ) ) {
				head->count = head->count + 1;
				return;
			}
			prev = head;
			head = head->next;
		}
		cout << "\n";
		prev->next = createNode( str );
	}
}

char* findMax( struct HEntry** HTbl ) {
	
	int i;
	int maxVal = -1, ct = 0;
	char* s = NULL;
	bool flag = true;
	for( i = 0;i < sz;i++ ) {
		struct HEntry* head = HTbl[ i ];
		while( head != NULL ) {
			if( head->count > maxVal ) {
				maxVal = head->count;
				strCopy( s, head->s );
			}
			head = head->next;
		}
	}

	for( i = 0;i < sz;i++ ) {
		struct HEntry* head = HTbl[ i ];
		while( head != NULL ) {
			if( head->count == maxVal ) {
				if( ct == 1 ) {
					flag = false;
					break;
				}
				ct++;
			}
			head = head->next;
		}
	}
	if( flag ) {
		return s;
	} else {
		return "Draw";
	}

}
int main(int argc, char* argv[]) {
	
	ios_base::sync_with_stdio( false );

	int t, n, i;

	cin >> t;

	while( t-- ) {
		
		struct HEntry** HTbl = new HEntry*[ sz ];
		char *s = new char[ 21 ];
		for( i = 0;i < sz;i++ ) {
			HTbl[ i ] = NULL;
		}

		cin >> n;

		for( i = 0;i < n;i++ ) {
			cin >> s;
			insertNode( HTbl, s );
		}

		cout << findMax( HTbl ) << "\n";
		for( i = 0;i < sz;i++ ) {
			delete HTbl[ i ];
		}
		delete HTbl;
		delete s;
	}
	return 0;
}
