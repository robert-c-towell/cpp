#include <iostream>

struct Node {
    int value;
    Node *next;
};

class LinkedList {
    private:
        int size;
        Node* head;
        Node* tail;

        Node* iterate(int index);

    public:
        LinkedList();
        void insert(int v);
        void print(int index);
        int get(int index);

};

LinkedList::LinkedList() {
    size = 0;
    head = NULL;
    tail = NULL;
}

Node* LinkedList::iterate(int index) {
    Node* p = head;
    for (auto i = 1; i < index; i++) {
        p = head->next;
    }
    return p;
}

void LinkedList::insert(int v) {
    auto newNode = new Node();
    newNode->value = v;
    if (size > 0) {
        tail->next = newNode;
    } else {
        tail = newNode;
    }
    if (size == 0) {
        head = newNode;
    }
    size++;
}

void LinkedList::print(int index) {
    auto n = iterate(index);
    std::cout << n->value << std::endl;
}

int LinkedList::get(int index) {
    auto n = iterate(index);
    return n->value;
}

int main() {
    auto linkedList = new LinkedList();
    linkedList->insert(4);
    linkedList->insert(7);
    linkedList->insert(10);
    linkedList->insert(43);
    linkedList->insert(3);
    linkedList->insert(17);
    linkedList->insert(9);
    linkedList->insert(2);
    linkedList->print(1);
    auto v = linkedList->get(5);
    std::cout << 2*v << std::endl;
}