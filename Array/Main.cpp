#include"Array.hpp"

int main()
{
    {
        int array[] = {1, 7, 2, -1, 2, 3, 0, 6, 5, 4};
        find_k_smallest_elements_using_modified_bubble_sort(array, sizeof(array)/sizeof(int), 3);
    }

    {
        int array[] = {1, 7, 2, -1, 2, 3, 0, 6, 5, 4};
        find_k_smallest_elements_using_sorting(array, sizeof(array)/sizeof(int), 3);
    }

    {
        int array[] = {0, -1, 2, -3, 1, -4, 5};
        find_all_triplets_with_sum_zero(array, sizeof(array)/sizeof(int));
    }

    {
        int array[] = {0, 1, 2, 6, 9};
        find_smallest_missing_number(array, sizeof(array)/sizeof(int));
    }

    {
        int array[] = {4, 6, 5, 2, 7, 1, 9};
        best_time_to_buy_and_sell_one_stock_1(array, sizeof(array)/sizeof(int));
        best_time_to_buy_and_sell_one_stock_2(array, sizeof(array)/sizeof(int));
        best_time_to_buy_and_sell_one_stock_3(array, sizeof(array)/sizeof(int));
    }

    return(0);
}
