#include <iostream>

using namespace std;

struct Point {
	int x;
	int y;
};

struct Queue {
	struct Point* A;
	int rear;
	int front;
	int size;
	int capacity;
};

struct Queue enqueue( struct Queue Q, struct Point P ) {
	Q.A[ Q.rear ] = P;
	Q.rear = ( Q.rear + 1 ) % Q.capacity;
	Q.size += 1;
	return Q;
}

bool isEmpty( struct Queue Q ) {
		
	return ( Q.size == 0 );
}

struct Queue dequeue( struct Queue Q ) {
	if( !isEmpty( Q ) ) {
		Q.front = ( Q.front + 1 ) % Q.capacity;
		Q.size -= 1;
	}
	return Q;
}

struct Point frontElement( struct Queue Q ) {
	
	if( !isEmpty( Q ) ) {
		return A[ Q.front ];
	}
	struct Point P = {-1, -1};
	return P;
}

struct Queue init( int n ) {
	struct Queue Q;
	Q.A = new int[ n ];
	Q.front = Q.rear = Q.size = 0;
	Q.capacity = n;
	return Q;
}

void clearQueue( struct Queue Q ) {
	delete Q.A;
	Q.front = Q.rear = Q.size = Q.capacity = 0;
}

void BFS( struct Point P, struct Point Q ) {
	
}
int main() {
	
	ios_base::sync_with_stdio(false);

	return 0;
}