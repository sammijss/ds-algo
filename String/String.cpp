#include<iostream>
#include<algorithm>
#include"String.hpp"

/*
 * Recursively: Check that a given string a palindrome or not
 */
bool check_for_palindrome_recursively(std::string str, int start, int end)
{
    if (start >= end) {
        std::cout <<"Given string: " <<str <<", is a palindrome" <<std::endl;
        return(true);
    }

    if (str[start++] != str[end--]) {
        std::cout <<"Given string: " <<str <<", is not a palindrome" <<std::endl;
        return(false);
    }
    return check_for_palindrome_recursively(str, start, end);
}

void print_power_set_of_given_string(std::string str, int index, std::string& set)
{
    //We have considered all chars
    if (index < 0) {
        //std::for_each(std::begin(set), std::end(set), [](char ch) { std::cout <<ch <<" "; });
        std::cout <<set <<std::endl;
        return;
    }

    //Consider the n'th element
    set += str[index];
    //std::cout <<index <<", " <<set <<std::endl;
    print_power_set_of_given_string(str, index-1, set);

    str.pop_back(); //Backtrack
    //std::cout <<str <<", in: " <<index <<std::endl;

    //Or don't consider the n'th element
    set = "";
    print_power_set_of_given_string(str, str.length()-1, set);
}
