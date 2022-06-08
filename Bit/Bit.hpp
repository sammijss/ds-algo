#ifndef _BIT_H_
#define _BIT_H_

/*
 * APIs
 */
void is_ith_bit_set_using_right_shift(int num, int ith);

void is_ith_bit_set_using_left_shift(int num, int ith);

void set_ith_bit(int num, int ith);

void clear_ith_bit(int num, int ith);

int find_no_of_bits_to_change_to_become_b(int a, int b);

int count_no_of_set_bits_using_while_loop(int num);

int count_no_of_set_bits_using_bit_operation(int num);

int swap_bits_of_given_number(int num);

void find_only_one_non_repeating_element_from_an_array_where_each_element_repeats_twice(int array[], int size);

#endif
