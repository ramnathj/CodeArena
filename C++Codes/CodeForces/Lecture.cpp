#include <iostream>
#define sz 2069

using namespace std;

struct Node {
	char s[11];
	char fStr[11];
	struct Node* next;
};

struct Node* hTbl[sz];
char s1[11];
char s2[11];
char st[11];

void strCopy(char* dest, char* src) {
	
	register int i = 0;
	while( ( dest[i] = src[i] ) != '\0' ) {
		i++;
	}
}

int strComp( char* s1, char* s2 ) {
	
	register int i;
	for( i = 0;s1[i] && s2[i];i++ ) {
		if( s1[ i ] != s2[i] ) {
			break;
		}
	}
	return (s1[i] - s2[i]);
}

int computeHash( char* str ) {
	
	register unsigned long long hash = 5381;
	register int i;
	for( i = 0;str[i];i++ ) {
		hash = ( hash + (hash << 5 ) ) % sz;
		hash = ( hash + str[i] ) % sz;
	}
	return ( hash % sz );
}

struct Node* createNode(char* str, char* str2 ) {
	register struct Node* p = new Node;
	strCopy( p->s, str );
	strCopy( p->fStr, str2 );
	p->next = NULL; 
	return p;	
}

void insert( char* s1, char* s2 ) {
	
	register int hVal = computeHash( s1 );
	register int n1, n2;

	register struct Node* head = hTbl[ hVal ];

	for( n1 = 0;s1[n1];n1++ );
	for( n2 = 0;s2[n2];n2++ );


	if( head == NULL ) {
		if( n2 < n1 ) {
			hTbl[ hVal ] = createNode( s1, s2 );
		} else {
			hTbl[ hVal ] = createNode( s1, s1 );
		}
	} else {
		register struct Node* newNode = NULL;
		if( n2 < n1 ) {
			newNode = createNode( s1, s2 );
		} else {
			newNode = createNode( s1, s1 );
		}
		newNode->next = head;
		hTbl[ hVal ] = newNode;
	}
}

char* search( char* str ) {
	register int hVal = computeHash( str );
	register struct Node* head = hTbl[ hVal ];
	while( head != NULL ) {
		if( strComp( head->s, str ) == 0 ) {
			return head->fStr;
		}
		head = head->next;
	}
	return NULL;
}

void init() {
	
	register int i;
	for( i = 0;i < sz;i++ ) {
		hTbl[ i ] = NULL;
	}
}

int main() {
	
	register int n, m, i;

	cin >> n >> m;

	init();
	for( i = 0;i < m;i++ ) {
		cin >> s1 >> s2;
		insert( s1, s2 );
	}
	
	n -= 1;
	while( n-- ) {
		cin >> st;
		cout << search( st ) << " ";
	}

	cin >> st;
	cout << search(st) << "\n";
	return 0;
}