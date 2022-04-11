#include<iostream>
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
