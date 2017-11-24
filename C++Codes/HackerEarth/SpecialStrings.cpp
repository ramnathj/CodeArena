#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <map>

using namespace std;

map<string, bool> M;
vector<string> A;
vector<int> B;

bool Check( string s ) {
	
	if( M[ s ] ) {
		return false;
	}
	M[ s ] = true;
	int i, n = A.size(), val;

	for( i = 0;i < n;i++ ) {
		val = A[ i ].find( s );
		if( !( ( val >= 0 ) && ( val < A[ i ].length() ) ) )
			return false;
	}
	
	return true;
}

int main()
{
	ios_base::sync_with_stdio( false );
	
	int n, i, pos, minVal, len, count, j;

	cin >> n;

    pos = -1;
    minVal = INT_MAX;
    string p;
    for( i = 0;i < n;i++ ) {
    	cin >> p;
    	A.push_back( p );
    	B.push_back( p.length() );
    	if( B[ i ] < minVal ) {
    		minVal = B[ i ];
    		pos = i;
    	}
    }
    
    string s = A[ pos ];
    len = B[ pos ];

    count = 0;
    for( i = 0;i < len;i++ ) {
    	string str = "";
    	str = s[ i ];
    	if( Check( str ) )
    		count++;
    	for( j = 1;j < len - i;j++ ) {
    		if( s[ i + j ] < s[ i + j - 1 ] ) {
    			break;
    		}
    		string s2 = "";
    		s2 = s[ i + j ];
    		str = str + s2;
    		if( Check( str ) )
    			count++;
    	}
    }
 
    cout << count << "\n";
    
    return 0;
}
