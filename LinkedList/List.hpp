#ifndef _LIST_H_
#define _LIST_H_

#include<iostream>

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class List {
    private:
        Node* head;
        Node* tail;

        void add_element(int data);

    public:
        List(const std::initializer_list<int>& list);
        ~List();

        List(const List&) = delete;
        List& operator=(const List&) = delete;

        List(List&&) = delete;
        List& operator=(List&&) = delete;

        Node* get_head();
        void  reset_head(Node* node);

        Node* get_tail();
        void  reset_tail(Node* node);

        void print_list();
};

/*
 * OPEARTIONS APIs
 */

void operations();

/*
 *--------------------------------------------------------------------
 * INSERT APIs
 *--------------------------------------------------------------------
 */
void insert_node_at_front(List& list, int data);
void insert_node_at_end(List& list, int data);
void insert_node_before_given_node(List& list, int beforedata, int data);
void insert_node_after_given_node(List& list, int afterdata, int data);

/*
 *--------------------------------------------------------------------
 * FIND/SEARCH APIs
 *--------------------------------------------------------------------
 */
int   find_length_recursively(Node* head);
Node* find_node_recursively(Node* head, int data);
Node* find_nth_node_recursively(Node* head, int nth);
Node* find_nth_node_from_end(List& list, int nth);
Node* find_middle(List& list);
int   find_occurance_of_data_recursively(Node* head, int data);

/*
 *--------------------------------------------------------------------
 * DELETE APIs
 *--------------------------------------------------------------------
 */
void delete_node(List& list, int data);
void delete_node_at_given_position(List& list, int position);

/*
 *--------------------------------------------------------------------
 * REMOVE APIs
 *--------------------------------------------------------------------
 */
void remove_duplicates_from_sorted_list(Node* head);
void remove_duplicates_from_unsorted_list_using_two_loops(Node* head);
void remove_duplicates_from_unsorted_list_using_hashmap(Node* head);
void remove_duplicates_from_unsorted_list_using_sorting(Node* head);

/*
 * LOOP APIs
 */

void loop();

void print_the_looped_list(Node* head);
Node* detect_loop_using_hashmap(Node* head);
Node* detect_loop_using_floyd_cycle_detection_algo(Node* head);
int   find_lenght_of_the_loop(Node* head);
void  remove_the_loop(Node* head);

#endif
