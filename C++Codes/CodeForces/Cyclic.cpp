#include <iostream>
#define sz 2069

using namespace std;

struct Node {
	char s[51];
	struct Node* next;
};

struct Node* hTbl[sz];
char st[51];
int n;
int globalCtr;

int computeVal( char* str ) {

	unsigned long long int hash = 5381;
	register int i;
	for( i = 0;str[i];i++ ) {
		hash = ( hash + ( hash << 5 ) ) % sz;
		hash = ( hash + str[i] ) % sz;
	}
	return ( hash % sz );
}

void strCopy( char* dest, char* src ) {

	register int i = 0;
	while( ( dest[i] = src[i] ) != '\0' ) {
		i++;
	}
}

int strComp( char* s1, char* s2 ) {

	register int i;
	for( i = 0;s1[i] && s2[i];i++ ) {
		if( s1[i] != s2[i] ) {
			break;
		}
	}
	return (s1[i] - s2[i]);
}

struct Node* createNode(char* str) {

	register struct Node* p = new Node;
	strCopy(p->s, str);
	p->next = NULL;
	return p;
}

void insert(char *str) {

	register int hVal = computeVal(str);
	struct Node* head = hTbl[hVal];
	if( head == NULL ) {
		hTbl[hVal] = createNode(str);
		globalCtr++;
	} else {
		struct Node* prev = NULL;
		while( head != NULL ) {
			if( strComp( head->s, str ) == 0 ) {
				return;
			}
			prev = head;
			head = head->next;
		}
		prev->next = createNode(str);
		globalCtr++;
	}
}

void init() {
	
	register int i;
	for( i = 0;i < sz;i++ ) {
		hTbl[i] = NULL;
	}
}

void rotate() {
	
	register char ch;
	register int i;

	ch = st[n-1];
	for( i = n - 1;i >= 1;i-- ) {
		st[i] = st[i-1];
	}
	st[0] = ch;
}

int main() {
	
	register int i;
	cin >> st;
	globalCtr = 0;

	for( n = 0;st[n];n++ );

	init();

	for( i = 0;i < n;i++ ) {
		rotate();
		insert(st);
	}

	cout << globalCtr << "\n";

	return 0;
}

