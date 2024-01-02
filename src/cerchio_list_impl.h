#ifndef CERCHIO_LIST_IMPL_H
#define CERCHIO_LIST_IMPL_H

template <typename T>
CerchioList<T>::CerchioList() : head(nullptr) {}

template <typename T>
void CerchioList<T>::addNode(T val) {
    CerchioListNode<T>* newNode = new CerchioListNode<T>(val);
    newNode->next = head;
    head = newNode;
}

template <typename T>
T CerchioList<T>::removeNode(T val) {
    CerchioListNode<T>* current = head;
    CerchioListNode<T>* prev = nullptr;
    T removedValue = T();

    while (current != nullptr && current->data != val) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        removedValue = current->data;
        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
    }

    return removedValue;
}

template <typename T>
void CerchioList<T>::printList() {
    CerchioListNode<T>* current = head;
    while (current != nullptr) {
        Serial.print(current->data);
        Serial.print(" ");
        current = current->next;
    }
    Serial.println();
}

template <typename T>
T CerchioList<T>::getElement(int position) {
    CerchioListNode<T>* current = head;
    int currentPosition = 0;

    while (current != nullptr && currentPosition < position) {
        current = current->next;
        currentPosition++;
    }

    return (current != nullptr) ? current->data : T();
}

template <typename T>
CerchioList<T>::~CerchioList() {
    CerchioListNode<T>* current = head;
    while (current != nullptr) {
        CerchioListNode<T>* next = current->next;
        delete current;
        current = next;
    }
}

#endif // CERCHIO_LIST_IMPL_H
