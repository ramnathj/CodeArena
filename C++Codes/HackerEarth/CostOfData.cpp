#include <iostream>
using namespace std;

typedef long long int Lint;

struct Node {
    char ch;
    int isLeaf;
    struct Node* child[ 26 ];
};

struct Node* createNode( char c ) {
    int i;
    struct Node* p = new Node;
    p->ch = c;
    p->isLeaf = 0;
    for(i = 0;i < 26;i++ ) {
        p->child[ i ] = NULL;
    }
    return p;
}
int insertNode( struct Node* root, char* s) {
    
    int i, ct = 0, idx;
    struct Node* head = root;
    for( i = 0;s[ i ];i++ ) {
        idx = s[ i ] - 97;
        if( head->child[ idx ] == NULL ) {
            ct++;
            head->child[ idx ] = createNode( s[ i ] );
        }
        head = head->child[ idx ];
    }
    
    head->isLeaf = 1;
    return ct;
}

int main()
{
    struct Node* root = createNode('\0');
    int n, count = 1;
    cin >> n;
    while( n-- ) {
        char* s = new char[ 31 ];
        cin >> s;
        count += insertNode( root, s );
        delete s;
    }
    
    cout << count << "\n";
    return 0;
}
