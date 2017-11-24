#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

#define START 1465948800
#define END 1468540800

using namespace std;

int Score( long tym ) {
	
	if( ( tym >= START ) && ( tym <= END ) )
		return 20;
	else
		return 10;
}

int main() {
	
	ios_base::sync_with_stdio( false );

	int n, m, i, rId, rScore, lenScore, j, id, maxVal;
	long long int tym;

	cin >> n >> m;
	vector<string> A( n );

	for( i = 0;i < n;i++ ) {
		cin >> A[ i ];
		std::transform(A[ i ].begin(), A[ i ].end(), A[ i ].begin(), ::tolower);
	}

	vector<vector<int> > PR( n, vector<int>() );
	map<int, int> RS;

	for( i = 0;i < m;i++ ) {

		cin >> rId >> tym;
		rScore = Score( tym );
		cin.ignore();
		string s;
		getline( cin, s );
		std::transform(s.begin(), s.end(), s.begin(), ::tolower);
		lenScore = ( s.length() >= 100 ) ? 20 : 10;

		for( j = 0;j < n;j++ ) {
			if( s.find( A[ j ] ) != -1 ) {
				PR[ j ].push_back( rId );
				RS[ rId ] += ( rScore + lenScore );
			}
		}
	}

	for( i = 0;i < n;i++ ) {
		cout << A[ i ] << "->";
		for( j = 0;j < PR[ i ].size();j++ ) {
			cout << PR[ i ][ j ] << " ";
		}
		cout << "\n";
	}

	for( i = 0;i < n;i++ ) {
		maxVal = -1;
		id = -1;
		for( j = 0;j < PR[ i ].size();j++ ) {
			if( RS[ PR[ i ][ j ] ] > maxVal ) {
				maxVal = RS[ PR[ i ][ j ] ];
				id = PR[ i ][ j ];
			} else if( RS[ PR[ i ][ j ] ] == maxVal ) {
				if( id > PR[ i ][ j ] ) {
					id = PR[ i ][ j ];
				}
			}
		}
		cout << id << "\n";
	}

	return 0;
}