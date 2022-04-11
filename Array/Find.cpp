#include<climits>
#include"Array.hpp"

/*
 * Find the k largest (or smallest) elements in an array 
 * Time  Complexity: O(n*k)
 * Space Complexity: O(1)
 */
void find_k_smallest_elements_using_modified_bubble_sort(int array[], int size, int k)
{
    PRINT_ARRAY(array, size);
    for (int i=0; i<k; i++) {
        for (int j=0; j<size-1-i; j++) {
            if (array[j] < array[j+1]) {
                std::swap(array[j], array[j+1]);
            }
        }
    }

    for (int i=1; i<=k; i++) {
        std::cout <<array[size-i] <<" ";
    }
    std::cout <<std::endl;
}

/*
 * Find the k largest (or smallest) elements in an array 
 * Time  Complexity: O(n(logn))
 * Space Complexity: O(1)
 */
void find_k_smallest_elements_using_sorting(int array[], int size, int k)
{
    PRINT_ARRAY(array, size);
    std::sort(array, array+size);   //n*log2(n)
    PRINT_ARRAY(array, k);
}

//TODO
/*
 * Given a sorted array of n distinct integers where each integer is in the range from 0 to m-1 and m > n.
 *
 * Perform the linear search and compare the value of the array with index if both will not match then value of the index will be our smallest missing number
 * Time  Complexity: O(n))
 * Space Complexity: O(1)
 *
 * Perform the binary search and compare the value of the array with index if both will not match then value of the index will be our smallest missing number
 * Time  Complexity: O(logn))
 * Space Complexity: O(1)
 */
int find_smallest_missing_number(int array[], int size)
{
    int l = 0;
    int r = size - 1;
    while(l < r) {
        int m = (l + r)/2;
        std::cout <<"m: " <<m <<std::endl;
        if (array[m] != m) {
            std::cout <<"Smallest missing number: " <<m <<std::endl;
            return(m);
        } else if (array[m] > m) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    std::cout <<"Smallest missing number is not found" <<std::endl;
    return(INT_MIN);
}

/*
 * We can use three loops to find all triplets equal to zero
 * Time  Complexity: O(n3))
 * Space Complexity: O(1)
 *
 * We can optimize the solution by sorting the array and using two loops
 * Time  Complexity: O(n2))
 * Space Complexity: O(1)
 */
void find_all_triplets_with_sum_zero(int array[], int size)
{
    PRINT_ARRAY(array, size);
    std::sort(array, array+size);   //n*log2(n)

    for (int i=0; i<size-2; i++) {
        int x = array[i];
        int l = i+1;
        int r = size-1;
        while(l < r) {
            if ((x + array[l] + array[r]) == 0) {
                std::cout <<"(" <<x <<" + " <<array[l] <<" + " <<array[r] <<")" <<std::endl;
                l++;
                r--;
            } else if ((x + array[l] + array[r]) < 0) {
                l++;
            } else {
                r--;
            }
        }
    }
}
