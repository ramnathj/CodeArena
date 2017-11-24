#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool DFSUtil( vector< vector<int> >& A, int u, vector<bool>& visit, vector<bool>& recStack ) {

    visit[ u ] = true;
    recStack[ u ] = true;
    vector<int> :: iterator it;
    int v;
    for( it = A[ u ].begin();it != A[ u ].end();it++ ) {
        v = *it;
        if( !visit[ v ] && DFSUtil( A, v, visit, recStack )) {
            return true;
        } else if( recStack[ v ] ) {
            return true;
        }
    }

    recStack[ u ] = false;
    return false;
}

bool DFS( vector< vector<int> >& A, int n ) {
    
    vector<bool> visit( n + 1, false );
    vector<bool> recStack( n + 1, false );

    int i;
    
    for( i = 1;i < n;i++ ) {
        if( !visit[ i ] ) {
            if( DFSUtil( A, i, visit, recStack ) ) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    
    ios_base::sync_with_stdio( false );
    
    int t, n, i, k, j, val, m;
    
    cin >> t;
    cin.ignore();
    
    while( t-- ) {
        
        cin >> n;
        map<string, int> M;
        val = 1;
        cin.ignore();
        vector<vector<int> > A( 1000, vector<int>() );
        
        for( j = 0;j < n;j++ ) {

            string str;
            vector<string> arr;
            getline( cin, str );

            string s = "";
            for( i = 0;i < str.length();i++ ) {
                
                if( str[ i ] == ',' ) {
                    if( !M[ s ] ) {
                       M[ s ] = val;
                       val++;
                    }
                    arr.push_back(s);
                    s = "";
                } else {
                    s = s + str[ i ];
                }
            }
            
            if( !M[ s ] ) {
                M[ s ] = val;
                val++;
            }
            arr.push_back(s);
            k = arr.size();
            
            for( i = 0;i < k - 1;i++ ) {
                A[ M[ arr[ i ] ] ].push_back( M[ arr[ i + 1 ] ] );
            }
                        
        }
        
        if( DFS( A, val ) ) {
            cout << "ORDER VIOLATION\n";
        } else {
            cout << "ORDER EXISTS\n";
        }
    }
    return 0;
}
