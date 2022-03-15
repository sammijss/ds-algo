#include"List.hpp"

List::List(const std::initializer_list<int>& list) {
    head = tail = NULL;
    for (std::initializer_list<int>::iterator it = list.begin(); it != list.end(); ++it) {
        add_element(*it);
    }
}

List::~List() {
    while(head) {
        Node* next = head->next;
        delete(head);
        head = next;
    }
}

void List::add_element(int data) {
    Node* node = new Node(data);
    if (head == NULL) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void List::print_list() {
    Node* head = this->head; //Without this the original head will be moved
    while(head) {
        std::cout <<head->data <<" ";
        head = head->next;
    }
    std::cout <<std::endl;
}

Node* List::get_head() {
    return(head);
}

void List::reset_head(Node* node) {
    this->head = node;
}

Node* List::get_tail() {
    return(tail);
}

void List::reset_tail(Node* node) {
    this->tail = node;
}
