/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root,string s)
{
    int i, len = s.length();
    char ch;
    string str = "";
    node *start = root;
    for( i = 0;i < len;i++ ) {
        ch = s[ i ];
        if( ch == '1' ) {
            start = start->right;
            if( start->data != '\0' ) {
                str = str + start->data;
                start = root;
            }
        } else {
            start = start->left;
            if( start->data != '\0' ) {
                str = str + start->data;
                start = root; 
            }
        }
    }
    cout << str << "\n";
}
