#pragma once
#include <string>

struct node_sll {
    std::string errorMessage;
    node_sll* next;
    node_sll(std::string msg) : errorMessage(msg), next(nullptr) {}
};

class stringLinkedList {

    public:
        node_sll* head = nullptr;
        
        void append(std::string msg) {
            node_sll* newNode = new node_sll(msg);
            if (!head) { head = newNode; return; }
            node_sll* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }

};