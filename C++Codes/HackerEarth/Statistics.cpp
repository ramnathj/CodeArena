#include <iostream>
#define sz 2069

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

struct Node* createNode( char* s ) {
	struct Node* p = new Node;
	p->count = 1;
	p->data = new char[ 30 ];
	strCopy( p->data, s );
	p->next = NULL;
	return p;
}

int computeHash( char* s ) {
	
	int i, sum = 0;

	for( i = 0;s[ i ];i++ ) {
		sum = ( sum + ( ( ( s[ i ] ) * 10 ) + i + 1 ) ) % sz;
	}
	return sum;
}

int strComp( char* s1, char* s2 ) {
	int i;
	for( i = 0;s1[ i ] && s2[ i ];i++ ) {
		if( s1[ i ] != s2[ i ] ) {
			return ( s1[ i ] - s2[ i ] );
		} 
	}
	return ( s1[ i ] - s2[ i ] );
}

void insertNode( struct Node** hMap, char* str ) {
	
	int hVal = computeHash( str );
	struct Node* head = hMap[ hVal ];
	struct Node* prev = head;

	while( head != NULL ) {
		if( strComp( head->data, str ) == 0 ) {
			(head->count)++;
			return;
		}
		prev = head;
		head = head->next;	
	}
	prev->next = createNode( str );
}

void putNode( struct Node** uniqueMap, char* str ) {
	int val = computeHash( str );
	struct Node* head = uniqueMap[ val ];
	struct Node* prev = head;

	while( head != NULL ) {
		if( strComp( head->data, str ) == 0 ) {
			(head->count)++;
			return;
		}
		prev = head;
		head = head->next;	
	}
	prev->next = createNode( str );
}

int getNode( struct Node** uniqueMap, char* str ) {
	int val = computeHash( str );
	struct Node* head = uniqueMap[ val ]->next;
	while( head != NULL ) {
		if( strComp( head->data, str ) == 0 ) {
			return 1;
		}
		head = head->next;
	}
	return 0;		
}

int main() {
	
	int t, i, j;
	cin >> t;

	Node** hMap = new Node*[ sz ];
	Node** uniqueMap = new Node*[ sz ];
	for( i = 0;i < sz;i++ ) {
		hMap[ i ] = createNode("\0");
		uniqueMap[ i ] = createNode("\0");
	}

	while( t-- ) {
		char *name = new char[ 30 ];
		char *str = new char[ 30 ];
		cin >> name >> str;
		char* combStr = new char[ 60 ];
		for( i = 0;name[i];i++ ) {
			combStr[ i ] = name[ i ];
		}
		for( j = 0;str[j];j++ ) {
			combStr[ i + j ] = str[ j ];
		}
		combStr[ i + j ] = '\0';

		if( getNode( uniqueMap, combStr ) == 0 ) {
			insertNode( hMap, str );
			putNode( uniqueMap, combStr );
		}
		delete name;
		delete str;
	}

	int maxVal = 0;
	char* finalStr = new char[ 30 ];
	for( i = 0;i < sz;i++ ) {
		if( hMap[ i ]->next != NULL ) {
			struct Node* head = hMap[ i ]->next;
			while( head != NULL ) {
				if( head->count > maxVal ) {
					maxVal = head->count;
					strCopy( finalStr, head->data );
				} else if( head->count == maxVal ) {
					if( strComp( head->data, finalStr ) < 0 ) {
						strCopy( finalStr, head->data );
					}
				}
				head = head->next;
			}
		}
	}

	cout << finalStr << "\n";

	int val = computeHash("football\0");
	if( hMap[ val ]->next != NULL ) {
		struct Node* head = hMap[ val ]->next;
		int count = 0;
		while( head != NULL ) {
			if( strComp(head->data, "football\0") == 0 ) {
				count = head->count;
				break;
			}
			head = head->next;
		}
		cout << count << "\n";
	} else {
		cout << "0\n";
	}

	return 0;
}