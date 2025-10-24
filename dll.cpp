#include "dll.hpp"

DLinkedList::DLinkedList(unsigned int ones, unsigned int zeros) {
    
    head = new Node();
    head->bit = false;
    zeros--;
    unsigned long total = ones + zeros;
    Node * tempback = head;
    for(unsigned int i = 0; i < total; i++) {
        if (zeros) {
            Node* temp = new Node();
            temp->bit = false;
            temp->back = tempback;
            tempback->next = temp;
            tempback = temp;
            zeros--;
        }
        else {
            Node* temp = new Node();
            temp->bit = true;
            temp->back = tempback;
            tempback->next = temp;
            tempback = temp;
            ones--;
        }
    }
}
void DLinkedList::moveNNodesLeft(unsigned int N, unsigned int at) {
    /* at is the start of the nodes to
     * move and N is the number including at to move
     * this means that N must be > 0
    */

    if (at == 0) return;
    if (!N) return;

    Node *temp = head;

    for (unsigned int i = 0; i < at; i++) {
        temp = temp->next;
    }
    Node *frontMove = temp;
    for (unsigned int i = at; i < (N+at-1); i++) {
        temp = temp->next;
    }
    Node *newBack = nullptr;  // Initialize to nullptr
    if (at > 1) newBack = frontMove->back->back;
    Node *move = frontMove->back;
    Node *oldNext = nullptr;
    if (temp->next != nullptr) oldNext = temp->next;
    if (newBack != nullptr) {
        newBack->next = frontMove;
        frontMove->back = newBack;
    }
    else {
        head = frontMove;
        frontMove->back = nullptr;
    }
    temp->next = move;
    move->back = temp;
    if (oldNext!=nullptr) oldNext->back = move;
    move->next = oldNext;
}
string DLinkedList::toString() {
    Node *temp = head;
    string output = "";
    while (temp != nullptr) {
        int number = static_cast<int>(temp->bit);
        output += to_string(number);
        temp = temp->next;
    }
    return output;
}
