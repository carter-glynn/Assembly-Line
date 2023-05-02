# AssemblyLine

## Overview
Design and implement a simulated assembly line using data structure techniques. 
Write a C++ object oriented program that takes input from a file to build products, 
passes those products through the assembly line to be manufactured and then registers
them based on product serial number afterwards.

## Goal
* Create several Task objects linked together using a single-ended link list representing the assembly line. 
* Each task will have a queue for products being processed and a stack with available inventory. 
* Each task will be connected to the next via a pointer (single ended link list). 
* The output of the assembly line will be two arrays, a backordered products and completed products. 
* All completed products will be registered using the registration module, which consist of a binary tree based on Product serial numbers

## Structures
```
struct Item  {
    std::string Name;
    unsigned int SN;
};

struct Product  {
    unsigned int SN;
    Item Components[8];
};
```
## Classes
### Task
The task class is responsible for managing one item on the assembly. As a product is 
presented to the task it will check to see if the product requires one of its items. 
If it does, it will pop an item off the inventory stack and update the product with the S/N from the inventory

### AssemblyLine
The AssemblyLine object is the wrapper class (or container class) that makes a single station on the
assembly line. Essentially the AssemblyLine is the data type of your single-ended link list

### Registration
The registration system will consist of a single registration class that will store the S/N’s of all completed
Products using a binary tree. It will also provide the ability to traverse the tree, in a fast and efficient
manner, to determine if a product was registered or not
