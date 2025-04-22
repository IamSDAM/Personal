// S. Trowbridge 2024
#include <iostream>
                                                    // the standard namespace is NOT defined as the global namespace
int main() 
{
    std::cout << std::endl;                         // std:: prefix is required for all standard namespace commands

    std::string s = "Standard Namespace";           // std:: prefix required for all standard namespace commands
    std::cout << s << std::endl;

    std::cout << std::endl;
    return 0;
}
