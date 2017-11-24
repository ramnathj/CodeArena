#include <iostream>
#include <math.h>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio( false );

	int t, p, x, y, ct = 1;
	double val, theta, angle, v1, v2, d, num, deno;

	cin >> t;

	while( ct <= t ) {

		cin >> p >> x >> y;
		theta = static_cast<double>( p ) * 3.60;
		v1 = static_cast<double>( x ) - 50.0;
		v2 = static_cast<double>( y ) - 50.0;
		d = v1 * v1 + v2 * v2;
		num = v1;
		deno = sqrt( d );
		val = asin( num / deno );
		angle = ( val * 180.0 ) / M_PI;

		if( ( d <= 2500 ) && ( angle <= theta ) ) {
			cout << "Case #" << ct << ": black\n";
		} else {
			cout << "Case #" << ct << ": white\n";
		}

		ct++;
	}

	return 0;
}
