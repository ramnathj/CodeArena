#include <iostream>
#define sz 2069

using namespace std;

char str[33];

struct HTbl {
	char *s;
	struct HTbl* next;
	int lastNum; 		
};

struct HTbl* tbl[sz];

void strCopy( char* dest, char* src ) {
	int i = 0;
	while( ( dest[i] = src[i] ) != '\0' ) {
		i++;
	}
}

int strComp( char* s1, char* s2 ) {
	int i;
	for( i = 0;s1[i] && s2[i];i++ ) {
		if( s1[i] != s2[i] ) {
			break;
		}
	}
	return ( s1[i] - s2[i] );
}

struct HTbl* createNode(char* s, int val) {
	struct HTbl* p = new HTbl;
	p->lastNum = val;
	p->s = new char[33];
	strCopy( p->s, s);
	p->next = NULL;
	return p;
}

int computeHash( char* s ) {
	unsigned long hash = 5381;
	for( int i = 0;s[i];i++ ) {
		hash = ( ( hash * 33 ) + ( s[ i ] - 'a' ) ) % sz;
	}
	return ( hash % sz );
}

void init() {
	
	for( int i = 0;i < sz;i++ ) {
		tbl[i] = createNode("", 0);
	}
}

void insert(char *s) {
	int val = computeHash(s);
	struct HTbl* head = tbl[val];
	struct HTbl* nxt = head->next;
	struct HTbl* newNode = createNode(s,0);
	head->next = newNode;
	newNode->next = nxt;
}

int search( char* s ) {
	int val = computeHash( s );
	int res;
	struct HTbl* head = tbl[val];
	while( head != NULL ) {
		if( strComp( head->s, s ) == 0 ) {
			res = head->lastNum;
			(head->lastNum)++;
			return res;
		}
		head = head->next;
	}
	return -1;
}

int main() {
	
	int n, i, lastNum;

	cin >> n;

	init();

	while( n-- ) {
		cin >> str;
		lastNum = search(str);
		if(  lastNum != -1) {
			cout << str << lastNum+1 << "\n";
		} else {
			insert(str);
			cout << "OK\n";
		}
	}

	for( i = 0;i < sz;i++ ) {
		delete tbl[i];
		tbl[i] = NULL;
	}
	return 0;
}
