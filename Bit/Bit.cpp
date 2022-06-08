#include "Bit.hpp"
#include <iostream> 

/*
 * Check if ith bit is set or not
 * We will do right shift of number i times and do & with 1 (we will do masking with 1)
 */
void is_ith_bit_set_using_right_shift(int num, int ith)
{
    num >>= ith;

    if (num & 1) {
        std::cout <<"Bit is set" <<std::endl;
    } else {
        std::cout <<"Bit is not set" <<std::endl;
    }
}

/*
 * Check if ith bit is set or not
 * We will create a mask by left shifting 1 i times and do & with number
 */
void is_ith_bit_set_using_left_shift(int num, int ith)
{
    int mask = 1 << ith;

    if (num & mask) {
        std::cout <<"Bit is set" <<std::endl;
    } else {
        std::cout <<"Bit is not set" <<std::endl;
    }
}

/*
 * Set the ith bit
 * We will create a mask by left shifting 1 i times and do | with number
 */
void set_ith_bit(int num, int ith)
{
    int mask = 1 << ith;
    num |= mask;
    std::cout <<"Num after setting ith bit: " <<num <<std::endl; 
}

/*
 * Clear the ith bit
 * STEP 1: Creat a mask by left shifting 1 i times
 * STEP 2: Invert the bits of this mask
 * STEP 3: Perform & operation of number and mask
 */
void clear_ith_bit(int num, int ith)
{
    int mask = 1 << ith;
    mask = ~mask;
    num &= mask;
    std::cout <<"Num after clearing ith bit: " <<num <<std::endl; 
}

/*
 * Count the number of bits needed to change in a to become b
 * STEP 1: To find the number of different bits do XOR of a and b, we will get the number with all different bits
 * STEP 2: Count the nuber of set bits in the XOR's result
 */
int find_no_of_bits_to_change_to_become_b(int a, int b)
{
    int xorresult = a ^ b; //Number with different bits
    return count_no_of_set_bits_using_while_loop(xorresult);
}

/*
 * Count the number of set bits
 * Note: Total no of bits in a num = O(log(n)) + 1 [For Example: 8 = 1000, Number of bits = O(log(8)) + 1 = 3 + 1 = 4]
 * Timecomplexity: O(log(n)) [For Example: 8 = 1000, Number of loop iteration = O(log(8)) = 3]
 *                           [For Example: 2^50 = Number of loop iteration = O(log(2^50)) = 50]
 */
int count_no_of_set_bits_using_while_loop(int num)
{
    int bitcount = 0;
    while(num) {
        if (num & 1) {
            bitcount++;
        }
        num >>= 1;
    }
    return bitcount;
}

/*
 * Count the number of set bits
 * Timecomplexity: O(Number of set bit only) [For Example: 8 = 1000, Number of loop iteration = O(Number of set bit only) = 1]
 *                                           [For Example: 2^50 = Number of loop iteration = O(Number of set bit only) = 1]
 */
int count_no_of_set_bits_using_bit_operation(int num)
{
    int bitcount = 0;
    while(num) {
        bitcount++;
        num = num & (num - 1); 
    }
    return bitcount;
}

/*
 * Swap the bits of a given number
 * STEP 1: Get the even bits from the given number and shift them to odd position by right shifting 1
 * STEP 2: Get the odd bits from the given number and shift them to even position by left shifting 1
 * STEP 3: Combine both shifted result to get the desire result
 */
int swap_bits_of_given_number(int num)
{
    //Using A & 5 to change the bits in a nibble
    int evenbitsnum = num & 0xAAAAAAAA;
    int oddbitsnum  = num & 0x55555555;
    return ((evenbitsnum >> 1) | (oddbitsnum << 1));
}

/*
 * Find only one non-repeating element from an array where each element repeats twice
 * Method 1: Using two while loop, Timecomplexity: O(n^2), Spacecomplexity: O(1)
 * Method 2: Using hashmap (std::set<int>) if element will be present then remove it from the hashmap, if not then insert, Timecomplexity: O(n), Spacecomplexity: O(n)
 * Method 3: Using XOR operation, Timecomplexity: O(n), Spacecomplexity: O(1)
 * XOR of two same bits is 0
 * XOR of two different bits is 1
 */
void find_only_one_non_repeating_element_from_an_array_where_each_element_repeats_twice(int array[], int size)
{
    int xorresult = array[0];
    for (int i=1; i<size; i++) {
        xorresult ^= array[i];   
    }
    std::cout <<"One non-repeating element: " <<xorresult <<std::endl;
}


