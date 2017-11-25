#include <iostream>
using namespace std;

struct Node {
  char ch;
  struct Node* child[ 26 ];
  bool isEnd;
};

Node* createNode( char c ) {
    Node* p = new Node;
    p->ch = c;
    for( int i = 0;i < 26;i++ ) {
        p->child[ i ] = NULL;
    }
    p->isEnd = false;
    return p;
}

bool exists( Node* root, char* str ) {
    
    int i, indx;    
    for( i = 0;str[ i ];i++ ) {
        indx = str[ i ] - 'a';
        if( root->child[ indx ] == NULL ) {
            return false;
        }
        root = root->child[ indx ];
    }
    
    return ( root->isEnd == true );
}

int main() {
    
    int t, n, i, indx, j;
    
    cin >> t;
    
    while( t-- ) {
        Node* root = createNode(' ');
        cin >> n;
        for( i = 0;i < n;i++ ) {
            char *s = new char[ 10001 ];
            cin >> s;
            Node* head = root;
            for( j = 0;s[ j ];j++ ) {
                indx = s[ j ] - 'a';
                if( head->child[ indx ] == NULL ) {
                    head->child[ indx ] = createNode( s[ j ] );
                    if( s[ j + 1 ] == '\0') {
                        head->child[ indx ]->isEnd = true;
                    }
                }
                head = head->child[ indx ];
            }
            delete s;
        }
        
        char* str = new char[ 10001 ];
        cin >> str;
        
        if( exists( root, str ) ) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
        
        delete str;
    }
    return 0;
}