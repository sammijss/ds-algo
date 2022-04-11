#include"Array.hpp"

int main()
{
    int array[] = {1, 7, 2, -1, 2, 3, 0, 6, 5, 4};
    find_k_smallest_elements_using_modified_bubble_sort(array, sizeof(array)/sizeof(int), 3);

    int array2[] = {1, 7, 2, -1, 2, 3, 0, 6, 5, 4};
    find_k_smallest_elements_using_sorting(array2, sizeof(array2)/sizeof(int), 3);

    int array3[] = {0, -1, 2, -3, 1, -4, 5};
    find_all_triplets_with_sum_zero(array3, sizeof(array3)/sizeof(int));

    int array4[] = {0, 1, 2, 6, 9};
    find_smallest_missing_number(array4, sizeof(array4)/sizeof(int));

    return(0);
}
