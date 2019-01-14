#include <iostream>

using namespace std;

struct Node {
	
	char ch;
	struct Node* child[ 26 ];
	int isLeaf;
};

struct Node* createNode( char c ) {
	struct Node* p = new Node;
	p->ch = c;
	for( int i = 0;i < 26;i++ ) {
		p->child[ i ] = NULL;
	}
	p->isLeaf = 0;
	return p;
}

void insertNode( struct Node* root, char* s ) {
	
	struct Node* head = root;
	int i, idx;
	for( i = 0;s[ i ];i++ ) {
		idx = s[ i ] - 'a';
		if( head->child[ idx ] == NULL ) {
			head->child[ idx ] = createNode( s[ i ] );
			if( s[ i + 1 ] == '\0') {
				head->child[ idx ]->isLeaf = 1;
			}
			head = head->child[ idx ]; 			
		} else {
			head = head->child[ idx ]; 						
		}
	}
}

struct Node* root;

void display( struct Node* head, char* finalStr, int level, char* prefix ) {
	
	if( head->isLeaf ) {
		finalStr[ level ] = '\0';
		cout << prefix << finalStr << " ";
	}
	
	for( int i = 0;i < 26;i++ ) {
		if( head->child[ i ] != NULL ) {
			finalStr[ level ] = i + 'a';
			display( head->child[ i ], finalStr, level + 1, prefix ); 		
		}
	}	
}

void printStrings( struct Node* root, char* s ) {
	
	struct Node* head = root;
	int i, idx, flag = 1, k = 0;
	char* newStr = new char[ 51 ];
//	cout << "Checking for strings with prefix " << s << "\n";
	for( i = 0;s[ i ];i++ ) {
		idx = s[ i ] - 'a';
		newStr[ k ] = s[ i ];
		k++;
		if( head->child[ idx ] == NULL ) {
			flag = 0;
			cout << "0\n";
			break;
		} else {
			head = head->child[ idx ];
		}
	}
	newStr[ k ] = '\0';
	if( flag ) {
		struct Node* head2 = head;
		char* finalStr = new char[ 51 ];
		display( head2, finalStr, 0, newStr );
		delete finalStr;
		cout << "\n";		
	}

}



int main() {
	
	int t, n, i;

	cin >> t;

	while( t-- ) {
		
		cin >> n;
		
		root = createNode( ' ' );
		
		for( i = 0;i < n;i++ ) {
			char* s = new char[ 51 ];
			cin >> s;
			insertNode( root, s );
			delete s;
		}
	
		char* str = new char[ 51 ];
		cin >> str;
		char* s2 = new char[ 51 ];
		int k = 0;

//		cout << "Looking for strings in prefix : " << str << "\n";
		for( i = 0;str[ i ];i++ ) {
			s2[ k++ ] = str[ i ];
			s2[ k ] = '\0';
			printStrings(root, s2);
		}
		
		delete str;					
	}

	return 0;
}