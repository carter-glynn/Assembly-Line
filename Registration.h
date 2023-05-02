/********************************************
Author:	Carter Glynn
Email:	cglynn7212@conestogac.on.ca
SN:		8657212
*********************************************/
#ifndef REGISTRATION_H_
#define REGISTRATION_H_

struct Node {
	int SN;
	Node* left, * right;
};

//--------------External Root Definition--------------
extern Node* root;

class Registration
{
public:
	Registration();
	bool RegisterProduct(unsigned int);
	bool IsRegistered(unsigned int);
	void DisplayPreorder();
};

#endif /* REGISTRATION_H_ */