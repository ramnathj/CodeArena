#include <iostream>
#include <stdio.h>

#define sz 50000

using namespace std;

struct Node {
	
	char* data;
	int count;
	struct Node* next;
};

void strCopy( char* dest, char* src ) {

	int i = 0;
	while( ( dest[ i ] = src[ i ] ) != '\0' ) {
		i++;
	}	
}

int strComp( char* s1, char* s2 ) {

	int i = 0;
	for(;s1[ i ] && s2[ i ];i++ ) {
		if( s1[ i ] != s2[ i ] ) {
			break;
		}
	}
	return s1[ i ] - s2[ i ];
}

struct Node* createNode( char* s ) {
	
	struct Node* p = new Node;
	p->data = new char[ 20 ];
	strCopy( p->data, s);
	p->count = 1;
	p->next = NULL;

	return p;
}

int computeHash( char* s ) {
	
	unsigned long int hash = 5381;

	for( i = 0;s[ i ];i++ ) {
		hash = ( ( hash << 5 ) + hash ) + s[ i ];
	}
	hash = hash % sz;
	return hash;
}

void insertNode( struct Node** hMap, char* s ) {
	
	int val = computeHash( s );
	struct Node* head = hMap[ val ];
	struct Node* prev = head;

	while( head != NULL ) {
		if( !strComp( head->data, s ) ) {
			(head->count)++;
			return;
		}
		prev = head;
		head = head->next;
	}

	prev->next = createNode( s );
}

int findCount( struct Node** hMap, char* s ) {
	
	int val = computeHash( s );
	
	struct Node* head = hMap[ val ];
	
	while( head != NULL ) {
		
		if( !strComp( head->data, s ) ) {
			return head->count;
		}
		head = head->next;
	}
	return 0;	
}

int main() {
	
	int t, n, q, i;

	scanf("%d", &t );

	while( t-- ) {
		
		struct Node** hMap = new Node*[ sz ];
		for( i = 0;i < sz;i++ ) {
			hMap[ i ] = createNode("\0");
		}

		cin >> n >> q;

		for( i = 0;i < n;i++ ) {
			char* s = new char[ 20 ];
			scanf("%s",s);
			insertNode( hMap, s );
			delete s;
		}

		while( q-- ) {
			char* s = new char[ 20 ];
			scanf("\n%s", s);
			printf("%d\n", findCount( hMap, s ) );
			delete s;			
		}

		for( i = 0;i < sz;i++ ) {
			delete hMap[ i ];
		}
		delete hMap;
	}
	return 0;
}
