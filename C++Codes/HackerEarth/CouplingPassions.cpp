#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>

using namespace std;

double D2R( double val ) {

	double PII = 3.14159265359;
	return ( val * PII ) / 180.0;
}

double Calc( double lat1, double lon1, double lat2, double lon2 ) {
	
	double ER = 6371.0;
	double p1lat = D2R( lat1 );
	double p2lat = D2R( lat2 );
	double p1lon = D2R( lon1 );
	double p2lon = D2R( lon2 );

	double v1 = sin( p1lat ) * sin( p2lat );
	double v2 = cos( p1lat ) * cos( p2lat );
	double v3 = cos( p2lon - p1lon );
	double v4 = acos( v1 + ( v2 * v3 ) );

	return v4 * ER;
}

int main() {
	
	ios_base::sync_with_stdio( false );

	int n, m, y, z, i, j, k, maxVal, d1, d2;

	string d, s;

	cin >> n;
	set<string> S;

	for( i = 0;i < n;i++ ) {
		cin >> m;
		for( j = 0;j < m;j++ ) {
			cin >> s;
			S.insert( s );
		}
	}

	cin >> y;
	map<int, string> M;
	vector<double> lat( y ), lon( y );
	vector<vector<string> > V( y, vector<string>() );

	for( i = 0;i < y;i++ ) {
		cin >> d;
		M[ i ] = d;
		cin >> lat[ i ] >> lon[ i ] >> z;

		for( j = 0;j < z;j++ ) {
			cin >> s;
			if( S.find( s ) != S.end() ) {
				V[ i ].push_back( s );
			}
		}
	}

	vector<vector<double> > dist( y, vector<double> ( y ) );

	for( i = 0;i < y;i++ ) {
		for( j = i + 1;j < y;j++ ) {
			dist[ i ][ j ] = Calc( lat[ i ], lon[ i ], lat[ j ], lon[ j ] );
		}
	}

	vector<vector<int> > num( y, vector<int> ( y ) );

	for( i = 0;i < y;i++ ) {
		for( j = i + 1;j < y;j++ ) {

			set<string> S2;

			for( k = 0;k < V[ i ].size();k++ )
				S2.insert( V[ i ][ k ] );
			for( k = 0;k < V[ j ].size();k++ )
				S2.insert( V[ j ][ k ] );

			num[ i ][ j ] = S2.size();
		}
	}

	maxVal = -1;
	d1 = d2 = 0;

	for( i = 0;i < y;i++ ) {

		for( j = i + 1;j < y;j++ ) {
			if( num[ i ][ j ] > maxVal ) {
				maxVal = num[ i ][ j ];
				d1 = i;
				d2 = j;
			} else if( num[ i ][ j ] == maxVal ) {
				if( dist[ i ][ j ] < dist[ d1 ][ d2 ] ) {
					d1 = i;
					d2 = j;
				}

			}
		}
	}

	string str1 = M[ d1 ];
	string str2 = M[ d2 ];

	if( str1.compare( str2 ) < 0 )
		cout << str1 << " " << str2 << "\n";
	else
		cout << str2 << " " << str1 << "\n";

	return 0;

}
