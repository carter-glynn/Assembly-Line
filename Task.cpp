/********************************************
Author:	Carter Glynn
Email:	cglynn7212@conestogac.on.ca
SN:		8657212
*********************************************/
#include <iostream>
#include "Task.h"
#include <random>

//--------Task Function Definitions--------
Task::Task(std::string s) {
	Name = s;

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> random(1, 20); // random number of items in inventory between 1 and 15
	std::uniform_int_distribution<std::mt19937::result_type> serial(1000000, 9999999); // random 7 digit serial number
	int numInv = random(rng);
	std::cout << Name << " Inventory is " << numInv << std::endl;
	for (int i = 0; i < numInv; i++) {
		Item* inv = new Item;
		inv->Name = s;
		inv->SN = serial(rng);
		Inventory.push(inv);
	}
}
void Task::Run() {
	if (ProdQ.empty()) {												//if nothing in queue, console print
		//std::cout << Name << " Product queue is empty! (On Run)" << std::endl;
		return;
	}
	else {
		if (!Inventory.empty()) {

			for (int i = 0; i < 7; i++) {	//check all components in product
				//Catches error where front of queue gets assigned value that doesn't exist from empty inventory
				if (Inventory.empty()) {
					ProdQ.front()->state = Status::Backorder;
					return;
				}
				if ((Name == ProdQ.front()->Components[i].Name) && (ProdQ.front()->Components[i].SN == 0)) {			//if the names of any required components are the same as the task name

					ProdQ.front()->Components[i].SN = Inventory.top()->SN;	//add item to product with S/N
					Inventory.pop();										//get rid of item from inventory

					//std::cout << Name << " added to Product #" << ProdQ.front()->SN << std::endl;

				}
			}
			if (ProdQ.front()->state != Status::Backorder) {
				ProdQ.front()->state = Status::Complete;
			}
		}
		else {																//if inventory is empty
			ProdQ.front()->state = Status::Backorder;
			//set product status to backorder
			std::cout << Name << " Inventory is empty!" << std::endl;
		}
	}

}
Product* Task::MoveProduct() {
	//Product* returnedProduct = ProdQ.front();							//set variable to be returned from function
	if (!ProdQ.empty()) {												//if the product queue of this task isn't empty
		Product* moveProd = ProdQ.front();
		if (moveProd->state == Status::Complete || moveProd->state == Status::Backorder) {
			this->ProdQ.pop(); // Remove product from this queue.
			return moveProd;
		}
		return nullptr;												//return product to main
	}
	else {
		//std::cout << Name << " Product queue is empty! (On Move)" << std::endl;
		return nullptr;
	}
}
void Task::AddProduct(Product* prod) {
	prod->state = Status::InComplete;									//default state of product is incomplete
	ProdQ.push(prod);
	//std::cout << "Product " << prod->SN << " added to Task" << Name << std::endl;
}