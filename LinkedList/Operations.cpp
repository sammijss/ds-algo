#include"List.hpp"
#include<unordered_set>

void operations()
{
    /* INSERT, FIND, DELETE */
    {
        List list = {1, 2, 3, 4, 5};
        list.print_list();

        insert_node_at_front(list, 6);
        list.print_list();

        insert_node_at_end(list, 7);
        list.print_list();

        insert_node_after_given_node(list, 1, 10);
        list.print_list();

        Node* node = find_node_recursively(list.get_head(), 4);
        std::cout <<"Found data 4? " <<(node ? "Found" : "Not Found") <<std::endl;

        node = find_nth_node_from_end(list, 3);
        std::cout <<"nth(3) Node from end: " <<(node ? node->data : -999) <<std::endl;

        node = find_nth_node_recursively(list.get_head(), 3);
        std::cout <<"nth(3) Node recursively: " <<node->data <<std::endl;

        std::cout <<"Middle of the list: " <<find_middle(list)->data <<std::endl;

        std::cout <<"Find the occurance of 1: " <<find_occurance_of_data_recursively(list.get_head(), 1) <<std::endl;

        delete_node(list, 4);
        list.print_list();

        delete_node_at_given_position(list, 3);
        list.print_list();
    }

    /* REMOVE DUPLICATES FROM SORTED LIST */
    {
        List list = {1, 1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 8, 8, 8, 9, 9, 9, 9, 10};
        list.print_list();

        remove_duplicates_from_sorted_list(list.get_head());
        list.print_list();
    }

    /* REMOVE DUPLICATES FROM UNSORTED LIST USING TWO LOOPS */
    {
        List list = {1, 2, 1, 1, 7, 3, 4, 9, 5, 5, 6, 2, 7, 8, 8, 7, 9, 3, 9, 9, 10};
        list.print_list();

        remove_duplicates_from_unsorted_list_using_two_loops(list.get_head());
        list.print_list();
    }

    /* REMOVE DUPLICATES FROM UNSORTED LIST USING HASHMAP */
    {
        List list = {1, 2, 1, 1, 7, 3, 4, 9, 5, 5, 6, 2, 7, 8, 8, 7, 9, 3, 9, 9, 10};
        list.print_list();

        remove_duplicates_from_unsorted_list_using_hashmap(list.get_head());
        list.print_list();
    }

    /* REMOVE DUPLICATES FROM UNSORTED LIST USING SORTING */
    {
        List list = {1, 2, 1, 1, 7, 3, 4, 9, 5, 5, 6, 2, 7, 8, 8, 7, 9, 3, 9, 9, 10};
        list.print_list();

        remove_duplicates_from_unsorted_list_using_sorting(list.get_head());
        list.print_list();
    }
}

/*
 *--------------------------------------------------------------------
 * INSERT APIs
 *--------------------------------------------------------------------
 */
/*
 * Insert a node at the front of the list
 * Time  Complexity: O(1)
 * Space Complexity: O(1)
 */
void insert_node_at_front(List& list, int data)
{
    Node* node = new Node(data);
    Node* head = list.get_head();
    node->next = head;
    list.reset_head(node);
}

/*
 * Insert a node at the end of the list
 * Time  Complexity: O(n) - If we don't have tail, then need to iterate through the whole list
                     O(1) - If we will have tail
 * Space Complexity: O(1)
 */
void insert_node_at_end(List& list, int data)
{
    Node* node = new Node(data);
    Node* tail = list.get_tail();
    tail->next = node;
    list.reset_tail(node);
}

/*
 * Insert a node before a given data
 * Time  Complexity: O(n)
 * Space Complexity: O(1)
 */
void insert_node_before_given_node(List& list, int beforedata, int data)
{
    Node* head = list.get_head();
    Node* prev = nullptr;
    while(head) {
        if (head->data == beforedata) {
            Node* newnode = new Node(data);
            newnode->next = head;
            prev->next = newnode;
            return;
        }
        prev = head;
        head->next = head;
    }
}

/*
 * Insert a node after a given data
 * Time  Complexity: O(n)
 * Space Complexity: O(1)
 */
void insert_node_after_given_node(List& list, int afterdata, int data)
{
    Node* head = list.get_head();
    Node* node = find_node_recursively(head, afterdata);
    if (node == nullptr) {
        return;
    }
    Node* newnode = new Node(data);
    Node* tail = list.get_tail();
    if (node == tail) {
        tail->next = newnode;
        list.reset_tail(newnode);
    } else {
        Node* nodenext = node->next;
        node->next = newnode;
        newnode->next = nodenext;
    }
}

/*
 *--------------------------------------------------------------------
 * FIND/SEARCH APIs
 *--------------------------------------------------------------------
 */
/*
 * Find the lenght of the list recursively
 * Time  Complexity: O(n)
 * Space Complexity: O(1)
 */
int find_length_recursively(Node* head)
{
    if (!head) {
        return(0);
    }
    return(1 + find_length_recursively(head->next));
}

