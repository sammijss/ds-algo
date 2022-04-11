#ifndef _ARRAY_H_
#define _ARRAY_H_

#include<iostream>
#include<algorithm>
/*
 * PRINT API
 */
#define PRINT_ARRAY(array, size)\
    std::for_each(array, array+size, [](int a){ std::cout <<a <<" "; });\
    std::cout <<std::endl;

/*
 * FIND APIs
 */
void find_k_smallest_elements_using_modified_bubble_sort(int array[], int size, int k);
void find_k_smallest_elements_using_sorting(int array[], int size, int k);

int  find_smallest_missing_number(int array[], int size);

void find_all_triplets_with_sum_zero(int array[], int size);

#endif
