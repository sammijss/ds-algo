#include"String.hpp"

int main()
{
    
    std::string str;

    str = "abbcbba";
    check_for_palindrome_recursively(str, 0, str.length()-1);

    str = "abbcdbba";
    check_for_palindrome_recursively(str, 0, str.length()-1);

    str = "abc";
    std::string set;
    print_power_set_of_given_string(str, str.length()-1, set);

    return(0);
}
