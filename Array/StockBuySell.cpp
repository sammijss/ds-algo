#include"Array.hpp"

/*
 * Find maximum profit
 * We will try to get the different between buy stock and sell stock
 * Time  Complexity: O(n2)
 * Space Complexity: O(1)
 */
void best_time_to_buy_and_sell_one_stock_1(int array[], int size)
{
    PRINT_ARRAY(array, size);

    int buystock = 0;
    int maxprofit = 0;

    for (int i=0; i<size-1; i++) {
        buystock = array[i];
        for (int j=i+1; j<size; j++) {
            if ((array[j] - buystock) > maxprofit) {
                maxprofit = array[j] - buystock;
            }
        }
    }
    std::cout <<"MaxProfit: " <<maxprofit <<std::endl;
}

/*
 * Find maximum profit
 * We will find the buy stock (minimum element) and its index, after that index find for the sell stock
 * Time  Complexity: O(n)
 * Space Complexity: O(1)
 */
void best_time_to_buy_and_sell_one_stock_2(int array[], int size)
{
    int buystock = 0;
    int buystockindex = 0;
    int maxprofit = 0;

    buystock = array[0];
    for (int i=1; i<size; i++) {
        if (buystock > array[i]) {
            buystock = array[i];
            buystockindex = i;
        }
    }

    for (int i=buystockindex+1; i<size; i++) {
        if ((array[i] - buystock) > maxprofit) {
            maxprofit = array[i] - buystock;
        }
    }
    std::cout <<"MaxProfit: " <<maxprofit <<std::endl;
}

/*
 * Find maximum profit
 * We will buy the stock (try to find the minimum stock value) and try to sell the stock on the same day
 * Time  Complexity: O(n)
 * Space Complexity: O(1)
 */
void best_time_to_buy_and_sell_one_stock_3(int array[], int size)
{
    int buystock = 0;
    int maxprofit = 0;

    buystock = array[0];
    for (int i=0; i<size; i++) {
        if (buystock > array[i]) {
            buystock = array[i];
        }
        if ((array[i] - buystock) > maxprofit) {
            maxprofit = array[i] - buystock;
        }
    }

    std::cout <<"MaxProfit: " <<maxprofit <<std::endl;
}
