#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};


void deleteNode( struct Node* ptr ) {
	
	ptr->prev->next = ptr->next;
	ptr->next->prev = ptr->prev;
	delete ptr;
}

int main() {
	
	ios_base::sync_with_stdio( false );

	int t, n, m, p, i;
	cin >> t;
	while( t-- ) {
		cin >> n >> m >> p;
		struct Node* root = new Node;
		root->data = 1;
		struct Node* head = root;
		struct Node* nxt = NULL;

		for( i = 1;i < n;i++ ) {
			head->next = new Node;
			head->next->data = i + 1;
			head->next->prev = head;
			head = head->next;	
		}

		head->next = root;
		root->prev = head;

		head = root;

		for( i = 1;i < m;i++ ) {
			head = head->next;	
		}

		i = 1;
		while( n != 1 ) {
			
			for( ;i <= p;i++ ) {
				head = head->next;
			}
			nxt = head->next;
			deleteNode( head );
			head = nxt;
			i = 2;
			n--;		
		}

		cout << head->data << "\n";
	}
	return 0;
}