#include"List.hpp"

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
