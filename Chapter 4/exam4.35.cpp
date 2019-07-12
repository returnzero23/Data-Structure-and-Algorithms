#include <iostream>

using namespace std;

struct Node {
	int ele;
	Node* left = nullptr;
	Node* right = nullptr;
};

Node* genAVLTreeInner(int height, int& lastValue) {
	if (height < 0) return nullptr;
	Node* node = new Node();
	node->left = genAVLTreeInner(height - 2, lastValue);
	node->ele = ++lastValue;
	node->right = genAVLTreeInner(height - 1, lastValue);
	return node;
};

void genAVLTree(int height, Node*& root) {
	int value = 0;
	root = genAVLTreeInner(height, value);
}

void PrintAVLtree(Node* node) {
	if (node == nullptr) return;
	PrintAVLtree(node->left);
	cout << node->ele << endl;
	PrintAVLtree(node->right);
}

int main() {
	Node* root = nullptr;
	genAVLTree(3, root);

	PrintAVLtree(root);

	return 0;
}