/********************************************
Author:	Carter Glynn
Email:	cglynn7212@conestogac.on.ca
SN:		8657212
*********************************************/
#ifndef LINE_H_
#define LINE_H_

#include "Task.h"
#include "Structures.h"

//--------Class declarations--------
class AssemblyLine {
private:
    Task* pTask;
    AssemblyLine* pNext;
public:
    AssemblyLine(Task*);
    bool Push(AssemblyLine*);
    void Run();
    Product* MoveProduct();
    void AddProduct(Product*);
    AssemblyLine* GetNext();    //returns pNext
};

//--------External Declarations--------
extern AssemblyLine* head;

#endif /* LINE_H_ */