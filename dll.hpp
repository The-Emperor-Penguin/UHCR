#ifndef DOUBLYLIKEDLIST
#define DOUBLYLIKEDLIST

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstddef>
#include "cryptopp/cryptlib.h"
#include "cryptopp/blake2.h"
#include "cryptopp/hex.h"
#include "cryptopp/filters.h"
#include "cryptopp/files.h"
using namespace std;

struct Node {
    bool bit;
    Node* next;
    Node* back;
    Node(Node* const &node);
    Node();
    Node(bool bit);
};

class DLinkedList {
    public:
        DLinkedList(unsigned int ones, unsigned int zeros);
        DLinkedList(DLinkedList const &doublelinkedlist);
        ~DLinkedList();
        void moveNNodesLeft(unsigned int N, unsigned int at);
        string toString();
        Node* getHead()const;
    private:
        Node* head;
};

#endif