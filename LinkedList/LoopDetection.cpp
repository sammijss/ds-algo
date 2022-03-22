#include"List.hpp"
#include<unordered_set>

void loop()
{
    //This program will crash because Destructor ~List() will try to delete the memory of 4 two times, so we need to break the loop to avoid the crash
    List list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* tail = list.get_tail();
    Node* node = find_node_recursively(list.get_head(), 4);
    tail->next = node;

    Node* head = list.get_head();
    print_the_looped_list(head);

    std::cout <<(detect_loop_using_hashmap(head) ? "Loop Found" : "Loop Not Found") <<std::endl;
    std::cout <<(detect_loop_using_floyd_cycle_detection_algo(head) ? "Loop Found" : "Loop Not Found") <<std::endl;

    std::cout <<"Lenght of the loop: " <<find_lenght_of_the_loop(head) <<std::endl;

    //After this program will not crash
    remove_the_loop(head);
    list.print_list();
}

/*
 * Print the looped list (special list)
 * Time  Complexity: O(n)
 * Space Complexity: O(n)
 */
void print_the_looped_list(Node* head)
{
    std::unordered_set<Node*> hashmap;
    while(head) {
        auto it = hashmap.find(head);
        if (it != hashmap.end()) {
            std::cout <<head->data <<std::endl;
            return;
        }
        std::cout <<head->data <<" ";
        hashmap.insert(head);
        head = head->next;
    }
}

/*
 * Detects loop in the list
 * Time  Complexity: O(n)
 * Space Complexity: O(n)
 */
Node* detect_loop_using_hashmap(Node* head)
{
    std::unordered_set<Node*> hashmap;
    while(head) {
        auto it = hashmap.find(head);
        if (it != hashmap.end()) {
            return(*it);
        }
        hashmap.insert(head);
        head = head->next;
    }
    return(nullptr);
}

/*
 * Detects loop in the list
 * Time  Complexity: O(n)
 * Space Complexity: O(1)
 */
//THIS IS LIKE RACING TRACK WITH SLOW AND FAST CARS
Node* detect_loop_using_floyd_cycle_detection_algo(Node* head)
{
    Node* slowptr = head; //SLOW CAR
    Node* fastptr = head; //FAST CAR

    while(slowptr && fastptr && fastptr->next) {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if (slowptr == fastptr) {
            return(slowptr);
        }
    }
    return(nullptr);
}

/*
 * Finds the lenght of the loop
 * Time  Complexity: O(n)
 * Space Complexity: O(1)
 */
int find_lenght_of_the_loop(Node* head)
{
    Node* node = detect_loop_using_floyd_cycle_detection_algo(head);
    Node* nextnode = node;
    int count = 1;
    while(nextnode->next != node) {
        count++;
        nextnode = nextnode->next;
    }
    return(count);
}

/*
 * Remove the loop from the list
 * Time  Complexity: O(n)
 * Space Complexity: O(1)
 */
void remove_the_loop(Node* head)
{
    Node* ptr1 = detect_loop_using_floyd_cycle_detection_algo(head);
    Node* ptr2 = head;

    while(ptr1->next != ptr2->next) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr1->next = NULL; 
}
