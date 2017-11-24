#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio( false );

	string s;
	int n, i, j;
	unordered_set<string> S;

	cin >> s;
	n = s.length();

	for( i = 0;i < n;i++ ) {
		string str = "";
		for( j = 0;j < n - i;j++ ) {
			str += s[ i + j ];
			S.insert( str );
		}
	}

	cout << S.size() << "\n";

	return 0;
}