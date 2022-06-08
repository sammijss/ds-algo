#include"Bit.hpp"
#include <iostream> 

int main()
{
    is_ith_bit_set_using_right_shift(5, 2);
    is_ith_bit_set_using_right_shift(5, 1);

    is_ith_bit_set_using_left_shift(5, 2);
    is_ith_bit_set_using_left_shift(5, 1);

    set_ith_bit(5, 1);

    clear_ith_bit(5, 2);

    int bitcount = count_no_of_set_bits_using_while_loop(5);
    std::cout <<"Number of set bits: " <<bitcount <<std::endl;

    bitcount = count_no_of_set_bits_using_bit_operation(5);
    std::cout <<"Number of set bits: " <<bitcount <<std::endl;

    bitcount = find_no_of_bits_to_change_to_become_b(5, 7);
    std::cout <<"Number of bits need to change to make a to b: " <<bitcount <<std::endl;

    int swappednum = swap_bits_of_given_number(2);
    std::cout <<"Swapped number of 2: " <<swappednum <<std::endl;

    swappednum = swap_bits_of_given_number(5);
    std::cout <<"Swapped number of 5: " <<swappednum <<std::endl;

    int array[] = {1, 2, 3, 2, 4, 3, 1};
    find_only_one_non_repeating_element_from_an_array_where_each_element_repeats_twice(array, sizeof(array)/sizeof(int));

    return(0);
}
