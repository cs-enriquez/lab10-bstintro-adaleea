#include <iostream>

using namespace std;

// Implement the node class we will need for our Binary Search Tree
class Node {
	public:
		// the Node should contain
		int key;// 	- an integer "key" that holds the value of the Node
		Node* left;// 	- a pointer to each child possible child node ("right" and "left")
		Node* right;

		Node(int keyValue){// Write a constructor for the Node
		key = keyValue;// input: only an integer value for "key", no pointer arguments
		left = nullptr;// 		right and left pointers should be null
		right = nullptr;
		}
};

Node* insert(Node* root, int value){
	if (root == nullptr){
		return new Node(value);
	}
	if (value < root->key){
		root->left = insert(root->left, value);
	}
	else if(value > root->key){
		root->right = insert(root->right, value);
	}
	return root;
}

// Use this function to create a Binary Search Tree (BST) tree with the following values
// {13, 0, 7, 6, 21, 15, -2, 12, 99, 18, 19, -1}
Node* createTree() {
	int value[] = {13, 0, 7, 6, 21, 15, -2, 12, 99, 18, 19, -1};
	// root
	Node *root = nullptr;
	for(int value : value){
		root = insert(root, value);
	}
	// level 1 (children of root)

	// level 2 (children of 0)

	// level 2 (children of 21)

	// level 3 (children of -2)

	// level 3 (children of 7)

	// level 3 (children of 15)

	// level 3 (children of 99)

	// level 4 (children of 18)

	return root;
}

// Write a function that will search the BST for a target value
//	input: integer target to search for,
			// pointer to root Node
// 	returns: true or false depending on if the value is found
// You should write this function recursively! What is the base case? What is the general case?
bool searchTree(int target, Node* root) {
	// Base cases
	if(root == nullptr){
	return false;
	}
	if(root->key == target){
		return true;
	}
	// General case
	if(target < root->key){
	return searchTree(target, root->left);
	}
	else{
		return searchTree(target, root->right);
	}
}

// Write a function that will return the total number of Nodes in the tree
// 	input: pointer to the root Node
// 	returns: number of nodes currently in the tree
// You should write this function recursively!
int treeSize(Node* root) {
	// base case
	if(root == nullptr){
	return 0;
	}

	// General case
	return 1 + treeSize(root-> left) + treeSize(root->right);

}

// BONUS! Write a function that will determine the height of the tree
int treeHeight(Node* root) {
	// base case
	if ( root == nullptr){
	return -1;}

	// General case
	return 1 + max(treeHeight(root->left), treeHeight(root->right));
}
