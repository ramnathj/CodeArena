#include <iostream>
#define sz 269

using namespace std;

struct Node {
	
	char* s;
	struct Node* next;	
};

struct Node* hTbl[sz];
struct Node nodePool[110];
int it;
char st[101];

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
	return (s1[i] - s2[i]);
}

struct Node* createNode( char* str ) {
	struct Node* p = &nodePool[it++];
	p->s = new char[ 101 ];
	strCopy(p->s, str);
	p->next = NULL;
	return p;
}

int computeHash(char* str) {
	int i;
	unsigned long long hash = 5381;
	for( i = 0;str[i];i++ ) {
		hash = ( hash + ( hash << 5 ) );
		hash = ( hash + ( str[i] ) ) % sz;
	}
	return hash % sz;
}

bool insert( char* str ) {

	int val = computeHash( str );

	if( hTbl[val] == NULL ) {
		hTbl[val] = createNode(str);
		return true;
	} else {
		struct Node* prev = NULL;
		struct Node* head = hTbl[val];
		while( head != NULL ) {
			if( strComp(head->s, str ) == 0 ) {
				return false;
			}
			prev = head;
			head = head->next;
		}
		prev->next = createNode(str);
		return true; 
	}
}

int main() {
	
	int n, i;
	cin >> n;

	for( i = 0;i < sz;i++ ) {
		hTbl[i] = NULL;
	}
	
	it = 0;

	while( n-- ) {
		cin >> st;
		if( !insert(st) ) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}