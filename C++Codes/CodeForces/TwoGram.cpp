#include <iostream>

using namespace std;

struct Node {
	int count;
};

struct Node arr[3000];

char st[101];
int globalCt;
char fStr[3];

int main() {
	
	int n, i, val, v;
	globalCt = 0;

	for( i = 0;i < 3000;i++ ) {
		arr[i].count = 0;
	}
	cin >> n;
	cin >> st;
	
	for( i = 0;i < n - 1;i++ ) {
		val = ( st[ i ] - 'A' ) * 100 + ( st[ i + 1 ] - 'A');
		arr[ val ].count += 1;
		v = arr[ val ].count;
		if( v > globalCt ) {
			globalCt = v;
			fStr[0]= st[i];
			fStr[1] = st[i+1];
			fStr[2] = '\0';
		}
	}

	cout << fStr << "\n";
	return 0;
}
