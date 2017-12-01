#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Node {
    
    char ch;
    struct Node* child[ 26 ];
    bool isEnd;
    int ct;
};

struct Node* createNode( char val ) {
    
    int i;
    struct Node* p = new Node;
    p->ch = val;
    for( i = 0;i < 26;i++ ) {
        p->child[ i ] = NULL;
    }
    p->isEnd = false;
    p->ct = 1;
    return p;
}

int main() {

    int t, i, j, count;
    bool flag;
    
    struct Node* T = createNode(' ');
    struct Node* head = T;
    cin >> t;
    
    while( t-- ) {
        char *cmd = new char[ 22 ];
        char *str = new char[ 22 ];
        
        cin >> cmd >> str;
        
        if( cmd[ 0 ] == 'a' ) {
            T = head;
            for( i = 0;str[ i ];i++ ) {
                if( T->child[ str[ i ] - 'a' ] == NULL ) {
                    T->child[ str[ i ] - 'a' ] = createNode( str[ i ] );
                } else {
                    T->child[ str[ i ] - 'a' ]->ct++;
                }
                if( str[ i + 1 ] == '\0' ) {
                    T->child[ str[ i ] - 'a' ]->isEnd = true;
                }           
                T = T->child[ str[ i ] - 'a' ];
            }
        } else {
            
            struct Node* node = head;
            flag = true;
            
            if( node != NULL ) {
                for( i = 0;str[ i ];i++ ) {
                    if( node->child[ str[ i ] - 'a' ] == NULL ) {
                        flag = false;
                        break;
                    }
                    node = node->child[ str[ i ] - 'a' ];
                }

                if( flag ) {
                    cout << node->ct << "\n";
                } else {
                    cout << "0\n";
                }
            } else {
                cout << "0\n";
            }
        }
        delete cmd;
        delete str;
        
    }
    return 0;
}
