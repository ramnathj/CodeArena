#include <iostream>

using namespace std;

struct Node {
	
	int count;
	bool isLeaf;
	struct Node* child[26];
};

struct Node* root;
char s[11];
char fStr[11];
int globalMax;
char s3[11];
char s2[11];

struct Node triePool[1000000];
int it = 0;

struct Node* createNode() {
	
	struct Node* p = &triePool[it++];
	p->isLeaf = false;
	p->count = 0;
	for( int i  = 0;i < 26;i++ ) {
		p->child[i] = NULL;
	}	

	return p;
}

void insert( char* str ) {
	
	int i, idx;
	struct Node* head = root;

	for( i = 0;str[i];i++ ) {
		idx = str[i] - 'a';
		if( head->child[idx] == NULL ) {
			head->child[idx] = createNode();
		} 
		if( str[i+1] == '\0' ) {
			head->child[idx]->isLeaf = true;
			(head->child[idx]->count)++;
		}
		head = head->child[idx];
	}
}

void strCopy( char* dest, char* src ) {	
	int i = 0;
	while( ( dest[ i ] = src[i] ) != '\0' ) {
		i++;
	}	
}

void getMaxFrequency( struct Node* head, char* str, int level ) {
	if( head->isLeaf ) {
		str[level] = '\0';
		if( head->count > globalMax ) {
			globalMax = head->count;
			strCopy( fStr, str );
		}
	}

	for( int i = 0;i < 26;i++ ) {
		if( head->child[ i ] != NULL ) {
			str[level] = (char)('a' + i);
			getMaxFrequency( head->child[i], str, level + 1 );
		}
	}
}

struct Node* getRootNodeForPrefix(char* str ) {
	struct Node* head = root;
	int i, idx;

	for( i = 0;str[i];i++ ) {
		idx = str[i] - 'a';
		if( head->child[idx] == NULL ) {
			return NULL;
		} else {
			head = head->child[idx];
		}
	}
	return head;
}

int main() {

		int t, q;
	cin >> t;
	
	root = createNode();	

	while( t-- ) {
		cin >> s;
		insert( s );
	}

	cin >> q;

	while( q-- ) {
		cin >> s3;
		struct Node* h = getRootNodeForPrefix(s3);
		if( h == NULL ) {
			cout << "-1\n";
		} else {
			globalMax = -1;
			getMaxFrequency(h, s2, 0 );
			cout << s3 << fStr << " " << globalMax << "\n";
		}
	}
	return 0;
}