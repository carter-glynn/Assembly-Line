/********************************************
Author:	Carter Glynn
Email:	cglynn7212@conestogac.on.ca
SN:		8657212
*********************************************/
#ifndef TASK_H_
#define TASK_H_

#include "Structures.h"
#include <queue>
#include <stack>

//--------Class declarations--------
class Task {
private:
    std::string Name;
    std::queue<Product*> ProdQ;
    std::stack<Item*> Inventory;
public:
    Task(std::string);
    void Run();
    Product* MoveProduct();
    void AddProduct(Product*);
};

#endif /* TASK_H_ */