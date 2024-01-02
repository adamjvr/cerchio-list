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

#include "cerchio_list.h"

// Constructor definition
template <typename T>
CerchioList<T>::CerchioList() : head(nullptr) {}

// Function to add a node to the list
template <typename T>
void CerchioList<T>::addNode(T val) {
    CerchioListNode<T>* newNode = new CerchioListNode<T>(val); // Create a new node
    newNode->next = head; // Point the new node to the current head
    head = newNode; // Update the head to the new node
}

// Function to remove a node from the list
template <typename T>
T CerchioList<T>::removeNode(T val) {
    CerchioListNode<T>* current = head;
    CerchioListNode<T>* prev = nullptr;
    T removedValue = T(); // Default value if the element is not found

    // Search for the node with the specified value
    while (current != nullptr && current->data != val) {
        prev = current;
        current = current->next;
    }

    // If the node with the specified value is found
    if (current != nullptr) {
        removedValue = current->data; // Save the value of the removed node

        // If the node is the head of the list
        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current; // Free the memory of the removed node
    }

    return removedValue;
}

// Function to print the elements of the list
template <typename T>
void CerchioList<T>::printList() {
    CerchioListNode<T>* current = head; // Start from the head of the list
    while (current != nullptr) {
        Serial.print(current->data); // Print the data of the current node
        Serial.print(" ");
        current = current->next; // Move to the next node
    }
    Serial.println(); // Print a newline at the end
}

// Function to get the element at a specific position in the list
template <typename T>
T CerchioList<T>::getElement(int position) {
    CerchioListNode<T>* current = head;
    int currentPosition = 0;

    // Traverse the list to the specified position
    while (current != nullptr && currentPosition < position) {
        current = current->next;
        currentPosition++;
    }

    // Return the data at the specified position, or a default value if not found
    return (current != nullptr) ? current->data : T();
}

// Destructor definition
template <typename T>
CerchioList<T>::~CerchioList() {
    CerchioListNode<T>* current = head; // Start from the head of the list
    while (current != nullptr) {
        CerchioListNode<T>* next = current->next; // Save the next node
        delete current; // Delete the current node
        current = next; // Move to the next node
    }
}
