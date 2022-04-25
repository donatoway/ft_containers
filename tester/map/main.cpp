#include "STDtestMap.hpp"
#include "FTestMap.hpp"
int main()
{
    std::cout  << "Do you want test my map container first? y/n\n";

    char c ;
    std::cin >> c;
    if (c   == 'y')
        std_test_map();

    c = 0;
    std::cout << "Do you want test std namespace?\n";
    std::cin >> c;
    if (c   == 'y')
        ft_test_map();

}