#include <iostream>

using namespace std;

char s[51];
char t[51];
int main() {
	
	int n, i, k = 0, j;
	char tmp;
	
	cin >> t;
	for(n=0;t[n];n++ );
	
	i = 0;
	j = n - 1;

	if( n & 0x1 ) {
		while( k < n ) {

			s[k++] = t[i];

			if( k == n ) {
				break;
			}

			s[k++] = t[j];
			i++;
			j--;
		}
	} else {
		while( k < n ) {

			s[k++] = t[j];

			if( k == n ) {
				break;
			}

			s[k++] = t[i];
			i++;
			j--;
		}	
	}
	s[k] = '\0';

	for( i = 0;i < k / 2;i++ ) {
		tmp = s[i];
		s[i] = s[k-i-1];
		s[k-i-1] = tmp;
	}

	cout << s << "\n";

	return 0;
}
