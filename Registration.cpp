/********************************************
Author:	Carter Glynn
Email:	cglynn7212@conestogac.on.ca
SN:		8657212
*********************************************/
#include <iostream>
#include <stack>
#include "Registration.h"

//--------------Initializing Root--------------
Node* root = nullptr;

Registration::Registration() {
	root = nullptr;
}

bool Registration::RegisterProduct(unsigned int key) {
	Node* node = new Node;
	node->SN = key;
	node->left = nullptr;
	node->right = nullptr;
	
	if (IsRegistered(key)) { //checks if product is already registered
		return false;
	}

	if (root == nullptr) {	//if root doesn't exist insert this as the root
		root = new Node;
		root->SN = key;
		root->left = nullptr;
		root->right = nullptr;
		return true;
	}

	Node* temp = root;
	Node* prev = NULL;

	while (temp) {	//while temp is not NULL
		if (temp->SN > key) {	//if root's SN is bigger than key
			if (temp != nullptr) {	//and if root exists
				prev = temp;		//move onto next leftmost branch
				temp = temp->left;
			}
			else {					//and root doesn't exist
				temp->SN = key;	//create a blank 'root'
				temp->left = nullptr;
				temp->right = nullptr;
				break;
			}
		}
		else if (temp->SN < key) {	//if root's SN is less than key
			if (temp != nullptr) {		//and root exists
				prev = temp;			//move onto next rightmost branch
				temp = temp->right;
			}
			else {					//and root doesn't exist
				temp->SN = key;	//create a blank 'root'
				temp->left = nullptr;
				temp->right = nullptr;
				break;
			}
		}
	}

	if (prev->SN > key) { //if previous node's SN is bigger than key, insert at previous node's left
		prev->left = node;
	}
	else {					//if previous node's SN is bigger than key, insert at previous node's right
		prev->right = node;
	}
}

bool Registration::IsRegistered(unsigned int key) {
	Node* temp = nullptr;
	if (temp == nullptr) {	//ensures temp is set as root so root doesn't get changed
		temp = root;
	}
	while (temp) {	//while temp is not nullptr
		if (temp == nullptr || temp->SN == key) { //check for non-existant root or if root is what is being searched for
			return true;
		}
		if (temp->SN < key) {	//if root value is bigger than key
			temp = temp->right;		//check right branch
		}
		else if (temp->SN > key) {	//if root value is smaller than key
			temp = temp->left;			//check left branch
		}
		else {				//if tree cannot be traversed further
			return false;	//return false
		}
	}
}

void Registration::DisplayPreorder() {
	if (root == nullptr) {
		return;
	}

	std::stack<Node*> preorder;	//create preorder
	preorder.push(root);	//push root to preorder

	while (!preorder.empty())
	{
		Node* temp = preorder.top();	//create temp node to be top of stack
		preorder.pop();					//pop and print 

		std::cout << temp->SN << ",";		//comma for desired output

		if (temp->right) {
			preorder.push(temp->right);	//push right branch into order (populates bottom of stack)
		}

		if (temp->left) {
			preorder.push(temp->left);	//push left branch into order (populates top of stack)
		}
	}
	std::cout << std::endl << std::endl;;
}