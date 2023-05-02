/********************************************
Author:	Carter Glynn
Email:	cglynn7212@conestogac.on.ca
SN:		8657212
*********************************************/
#include <iostream>
#include "Line.h"

//--------External Declarations--------
AssemblyLine* head = nullptr;

//--------AssemblyLine Function Definitions--------
AssemblyLine::AssemblyLine(Task* task) {
	pTask = task;
	pNext = nullptr;
}
bool AssemblyLine::Push(AssemblyLine* addtoLine) {
	if (addtoLine == nullptr) {											//if object to be added is null
		std::cout << "Provided AssemblyLine object is nullptr" << std::endl;
		return false;													//return problem state
	}
	if (head == nullptr) {												//if the head of the assembly line is null
		head = addtoLine;												//create assembly line with object provided
		return true;
	}

	AssemblyLine* newLine = addtoLine;									//create new assembly line
	newLine->pNext = nullptr;											//set next to nullptr (linked list)
	AssemblyLine* last = head;											//set last to head pointer

	while (last->pNext != nullptr) {
		last = last->pNext;												//iterate through list
	}

	last->pNext = newLine;												//add to list

	return true;
}
void AssemblyLine::Run() {
	pTask->Run();
}
Product* AssemblyLine::MoveProduct() {
	return pTask->MoveProduct();
}
void AssemblyLine::AddProduct(Product* prod) {
	pTask->AddProduct(prod);
}
AssemblyLine* AssemblyLine::GetNext() {
	return pNext;
}