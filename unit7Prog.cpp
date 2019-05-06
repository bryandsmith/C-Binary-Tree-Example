// Written by Bryan Smith
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
struct node {
public:
	int nodeValue;
	struct node *left, *right;
};
struct node *newNode(int item)//make a new node
{
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->nodeValue = item;
	temp->left = temp->right = NULL;
	return temp;
}
struct node* insert(struct node* node, int key)//insert function to call newNode in correct location (recursion is used)
{
	if (!node) { //tree is empty
		return newNode(key);
	}
	if (key < node->nodeValue) { //node belongs on the left
		node->left = insert(node->left, key);
	}
	else if (key > node->nodeValue) { //node belongs on the right
		node->right = insert(node->right, key);
	}
	return node;
}
static bool search(struct node* root, int key) //searches through tree and returns true if value found(recursion is used)
{	
	if (!root) {
		return false;
	}
	if (root->nodeValue == key) {
		return true;
	}
	if (root->nodeValue < key) {
		return search(root->right, key);
	}
	return search(root->left, key);
}
int main()
{
	int input = 0;
	bool found = false;
	struct node *root = NULL;
	root = insert(root, 35);
	insert(root, 18);
	insert(root, 48);
	insert(root, 72);
	insert(root, 60);
	insert(root, 25);
	while (true) { //infinite loop (just for input simplicity)
		cout << "Enter Integer to search for: ";
		cin >> input;
		cout << "\n";
		found = search(root, input);
		if (found) {
			cout << "True\n";
		}
		else {
			cout << "False\n";
		}
	}
	system("PAUSE");
}