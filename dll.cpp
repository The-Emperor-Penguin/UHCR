#include "dll.hpp"

Node::Node(Node* const &node) {
    if (node == nullptr) return;
    bit = node->bit;
    next = node->next;
    back = node->back;

}

Node::Node() {
    bit = false;
    next = nullptr;
    back = nullptr;
}

Node::Node(bool bit) {
    this->bit = bit;
    next = nullptr;
    back = nullptr;
}

DLinkedList::~DLinkedList() {
    Node *temp = head;
    Node *nexttemp = head->next;
    while (temp != nullptr) {
        temp->back = nullptr;
        temp->next = nullptr;
        delete temp;
        temp = nexttemp;
        if (temp != nullptr) nexttemp = temp->next;
    }
}

DLinkedList::DLinkedList(unsigned int ones, unsigned int zeros) {
    
    head = new Node(false);
    zeros--;
    unsigned long total = ones + zeros;
    Node * tempback = head;
    for(unsigned int i = 0; i < total; i++) {
        if (zeros) {
            Node* temp = new Node(false);
            temp->back = tempback;
            tempback->next = temp;
            tempback = temp;
            zeros--;
        }
        else {
            Node* temp = new Node(true);
            temp->back = tempback;
            tempback->next = temp;
            tempback = temp;
            ones--;
        }
    }
}

DLinkedList::DLinkedList(DLinkedList const &doublelinkedlist) {
    Node *oldtemp = doublelinkedlist.getHead()->next;
    head = new Node(doublelinkedlist.getHead());
    Node *temp = head->next;
    Node *tback = head;
    while (oldtemp != nullptr) {
      temp = new Node(oldtemp);
      temp->back = tback;
      tback->next = temp;
      tback = temp;
      temp = temp->next;
      oldtemp = oldtemp->next;
    }
}

 Node* DLinkedList::getHead() const {
    return head;
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
