#include"String.hpp"

int main()
{
    std::string str = "abbcbba";
    check_for_palindrome_recursively(str, 0, str.length()-1);

    std::string str2 = "abbcdbba";
    check_for_palindrome_recursively(str2, 0, str.length()-1);

    return(0);
}