/*
 * Find the node recursively
 * Time  Complexity: O(n)
 * Space Complexity: O(1)
 */
Node* find_node_recursively(Node* head, int data)
{
    if (!head) {
        return(nullptr);
    }
    else if (head->data == data) {
        return(head);
    }
    else {
        return(find_node_recursively(head->next, data));
    }
}

/*
 * Find nth node recursively
 * Time  Complexity: O(n)
 * Space Complexity: O(1)
 */
Node* find_nth_node_recursively(Node* head, int nth)
{
    static int count = 1;
    if (!head || (count++ == nth)) {
        return(head);
    }
    return(find_nth_node_recursively(head->next, nth));
}

/*
 * Find nth node from the end
 * Time  Complexity: O(n)
 * Space Complexity: O(1)
 */
Node* find_nth_node_from_end(List& list, int nth)
{
    Node* ptr1 = list.get_head();
    Node* ptr2 = list.get_head();

    while(nth-- && ptr2) {
        ptr2 = ptr2->next;
    }

    if (ptr2) {
        while(ptr1 && ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return(ptr1);
    }
    return(nullptr);
}

/*
 * Find the middle of the list
 * Time  Complexity: O(n)
 * Space Complexity: O(1)
 */
Node* find_middle(List& list)
{
    Node* head = list.get_head();
    if (!head || !(head->next)) {
        return(head);
    }

    Node* slow = head;
    Node* fast = head;;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return(slow);
}

/*
 * Find the occurance of a data recursively
 * Time  Complexity: O(n)
 * Space Complexity: O(1)
 */
int find_occurance_of_data_recursively(Node* head, int data)
{
    int count = 0;
    if (!head) {
       return(0); 
    }
    if (head->data == data) {
        count++;
    }
    return(count + find_occurance_of_data_recursively(head->next, data));
}

/*
 *--------------------------------------------------------------------
 * DELETE APIs
 *--------------------------------------------------------------------
 */
/*
 * Delete a node
 * Time  Complexity: O(n)
 * Space Complexity: O(1)
 */
void delete_node(List& list, int data)
{
    Node* head = list.get_head();
    if (!head) {
        return;
    }

    if (head->data == data) {
        Node* headnext = head->next;
        delete (head);
        list.reset_head(headnext);            
        return;
    }

    Node* prev = nullptr;
    Node* tail = list.get_tail();
    while(head) {
        if (head->data == data) {
            prev->next = head->next;
            if (head == tail) {
                list.reset_tail(prev);
            }
            delete (head);
            return;
        }
        prev = head;
        head = head->next;
    }
}

/*
 * Delete a node from a given position 
 * Time  Complexity: O(n)
 * Space Complexity: O(1)
 */
void delete_node_at_given_position(List& list, int position)
{
    Node* head = list.get_head();
    if (!head || position < 1) {
        return;
    }

    if (position == 1) {
        Node* headnext = head->next;
        delete (head);
        list.reset_head(headnext);            
        return;
    }

    Node* prev = nullptr;
    Node* tail = list.get_tail();
    while(head && --position) {
        prev = head;
        head = head->next;
    }

    if (head) {
        prev->next = head->next;
        if (head == tail) {
            list.reset_tail(prev);
        }
        delete (head);
    }
}

/*
 *--------------------------------------------------------------------
 * REMOVE APIs
 *--------------------------------------------------------------------
 */
/*
 * Remove the duplicates from a sorted linked list
 * Time  Complexity: O(n)
 * Space Complexity: O(1)
 */
void remove_duplicates_from_sorted_list(Node* head)
{
    while(head && head->next) {
        if (head->data == head->next->data) {
            Node* next = head->next->next;
            delete(head->next);
            head->next = next;
        } else {
            head = head->next;
        }
    }
}

/*
 * Remove the duplicates from a unsorted linked list using two loops 
 * Time  Complexity: O(n2)
 * Space Complexity: O(1)
 */
void remove_duplicates_from_unsorted_list_using_two_loops(Node* head)
{
    while(head) {
        Node* prev = head;
        Node* node = head->next;
        while(node) {
            if (head->data == node->data) {
                prev->next = node->next;
                delete(node);
                node = prev->next;
            } else {
                prev = node;
                node = node->next;
            }
        }
        head = head->next;
    }
}

/*
 * Remove the duplicates from a unsorted linked list using hashmap
 * Time  Complexity: O(n)
 * Space Complexity: O(n)
 */
void remove_duplicates_from_unsorted_list_using_hashmap(Node* head)
{
    std::unordered_set<int> hashmap;
    Node* prev = NULL;
    while(head) {
        if (hashmap.find(head->data) == hashmap.end()) {
            prev = head;
            hashmap.insert(head->data);
            head = head->next;
        } else {
            prev->next = head->next;
            delete(head);
            head = prev->next;
        }
    }
}

//TODO
/*
 * Using sorting 
 * Time  Complexity: O(n(logn))
 * Space Complexity: O(1)
 */
void remove_duplicates_from_unsorted_list_using_sorting(Node* head)
{
}
