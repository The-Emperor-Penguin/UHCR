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
};

class DLinkedList {
    public:
        DLinkedList(unsigned int ones, unsigned int zeros);
        void moveNNodesLeft(unsigned int N, unsigned int at);
        string toString();
    private:
        Node* head;
};

#endif