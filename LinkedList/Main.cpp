#include"List.hpp"

int main()
{
#if 1
    std::cout <<"Operations on List Start" <<std::endl;
    std::cout <<"------------------------" <<std::endl;
    operations();
    std::cout <<"Operations on List End!" <<std::endl;
    std::cout <<"------------------------" <<std::endl;
#else

    std::cout <<"Loop on List Start" <<std::endl;
    std::cout <<"------------------------" <<std::endl;
    loop();
    std::cout <<"Loop on List End" <<std::endl;
    std::cout <<"------------------------" <<std::endl;
    return(0);
#endif
}
