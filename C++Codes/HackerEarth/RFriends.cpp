#include <iostream>

using namespace std;

struct Node {
	
	int data;
	struct Node* next;	
};

struct Node* createNode( int val ) {
	struct Node* p = new Node;
	p->data = val;
	p->next = NULL;

	return p;
}

int main() {
	
	ios_base::sync_with_stdio( false );

	int t, n, i, k, val;

	cin >> t;

	while( t-- ) {

		cin >> n >> k;

		cin >> val;

		struct Node* root2 = createNode( val );
		struct Node* head = root2;

		for( i = 1;i < n;i++ ) {
			cin >> val;
			root2->next = createNode( val );
			root2 = root2->next;
		}

		for( i = 1;i <= k;i++ ) {

			struct Node* root = head;
			struct Node* prev = NULL;

			int flag = 0;
			while( root != NULL && root->next != NULL ) {
				if( root->data < root->next->data ) {
					flag = 1;
					//Delete Root
					root->data = root->next->data;
					struct Node* tmp = root->next;
					root->next = root->next->next;
					delete tmp;
					break;
				}
				prev = root;
				root = root->next;
			}
			if( !flag ) {
				if( prev != NULL ) {
					delete root;
					prev->next = NULL;
				} else {
					delete root;
					head = NULL;
				}
			}
		}

		 struct Node* root = head;

		 while( root != NULL ) {
		 	cout << root->data << " ";
		 	root = root->next;
		 }
		 cout << "\n";
	}

	return 0;
}
