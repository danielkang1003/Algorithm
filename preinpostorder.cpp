#include<iostream>

using namespace std;

const int number = 15;

typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;

void preorder(treePointer ptr) {
	if (ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main() {
	node nodes[number + 1];
	for (int i = 1; i <= number; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	for (int i = 1; i <= number; i++) {
		if (i % 2 == 0) nodes[i / 2].leftChild = &nodes[i];
		else nodes[i / 2].rightChild = &nodes[i];
	}
	preorder(&nodes[1]);
	cout << '\n';
	inorder(&nodes[1]);
	cout << '\n';
	postorder(&nodes[1]);
}