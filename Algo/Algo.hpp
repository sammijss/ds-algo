#ifndef _ALGO_H_
#define _ALGO_H_

#include<iostream>
#include<algorithm>

/*
 * PRINT API
 */
#define PRINT_ARRAY(array, size)\
    std::for_each(array, array+size, [](int a){ std::cout <<a <<" "; });\
    std::cout <<std::endl;

/*
 * Kadane’s algorithm
 */
void best_time_to_buy_and_sell_one_stock_3(int array[], int size);

#endif
