# CerchioList Library

## Overview

The CerchioList library provides an intrusively linked list implementation for Arduino, allowing users to create and manage linked lists with ease. It is a templated C++ class that can store elements of any type. The library includes functions to add nodes, remove nodes, and print the elements of the list.  Cerchio is Italian for Circle

## Installation

1. Download the CerchioList library ZIP file from [GitHub](https://github.com/adamjvr/cerchio-list).
2. Add the contents of the Zip to your Arduino Sketch directory.

## Usage

### Creating an Instance

```cpp
// Example usage with integers
CerchioList<int> intList;

// Example usage with strings
CerchioList<String> stringList;
```

### Adding Nodes
```cpp
// Add elements to the list
intList.addNode(1);
intList.addNode(2);
intList.addNode(3);

stringList.addNode("Hello");
stringList.addNode("World");

```

### Removing Nodes
```cpp
// Remove a node from the list
intList.removeNode(2);
```

### Printing The List

```cpp
// Print the elements of the list
intList.printList();
```

### Deconstructor
The library includes a destructor that automatically frees the memory occupied by the linked list when the object goes out of scope or is explicitly destroyed.

## Function Details

### Constructor 
`CerchioList() ` :Constructor to initialize an empty linked list.



### Deconstructor
`~CerchioList()`: Destructor to free the memory occupied by the linked list.



### addNode
`void addNode(T val)`.

**Drescription**:: Adds a new node with the specified value to the list.

**Parameters**:
-  `T val`: The value to be stored in the new node.


### removeNode
`T removeNode(T val)`

**Drescription**:: Removes the first node with the specified value from the list and returns the removed element.

**Parameters**:
- `T val`: The value to be removed from the list.


**Return Value**:
 - The data of the removed node, or a default value if not found.


 ### getElement
 `T getElement(int position)`

 **Drescription**: Gets the element at a specific position in the list.

**Parameters**: 
- `int position`: The position of the element to retrieve (0-based index).

**Return Value**:
- The data of the node at the specified position, or a default value if not found.

### printList
`void printList()`

**Description**: Prints the elements of the list to the Serial Monitor.


## Example Sketch

Check the provided Arduino sketch for a detailed example demonstrating the usage of all functions.

```cpp
#include "cerchio_list.h"

// Example usage with integers
CerchioList<int> intList;

void setup() {
    Serial.begin(9600);

    // Add some elements to the list
    intList.addNode(1);
    intList.addNode(2);
    intList.addNode(3);

    // Print the original list
    Serial.println("Original Integer List:");
    intList.printList();
    Serial.println();

    // Remove a node from the list and get the removed element
    int removedElement = intList.removeNode(2);
    Serial.println("Removed Element: " + String(removedElement));
    Serial.println();

    // Print the modified list
    Serial.println("List after removing 2:");
    intList.printList();
    Serial.println();

    // Get the element at a specific position in the list
    int retrievedElement = intList.getElement(1);
    Serial.println("Element at position 1: " + String(retrievedElement));
    Serial.println();
}

void loop() {
    // Your code here
}
```

## Contributing

Feel free to contribute to the development of this library. If you find any issues or have suggestions for improvements, please create an issue or submit a pull request.

## License

MIT License

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