#include"List.hpp"

int main()
{
    List list = {1, 2, 3, 4, 5};
    list.print_list();

    insert_node_at_front(list, 6);
    list.print_list();

    insert_node_at_end(list, 7);
    list.print_list();

    insert_node_after_given_node(list, 1, 10);
    list.print_list();

    insert_node_after_given_node(list, 4, 40);
    list.print_list();

    insert_node_after_given_node(list, 7, 70);
    list.print_list();

    Node* node = find_node_recursively(list.get_head(), 4);
    std::cout <<"Found data 4? " <<(node ? "Found" : "Not Found") <<std::endl;

    node = find_node_recursively(list.get_head(), 40);
    std::cout <<"Found data 40? " <<(node ? "Found" : "Not Found") <<std::endl;

    node = find_nth_node_from_end(list, 3);
    std::cout <<"nth(3) Node from end: " <<(node ? node->data : -999) <<std::endl;

    node = find_nth_node_recursively(list.get_head(), 3);
    std::cout <<"nth(3) Node: " <<node->data <<std::endl;

    std::cout <<"Middle of the list: " <<find_middle(list)->data <<std::endl;

    std::cout <<"Find the occurance of 1: " <<find_occurance_of_data_recursively(list.get_head(), 1) <<std::endl;

    delete_node(list, 6);
    list.print_list();

    delete_node(list, 40);
    list.print_list();

    delete_node(list, 70);
    list.print_list();

    delete_node_at_given_position(list, 1);
    list.print_list();

    delete_node_at_given_position(list, 3);
    list.print_list();

    delete_node_at_given_position(list, 5);
    list.print_list();

    delete_node_at_given_position(list, 4);
    list.print_list();

    delete_node_at_given_position(list, 3);
    list.print_list();

    return(0);
}
