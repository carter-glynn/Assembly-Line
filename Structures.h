/********************************************
Author:	Carter Glynn
Email:	cglynn7212@conestogac.on.ca
SN:		8657212
*********************************************/
#ifndef STRUCTURES_H_
#define STRUCTURES_H_

#include <iostream>

//--------Enum class to keep track of product status--------
enum class Status
{
    InComplete, Complete, Backorder
};

//--------Structure declarations--------
struct Item
{
    std::string Name;
    unsigned int SN;
};
struct Product
{
    unsigned int SN;
    Item Components[8];
    Status state;          //product status has been added as a variable
};

#endif /* STRUCTURES_H_ */