/********************************************
Author:	Carter Glynn
Email:	cglynn7212@conestogac.on.ca
SN:		8657212
*********************************************/

#include <iostream>
#include "Line.h"
#include "Registration.h"
#include <fstream>
#include <string>
#include <vector>
#define COUNT 10
//--------------Array Definitions--------------
std::vector<Product*> backorder;
std::vector<Product*> completed;

void RunBacktoFront() { //runs the Run() function from the back to the frontn of the assembly line
    AssemblyLine* LastReverseOrder = nullptr;
    while (LastReverseOrder != head) {
        AssemblyLine* prev = nullptr;
        AssemblyLine* curr = head;
        while (curr != LastReverseOrder) {
            prev = curr;
            curr = curr->GetNext();
        }
        LastReverseOrder = prev;
        prev->Run();

    }
}

void MoveFronttoBack() { //moves products along the assemby line
    AssemblyLine* currentTask = head;

    while (currentTask != nullptr) {
        Product* movedProd = currentTask->MoveProduct();
        if ((movedProd != nullptr) && (currentTask->GetNext() != nullptr)) {
            movedProd->state = Status::InComplete;
            currentTask->GetNext()->AddProduct(movedProd);
        }
        else if ((movedProd != nullptr) && (currentTask->GetNext() == nullptr)) {
            for (int i = 0; i < 8; i++) {
                if (movedProd->Components[i].SN == NULL) {
                    movedProd->state = Status::Backorder;
                }
            }
            if (movedProd->state == Status::Complete) {
                completed.push_back(movedProd);
            }
            else if (movedProd->state == Status::Backorder) {
                backorder.push_back(movedProd);
            }
        }
        currentTask = currentTask->GetNext();
    }
}
//--------------Run 1 AssemblyLine Cycle--------------
void RunProduct() {
    RunBacktoFront();
    MoveFronttoBack();
}

int main()
{
    const std::vector<std::string> items = { "CPU", "GPU", "RAM", "Monitor", "Controller", "VR Headset", "AR Glasses"};
    int numItems = items.size();

    //--------------Creating Linked List--------------
    for (int i = 0; i < numItems; i++) {        
        Task* tempTask = new Task(items[i]);
        AssemblyLine* tempAssemblyLine = new AssemblyLine(tempTask);
        head->Push(tempAssemblyLine);
    }

    std::string input;
    std::ifstream InputProducts("InputProducts.txt");

    int prodCount = 0;
    int itemCount = 0;
    Product* newProd = nullptr;

    //--------------Getting Input--------------
    while (getline(InputProducts, input)) {
        if (input[0] != '-') {
            //New Products
            prodCount++;

            newProd = new Product;
            newProd->SN = std::stoul(input);
            itemCount = 0;

            head->AddProduct(newProd);
        }
        else {
            //New Items
            Item newItem = Item();

            newItem.Name = input.erase(0, 1);
            newItem.SN = 0;
            newProd->Components[itemCount] = newItem;

            itemCount++;
        }
    }
    while ((backorder.size() + completed.size()) != prodCount) {
        RunProduct();
    }

    InputProducts.close();

    //--------------Creating and Printing Binary Tree--------------
    Registration* regSN = new Registration;
    for (int i = 0; i < completed.size(); i++) {
        regSN->RegisterProduct(completed[i]->SN);
    }
    std::cout << std::endl << "Preorder print of tree" << std::endl;
    regSN->DisplayPreorder();

    //--------------Printing Arrays--------------
    std::cout << "Backlogged Products: (" << backorder.size() << ")" << std::endl;
    for (int i = 0; i < backorder.size(); i++) {
        
        std::cout << backorder[i]->SN << std::endl;
    }
    std::cout << "Completed Products: (" << completed.size() << ")" << std::endl;
    for (int i = 0; i < completed.size(); i++) {
        
        std::cout << completed[i]->SN << std::endl;
    }
    return 0;
}
