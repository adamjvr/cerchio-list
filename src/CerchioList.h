/*
MIT License

Copyright (c) 2024 Adam Vadala-Roth

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef CERCHIO_LIST_H
#define CERCHIO_LIST_H

#include <Arduino.h>

// Define a simple data structure to be stored in the list
template <typename T>
struct CerchioListNode {
    T data;                // Data of the node, templated to allow any type
    CerchioListNode* next; // Pointer to the next node in the list

    // Constructor to initialize the node with data
    CerchioListNode(T val) : data(val), next(nullptr) {}
};

// Define the intrusively linked list class
template <typename T>
class CerchioList {
public:
    // Constructor: Initializes the list with an empty head
    CerchioList();

    // Destructor: Frees memory by deleting all nodes
    ~CerchioList();

    // Function to add a node to the list
    void addNode(T val);

    // Function to remove a node from the list
    void removeNode(T val);

    // Function to print the elements of the list
    void printList();

private:
    CerchioListNode<T>* head; // Pointer to the first node in the list
};

#endif // CERCHIO_LIST_H
